#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"

TACList tacList;
TACList optimizedList;

void initTAC() {
    tacList.head = NULL;
    tacList.tail = NULL;
    tacList.tempCount = 0;
    optimizedList.head = NULL;
    optimizedList.tail = NULL;
}

char* newTemp() {
    char* temp = malloc(10);
    sprintf(temp, "t%d", tacList.tempCount++);
    return temp;
}

TACInstr* createTAC(TACOp op, char* arg1, char* arg2, char* result) {
    TACInstr* instr = malloc(sizeof(TACInstr));
    instr->op = op;
    instr->arg1 = arg1 ? strdup(arg1) : NULL;
    instr->arg2 = arg2 ? strdup(arg2) : NULL;
    instr->result = result ? strdup(result) : NULL;
    instr->next = NULL;
    return instr;
}

void appendTAC(TACInstr* instr) {
    if (!tacList.head) {
        tacList.head = tacList.tail = instr;
    } else {
        tacList.tail->next = instr;
        tacList.tail = instr;
    }
}

void appendOptimizedTAC(TACInstr* instr) {
    if (!optimizedList.head) {
        optimizedList.head = optimizedList.tail = instr;
    } else {
        optimizedList.tail->next = instr;
        optimizedList.tail = instr;
    }
}

char* generateTACExpr(ASTNode* node) {
    if (!node) return NULL;
    
    switch(node->type) {
        case NODE_NUM: {
            char* temp = malloc(20);
            sprintf(temp, "%d", node->data.num);
            return temp;
        }
        
        case NODE_FLOAT_NUM: {
            char* temp = malloc(30);
            sprintf(temp, "%.6f", node->data.fnum);
            return temp;
        }
        
        case NODE_VAR:
            return strdup(node->data.name);
        
        case NODE_BINOP: {
            char* left = generateTACExpr(node->data.binop.left);
            char* right = generateTACExpr(node->data.binop.right);
            char* temp = newTemp();
            
            if (node->data.binop.op == '+') {
                appendTAC(createTAC(TAC_ADD, left, right, temp));
            } else if (node->data.binop.op == '-') {
                appendTAC(createTAC(TAC_SUB, left, right, temp));
            } else if (node->data.binop.op == '*') {
                appendTAC(createTAC(TAC_MUL, left, right, temp));
            } else if (node->data.binop.op == '/') {
                appendTAC(createTAC(TAC_DIV, left, right, temp));
            } else if (node->data.binop.op == '%') {
                appendTAC(createTAC(TAC_MOD, left, right, temp));
            }
            
            return temp;
        }
        case NODE_ARRAY_ACCESS: {
            char* indexExpr = generateTACExpr(node->data.array_access.index);
            char* temp = newTemp();
            
            // Create a string like "arr[t0]"
            char* arrayRef = malloc(strlen(node->data.array_access.name) + strlen(indexExpr) + 10);
            sprintf(arrayRef, "%s[%s]", node->data.array_access.name, indexExpr);
            
            appendTAC(createTAC(TAC_ASSIGN, arrayRef, NULL, temp));
            free(arrayRef);
            return temp;
        }

        case NODE_ARRAY_2D_ACCESS: {
            char* rowExpr = generateTACExpr(node->data.array_2d_access.row);
            char* colExpr = generateTACExpr(node->data.array_2d_access.col);
            char* temp = newTemp();
            
            // Create a string like "matrix[t0][t1]"
            char* arrayRef = malloc(strlen(node->data.array_2d_access.name) + 
                                   strlen(rowExpr) + strlen(colExpr) + 20);
            sprintf(arrayRef, "%s[%s][%s]", node->data.array_2d_access.name, 
                    rowExpr, colExpr);
            
            appendTAC(createTAC(TAC_ASSIGN, arrayRef, NULL, temp));
            free(arrayRef);
            return temp;
        }
        
        default:
            return NULL;
    }
}

