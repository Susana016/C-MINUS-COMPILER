#ifndef AST_H
#define AST_H

#include <stdio.h>

typedef enum {
    NODE_NUM,
    NODE_FLOAT_NUM,
    NODE_VAR,
    NODE_BINOP,
    NODE_ASSIGN,
    NODE_DECL,
    NODE_DECL_DOUBLE,
    NODE_PRINT,
    NODE_STMT_LIST,
    NODE_ARRAY_DECL,
    NODE_ARRAY_ASSIGN,
    NODE_ARRAY_ACCESS,
    NODE_ARRAY_2D_DECL,
    NODE_ARRAY_2D_ASSIGN,
    NODE_ARRAY_2D_ACCESS
} NodeType;

typedef struct ASTNode {
    NodeType type;
    union {
        /* Integer literal */
        int num;

        /* Floating-point literal */
        double fnum;

        /* Variable name */
        char* name;

        /* Binary operator */
        struct {
            char op;
            struct ASTNode* left;
            struct ASTNode* right;
        } binop;

        /* Assignment: var = value */
        struct {
            char* var;
            struct ASTNode* value;
        } assign;

        /* Print statement */
        struct {
            struct ASTNode* expr;
        } print;

        /* Statement list: stmt; next */
        struct {
            struct ASTNode* stmt;
            struct ASTNode* next;
        } stmtlist;

        /* Array declaration */
        struct {
            char* name;
            int size;
        } array_decl;

        /* Array assignment: arr[index] = value */
        struct {
            char* name;
            struct ASTNode* index;
            struct ASTNode* value;
        } array_assign;

        /* Array access: arr[index] */
        struct {
            char* name;
            struct ASTNode* index;
        } array_access;

        /* 2D array declaration */
        struct {
            char* name;
            int rows;
            int cols;
        } array_2d_decl;

        /* 2D array assignment: arr[row][col] = value */
        struct {
            char* name;
            struct ASTNode* row;
            struct ASTNode* col;
            struct ASTNode* value;
        } array_2d_assign;

        /* 2D array access: arr[row][col] */
        struct {
            char* name;
            struct ASTNode* row;
            struct ASTNode* col;
        } array_2d_access;

    } data;
} ASTNode;

/* Function prototypes */
ASTNode* createNumNode(int value);
ASTNode* createFloatNode(double value);
ASTNode* createVarNode(char* name);
ASTNode* createBinOpNode(char op, ASTNode* left, ASTNode* right);
ASTNode* createAssignNode(char* var, ASTNode* value);
ASTNode* createPrintNode(ASTNode* expr);
ASTNode* createStmtListNode(ASTNode* stmt, ASTNode* next);
ASTNode* createArrayDecl(char* name, int size);
ASTNode* createArrayAssign(char* name, ASTNode* index, ASTNode* value);
ASTNode* createArrayAccess(char* name, ASTNode* index);
ASTNode* createArray2DDecl(char* name, int rows, int cols);
ASTNode* createArray2DAssign(char* name, ASTNode* row, ASTNode* col, ASTNode* value);
ASTNode* createArray2DAccess(char* name, ASTNode* row, ASTNode* col);
void printAST(ASTNode* node, int level);

#endif
