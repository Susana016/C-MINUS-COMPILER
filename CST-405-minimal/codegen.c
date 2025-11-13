#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"
#include "symtab.h"

FILE* output;
int tempReg = 0;

int getNextTemp() {
    int reg = tempReg++;
    if (tempReg > 7) tempReg = 0;  // Reuse $t0-$t7
    return reg;
}

void genExpr(ASTNode* node) {
    if (!node) return;
    
    switch(node->type) {
        case NODE_NUM:
            fprintf(output, "    li $t%d, %d\n", getNextTemp(), node->data.num);
            break;
        
        case NODE_FLOAT_NUM: {
            int reg = getNextTemp();
            fprintf(output, "    li.d $f%d, %.6f\n", reg * 2, node->data.fnum);  /* Use even FP registers */
            break;
        }
            
        case NODE_VAR: {
            Symbol* sym = lookupSymbol(node->data.name);
            if (!sym) {
                fprintf(stderr, "Error: Variable %s not declared\n", node->data.name);
                exit(1);
            }
            // Check if the symbol found is actually in global scope (not just same name)
            int isGlobal = 0;
            for (int i = 0; i < symtab.globalScope->count; i++) {
                if (&symtab.globalScope->symbols[i] == sym) {
                    isGlobal = 1;
                    break;
                }
            }
            if (isGlobal) {
                fprintf(output, "    lw $t%d, %d($s7)\n", getNextTemp(), sym->offset);
            } else {
                fprintf(output, "    lw $t%d, %d($sp)\n", getNextTemp(), sym->offset);
            }
            break;
        }
        
        case NODE_BINOP:
            /* Handle unary NOT operator */
            if (node->data.binop.op == '!' && node->data.binop.right == NULL) {
                genExpr(node->data.binop.left);
                int reg = tempReg - 1;
                fprintf(output, "    seq $t%d, $t%d, $zero\n", reg, reg);
                break;
            }

            genExpr(node->data.binop.left);
            int leftReg = tempReg - 1;
            genExpr(node->data.binop.right);
            int rightReg = tempReg - 1;

            switch(node->data.binop.op) {
                case '+':
                    fprintf(output, "    add $t%d, $t%d, $t%d\n", leftReg, leftReg, rightReg);
                    break;
                case '-':
                    fprintf(output, "    sub $t%d, $t%d, $t%d\n", leftReg, leftReg, rightReg);
                    break;
                case '*':
                    fprintf(output, "    mul $t%d, $t%d, $t%d\n", leftReg, leftReg, rightReg);
                    break;
                case '/':
                    fprintf(output, "    div $t%d, $t%d, $t%d\n", leftReg, leftReg, rightReg);
                    break;
                case '%':
                    // Modulo: use div then mfhi to get remainder
                    fprintf(output, "    div $t%d, $t%d\n", leftReg, rightReg);
                    fprintf(output, "    mfhi $t%d\n", leftReg);  // Get remainder from HI register
                    break;
                case '<':
                    // Less than: result is 1 if left < right, 0 otherwise
                    fprintf(output, "    slt $t%d, $t%d, $t%d\n", leftReg, leftReg, rightReg);
                    break;
                case '>':
                    // Greater than: result is 1 if left > right, 0 otherwise
                    fprintf(output, "    slt $t%d, $t%d, $t%d\n", leftReg, rightReg, leftReg);
                    break;
                case '=':
                    // Equality: result is 1 if left == right, 0 otherwise
                    fprintf(output, "    seq $t%d, $t%d, $t%d\n", leftReg, leftReg, rightReg);
                    break;
                case '&':
                    // Logical AND: result is 1 if both are non-zero, 0 otherwise
                    fprintf(output, "    sne $t%d, $t%d, $zero\n", leftReg, leftReg);
                    fprintf(output, "    sne $t%d, $t%d, $zero\n", rightReg, rightReg);
                    fprintf(output, "    and $t%d, $t%d, $t%d\n", leftReg, leftReg, rightReg);
                    break;
                case '|':
                    // Logical OR: result is 1 if either is non-zero, 0 otherwise
                    fprintf(output, "    or $t%d, $t%d, $t%d\n", leftReg, leftReg, rightReg);
                    fprintf(output, "    sne $t%d, $t%d, $zero\n", leftReg, leftReg);
                    break;
            }

            tempReg = leftReg + 1;
            break;

        case NODE_ARRAY_ACCESS: {
            // Generate code for array element access: arr[index]
            int offset = getVarOffset(node->data.array_access.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Array %s not declared\n", node->data.array_access.name);
                exit(1);
            }

            // Compute index
            genExpr(node->data.array_access.index);
            int indexReg = tempReg - 1;

            // Calculate address: base_offset + (index * 4)
            fprintf(output, "    # Array access: %s[index]\n", node->data.array_access.name);
            fprintf(output, "    sll $t%d, $t%d, 2\n", indexReg, indexReg);      // index * 4
            fprintf(output, "    add $t%d, $t%d, $sp\n", indexReg, indexReg);    // addr = (index*4) + $sp
            fprintf(output, "    lw $t%d, %d($t%d)\n", indexReg, offset, indexReg);  // load from offset(addr)
            break;
        }

        case NODE_ARRAY_2D_ACCESS: {
            // Generate code for 2D array access: matrix[row][col]
            int offset = getVarOffset(node->data.array_2d_access.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Array %s not declared\n", node->data.array_2d_access.name);
                exit(1);
            }

            // Address = base + (row * cols + col) * 4
            // Assuming 2x2 matrix for simplicity

            genExpr(node->data.array_2d_access.row);
            int rowReg = tempReg - 1;
            genExpr(node->data.array_2d_access.col);
            int colReg = tempReg - 1;

            fprintf(output, "    # 2D Array access: %s[row][col]\n", node->data.array_2d_access.name);
            fprintf(output, "    sll $t%d, $t%d, 1\n", rowReg, rowReg);          // row * 2
            fprintf(output, "    add $t%d, $t%d, $t%d\n", rowReg, rowReg, colReg); // row*2 + col
            fprintf(output, "    sll $t%d, $t%d, 2\n", rowReg, rowReg);          // * 4 for bytes
            fprintf(output, "    add $t%d, $t%d, $sp\n", rowReg, rowReg);        // + $sp
            fprintf(output, "    lw $t%d, %d($t%d)\n", rowReg, offset, rowReg);  // load from offset(addr)
            tempReg = rowReg + 1;
            break;
        }

        case NODE_CALL_EXPR: {
            // Function call as an expression - similar to NODE_CALL but result stays in register
            ASTNode* arg = node->data.call_expr.args;
            int argNum = 0;

            while (arg && argNum < 4) {
                genExpr(arg);
                fprintf(output, "    move $a%d, $t%d\n", argNum, tempReg - 1);
                argNum++;
                // For expressions, we don't have a next pointer like statements
                break;
            }

            // Call function and result will be in $v0
            fprintf(output, "    jal %s\n", node->data.call_expr.funcName);
            // Move result to next temp register
            int resultReg = getNextTemp();
            fprintf(output, "    move $t%d, $v0\n", resultReg);
            break;
        }

        case NODE_MULTI_VALUE_CHECK: {
            /* Multi-value equality check: expr is val1, val2, val3
             * Generates: (expr == val1) || (expr == val2) || (expr == val3)
             * Uses stack to preserve the expression value across multiple comparisons
             */
            fprintf(output, "    # Multi-value check: expr is values...\n");

            // Generate code for the expression being checked
            genExpr(node->data.multiValueCheck.expr);
            int exprReg = tempReg - 1;

            // Save expression value to stack to prevent register clobbering
            fprintf(output, "    addi $sp, $sp, -4\n");
            fprintf(output, "    sw $t%d, 0($sp)\n", exprReg);

            // Process value list and build OR chain
            ASTNode* valueNode = node->data.multiValueCheck.values;
            int resultReg = -1;
            int firstComparison = 1;

            while (valueNode != NULL) {
                // Reload expression from stack
                fprintf(output, "    lw $t0, 0($sp)\n");

                // Generate code for current value
                genExpr(valueNode->data.valueList.value);
                int valueReg = (tempReg == 0) ? 7 : (tempReg - 1);

                // Compare: savedExpr == value
                int cmpReg = getNextTemp();
                fprintf(output, "    seq $t%d, $t0, $t%d\n", cmpReg, valueReg);

                if (firstComparison) {
                    // First comparison becomes the initial result
                    resultReg = cmpReg;
                    firstComparison = 0;
                } else {
                    // OR this comparison with previous result
                    int orReg = getNextTemp();
                    fprintf(output, "    or $t%d, $t%d, $t%d\n", orReg, resultReg, cmpReg);
                    fprintf(output, "    sne $t%d, $t%d, $zero\n", orReg, orReg);
                    resultReg = orReg;
                }

                // Move to next value
                valueNode = valueNode->data.valueList.next;
            }

            // Restore stack pointer
            fprintf(output, "    addi $sp, $sp, 4\n");

            tempReg = resultReg + 1;
            break;
        }

        default:
            break;
    }
}

