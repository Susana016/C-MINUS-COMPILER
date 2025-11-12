/* AST IMPLEMENTATION
 * Functions to create and manipulate Abstract Syntax Tree nodes
 * The AST is built during parsing and used for all subsequent phases
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

/* Create a number literal node */
ASTNode* createNum(int value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_NUM;
    node->data.num = value;  /* Store the integer value */
    return node;
}

/* Create a floating-point literal node */
ASTNode* createFloatNum(double value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FLOAT_NUM;
    node->data.fnum = value;  /* Store the double value */
    return node;
}

/* Create a variable reference node */
ASTNode* createVar(char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_VAR;
    node->data.name = strdup(name);  /* Copy the variable name */
    return node;
}

/* Create a binary operation node (for addition) */
ASTNode* createBinOp(char op, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_BINOP;
    node->data.binop.op = op;        /* Store operator (+) */
    node->data.binop.left = left;    /* Left subtree */
    node->data.binop.right = right;  /* Right subtree */
    return node;
}

/* Create a variable declaration node */
ASTNode* createDecl(char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_DECL;
    node->data.name = strdup(name);  /* Store variable name */
    return node;
}

/* Create a double variable declaration node */
ASTNode* createDeclDouble(char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_DECL_DOUBLE;
    node->data.name = strdup(name);  /* Store variable name */
    return node;
}

/* Create an assignment statement node */
ASTNode* createAssign(char* var, ASTNode* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ASSIGN;
    node->data.assign.var = strdup(var);  /* Variable name */
    node->data.assign.value = value;      /* Expression tree */
    return node;
}

/* Create a declaration with initialization node */
ASTNode* createDeclInit(char* name, ASTNode* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_DECL_INIT;
    node->data.decl_init.name = strdup(name);
    node->data.decl_init.value = value;
    return node;
}

/* Create an array declaration node */
ASTNode* createArrayDecl(char* name, int size) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ARRAY_DECL;
    node->data.array_decl.name = strdup(name);
    node->data.array_decl.size = size;
    return node;
}

/* Create an array access node */
ASTNode* createArrayAccess(char* name, ASTNode* index) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ARRAY_ACCESS;
    node->data.array_access.name = strdup(name);
    node->data.array_access.index = index;
    return node;
}

/* Create an array assignment node */
ASTNode* createArrayAssign(char* name, ASTNode* index, ASTNode* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ARRAY_ASSIGN;
    node->data.array_assign.name = strdup(name);
    node->data.array_assign.index = index;
    node->data.array_assign.value = value;
    return node;
}

/* Create a print statement node */
ASTNode* createPrint(ASTNode* expr) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_PRINT;
    node->data.expr = expr;  /* Expression to print */
    return node;
}

/* Create a statement list node (links statements together) */
ASTNode* createStmtList(ASTNode* stmt1, ASTNode* stmt2) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_STMT_LIST;
    node->data.stmtlist.stmt = stmt1;  /* First statement */
    node->data.stmtlist.next = stmt2;  /* Rest of list */
    return node;
}

/* Create a while loop node */
ASTNode* createWhile(ASTNode* condition, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_WHILE;
    node->data.ifstmt.condition = condition; /* reuse ifstmt struct for cond/body */
    node->data.ifstmt.thenBlock = body;
    return node;
}

/* Create a for loop node */
ASTNode* createFor(ASTNode* init, ASTNode* condition, ASTNode* update, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FOR;
    node->data.forstmt.init = init;
    node->data.forstmt.condition = condition;
    node->data.forstmt.update = update;
    node->data.forstmt.body = body;
    return node;
}

/* Create a 2D array declaration node */
ASTNode* createArray2DDecl(char* name, int rows, int cols) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ARRAY_2D_DECL;
    node->data.array_2d_decl.name = strdup(name);
    node->data.array_2d_decl.rows = rows;
    node->data.array_2d_decl.cols = cols;
    return node;
}

/* Create a 2D array assignment node */
ASTNode* createArray2DAssign(char* name, ASTNode* row, ASTNode* col, ASTNode* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ARRAY_2D_ASSIGN;
    node->data.array_2d_assign.name = strdup(name);
    node->data.array_2d_assign.row = row;
    node->data.array_2d_assign.col = col;
    node->data.array_2d_assign.value = value;
    return node;
}

