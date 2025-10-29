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
    tacList.labelCount = 0;
    optimizedList.head = NULL;
    optimizedList.tail = NULL;
}

char* newTemp() {
    char* temp = malloc(10);
    sprintf(temp, "t%d", tacList.tempCount++);
    return temp;
}

char* newLabel() {
    char buf[32];
    sprintf(buf, "L%d", tacList.labelCount++);
    return strdup(buf);
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

/* ========================================
   generateTACExpr - EXPRESSIONS ONLY
   ======================================== */
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
            } else if (node->data.binop.op == '<') {
                appendTAC(createTAC(TAC_CMP_LT, left, right, temp));
            } else if (node->data.binop.op == '>') {
                appendTAC(createTAC(TAC_CMP_GT, left, right, temp));
            } else if (node->data.binop.op == '&') {
                appendTAC(createTAC(TAC_AND, left, right, temp));
            } else if (node->data.binop.op == '|') {
                appendTAC(createTAC(TAC_OR, left, right, temp));
            }

            return temp;
        }
        
        case NODE_ARRAY_ACCESS: {
            char* indexExpr = generateTACExpr(node->data.array_access.index);
            char* temp = newTemp();
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
            char* arrayRef = malloc(strlen(node->data.array_2d_access.name) + 
                                   strlen(rowExpr) + strlen(colExpr) + 20);
            sprintf(arrayRef, "%s[%s][%s]", node->data.array_2d_access.name, 
                    rowExpr, colExpr);
            appendTAC(createTAC(TAC_ASSIGN, arrayRef, NULL, temp));
            free(arrayRef);
            return temp;
        }
        
        /* NEW: Function call in EXPRESSION context */
        case NODE_CALL_EXPR: {
            // Generate PARAM instructions for arguments
            ASTNode* arg = node->data.call_expr.args;
            int paramCount = 0;
            
            while (arg) {
                char* argVal = generateTACExpr(arg);
                appendTAC(createTAC(TAC_PARAM, argVal, NULL, NULL));
                paramCount++;
                arg = NULL; // Single argument for now
            }
            
            // Generate CALL and return temp holding result
            char* temp = newTemp();
            appendTAC(createTAC(TAC_CALL, node->data.call_expr.funcName, NULL, temp));
            return temp;
        }
        
        default:
            return NULL;
    }
}

/* ========================================
   generateTAC - STATEMENTS
   ======================================== */
