#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"
#include "symtab.h"
#include "parser.tab.h"  // Add this to get token definitions


FILE* output;
int tempReg = 0;

int getNextTemp() {
    int reg = tempReg;
    tempReg++;
    if (tempReg > 7) tempReg = 0;
    return reg;
}

int getPrevTemp() {
    // Safe way to get the previously allocated temp register
    int prev = tempReg - 1;
    if (prev < 0) prev = 7;  // Wrap around to $t7
    return prev;
}

void genExpr(ASTNode* node) {
    if (!node) return;
    
    int resultReg;
    
    switch(node->type) {
        case NODE_NUM:
            resultReg = getNextTemp();
            fprintf(output, "    li $t%d, %d\n", resultReg, node->data.num);
            break;
            
        case NODE_FLOAT_NUM:
            resultReg = getNextTemp();
            fprintf(output, "    li.s $f%d, %.2f\n", resultReg, node->data.fnum);
            break;
            
        case NODE_VAR: {
            Symbol* sym = lookupSymbol(node->data.name);
            if (!sym) {
                fprintf(stderr, "Error: Variable %s not declared\n", node->data.name);
                exit(1);
            }
            resultReg = getNextTemp();
            fprintf(output, "    lw $t%d, %d($sp)\n", resultReg, sym->offset);
            break;
        }
        
        case NODE_BINOP: {
            // Generate code for left operand
            genExpr(node->data.binop.left);
            int leftReg = getPrevTemp();
            
            // Generate code for right operand
            genExpr(node->data.binop.right);
            int rightReg = getPrevTemp();
            
            // Get register for result
            resultReg = getNextTemp();
            
            switch(node->data.binop.op) {
                case '+':
                    fprintf(output, "    add $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case '-':
                    fprintf(output, "    sub $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case '*':
                    fprintf(output, "    mul $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case '/':
                    fprintf(output, "    div $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case '%':
                    fprintf(output, "    rem $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case '<':
                    fprintf(output, "    slt $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case '>':
                    fprintf(output, "    sgt $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case EQ:
                    fprintf(output, "    seq $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case NEQ:
                    fprintf(output, "    sne $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case LE:
                    fprintf(output, "    sle $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case GE:
                    fprintf(output, "    sge $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case AND:
                    fprintf(output, "    and $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                case OR:
                    fprintf(output, "    or $t%d, $t%d, $t%d\n", resultReg, leftReg, rightReg);
                    break;
                default:
                    fprintf(stderr, "Unknown binary operator: %c\n", node->data.binop.op);
                    break;
            }
            break;
        }

        case NODE_UNARY_OP: {
            // Generate code for the operand
            genExpr(node->data.unary_op.operand);
            int operandReg = getPrevTemp();
            
            // Get register for result
            resultReg = getNextTemp();
            
            switch(node->data.unary_op.op) {
                case '-':  // Unary negation
                    fprintf(output, "    li $t%d, 0\n", resultReg);
                    fprintf(output, "    sub $t%d, $t%d, $t%d\n", resultReg, resultReg, operandReg);
                    break;
                case NOT:  // Logical NOT
                    fprintf(output, "    seq $t%d, $t%d, $zero\n", resultReg, operandReg);
                    break;
                default:
                    fprintf(stderr, "Unknown unary operator: %c\n", node->data.unary_op.op);
                    break;
            }
            break;
        }
        
        case NODE_ARRAY_ACCESS: {
            // Array access: arr[index]
            Symbol* sym = lookupSymbol(node->data.array_access.name);
            if (!sym) {
                fprintf(stderr, "Error: Array %s not declared\n", node->data.array_access.name);
                exit(1);
            }
            
            // Calculate index
            genExpr(node->data.array_access.index);
            int indexReg = getPrevTemp();
            
            resultReg = getNextTemp();
            fprintf(output, "    # Array access: arr[index]\n");
            fprintf(output, "    sll $t%d, $t%d, 2\n", indexReg, indexReg);
            fprintf(output, "    add $t%d, $t%d, $sp\n", indexReg, indexReg);
            fprintf(output, "    lw $t%d, %d($t%d)\n", resultReg, sym->offset, indexReg);
            break;
        }
        
        case NODE_CALL_EXPR: {
            // Function call as expression
            ASTNode* arg = node->data.call_expr.args;
            int argNum = 0;
            
            while (arg && argNum < 4) {
                if (arg->type == NODE_ARG_LIST) {
                    genExpr(arg->data.arg_list.arg);
                    fprintf(output, "    move $a%d, $t%d\n", argNum, getPrevTemp());
                    argNum++;
                    arg = arg->data.arg_list.next;
                } else {
                    genExpr(arg);
                    fprintf(output, "    move $a%d, $t%d\n", argNum, getPrevTemp());
                    argNum++;
                    break;
                }
            }
            
            fprintf(output, "    jal %s\n", node->data.call_expr.funcName);
            resultReg = getNextTemp();
            fprintf(output, "    move $t%d, $v0\n", resultReg);
            break;
        }
        
        default:
            fprintf(stderr, "Unknown expression node type: %d\n", node->type);
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
            genExpr(node->data.assign.value);
            Symbol* sym = lookupSymbol(node->data.assign.var);
            if (!sym) {
                fprintf(stderr, "Error: Variable %s not declared\n", node->data.assign.var);
                exit(1);
            }
            fprintf(output, "    sw $t%d, %d($sp)\n", getPrevTemp(), sym->offset);
            break;
        }
        
        case NODE_PRINT:
            genExpr(node->data.expr);
            fprintf(output, "    # Print integer\n");
            fprintf(output, "    move $a0, $t%d\n", getPrevTemp());
            fprintf(output, "    li $v0, 1\n");
            fprintf(output, "    syscall\n");
            fprintf(output, "    # Print newline\n");
            fprintf(output, "    li $v0, 11\n");
            fprintf(output, "    li $a0, 10\n");
            fprintf(output, "    syscall\n");
            tempReg = 0;
            break;
            
        case NODE_STMT_LIST:
            // Process both the current statement and continue to next
            if (node->data.stmtlist.stmt) {
                genStmt(node->data.stmtlist.stmt);
            }
            if (node->data.stmtlist.next) {
                genStmt(node->data.stmtlist.next);
            }
            break;

        case NODE_WHILE: {
            /* while (cond) body */
            static int whileCounter = 0;
            int id = whileCounter++;
            fprintf(output, "Lwhile_%d:\n", id);

            genExpr(node->data.ifstmt.condition);
            int condReg = getPrevTemp();
            fprintf(output, "    # while condition result in $t%d\n", condReg);
            fprintf(output, "    beq $t%d, $zero, Lend_while_%d\n", condReg, id);
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
            int condReg = getPrevTemp();
            fprintf(output, "    # for condition result in $t%d\n", condReg);
            fprintf(output, "    beq $t%d, $zero, Lend_for_%d\n", condReg, id);
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
            static int ifCounter = 0;
            int currentIf = ifCounter++;
            
            genExpr(node->data.ifstmt.condition);
            int condReg = getPrevTemp();
            fprintf(output, "    # if condition result in $t%d\n", condReg);
            fprintf(output, "    beq $t%d, $zero, Lend_if_%d\n", condReg, currentIf);
            genStmt(node->data.ifstmt.thenBlock);
            fprintf(output, "Lend_if_%d:\n", currentIf);
            break;
        }
        
        case NODE_IF_ELSE: {
            int currentIf = globalIfCounter++;
            
            genExpr(node->data.ifstmt.condition);
            int condReg = getPrevTemp();
            fprintf(output, "    # if-else condition result in $t%d\n", condReg);
            fprintf(output, "    beq $t%d, $zero, Lelse_%d\n", condReg, currentIf);
            genStmt(node->data.ifstmt.thenBlock);
            fprintf(output, "    j Lend_if_%d\n", currentIf);
            fprintf(output, "Lelse_%d:\n", currentIf);
            genStmt(node->data.ifstmt.elseBlock);
            fprintf(output, "Lend_if_%d:\n", currentIf);
            break;
        }
        
        case NODE_DECL_INIT: {
            Symbol* sym = lookupSymbol(node->data.decl_init.name);
            if (!sym) {
                fprintf(stderr, "Error: Variable %s not declared\n", node->data.decl_init.name);
                exit(1);
            }
            fprintf(output, "    # Declared int %s at offset %d\n", 
                    node->data.decl_init.name, sym->offset);
            genExpr(node->data.decl_init.value);
            fprintf(output, "    sw $t%d, %d($sp)\n", getPrevTemp(), sym->offset);
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
            Symbol* arrSym = lookupSymbol(node->data.array_assign.name);
            if (!arrSym) {
                fprintf(stderr, "Error: Array %s not declared\n", node->data.array_assign.name);
                exit(1);
            }
            int offset = arrSym->offset;

            // Evaluate value first
            genExpr(node->data.array_assign.value);
            int valueReg = getPrevTemp();

            // Evaluate index
            genExpr(node->data.array_assign.index);
            int indexReg = getPrevTemp();

            // Check if array is global
            int isGlobal = 0;
            if (symtab.globalScope) {
                for (int i = 0; i < symtab.globalScope->count; i++) {
                    if (&symtab.globalScope->symbols[i] == arrSym) {
                        isGlobal = 1;
                        break;
                    }
                }
            }

            // Calculate address and store
            fprintf(output, "    # Array assignment: arr[index] = value\n");
            fprintf(output, "    sll $t%d, $t%d, 2\n", indexReg, indexReg);
            if (isGlobal) {
                fprintf(output, "    add $t%d, $t%d, $s7\n", indexReg, indexReg);
            } else {
                fprintf(output, "    add $t%d, $t%d, $sp\n", indexReg, indexReg);
            }
            fprintf(output, "    sw $t%d, %d($t%d)\n", valueReg, offset, indexReg);
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
            int valueReg = getPrevTemp();

            // Evaluate row and column indices
            genExpr(node->data.array_2d_assign.row);
            int rowReg = getPrevTemp();
            genExpr(node->data.array_2d_assign.col);
            int colReg = getPrevTemp();

            // Calculate address: base + (row * cols + col) * 4
            fprintf(output, "    # 2D Array assignment: %s[row][col] = value\n",
                    node->data.array_2d_assign.name);
            fprintf(output, "    sll $t%d, $t%d, 1\n", rowReg, rowReg);
            fprintf(output, "    add $t%d, $t%d, $t%d\n", rowReg, rowReg, colReg);
            fprintf(output, "    sll $t%d, $t%d, 2\n", rowReg, rowReg);
            fprintf(output, "    add $t%d, $t%d, $sp\n", rowReg, rowReg);
            fprintf(output, "    sw $t%d, %d($t%d)\n", valueReg, offset, rowReg);
            tempReg = 0;
            break;
        }
        
        case NODE_FUNCTION: {
            fprintf(output, "\n# Function: %s returns %s\n", 
                    node->data.function.name, node->data.function.returnType);
            fprintf(output, "%s:\n", node->data.function.name);
            
            // Create new scope for function
            pushScope();
            
            // Prologue
            fprintf(output, "    addi $sp, $sp, -408\n");
            fprintf(output, "    sw $ra, 404($sp)\n");
            fprintf(output, "    sw $fp, 400($sp)\n");
            fprintf(output, "    move $fp, $sp\n");
            
            // Save parameters AND add them to symbol table
            ASTNode* param = node->data.function.params;
            int paramOffset = 8;
            int paramNum = 0;
            
            while (param && paramNum < 4) {
                // Get parameter name
                char* paramName = NULL;
                if (param->type == NODE_PARAMETER) {
                    paramName = param->data.parameter.name;
                } else if (param->type == NODE_STMT_LIST) {
                    if (param->data.stmtlist.stmt && 
                        param->data.stmtlist.stmt->type == NODE_PARAMETER) {
                        paramName = param->data.stmtlist.stmt->data.parameter.name;
                    }
                }
                
                if (paramName) {
                    // Save parameter to stack
                    fprintf(output, "    sw $a%d, %d($sp)\n", paramNum, paramOffset);
                    
                    // Add parameter to symbol table at the same offset
                    Symbol* paramSym = addSymbol(paramName, TYPE_INT);
                    if (paramSym) {
                        paramSym->offset = paramOffset;
                    }
                    
                    paramOffset += 4;
                    paramNum++;
                }
                
                // Move to next parameter
                if (param->type == NODE_STMT_LIST) {
                    param = param->data.stmtlist.next;
                } else {
                    break;
                }
            }
            
            // Generate function body
            if (node->data.function.body) {
                genStmt(node->data.function.body);
            }
            
            // Pop function scope
            popScope();
            
            // Epilogue
            fprintf(output, "    lw $fp, 400($sp)\n");
            fprintf(output, "    lw $ra, 404($sp)\n");
            fprintf(output, "    addi $sp, $sp, 408\n");
            fprintf(output, "    jr $ra\n");
            break;
        }
        
        case NODE_RETURN: {
            if (node->data.expr) {
                genExpr(node->data.expr);
                fprintf(output, "    move $v0, $t%d\n", getPrevTemp());
            }
            fprintf(output, "    lw $fp, 400($sp)\n");
            fprintf(output, "    lw $ra, 404($sp)\n");
            fprintf(output, "    addi $sp, $sp, 408\n");
            fprintf(output, "    jr $ra\n");
            break;
        }
        
        case NODE_CALL: {
            /* Load arguments into $a0-$a3 */
            ASTNode* arg = node->data.call.args;
            int argNum = 0;

            // Handle NODE_ARG_LIST chain
            while (arg && argNum < 4) {
                if (arg->type == NODE_ARG_LIST) {
                    // Evaluate the current argument
                    genExpr(arg->data.arg_list.arg);
                    fprintf(output, "    move $a%d, $t%d\n", argNum, getPrevTemp());
                    argNum++;
                    // Move to next argument in the list
                    arg = arg->data.arg_list.next;
                } else {
                    // Single argument (not in a list)
                    genExpr(arg);
                    fprintf(output, "    move $a%d, $t%d\n", argNum, getPrevTemp());
                    argNum++;
                    break;
                }
            }

            /* Call function */
            fprintf(output, "    jal %s\n", node->data.call.funcName);
            tempReg = 0;
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
            fprintf(output, "    sw $t%d, %d($sp)\n", getPrevTemp(), offset);
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
            int exprReg = getPrevTemp();
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
                    int valueReg = getPrevTemp();
                    fprintf(output, "    beq $t%d, $t%d, Lcase_%d_%d\n", exprReg, valueReg, id, caseNum);
                    caseNum++;
                    caseNode = caseNode->data.casestmt.next;
                } else if (caseNode->type == NODE_DEFAULT) {
                    hasDefault = 1;
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
            break;

        default:
            break;
    }
}

void generateMIPS(ASTNode* root, const char* filename) {
    output = fopen(filename, "w");
    if (!output) {
        perror("Cannot open output file");
        return;
    }

    initSymTab();

    fprintf(output, ".data\n");
    fprintf(output, "\n.text\n");
    fprintf(output, ".globl main\n\n");

    // Process all top-level declarations and functions
    ASTNode* current = root;
    while (current) {
        if (current->type == NODE_STMT_LIST) {
            // Process the statement in this node
            genStmt(current->data.stmtlist.stmt);
            // Move to next item in list
            current = current->data.stmtlist.next;
        } else {
            // Single top-level item (not in a list)
            genStmt(current);
            break;
        }
    }

    fclose(output);
}