/* Create a 2D array access node */
ASTNode* createArray2DAccess(char* name, ASTNode* row, ASTNode* col) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ARRAY_2D_ACCESS;
    node->data.array_2d_access.name = strdup(name);
    node->data.array_2d_access.row = row;
    node->data.array_2d_access.col = col;
    return node;
}

ASTNode* createFunction(char* name, char* returnType, ASTNode* params, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FUNCTION;
    node->data.function.name = strdup(name);
    node->data.function.returnType = strdup(returnType);
    node->data.function.params = params;
    node->data.function.body = body;
    return node;
}

ASTNode* createFunctionList(ASTNode* head, ASTNode* tail) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FUNCTION_LIST;
    node->data.funclist.head = head;
    node->data.funclist.tail = tail;
    return node;
}

ASTNode* createParameter(char* name, char* type, ASTNode* next) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_PARAMETER;
    node->data.parameter.name = strdup(name);
    node->data.parameter.type = strdup(type);
    node->data.parameter.next = next;
    return node;
}
ASTNode* createReturn(ASTNode* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_RETURN;
    node->data.returnstmt.value = value;  /* Expression to return */
    return node;
}

ASTNode* createCall(char* funcName, ASTNode* args) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_CALL;
    node->data.call.funcName = strdup(funcName);  // Change: name → funcName
    node->data.call.args = args;
    return node;
}

ASTNode* createCallExpr(char* funcName, ASTNode* args) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_CALL_EXPR;
    node->data.call_expr.funcName = strdup(funcName);  // Change: name → funcName
    node->data.call_expr.args = args;
    return node;
}

ASTNode* createProgram(ASTNode* globals, ASTNode* functions) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_PROGRAM;
    node->data.program.globals = globals;
    node->data.program.functions = functions;
    return node;
}

ASTNode* createGlobalDecl(char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_GLOBAL_DECL;
    node->data.name = strdup(name);
    return node;
}

ASTNode* createGlobalDeclDouble(char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_GLOBAL_DECL_DOUBLE;
    node->data.name = strdup(name);
    return node;
}

ASTNode* createGlobalDeclInit(char* name, ASTNode* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_GLOBAL_DECL_INIT;
    node->data.decl_init.name = strdup(name);
    node->data.decl_init.value = value;
    return node;
}

ASTNode* createGlobalArrayDecl(char* name, int size) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_GLOBAL_ARRAY_DECL;
    node->data.array_decl.name = strdup(name);
    node->data.array_decl.size = size;
    return node;
}

ASTNode* createGlobalArray2DDecl(char* name, int rows, int cols) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_GLOBAL_ARRAY_2D_DECL;
    node->data.array_2d_decl.name = strdup(name);
    node->data.array_2d_decl.rows = rows;
    node->data.array_2d_decl.cols = cols;
    return node;
}

/* Create an if statement node (no else) */
ASTNode* createIf(ASTNode* condition, ASTNode* thenBlock) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_IF;
    node->data.ifstmt.condition = condition;
    node->data.ifstmt.thenBlock = thenBlock;
    node->data.ifstmt.elseBlock = NULL;
    return node;
}

/* Create an if-else statement node */
ASTNode* createIfElse(ASTNode* condition, ASTNode* thenBlock, ASTNode* elseBlock) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_IF_ELSE;
    node->data.ifstmt.condition = condition;
    node->data.ifstmt.thenBlock = thenBlock;
    node->data.ifstmt.elseBlock = elseBlock;
    return node;
}

/* Create a label node */
ASTNode* createLabel(char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_LABEL;
    node->data.label.name = strdup(name);
    return node;
}

/* Create a goto statement node */
ASTNode* createGoto(char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_GOTO;
    node->data.gotostmt.name = strdup(name);
    return node;
}

/* Create a multi-value equality check node */
ASTNode* createMultiValueCheck(ASTNode* expr, ASTNode* values) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_MULTI_VALUE_CHECK;
    node->data.multiValueCheck.expr = expr;
    node->data.multiValueCheck.values = values;
    return node;
}

/* Create a value list node */
ASTNode* createValueList(ASTNode* value, ASTNode* next) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_VALUE_LIST;
    node->data.valueList.value = value;
    node->data.valueList.next = next;
    return node;
}