void generateTAC(ASTNode* node) {
    if (!node) return;
    
    switch(node->type) {
        /* ========== NEW: PROGRAM AND FUNCTIONS ========== */
        case NODE_PROGRAM:
            printf("DEBUG: Processing PROGRAM\n");
            if (node->data.program.globals) {
                generateTAC(node->data.program.globals);
            }
            if (node->data.program.functions) {
                generateTAC(node->data.program.functions);
            }
            break;
        
        case NODE_FUNCTION:
            printf("DEBUG: Processing FUNCTION: %s\n", node->data.function.name);
            appendTAC(createTAC(TAC_FUNC_BEGIN, NULL, NULL, node->data.function.name));
            appendTAC(createTAC(TAC_LABEL, NULL, NULL, node->data.function.name));
            
            if (node->data.function.body) {
                generateTAC(node->data.function.body);
            }
            
            appendTAC(createTAC(TAC_FUNC_END, NULL, NULL, node->data.function.name));
            break;
        
        case NODE_FUNCTION_LIST:
            printf("DEBUG: Processing FUNCTION_LIST\n");
            if (node->data.funclist.head) {
                generateTAC(node->data.funclist.head);
            }
            if (node->data.funclist.tail) {
                generateTAC(node->data.funclist.tail);
            }
            break;
        
        case NODE_RETURN:
            printf("DEBUG: Processing RETURN\n");
            if (node->data.returnstmt.value) {
                char* retVal = generateTACExpr(node->data.returnstmt.value);
                appendTAC(createTAC(TAC_RETURN, retVal, NULL, NULL));
            } else {
                appendTAC(createTAC(TAC_RETURN, NULL, NULL, NULL));
            }
            break;
        
        case NODE_CALL: {
            printf("DEBUG: Processing CALL statement: %s\n", node->data.call.funcName);
            ASTNode* arg = node->data.call.args;
            int paramCount = 0;
            
            while (arg) {
                char* argVal = generateTACExpr(arg);
                appendTAC(createTAC(TAC_PARAM, argVal, NULL, NULL));
                paramCount++;
                arg = NULL; // Single arg for now
            }
            
            char* temp = newTemp();
            appendTAC(createTAC(TAC_CALL, node->data.call.funcName, NULL, temp));
            break;
        }
        
        /* ========== EXISTING STATEMENT TYPES ========== */
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

        case NODE_WHILE: {
            char* labelStart = newLabel();
            char* labelEnd = newLabel();
            appendTAC(createTAC(TAC_LABEL, NULL, NULL, labelStart));
            char* condTemp = generateTACExpr(node->data.ifstmt.condition);
            appendTAC(createTAC(TAC_IF_FALSE, condTemp, NULL, labelEnd));
            generateTAC(node->data.ifstmt.thenBlock);
            appendTAC(createTAC(TAC_GOTO, NULL, NULL, labelStart));
            appendTAC(createTAC(TAC_LABEL, NULL, NULL, labelEnd));
            free(labelStart);
            free(labelEnd);
            break;
        }

        case NODE_DECL_INIT: {
            char* valueExpr = generateTACExpr(node->data.decl_init.value);
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.decl_init.name));
            appendTAC(createTAC(TAC_ASSIGN, valueExpr, NULL, node->data.decl_init.name));
            break;
        }

        case NODE_ARRAY_DECL:
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.array_decl.name));
            break;
        
        case NODE_ARRAY_ASSIGN: {
            char* indexExpr = generateTACExpr(node->data.array_assign.index);
            char* valueExpr = generateTACExpr(node->data.array_assign.value);
            char* arrayRef = malloc(strlen(node->data.array_assign.name) + strlen(indexExpr) + 10);
            sprintf(arrayRef, "%s[%s]", node->data.array_assign.name, indexExpr);
            appendTAC(createTAC(TAC_ASSIGN, valueExpr, NULL, arrayRef));
            free(arrayRef);
            break;
        }

        case NODE_ARRAY_2D_DECL:
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.array_2d_decl.name));
            break;
        
        case NODE_ARRAY_2D_ASSIGN: {
            char* rowExpr = generateTACExpr(node->data.array_2d_assign.row);
            char* colExpr = generateTACExpr(node->data.array_2d_assign.col);
            char* valueExpr = generateTACExpr(node->data.array_2d_assign.value);
            char* arrayRef = malloc(strlen(node->data.array_2d_assign.name) + 
                                   strlen(rowExpr) + strlen(colExpr) + 20);
            sprintf(arrayRef, "%s[%s][%s]", node->data.array_2d_assign.name, 
                    rowExpr, colExpr);
            appendTAC(createTAC(TAC_ASSIGN, valueExpr, NULL, arrayRef));
            free(arrayRef);
            break;
        }
        
        /* Global declarations */
        case NODE_GLOBAL_DECL:
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.name));
            break;
        
        case NODE_GLOBAL_DECL_DOUBLE:
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.name));
            break;
        
        case NODE_GLOBAL_DECL_INIT: {
            char* valueExpr = generateTACExpr(node->data.decl_init.value);
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.decl_init.name));
            appendTAC(createTAC(TAC_ASSIGN, valueExpr, NULL, node->data.decl_init.name));
            break;
        }
        
        case NODE_GLOBAL_ARRAY_DECL:
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.array_decl.name));
            break;
        
        case NODE_GLOBAL_ARRAY_2D_DECL:
            appendTAC(createTAC(TAC_DECL, NULL, NULL, node->data.array_2d_decl.name));
            break;
            
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
            case TAC_FUNC_BEGIN:
                printf("FUNC_BEGIN %s\n", curr->result);
                break;
            case TAC_FUNC_END:
                printf("FUNC_END %s\n", curr->result);
                break;
            case TAC_PARAM:
                printf("PARAM %s\n", curr->arg1);
                break;
            case TAC_CALL:
                printf("%s = CALL %s\n", curr->result, curr->arg1);
                break;
            case TAC_RETURN:
                if (curr->arg1) {
                    printf("RETURN %s\n", curr->arg1);
                } else {
                    printf("RETURN (void)\n");
                }
                break;
            case TAC_DECL:
                printf("DECL %s\n", curr->result);
                break;
            case TAC_ADD:
                printf("%s = %s + %s\n", curr->result, curr->arg1, curr->arg2);
                break;
            case TAC_SUB:
                printf("%s = %s - %s\n", curr->result, curr->arg1, curr->arg2);
                break;
            case TAC_MUL:
                printf("%s = %s * %s\n", curr->result, curr->arg1, curr->arg2);
                break;
            case TAC_DIV:
                printf("%s = %s / %s\n", curr->result, curr->arg1, curr->arg2);
                break;
            case TAC_MOD:
                printf("%s = %s %% %s\n", curr->result, curr->arg1, curr->arg2);
                break;
            case TAC_CMP_LT:
                printf("%s = %s < %s\n", curr->result, curr->arg1, curr->arg2);
                break;
            case TAC_CMP_GT:
                printf("%s = %s > %s\n", curr->result, curr->arg1, curr->arg2);
                break;
            case TAC_AND:
                printf("%s = %s && %s\n", curr->result, curr->arg1, curr->arg2);
                break;
            case TAC_OR:
                printf("%s = %s || %s\n", curr->result, curr->arg1, curr->arg2);
                break;
            case TAC_ASSIGN:
                printf("%s = %s\n", curr->result, curr->arg1);
                break;
            case TAC_PRINT:
                printf("PRINT %s\n", curr->arg1);
                break;
            case TAC_GOTO:
                printf("GOTO %s\n", curr->result);
                break;
            case TAC_IF_FALSE:
                printf("IF_FALSE %s GOTO %s\n", curr->arg1, curr->result);
                break;
            case TAC_LABEL:
                printf("LABEL %s:\n", curr->result);
                break;
            case TAC_ARRAY_ACCESS:
                printf("%s = %s\n", curr->result, curr->arg1);
                break;
            default:
                printf("<unknown tac op>\n");
                break;
        }
        curr = curr->next;
    }
}

