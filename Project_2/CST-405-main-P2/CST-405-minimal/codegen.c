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
            
        case NODE_VAR: {
            int offset = getVarOffset(node->data.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Variable %s not declared\n", node->data.name);
                exit(1);
            }
            fprintf(output, "    lw $t%d, %d($sp)\n", getNextTemp(), offset);
            break;
        }
        
        case NODE_BINOP: {
            genExpr(node->data.binop.left);
            int leftReg = tempReg - 1;
            
            genExpr(node->data.binop.right);
            int rightReg = tempReg - 1;
            
            // Check operator type
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
                    fprintf(output, "    div $t%d, $t%d\n", leftReg, rightReg);
                    fprintf(output, "    mflo $t%d\n", leftReg);
                    break;
                default:
                    fprintf(stderr, "Error: Unknown operator %c\n", node->data.binop.op);
                    exit(1);
            }
            
            tempReg = leftReg + 1;
            break;
        }

        case NODE_ARRAY_ACCESS: {
            int offset = getVarOffset(node->data.array_access.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Array %s not declared\n", node->data.array_access.name);
                exit(1);
            }
            genExpr(node->data.array_access.index);
            int indexReg = tempReg - 1;
            
            // Multiply index by 4 (word size)
            fprintf(output, "    # Array access: %s[index]\n", node->data.array_access.name);
            fprintf(output, "    sll $t%d, $t%d, 2    # index * 4\n", indexReg, indexReg);
            
            // Add base address offset
            fprintf(output, "    addi $t%d, $sp, %d   # base address\n", getNextTemp(), offset);
            int baseReg = tempReg - 1;
            
            // Add index offset to base
            fprintf(output, "    add $t%d, $t%d, $t%d # base + index*4\n", baseReg, baseReg, indexReg);
            
            // Load value from memory
            fprintf(output, "    lw $t%d, 0($t%d)     # load array[index]\n", indexReg, baseReg);
            tempReg = indexReg + 1;
            break;
        }
            
        default:
            break;
    }
}

void genStmt(ASTNode* node) {
    if (!node) return;
    
    switch(node->type) {
        case NODE_DECL: {
            int offset = addVar(node->data.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Variable %s already declared\n", node->data.name);
                exit(1);
            }
            fprintf(output, "    # Declared %s at offset %d\n", node->data.name, offset);
            break;
        }

        case NODE_DECL_INIT: {
            // Combined declaration and initialization
            int offset = addVar(node->data.decl_init.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Variable %s already declared\n", node->data.decl_init.name);
                exit(1);
            }
            fprintf(output, "    # Declared %s at offset %d\n", node->data.decl_init.name, offset);
            
            // Generate code for the initialization expression
            genExpr(node->data.decl_init.value);
            fprintf(output, "    sw $t%d, %d($sp)\n", tempReg - 1, offset);
            tempReg = 0;
            break;
        }

        case NODE_ARRAY_DECL: {
            int offset = addArray(node->data.array_decl.name, node->data.array_decl.size);
            if (offset == -1) {
                fprintf(stderr, "Error: Array %s already declared\n", node->data.array_decl.name);
                exit(1);
            }
            fprintf(output, "    # Declared array %s of size %d at offset %d\n", 
                    node->data.array_decl.name, node->data.array_decl.size, offset);
            break;
        }

        case NODE_ARRAY_ASSIGN: {
            // Get array base address
            int offset = getVarOffset(node->data.array_assign.name);
            if (offset == -1) {
                fprintf(stderr, "Error: Array %s not declared\n", node->data.array_assign.name);
                exit(1);
            }
            
            // Calculate index
            genExpr(node->data.array_assign.index);
            int indexReg = tempReg - 1;
            
            // Calculate value to store
            genExpr(node->data.array_assign.value);
            int valueReg = tempReg - 1;
            
            // Multiply index by 4 (word size)
            fprintf(output, "    # Array assignment: %s[index] = value\n", node->data.array_assign.name);
            fprintf(output, "    sll $t%d, $t%d, 2    # index * 4\n", indexReg, indexReg);
            
            // Add base address offset
            fprintf(output, "    addi $t%d, $sp, %d   # base address\n", getNextTemp(), offset);
            int baseReg = tempReg - 1;
            
            // Add index offset to base
            fprintf(output, "    add $t%d, $t%d, $t%d # base + index*4\n", baseReg, baseReg, indexReg);
            
            // Store value to memory
            fprintf(output, "    sw $t%d, 0($t%d)     # store to array[index]\n", valueReg, baseReg);
            tempReg = 0;
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