void genStmt(ASTNode* node) {
    if (!node) return;

    /* Shared counter for all if/if-else statements to prevent duplicate labels */
    static int globalIfCounter = 0;

    switch(node->type) {
        case NODE_DECL: {
            int offset = addVar(node->data.name, TYPE_INT);
            if (offset == -1) {
                fprintf(stderr, "Error: Variable %s already declared\n", node->data.name);
                exit(1);
            }
            fprintf(output, "    # Declared int %s at offset %d\n", node->data.name, offset);
            break;
        }
        
        case NODE_DECL_DOUBLE: {
            int offset = addVar(node->data.name, TYPE_DOUBLE);
            if (offset == -1) {
                fprintf(stderr, "Error: Variable %s already declared\n", node->data.name);
                exit(1);
            }
            fprintf(output, "    # Declared double %s at offset %d\n", node->data.name, offset);
            break;
        }
        
        case NODE_ASSIGN: {
            Symbol* sym = lookupSymbol(node->data.assign.var);
            if (!sym) {
                fprintf(stderr, "Error: Variable %s not declared\n", node->data.assign.var);
                exit(1);
            }
            genExpr(node->data.assign.value);
            // Check if the symbol found is actually in global scope (not just same name)
            int isGlobal = 0;
            for (int i = 0; i < symtab.globalScope->count; i++) {
                if (&symtab.globalScope->symbols[i] == sym) {
                    isGlobal = 1;
                    break;
                }
            }
            if (isGlobal) {
                fprintf(output, "    sw $t%d, %d($s7)\n", tempReg - 1, sym->offset);
            } else {
                fprintf(output, "    sw $t%d, %d($sp)\n", tempReg - 1, sym->offset);
            }
            tempReg = 0;
            break;
        }
        
        case NODE_PRINT:
            genExpr(node->data.expr);
            fprintf(output, "    # Print integer\n");
            fprintf(output, "    move $a0, $t%d\n", tempReg - 1);
            fprintf(output, "    li $v0, 1\n");
            fprintf(output, "    syscall\n");
            fprintf(output, "    # Print newline\n");
            fprintf(output, "    li $v0, 11\n");
            fprintf(output, "    li $a0, 10\n");
            fprintf(output, "    syscall\n");
            tempReg = 0;
            break;
            
        case NODE_STMT_LIST:
            genStmt(node->data.stmtlist.stmt);
            genStmt(node->data.stmtlist.next);
            break;

        case NODE_WHILE: {
            /* while (cond) body */
            static int whileCounter = 0;
            int id = whileCounter++;
            fprintf(output, "Lwhile_%d:\n", id);

            genExpr(node->data.ifstmt.condition);
            fprintf(output, "    # while condition result in $t%d\n", tempReg - 1);
            fprintf(output, "    beq $t%d, $zero, Lend_while_%d\n", tempReg - 1, id);
            tempReg = 0;

            genStmt(node->data.ifstmt.thenBlock);
            fprintf(output, "    j Lwhile_%d\n", id);
            fprintf(output, "Lend_while_%d:\n", id);
            break;
        }

        case NODE_FOR: {
            /* for (init; cond; update) body */
            static int forCounter = 0;
            int id = forCounter++;

            // Execute init statement
            genStmt(node->data.forstmt.init);

            // Loop start
            fprintf(output, "Lfor_%d:\n", id);

            // Evaluate condition
            genExpr(node->data.forstmt.condition);
            fprintf(output, "    # for condition result in $t%d\n", tempReg - 1);
            fprintf(output, "    beq $t%d, $zero, Lend_for_%d\n", tempReg - 1, id);
            tempReg = 0;

            // Execute body
            genStmt(node->data.forstmt.body);

            // Execute update
            genStmt(node->data.forstmt.update);

            // Jump back to condition check
            fprintf(output, "    j Lfor_%d\n", id);
            fprintf(output, "Lend_for_%d:\n", id);
            break;
        }

        case NODE_IF: {
            /* if (cond) then */
            int id = globalIfCounter++;

            genExpr(node->data.ifstmt.condition);
            fprintf(output, "    # if condition result in $t%d\n", tempReg - 1);
            fprintf(output, "    beq $t%d, $zero, Lend_if_%d\n", tempReg - 1, id);
            tempReg = 0;

            genStmt(node->data.ifstmt.thenBlock);
            fprintf(output, "Lend_if_%d:\n", id);
            break;
        }

        case NODE_IF_ELSE: {
            /* if (cond) then else */
            int id = globalIfCounter++;

            genExpr(node->data.ifstmt.condition);
            fprintf(output, "    # if-else condition result in $t%d\n", tempReg - 1);
            fprintf(output, "    beq $t%d, $zero, Lelse_%d\n", tempReg - 1, id);
            tempReg = 0;

            genStmt(node->data.ifstmt.thenBlock);
            fprintf(output, "    j Lend_if_%d\n", id);
            fprintf(output, "Lelse_%d:\n", id);
            genStmt(node->data.ifstmt.elseBlock);
            fprintf(output, "Lend_if_%d:\n", id);
            break;
        }

        case NODE_DECL_INIT: {
            // Declaration with initialization: int x = 5;
            int offset = addVar(node->data.decl_init.name, TYPE_INT);
            if (offset == -1) {
                fprintf(stderr, "Error: Variable %s already declared\n", node->data.decl_init.name);
                exit(1);
            }
            fprintf(output, "    # Declared and initialized int %s at offset %d\n",
                    node->data.decl_init.name, offset);
            genExpr(node->data.decl_init.value);
            // Always use $sp for local declarations within functions
            fprintf(output, "    sw $t%d, %d($sp)\n", tempReg - 1, offset);
            tempReg = 0;
            break;
        }

        case NODE_ARRAY_DECL: {
            // Allocate space for 1D array
            int size = node->data.array_decl.size;
            int offset = addVar(node->data.array_decl.name, TYPE_INT);
            if (offset == -1) {
                fprintf(stderr, "Error: Array %s already declared\n", node->data.array_decl.name);
                exit(1);
            }
            fprintf(output, "    # Declared array %s[%d] at offset %d\n", 
                    node->data.array_decl.name, size, offset);
            // Reserve additional space for array elements (size-1 more slots)
            for (int i = 1; i < size; i++) {
                addVar("", TYPE_INT); // Reserve space without name
            }
            break;
        }

        case NODE_ARRAY_ASSIGN: {
            // Array element assignment: arr[index] = value;
            int offset = getVarOffset(node->data.array_assign.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Array %s not declared\n", node->data.array_assign.name);
                exit(1);
            }

            // Evaluate value first
            genExpr(node->data.array_assign.value);
            int valueReg = tempReg - 1;

            // Evaluate index
            genExpr(node->data.array_assign.index);
            int indexReg = tempReg - 1;

            // Calculate address and store
            fprintf(output, "    # Array assignment: %s[index] = value\n", node->data.array_assign.name);
            fprintf(output, "    sll $t%d, $t%d, 2\n", indexReg, indexReg);     // index * 4
            fprintf(output, "    add $t%d, $t%d, $sp\n", indexReg, indexReg);   // addr = (index*4) + $sp
            fprintf(output, "    sw $t%d, %d($t%d)\n", valueReg, offset, indexReg);  // store at offset(addr)
            tempReg = 0;
            break;
        }

        case NODE_ARRAY_2D_DECL: {
            // Allocate space for 2D array
            int rows = node->data.array_2d_decl.rows;
            int cols = node->data.array_2d_decl.cols;
            int totalSize = rows * cols;
            
            int offset = addVar(node->data.array_2d_decl.name, TYPE_INT);
            if (offset == -1) {
                fprintf(stderr, "Error: Array %s already declared\n", node->data.array_2d_decl.name);
                exit(1);
            }
            fprintf(output, "    # Declared 2D array %s[%d][%d] at offset %d\n", 
                    node->data.array_2d_decl.name, rows, cols, offset);
            // Reserve space for all elements
            for (int i = 1; i < totalSize; i++) {
                addVar("", TYPE_INT);
            }
            break;
        }

        case NODE_ARRAY_2D_ASSIGN: {
            // 2D array assignment: matrix[row][col] = value;
            int offset = getVarOffset(node->data.array_2d_assign.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Array %s not declared\n", node->data.array_2d_assign.name);
                exit(1);
            }

            // Evaluate value
            genExpr(node->data.array_2d_assign.value);
            int valueReg = tempReg - 1;

            // Evaluate row and column indices
            genExpr(node->data.array_2d_assign.row);
            int rowReg = tempReg - 1;
            genExpr(node->data.array_2d_assign.col);
            int colReg = tempReg - 1;

            // Calculate address: base + (row * cols + col) * 4
            fprintf(output, "    # 2D Array assignment: %s[row][col] = value\n",
                    node->data.array_2d_assign.name);
            fprintf(output, "    sll $t%d, $t%d, 1\n", rowReg, rowReg);          // row * 2
            fprintf(output, "    add $t%d, $t%d, $t%d\n", rowReg, rowReg, colReg); // + col
            fprintf(output, "    sll $t%d, $t%d, 2\n", rowReg, rowReg);          // * 4 for bytes
            fprintf(output, "    add $t%d, $t%d, $sp\n", rowReg, rowReg);        // + $sp
            fprintf(output, "    sw $t%d, %d($t%d)\n", valueReg, offset, rowReg);  // store at offset(addr)
            tempReg = 0;
            break;
        }
        
        /* IF/ELSE codegen disabled - skip these node types if encountered 
        case NODE_IF:
        case NODE_IF_ELSE:
            If/Else behavior intentionally disabled; no code emitted. 
            break; */
        case NODE_FUNCTION: {
            char* funcName = node->data.function.name;
            // Rename user's main to _user_main to avoid conflict with setup code
            char* actualName = (strcmp(funcName, "main") == 0) ? "_user_main" : funcName;
            fprintf(output, "\n# Function: %s returns %s\n", funcName, node->data.function.returnType);
            fprintf(output, "%s:\n", actualName);

            /* Prologue: save $ra and $fp, allocate space for locals */
            fprintf(output, "    addi $sp, $sp, -408\n");  /* 8 for $ra/$fp + 400 for locals */
            fprintf(output, "    sw $ra, 404($sp)\n");
            fprintf(output, "    sw $fp, 400($sp)\n");
            fprintf(output, "    move $fp, $sp\n");

            /* Enter function scope */
            enterScope();

            /* Add parameters to symbol table */
            ASTNode* param = node->data.function.params;
            while (param) {
                addParameter(param->data.parameter.name, param->data.parameter.type);
                param = param->data.parameter.next;
            }

            /* Generate body */
            genStmt(node->data.function.body);

            /* Epilogue: restore and return */
            fprintf(output, "    move $sp, $fp\n");
            fprintf(output, "    lw $fp, 400($sp)\n");
            fprintf(output, "    lw $ra, 404($sp)\n");
            fprintf(output, "    addi $sp, $sp, 408\n");
            fprintf(output, "    jr $ra\n");

            /* Exit function scope */
            exitScope();
            break;
        }
        
        case NODE_RETURN: {
            if (node->data.returnstmt.value) {
                genExpr(node->data.returnstmt.value);
                fprintf(output, "    move $v0, $t%d\n", tempReg - 1);
            }
            /* Jump to epilogue (you may need labels for this) */
            break;
        }
        
        case NODE_CALL: {
            /* Load arguments into $a0-$a3 */
            ASTNode* arg = node->data.call.args;
            int argNum = 0;

            while (arg && argNum < 4) {
                genExpr(arg);
                fprintf(output, "    move $a%d, $t%d\n", argNum, tempReg - 1);
                argNum++;
                arg = arg->data.stmtlist.next;
            }

            /* Call function */
            fprintf(output, "    jal %s\n", node->data.call.funcName);
            break;
        }

        case NODE_PROGRAM: {
            // Handle program node - process globals then functions
            if (node->data.program.globals) {
                genStmt(node->data.program.globals);
            }
            if (node->data.program.functions) {
                genStmt(node->data.program.functions);
            }
            break;
        }

        case NODE_FUNCTION_LIST: {
            // Process each function in the list
            genStmt(node->data.funclist.head);
            if (node->data.funclist.tail) {
                genStmt(node->data.funclist.tail);
            }
            break;
        }

        case NODE_GLOBAL_DECL: {
            int offset = addVar(node->data.name, TYPE_INT);
            if (offset == -1) {
                fprintf(stderr, "Error: Global variable %s already declared\n", node->data.name);
                exit(1);
            }
            fprintf(output, "    # Global int %s at offset %d\n", node->data.name, offset);
            break;
        }

        case NODE_GLOBAL_DECL_DOUBLE: {
            int offset = addVar(node->data.name, TYPE_DOUBLE);
            if (offset == -1) {
                fprintf(stderr, "Error: Global variable %s already declared\n", node->data.name);
                exit(1);
            }
            fprintf(output, "    # Global double %s at offset %d\n", node->data.name, offset);
            break;
        }

        case NODE_GLOBAL_DECL_INIT: {
            int offset = addVar(node->data.decl_init.name, TYPE_INT);
            if (offset == -1) {
                fprintf(stderr, "Error: Global variable %s already declared\n", node->data.decl_init.name);
                exit(1);
            }
            fprintf(output, "    # Global int %s = init at offset %d\n", node->data.decl_init.name, offset);
            genExpr(node->data.decl_init.value);
            fprintf(output, "    sw $t%d, %d($sp)\n", tempReg - 1, offset);
            tempReg = 0;
            break;
        }

        case NODE_GLOBAL_ARRAY_DECL: {
            int size = node->data.array_decl.size;
            int offset = addVar(node->data.array_decl.name, TYPE_INT);
            if (offset == -1) {
                fprintf(stderr, "Error: Global array %s already declared\n", node->data.array_decl.name);
                exit(1);
            }
            fprintf(output, "    # Global array %s[%d] at offset %d\n",
                    node->data.array_decl.name, size, offset);
            for (int i = 1; i < size; i++) {
                addVar("", TYPE_INT);
            }
            break;
        }

        case NODE_GLOBAL_ARRAY_2D_DECL: {
            int rows = node->data.array_2d_decl.rows;
            int cols = node->data.array_2d_decl.cols;
            int totalSize = rows * cols;
            int offset = addVar(node->data.array_2d_decl.name, TYPE_INT);
            if (offset == -1) {
                fprintf(stderr, "Error: Global array %s already declared\n", node->data.array_2d_decl.name);
                exit(1);
            }
            fprintf(output, "    # Global 2D array %s[%d][%d] at offset %d\n",
                    node->data.array_2d_decl.name, rows, cols, offset);
            for (int i = 1; i < totalSize; i++) {
                addVar("", TYPE_INT);
            }
            break;
        }

        case NODE_SWITCH: {
            /* switch (expr) { case val: ... } */
            static int switchCounter = 0;
            int id = switchCounter++;

            // Evaluate the switch expression
            genExpr(node->data.switchstmt.expr);
            int exprReg = tempReg - 1;
            fprintf(output, "    # switch expression result in $t%d\n", exprReg);

            // Create end label for the entire switch
            char endLabel[20];
            sprintf(endLabel, "Lend_switch_%d", id);

            // First pass: generate comparisons for all cases
            ASTNode* caseNode = node->data.switchstmt.cases;
            int caseNum = 0;
            int hasDefault = 0;

            while (caseNode) {
                if (caseNode->type == NODE_CASE) {
                    // Generate comparison for this case
                    fprintf(output, "    # case %d:\n", caseNode->data.casestmt.value);
                    fprintf(output, "    li $t%d, %d\n", getNextTemp(), caseNode->data.casestmt.value);
                    int valueReg = tempReg - 1;
                    fprintf(output, "    beq $t%d, $t%d, Lcase_%d_%d\n", exprReg, valueReg, id, caseNum);
                    caseNum++;
                    caseNode = caseNode->data.casestmt.next;
                } else if (caseNode->type == NODE_DEFAULT) {
                    hasDefault = 1;
                    // DEFAULT doesn't have a next field, it's the end of the list
                    break;
                } else {
                    break;
                }
            }

            // If no case matched, jump to default or end
            if (hasDefault) {
                fprintf(output, "    j Ldefault_%d\n", id);
            } else {
                fprintf(output, "    j %s\n", endLabel);
            }

            // Second pass: generate code for each case body
            caseNode = node->data.switchstmt.cases;
            caseNum = 0;
            while (caseNode) {
                if (caseNode->type == NODE_CASE) {
                    fprintf(output, "Lcase_%d_%d:\n", id, caseNum);
                    if (caseNode->data.casestmt.body) {
                        genStmt(caseNode->data.casestmt.body);
                    }
                    fprintf(output, "    j %s\n", endLabel);
                    caseNum++;
                    caseNode = caseNode->data.casestmt.next;
                } else if (caseNode->type == NODE_DEFAULT) {
                    fprintf(output, "Ldefault_%d:\n", id);
                    if (caseNode->data.defaultstmt.body) {
                        genStmt(caseNode->data.defaultstmt.body);
                    }
                    fprintf(output, "    j %s\n", endLabel);
                    // DEFAULT doesn't have a next field, it's the end of the list
                    break;
                } else {
                    break;
                }
            }

            fprintf(output, "%s:\n", endLabel);
            tempReg = 0;
            break;
        }

        case NODE_BREAK:
            // Break is handled by jumps to end labels in switch/while/for
            // No code generation needed here as it's implicit in the control flow
            break;

        default:
            break;
    }
}