void generateTAC(ASTNode* node) {
    if (!node) return;
    
    switch(node->type) {
        case NODE_DECL:
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.name));
            break;
        
        case NODE_DECL_DOUBLE:
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.name));
            break;
            
        case NODE_ASSIGN: {
            char* expr = generateTACExpr(node->data.assign.value);
            appendTAC(createTAC(TAC_ASSIGN, expr, NULL, node->data.assign.var));
            break;
        }
        
        case NODE_PRINT: {
            char* expr = generateTACExpr(node->data.expr);
            appendTAC(createTAC(TAC_PRINT, expr, NULL, NULL));
            break;
        }
        
        case NODE_STMT_LIST:
            generateTAC(node->data.stmtlist.stmt);
            generateTAC(node->data.stmtlist.next);
            break;

        /* Declaration with initialization */
        case NODE_DECL_INIT: {
            char* valueExpr = generateTACExpr(node->data.decl_init.value);
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.decl_init.name));
            appendTAC(createTAC(TAC_ASSIGN, valueExpr, NULL, node->data.decl_init.name));
            break;
        }

        /* Array declaration */
        case NODE_ARRAY_DECL:
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.array_decl.name));
            break;
        
        /* Array assignment */
        case NODE_ARRAY_ASSIGN: {
            // Generate: arr[index] = value
            char* indexExpr = generateTACExpr(node->data.array_assign.index);
            char* valueExpr = generateTACExpr(node->data.array_assign.value);
            
            // Create a string like "arr[t0]"
            char* arrayRef = malloc(strlen(node->data.array_assign.name) + strlen(indexExpr) + 10);
            sprintf(arrayRef, "%s[%s]", node->data.array_assign.name, indexExpr);
            
            appendTAC(createTAC(TAC_ASSIGN, valueExpr, NULL, arrayRef));
            free(arrayRef);
            break;
        }

        /* 2D Array declaration */
        case NODE_ARRAY_2D_DECL:
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.array_2d_decl.name));
            break;
        
        /* 2D Array assignment */
        case NODE_ARRAY_2D_ASSIGN: {
            // Generate: matrix[row][col] = value
            char* rowExpr = generateTACExpr(node->data.array_2d_assign.row);
            char* colExpr = generateTACExpr(node->data.array_2d_assign.col);
            char* valueExpr = generateTACExpr(node->data.array_2d_assign.value);
            
            // Create a string like "matrix[t0][t1]"
            char* arrayRef = malloc(strlen(node->data.array_2d_assign.name) + 
                                   strlen(rowExpr) + strlen(colExpr) + 20);
            sprintf(arrayRef, "%s[%s][%s]", node->data.array_2d_assign.name, 
                    rowExpr, colExpr);
            
            appendTAC(createTAC(TAC_ASSIGN, valueExpr, NULL, arrayRef));
            free(arrayRef);
            break;
        }
            
        default:
            break;
    }
}

void printTAC() {
    printf("Unoptimized TAC Instructions:\n");
    printf("-----------------------------\n");
    TACInstr* curr = tacList.head;
    int lineNum = 1;
    while (curr) {
        printf("%2d: ", lineNum++);
        switch(curr->op) {
            case TAC_DECL:
                printf("DECL %s", curr->result);
                printf("          // Declare variable '%s'\n", curr->result);
                break;
            case TAC_ADD:
                printf("%s = %s + %s", curr->result, curr->arg1, curr->arg2);
                printf("     // Add: store result in %s\n", curr->result);
                break;
            case TAC_SUB:
                printf("%s = %s - %s", curr->result, curr->arg1, curr->arg2);
                printf("     // Subtract: store result in %s\n", curr->result);
                break;
            case TAC_MUL:
                printf("%s = %s * %s", curr->result, curr->arg1, curr->arg2);
                printf("     // Multiply: store result in %s\n", curr->result);
                break;
            case TAC_DIV:
                printf("%s = %s / %s", curr->result, curr->arg1, curr->arg2);
                printf("     // Divide: store result in %s\n", curr->result);
                break;
            case TAC_MOD:
                printf("%s = %s %% %s", curr->result, curr->arg1, curr->arg2);
                printf("     // Modulo: store result in %s\n", curr->result);
                break;
            case TAC_ASSIGN:
                printf("%s = %s", curr->result, curr->arg1);
                printf("           // Assign value to %s\n", curr->result);
                break;
            case TAC_PRINT:
                printf("PRINT %s", curr->arg1);
                printf("          // Output value of %s\n", curr->arg1);
                break;
        }
        curr = curr->next;
    }
}

// Helper function to check if a string represents a floating-point number
int isFloat(const char* str) {
    return strchr(str, '.') != NULL;
}

