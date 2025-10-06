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
            }
            
            tempReg = leftReg + 1;
            break;
            
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
        
        /* IF/ELSE codegen disabled - skip these node types if encountered 
        case NODE_IF:
        case NODE_IF_ELSE:
            If/Else behavior intentionally disabled; no code emitted. 
            break; */
        case NODE_ARRAY_ACCESS: {
            // Assuming single array named "array" declared at offset 0
            genExpr(node->data.arrayaccess.index);
            fprintf(output, "    # Array access\n");
            fprintf(output, "    sll $t%d, $t%d, 2\n", tempReg - 1, tempReg - 1); // Multiply index by 4
            fprintf(output, "    addi $t%d, $sp, 0\n", getNextTemp()); // Base address of array
            fprintf(output, "    add $t%d, $t%d, $t%d\n", tempReg - 1, tempReg - 1, tempReg - 2); // Address of element
            fprintf(output, "    lw $t%d, 0($t%d)\n", getNextTemp(), tempReg - 1); // Load element
            break;
        }
            
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