/* Keep your existing freeTACList, freeTAC, isFloat, optimizeTAC, and printOptimizedTAC functions */

void freeTACList(TACInstr* head) {
    TACInstr* cur = head;
    while (cur) {
        TACInstr* next = cur->next;
        if (cur->arg1) free(cur->arg1);
        if (cur->arg2) free(cur->arg2);
        if (cur->result) free(cur->result);
        free(cur);
        cur = next;
    }
}

void freeTAC() {
    freeTACList(tacList.head);
    tacList.head = tacList.tail = NULL;
    freeTACList(optimizedList.head);
    optimizedList.head = optimizedList.tail = NULL;
}

int isFloat(const char* str) {
    return strchr(str, '.') != NULL;
}

int isConstant(const char* str) {
    if (!str) return 0;
    char* endptr;
    strtod(str, &endptr);
    return *endptr == '\0';
}

int evalConstantBool(const char* str) {
    if (!str) return 0;
    double val = atof(str);
    return (val != 0.0) ? 1 : 0;
}

void optimizeTAC() {
    TACInstr* curr = tacList.head;
    while (curr) {
        int optimized = 0;

        // Constant folding for comparisons
        if ((curr->op == TAC_CMP_LT || curr->op == TAC_CMP_GT) &&
            isConstant(curr->arg1) && isConstant(curr->arg2)) {
            int val1 = atoi(curr->arg1);
            int val2 = atoi(curr->arg2);
            int result = (curr->op == TAC_CMP_LT) ? (val1 < val2) : (val1 > val2);
            char resultStr[20];
            sprintf(resultStr, "%d", result);
            appendOptimizedTAC(createTAC(TAC_ASSIGN, resultStr, NULL, curr->result));
            optimized = 1;
        }
        // Short-circuit AND: FALSE && x = FALSE
        else if (curr->op == TAC_AND && isConstant(curr->arg1) && !evalConstantBool(curr->arg1)) {
            appendOptimizedTAC(createTAC(TAC_ASSIGN, "0", NULL, curr->result));
            optimized = 1;
        }
        // Short-circuit AND: TRUE && x = x
        else if (curr->op == TAC_AND && isConstant(curr->arg1) && evalConstantBool(curr->arg1)) {
            appendOptimizedTAC(createTAC(TAC_ASSIGN, curr->arg2, NULL, curr->result));
            optimized = 1;
        }
        // Short-circuit OR: TRUE || x = TRUE
        else if (curr->op == TAC_OR && isConstant(curr->arg1) && evalConstantBool(curr->arg1)) {
            appendOptimizedTAC(createTAC(TAC_ASSIGN, "1", NULL, curr->result));
            optimized = 1;
        }
        // Short-circuit OR: FALSE || x = x
        else if (curr->op == TAC_OR && isConstant(curr->arg1) && !evalConstantBool(curr->arg1)) {
            appendOptimizedTAC(createTAC(TAC_ASSIGN, curr->arg2, NULL, curr->result));
            optimized = 1;
        }
        // Constant folding for AND with both constants
        else if (curr->op == TAC_AND && isConstant(curr->arg1) && isConstant(curr->arg2)) {
            int result = evalConstantBool(curr->arg1) && evalConstantBool(curr->arg2);
            char resultStr[20];
            sprintf(resultStr, "%d", result);
            appendOptimizedTAC(createTAC(TAC_ASSIGN, resultStr, NULL, curr->result));
            optimized = 1;
        }
        // Constant folding for OR with both constants
        else if (curr->op == TAC_OR && isConstant(curr->arg1) && isConstant(curr->arg2)) {
            int result = evalConstantBool(curr->arg1) || evalConstantBool(curr->arg2);
            char resultStr[20];
            sprintf(resultStr, "%d", result);
            appendOptimizedTAC(createTAC(TAC_ASSIGN, resultStr, NULL, curr->result));
            optimized = 1;
        }
        // Constant folding for arithmetic
        else if ((curr->op == TAC_ADD || curr->op == TAC_SUB || curr->op == TAC_MUL ||
                  curr->op == TAC_DIV || curr->op == TAC_MOD) &&
                 isConstant(curr->arg1) && isConstant(curr->arg2)) {
            int val1 = atoi(curr->arg1);
            int val2 = atoi(curr->arg2);
            int result;
            switch(curr->op) {
                case TAC_ADD: result = val1 + val2; break;
                case TAC_SUB: result = val1 - val2; break;
                case TAC_MUL: result = val1 * val2; break;
                case TAC_DIV: result = (val2 != 0) ? val1 / val2 : 0; break;
                case TAC_MOD: result = (val2 != 0) ? val1 % val2 : 0; break;
                default: result = 0;
            }
            char resultStr[20];
            sprintf(resultStr, "%d", result);
            appendOptimizedTAC(createTAC(TAC_ASSIGN, resultStr, NULL, curr->result));
            optimized = 1;
        }

        if (!optimized) {
            appendOptimizedTAC(createTAC(curr->op, curr->arg1, curr->arg2, curr->result));
        }
        curr = curr->next;
    }
}