// Simple optimization: constant folding and copy propagation
void optimizeTAC() {
    TACInstr* curr = tacList.head;
    
    // Copy propagation table
    typedef struct {
        char* var;
        char* value;
    } VarValue;
    
    VarValue values[100];
    int valueCount = 0;
    
    while (curr) {
        TACInstr* newInstr = NULL;
        
        switch(curr->op) {
            case TAC_DECL:
                newInstr = createTAC(TAC_DECL, NULL, NULL, curr->result);
                break;
                
            case TAC_ADD:
            case TAC_SUB:
            case TAC_MUL:
            case TAC_DIV:
            case TAC_MOD: {
                // Check if both operands are constants
                char* left = curr->arg1;
                char* right = curr->arg2;
                
                // Look up values in propagation table (search from most recent)
                for (int i = valueCount - 1; i >= 0; i--) {
                    if (strcmp(values[i].var, left) == 0) {
                        left = values[i].value;
                        break;
                    }
                }
                for (int i = valueCount - 1; i >= 0; i--) {
                    if (strcmp(values[i].var, right) == 0) {
                        right = values[i].value;
                        break;
                    }
                }
                
                // Constant folding - check if both are numeric
                if ((isdigit(left[0]) || left[0] == '-') && (isdigit(right[0]) || right[0] == '-')) {
                    // Check if either operand is a float
                    int isFloatOp = isFloat(left) || isFloat(right);
                    
                    if (isFloatOp) {
                        // Floating-point constant folding
                        double leftVal = atof(left);
                        double rightVal = atof(right);
                        double result;
                        
                        switch(curr->op) {
                            case TAC_ADD: result = leftVal + rightVal; break;
                            case TAC_SUB: result = leftVal - rightVal; break;
                            case TAC_MUL: result = leftVal * rightVal; break;
                            case TAC_DIV:
                                if (rightVal == 0.0) {
                                    fprintf(stderr, "Error: Division by zero\n");
                                    exit(1);
                                }
                                result = leftVal / rightVal;
                                break;
                            case TAC_MOD:
                                fprintf(stderr, "Error: Modulo not supported for floating-point\n");
                                exit(1);
                                break;
                            default: result = 0.0;
                        }
                        
                        char* resultStr = malloc(30);
                        sprintf(resultStr, "%.6f", result);
                        
                        // Store for propagation
                        values[valueCount].var = strdup(curr->result);
                        values[valueCount].value = resultStr;
                        valueCount++;
                        
                        newInstr = createTAC(TAC_ASSIGN, resultStr, NULL, curr->result);
                    } else {
                        // Integer constant folding
                        int leftVal = atoi(left);
                        int rightVal = atoi(right);
                        int result;
                        
                        switch(curr->op) {
                            case TAC_ADD: result = leftVal + rightVal; break;
                            case TAC_SUB: result = leftVal - rightVal; break;
                            case TAC_MUL: result = leftVal * rightVal; break;
                            case TAC_DIV:
                                if (rightVal == 0) {
                                    fprintf(stderr, "Error: Division by zero\n");
                                    exit(1);
                                }
                                result = leftVal / rightVal;
                                break;
                            case TAC_MOD:
                                if (rightVal == 0) {
                                    fprintf(stderr, "Error: Modulo by zero\n");
                                    exit(1);
                                }
                                result = leftVal % rightVal;
                                break;
                            default: result = 0;
                        }
                        
                        char* resultStr = malloc(20);
                        sprintf(resultStr, "%d", result);
                        
                        // Store for propagation
                        values[valueCount].var = strdup(curr->result);
                        values[valueCount].value = resultStr;
                        valueCount++;
                        
                        newInstr = createTAC(TAC_ASSIGN, resultStr, NULL, curr->result);
                    }
                } else {
                    newInstr = createTAC(curr->op, left, right, curr->result);
                }
                break;
            }
            
            case TAC_ASSIGN: {
                char* value = curr->arg1;
                
                // Look up value in propagation table (search from most recent)
                for (int i = valueCount - 1; i >= 0; i--) {
                    if (strcmp(values[i].var, value) == 0) {
                        value = values[i].value;
                        break;
                    }
                }
                
                // Store for propagation
                values[valueCount].var = strdup(curr->result);
                values[valueCount].value = strdup(value);
                valueCount++;
                
                newInstr = createTAC(TAC_ASSIGN, value, NULL, curr->result);
                break;
            }
            
            case TAC_PRINT: {
                char* value = curr->arg1;
                
                // Look up value in propagation table
                for (int i = valueCount - 1; i >= 0; i--) {  // Search from most recent
                    if (strcmp(values[i].var, value) == 0) {
                        value = values[i].value;
                        break;
                    }
                }
                
                newInstr = createTAC(TAC_PRINT, value, NULL, NULL);
                break;
            }    
        }
        
        if (newInstr) {
            appendOptimizedTAC(newInstr);
        }
        
        curr = curr->next;
    }
}

void printOptimizedTAC() {
    printf("Optimized TAC Instructions:\n");
    printf("-----------------------------\n");
    TACInstr* curr = optimizedList.head;
    int lineNum = 1;
    while (curr) {
        printf("%2d: ", lineNum++);
        switch(curr->op) {
            case TAC_DECL:
                printf("DECL %s\n", curr->result);
                break;
            case TAC_ADD:
                printf("%s = %s + %s", curr->result, curr->arg1, curr->arg2);
                printf("     // Runtime addition needed\n");
                break;
            case TAC_SUB:
                printf("%s = %s - %s", curr->result, curr->arg1, curr->arg2);
                printf("     // Runtime subtraction needed\n");
                break;
            case TAC_MUL:
                printf("%s = %s * %s", curr->result, curr->arg1, curr->arg2);
                printf("     // Runtime multiplication needed\n");
                break;
            case TAC_DIV:
                printf("%s = %s / %s", curr->result, curr->arg1, curr->arg2);
                printf("     // Runtime division needed\n");
                break;
            case TAC_MOD:
                printf("%s = %s %% %s", curr->result, curr->arg1, curr->arg2);
                printf("     // Runtime modulo needed\n");
                break;
            case TAC_ASSIGN:
                printf("%s = %s", curr->result, curr->arg1);
                // Check if it's a constant
                if (curr->arg1[0] >= '0' && curr->arg1[0] <= '9') {
                    printf("           // Constant value: %s\n", curr->arg1);
                } else {
                    printf("           // Copy value\n");
                }
                break;
            case TAC_PRINT:
                printf("PRINT %s", curr->arg1);
                if (curr->arg1[0] >= '0' && curr->arg1[0] <= '9') {
                    printf("          // Print constant: %s\n", curr->arg1);
                } else {
                    printf("          // Print variable: %s\n", curr->arg1);
                }
                break;
        }
        curr = curr->next;
    }
}