void generateMIPS(ASTNode* root, const char* filename) {
    output = fopen(filename, "w");
    if (!output) {
        fprintf(stderr, "Cannot open output file %s\n", filename);
        exit(1);
    }

    // Initialize symbol table
    initSymTab();

    // MIPS program header
    fprintf(output, ".data\n");
    fprintf(output, "\n.text\n");
    fprintf(output, ".globl main\n\n");

    // Check if root is a program node or old-style statement list
    if (root && root->type == NODE_PROGRAM) {
        // Check if we have real functions or just an implicit main
        int hasRealFunctions = 0;
        ASTNode* funcNode = root->data.program.functions;

        // Check if functions contain actual user-defined functions (not just implicit main)
        if (funcNode && funcNode->type == NODE_FUNCTION_LIST) {
            hasRealFunctions = 1;
        } else if (funcNode && funcNode->type == NODE_FUNCTION) {
            // Single function - check if it has calls or is just implicit main
            // For now, assume if it's named "main" and we have it as a single function with globals, it's implicit
            if (root->data.program.globals != NULL) {
                // Old style: globals + implicit main
                hasRealFunctions = 0;
            } else {
                hasRealFunctions = 1;
            }
        }

        if (!hasRealFunctions) {
            // Old style: generate everything inline
            fprintf(output, "main:\n");
            fprintf(output, "    # Allocate stack space\n");
            fprintf(output, "    addi $sp, $sp, -400\n");
            fprintf(output, "    move $s7, $sp    # Save global base pointer in $s7\n\n");

            // Process globals
            if (root->data.program.globals) {
                genStmt(root->data.program.globals);
            }

            // Process main body inline (without function frame)
            if (funcNode && funcNode->type == NODE_FUNCTION) {
                enterScope();
                genStmt(funcNode->data.function.body);
                exitScope();
            }

            // Exit
            fprintf(output, "\n    # Exit program\n");
            fprintf(output, "    addi $sp, $sp, 400\n");
            fprintf(output, "    li $v0, 10\n");
            fprintf(output, "    syscall\n");
        } else {
            // New style with real functions
            // MARS starts at 'main', so we make main do the setup
            fprintf(output, "main:\n");
            fprintf(output, "    # Allocate space for global variables\n");
            fprintf(output, "    addi $sp, $sp, -400\n");
            fprintf(output, "    move $s7, $sp    # Save global base pointer in $s7\n\n");

            // Process global declarations and initializations
            if (root->data.program.globals) {
                genStmt(root->data.program.globals);
            }

            // Jump to user's actual main function (renamed to _user_main internally)
            fprintf(output, "    jal _user_main\n");
            fprintf(output, "\n");
            fprintf(output, "    # Exit program\n");
            fprintf(output, "    addi $sp, $sp, 400\n");
            fprintf(output, "    li $v0, 10\n");
            fprintf(output, "    syscall\n\n");

            // Generate all function definitions (rename main to _user_main)
            if (root->data.program.functions) {
                genStmt(root->data.program.functions);
            }
        }
    } else {
        // Old style: just statement list (backward compatibility)
        fprintf(output, "main:\n");
        fprintf(output, "    # Allocate stack space\n");
        fprintf(output, "    addi $sp, $sp, -400\n\n");

        genStmt(root);

        fprintf(output, "\n    # Exit program\n");
        fprintf(output, "    addi $sp, $sp, 400\n");
        fprintf(output, "    li $v0, 10\n");
        fprintf(output, "    syscall\n");
    }

    fclose(output);
}