void printOptimizedTAC() {
    printf("Optimized TAC Instructions:\n");
    printf("---------------------------\n");
    TACInstr* curr = optimizedList.head;
    int lineNum = 1;
    while (curr) {
        printf("%2d: ", lineNum++);
        switch(curr->op) {
            case TAC_FUNC_BEGIN: printf("FUNC_BEGIN %s\n", curr->result); break;
            case TAC_FUNC_END: printf("FUNC_END %s\n", curr->result); break;
            case TAC_PARAM: printf("PARAM %s\n", curr->arg1); break;
            case TAC_CALL: printf("%s = CALL %s\n", curr->result, curr->arg1); break;
            case TAC_RETURN: printf("RETURN %s\n", curr->arg1 ? curr->arg1 : "(void)"); break;
            case TAC_DECL: printf("DECL %s\n", curr->result); break;
            case TAC_ADD: printf("%s = %s + %s\n", curr->result, curr->arg1, curr->arg2); break;
            case TAC_SUB: printf("%s = %s - %s\n", curr->result, curr->arg1, curr->arg2); break;
            case TAC_MUL: printf("%s = %s * %s\n", curr->result, curr->arg1, curr->arg2); break;
            case TAC_DIV: printf("%s = %s / %s\n", curr->result, curr->arg1, curr->arg2); break;
            case TAC_MOD: printf("%s = %s %% %s\n", curr->result, curr->arg1, curr->arg2); break;
            case TAC_CMP_LT: printf("%s = %s < %s\n", curr->result, curr->arg1, curr->arg2); break;
            case TAC_CMP_GT: printf("%s = %s > %s\n", curr->result, curr->arg1, curr->arg2); break;
            case TAC_AND: printf("%s = %s && %s\n", curr->result, curr->arg1, curr->arg2); break;
            case TAC_OR: printf("%s = %s || %s\n", curr->result, curr->arg1, curr->arg2); break;
            case TAC_ASSIGN: printf("%s = %s\n", curr->result, curr->arg1); break;
            case TAC_PRINT: printf("PRINT %s\n", curr->arg1); break;
            case TAC_GOTO: printf("GOTO %s\n", curr->result); break;
            case TAC_IF_FALSE: printf("IF_FALSE %s GOTO %s\n", curr->arg1, curr->result); break;
            case TAC_LABEL: printf("LABEL %s:\n", curr->result); break;
            case TAC_ARRAY_ACCESS: printf("%s = %s\n", curr->result, curr->arg1); break;
            default: printf("<unknown tac op>\n"); break;
        }
        curr = curr->next;
    }
}