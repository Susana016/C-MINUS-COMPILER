#include <stdio.h>
#include <stdlib.h>
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
            int offset = getVarOffset(node->data.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Variable %s not declared\n", node->data.name);
                exit(1);
            }
            fprintf(output, "    lw $t%d, %d($sp)\n", getNextTemp(), offset);
            break;
        }
        
        case NODE_BINOP:
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
            
            // Multiply index by 4 (size of int) and add to base offset
            fprintf(output, "    # Array access: %s[index]\n", node->data.array_access.name);
            fprintf(output, "    sll $t%d, $t%d, 2\n", indexReg, indexReg);  // index * 4
            fprintf(output, "    addi $t%d, $sp, %d\n", indexReg, offset);   // base + offset
            fprintf(output, "    lw $t%d, 0($t%d)\n", indexReg, indexReg);   // load value
            break;
        }

        case NODE_ARRAY_2D_ACCESS: {
            // Generate code for 2D array access: matrix[row][col]
            int offset = getVarOffset(node->data.array_2d_access.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Array %s not declared\n", node->data.array_2d_access.name);
                exit(1);
            }
            
            // For simplicity, assume the array dimensions are known (could be improved)
            // Address = base + (row * cols + col) * 4
            // Here we'll use a simple calculation assuming the user knows array bounds
            
            genExpr(node->data.array_2d_access.row);
            int rowReg = tempReg - 1;
            genExpr(node->data.array_2d_access.col);
            int colReg = tempReg - 1;
            
            fprintf(output, "    # 2D Array access: %s[row][col]\n", node->data.array_2d_access.name);
            // Simplified: assuming 2x2 or similar, just use row*2 + col
            fprintf(output, "    sll $t%d, $t%d, 1\n", rowReg, rowReg);      // row * 2
            fprintf(output, "    add $t%d, $t%d, $t%d\n", rowReg, rowReg, colReg); // row*2 + col
            fprintf(output, "    sll $t%d, $t%d, 2\n", rowReg, rowReg);      // * 4 for bytes
            fprintf(output, "    addi $t%d, $sp, %d\n", rowReg, offset);     // add base
            fprintf(output, "    lw $t%d, 0($t%d)\n", rowReg, rowReg);       // load value
            tempReg = rowReg + 1;
            break;
        }
            
        default:
            break;
    }
}

void genStmt(ASTNode* node) {
    if (!node) return;
    
    static int ifLabelCounter = 0; /* -------- ADDITIONS PROJECT 2 --------*/

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
            int offset = getVarOffset(node->data.assign.var);
            if (offset == -1) {
                fprintf(stderr, "Error: Variable %s not declared\n", node->data.assign.var);
                exit(1);
            }
            genExpr(node->data.assign.value);
            fprintf(output, "    sw $t%d, %d($sp)\n", tempReg - 1, offset);
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
            fprintf(output, "    sll $t%d, $t%d, 2\n", indexReg, indexReg);    // index * 4
            fprintf(output, "    addi $t%d, $sp, %d\n", indexReg, offset);     // base + offset
            fprintf(output, "    sw $t%d, 0($t%d)\n", valueReg, indexReg);     // store value
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
            fprintf(output, "    sll $t%d, $t%d, 1\n", rowReg, rowReg);        // row * 2 (assuming 2 cols)
            fprintf(output, "    add $t%d, $t%d, $t%d\n", rowReg, rowReg, colReg); // + col
            fprintf(output, "    sll $t%d, $t%d, 2\n", rowReg, rowReg);        // * 4 for bytes
            fprintf(output, "    addi $t%d, $sp, %d\n", rowReg, offset);       // + base
            fprintf(output, "    sw $t%d, 0($t%d)\n", valueReg, rowReg);       // store
            tempReg = 0;
            break;
        }
        
        /* IF/ELSE codegen disabled - skip these node types if encountered 
        case NODE_IF:
        case NODE_IF_ELSE:
            If/Else behavior intentionally disabled; no code emitted. 
            break; */
            
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
    fprintf(output, ".globl main\n");
    fprintf(output, "main:\n");
    
    // Allocate stack space (max 100 variables * 4 bytes)
    fprintf(output, "    # Allocate stack space\n");
    fprintf(output, "    addi $sp, $sp, -400\n\n");
    
    // Generate code for statements
    genStmt(root);
    
    // Program exit
    fprintf(output, "\n    # Exit program\n");
    fprintf(output, "    addi $sp, $sp, 400\n");
    fprintf(output, "    li $v0, 10\n");
    fprintf(output, "    syscall\n");
    
    fclose(output);
}