/* Display the AST structure (for debugging and education) */
void printAST(ASTNode* node, int level) {
    if (!node) return;
    
    /* Indent based on tree depth */
    for (int i = 0; i < level; i++) printf("  ");
    
    /* Print node based on its type */
    switch(node->type) {
        case NODE_NUM:
            printf("NUM: %d\n", node->data.num);
            break;
        case NODE_FLOAT_NUM:
            printf("FLOAT_NUM: %.2f\n", node->data.fnum);
            break;
        case NODE_VAR:
            printf("VAR: %s\n", node->data.name);
            break;
        case NODE_BINOP:
            printf("BINOP: %c\n", node->data.binop.op);
            printAST(node->data.binop.left, level + 1);
            printAST(node->data.binop.right, level + 1);
            break;
        case NODE_DECL:
            printf("DECL (int): %s\n", node->data.name);
            break;
        case NODE_DECL_DOUBLE:
            printf("DECL (double): %s\n", node->data.name);
            break;
        case NODE_DECL_INIT:
            printf("DECL_INIT: %s\n", node->data.decl_init.name);
            printAST(node->data.decl_init.value, level + 1);
            break;
        case NODE_ASSIGN:
            printf("ASSIGN: %s\n", node->data.assign.var);
            printAST(node->data.assign.value, level + 1);
            break;
        case NODE_PRINT:
            printf("PRINT\n");
            printAST(node->data.expr, level + 1);
            break;
        case NODE_ARRAY_DECL:
            printf("ARRAY_DECL: %s[%d]\n", node->data.array_decl.name, node->data.array_decl.size);
            break;
        case NODE_ARRAY_ACCESS:
            printf("ARRAY_ACCESS: %s\n", node->data.array_access.name);
            printAST(node->data.array_access.index, level + 1);
            break;
        case NODE_ARRAY_ASSIGN:
            printf("ARRAY_ASSIGN: %s\n", node->data.array_assign.name);
            printAST(node->data.array_assign.index, level + 1);
            printAST(node->data.array_assign.value, level + 1);
            break;
        case NODE_STMT_LIST:
            /* Print statements in sequence at same level */
            printAST(node->data.stmtlist.stmt, level);
            printAST(node->data.stmtlist.next, level);
            break;
        case NODE_ARRAY_2D_DECL:
            printf("ARRAY_2D_DECL: %s[%d][%d]\n", 
                   node->data.array_2d_decl.name, 
                   node->data.array_2d_decl.rows, 
                   node->data.array_2d_decl.cols);
            break;
        case NODE_ARRAY_2D_ASSIGN:
            printf("ARRAY_2D_ASSIGN: %s\n", node->data.array_2d_assign.name);
            printAST(node->data.array_2d_assign.row, level + 1);
            printAST(node->data.array_2d_assign.col, level + 1);
            printAST(node->data.array_2d_assign.value, level + 1);
            break;
        case NODE_ARRAY_2D_ACCESS:
            printf("ARRAY_2D_ACCESS: %s\n", node->data.array_2d_access.name);
            printAST(node->data.array_2d_access.row, level + 1);
            printAST(node->data.array_2d_access.col, level + 1);
            break;
        case NODE_WHILE:
            printf("WHILE\n");
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Condition:\n");
            printAST(node->data.ifstmt.condition, level + 2);
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Body:\n");
            printAST(node->data.ifstmt.thenBlock, level + 2);
            break;

        case NODE_FOR:
            printf("FOR\n");
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Init:\n");
            printAST(node->data.forstmt.init, level + 2);
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Condition:\n");
            printAST(node->data.forstmt.condition, level + 2);
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Update:\n");
            printAST(node->data.forstmt.update, level + 2);
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Body:\n");
            printAST(node->data.forstmt.body, level + 2);
            break;

        case NODE_FUNCTION:
            for (int i = 0; i < level; i++) printf("  ");
            printf("FUNCTION: %s %s(...)\n", node->data.function.returnType, node->data.function.name);
            if (node->data.function.params) {
                for (int i = 0; i < level + 1; i++) printf("  ");
                printf("Parameters:\n");
                printAST(node->data.function.params, level + 2);
            }
            if (node->data.function.body) {
                for (int i = 0; i < level + 1; i++) printf("  ");
                printf("Body:\n");
                printAST(node->data.function.body, level + 2);
            }
            break;
        
        case NODE_FUNCTION_LIST:
            for (int i = 0; i < level; i++) printf("  ");
            printf("FUNCTION_LIST:\n");
            if (node->data.funclist.head) {
                printAST(node->data.funclist.head, level + 1);
            }
            if (node->data.funclist.tail) {
                printAST(node->data.funclist.tail, level);
            }
            break;
        
        case NODE_PARAMETER:
            for (int i = 0; i < level; i++) printf("  ");
            printf("PARAMETER: %s %s\n", node->data.parameter.type, node->data.parameter.name);
            if (node->data.parameter.next) {
                printAST(node->data.parameter.next, level);
            }
            break;
        
        case NODE_RETURN:
            for (int i = 0; i < level; i++) printf("  ");
            printf("RETURN:\n");
            if (node->data.returnstmt.value) {
                printAST(node->data.returnstmt.value, level + 1);
            } else {
                for (int i = 0; i < level + 1; i++) printf("  ");
                printf("(void)\n");
            }
            break;
        
        case NODE_CALL:
            for (int i = 0; i < level; i++) printf("  ");
            printf("CALL: %s(...)\n", node->data.call.funcName);
            if (node->data.call.args) {
                for (int i = 0; i < level + 1; i++) printf("  ");
                printf("Arguments:\n");
                printAST(node->data.call.args, level + 2);
            }
            break;
        
        case NODE_CALL_EXPR:
            for (int i = 0; i < level; i++) printf("  ");
            printf("CALL_EXPR: %s(...)\n", node->data.call_expr.funcName);
            if (node->data.call_expr.args) {
                for (int i = 0; i < level + 1; i++) printf("  ");
                printf("Arguments:\n");
                printAST(node->data.call_expr.args, level + 2);
            }
            break;    

            case NODE_PROGRAM:
            printf("PROGRAM:\n");
            if (node->data.program.globals) {
                for (int i = 0; i < level + 1; i++) printf("  ");
                printf("Global Declarations:\n");
                printAST(node->data.program.globals, level + 2);
            }
            if (node->data.program.functions) {
                for (int i = 0; i < level + 1; i++) printf("  ");
                printf("Functions:\n");
                printAST(node->data.program.functions, level + 2);
            }
            break;
            
        case NODE_GLOBAL_DECL:
            printf("GLOBAL_DECL (int): %s\n", node->data.name);
            break;
            
        case NODE_GLOBAL_DECL_DOUBLE:
            printf("GLOBAL_DECL (double): %s\n", node->data.name);
            break;
            
        case NODE_GLOBAL_DECL_INIT:
            printf("GLOBAL_DECL_INIT: %s\n", node->data.decl_init.name);
            printAST(node->data.decl_init.value, level + 1);
            break;
            
        case NODE_GLOBAL_ARRAY_DECL:
            printf("GLOBAL_ARRAY_DECL: %s[%d]\n", 
                   node->data.array_decl.name, node->data.array_decl.size);
            break;
            
        case NODE_GLOBAL_ARRAY_2D_DECL:
            printf("GLOBAL_ARRAY_2D_DECL: %s[%d][%d]\n",
                   node->data.array_2d_decl.name,
                   node->data.array_2d_decl.rows,
                   node->data.array_2d_decl.cols);
            break;

        case NODE_IF:
            printf("IF\n");
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Condition:\n");
            printAST(node->data.ifstmt.condition, level + 2);
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Then:\n");
            printAST(node->data.ifstmt.thenBlock, level + 2);
            break;

        case NODE_IF_ELSE:
            printf("IF-ELSE\n");
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Condition:\n");
            printAST(node->data.ifstmt.condition, level + 2);
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Then:\n");
            printAST(node->data.ifstmt.thenBlock, level + 2);
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Else:\n");
            printAST(node->data.ifstmt.elseBlock, level + 2);
            break;

        case NODE_MULTI_VALUE_CHECK:
            printf("MULTI_VALUE_CHECK (is)\n");
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Expression:\n");
            printAST(node->data.multiValueCheck.expr, level + 2);
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("Values:\n");
            printAST(node->data.multiValueCheck.values, level + 2);
            break;

        case NODE_VALUE_LIST:
            printf("VALUE: ");
            printAST(node->data.valueList.value, 0);
            if (node->data.valueList.next) {
                for (int i = 0; i < level; i++) printf("  ");
                printAST(node->data.valueList.next, level);
            }
            break;

        default:
            printf("UNKNOWN NODE TYPE\n");
    }
}

