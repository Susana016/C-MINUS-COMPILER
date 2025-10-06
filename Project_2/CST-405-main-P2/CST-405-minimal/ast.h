#ifndef AST_H
#define AST_H

/* ABSTRACT SYNTAX TREE (AST)
 * The AST is an intermediate representation of the program structure.
 * It represents the hierarchical syntax of the source code.
 * Each node represents a construct in the language.
 */

/* NODE TYPES - Different kinds of AST nodes in our language */
typedef enum {
    NODE_NUM,             /* Numeric literal (e.g., 42) */
    NODE_FLOAT_NUM,       /* Floating-point literal (e.g., 3.14) */
    NODE_VAR,             /* Variable reference (e.g., x) */
    NODE_BINOP,           /* Binary operation (e.g., x + y) */
    NODE_DECL,            /* Variable declaration (e.g., int x) */
    NODE_DECL_DOUBLE,     /* Double variable declaration (e.g., double x) */
    NODE_ASSIGN,          /* Assignment statement (e.g., x = 10) */
    NODE_PRINT,           /* Print statement (e.g., print(x)) */
    NODE_STMT_LIST,       /* List of statements (program structure) */
    NODE_ARRAY_ACCESS,    /* Array element access (e.g., arr[0]) */
    NODE_ARRAY_DECL,      /* Array declaration (e.g., int arr[10]) */
    NODE_ARRAY_ASSIGN,    /* Array assignment (e.g., arr[0] = 5) */
    NODE_ARRAY_2D_DECL,   /* 2D array declaration (e.g., int arr[3][4]) */
    NODE_ARRAY_2D_ASSIGN, /* 2D array assignment (e.g., arr[1][2] = 7) */
    NODE_ARRAY_2D_ACCESS, /* 2D array access (e.g., arr[1][2]) */
    NODE_DECL_INIT        /* Variable declaration with initialization */
} NodeType;

/* AST NODE STRUCTURE
 * Uses a union to efficiently store different node data.
 * Only the relevant fields for each node type are used.
 */
typedef struct ASTNode {
    NodeType type;  /* Identifies what kind of node this is */
    
    union {
        /* Literal number value (NODE_NUM) */
        int num;

        /* Literal floating-point value (NODE_FLOAT_NUM) */
        double fnum;

        /* Variable or declaration name (NODE_VAR, NODE_DECL, NODE_DECL_DOUBLE) */
        char* name;

        /* Binary operation structure (NODE_BINOP) */
        struct {
            char op;
            struct ASTNode* left;
            struct ASTNode* right;
        } binop;

        /* Assignment structure (NODE_ASSIGN) */
        struct {
            char* var;
            struct ASTNode* value;
        } assign;

        /* Print expression (NODE_PRINT) */
        struct ASTNode* expr;

        /* Statement list structure (NODE_STMT_LIST) */
        struct {
            struct ASTNode* stmt;
            struct ASTNode* next;
        } stmtlist;

        /* If / If-Else (reserved for Project 2) */
        struct {
            struct ASTNode* condition;
            struct ASTNode* thenBlock;
        } ifstmt;

        struct {
            struct ASTNode* condition;
            struct ASTNode* thenBlock;
            struct ASTNode* elseBlock;
        } ifelsestmt;

        /* Array access structure (NODE_ARRAY_ACCESS) */
        struct {
            char* name;
            struct ASTNode* index;
        } arrayaccess;

        /* Array declaration (NODE_ARRAY_DECL) */
        struct {
            char* name;
            int size;
        } array_decl;

        /* Array assignment (NODE_ARRAY_ASSIGN) */
        struct {
            char* name;
            struct ASTNode* index;
            struct ASTNode* value;
        } array_assign;

        /* 2D Array declaration (NODE_ARRAY_2D_DECL) */
        struct {
            char* name;
            int rows;
            int cols;
        } array_2d_decl;

        /* 2D Array assignment (NODE_ARRAY_2D_ASSIGN) */
        struct {
            char* name;
            struct ASTNode* row;
            struct ASTNode* col;
            struct ASTNode* value;
        } array_2d_assign;

        /* 2D Array access (NODE_ARRAY_2D_ACCESS) */
        struct {
            char* name;
            struct ASTNode* row;
            struct ASTNode* col;
        } array_2d_access;

        /* Declaration with initialization (NODE_DECL_INIT) */
        struct {
            char* name;
            struct ASTNode* value;
        } decl_init;

    } data;
} ASTNode;


/* ================================================================
 * AST CONSTRUCTION FUNCTIONS
 * ================================================================ */

/* Basic node constructors */
ASTNode* createNum(int value);
ASTNode* createFloatNum(double value);
ASTNode* createVar(char* name);
ASTNode* createBinOp(char op, ASTNode* left, ASTNode* right);
ASTNode* createDecl(char* name);
ASTNode* createDeclDouble(char* name);
ASTNode* createAssign(char* var, ASTNode* value);
ASTNode* createPrint(ASTNode* expr);
ASTNode* createStmtList(ASTNode* stmt1, ASTNode* stmt2);

/* Array-related constructors */
ASTNode* createArrayDecl(char* name, int size);
ASTNode* createArrayAccess(char* name, ASTNode* index);
ASTNode* createArrayAssign(char* name, ASTNode* index, ASTNode* value);

/* 2D array constructors */
ASTNode* createArray2DDecl(char* name, int rows, int cols);
ASTNode* createArray2DAssign(char* name, ASTNode* row, ASTNode* col, ASTNode* value);
ASTNode* createArray2DAccess(char* name, ASTNode* row, ASTNode* col);

/* Declaration with initialization */
ASTNode* createDeclInit(char* name, ASTNode* value);

/* AST Display Function */
void printAST(ASTNode* node, int level);

#endif
