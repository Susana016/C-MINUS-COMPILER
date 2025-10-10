#ifndef AST_H
#define AST_H

/* ABSTRACT SYNTAX TREE (AST)
 * The AST is an intermediate representation of the program structure
 * It represents the hierarchical syntax of the source code
 * Each node represents a construct in the language
 */

/* NODE TYPES - Different kinds of AST nodes in our language */
typedef enum {
    NODE_NUM,            /* Numeric literal (e.g., 42) */
    NODE_FLOAT_NUM,      /* Floating-point literal (e.g., 3.14) */
    NODE_VAR,            /* Variable reference (e.g., x) */
    NODE_BINOP,          /* Binary operation (e.g., x + y) */
    NODE_DECL,           /* Variable declaration (e.g., int x) */
    NODE_DECL_DOUBLE,    /* Double variable declaration (e.g., double x) */
    NODE_DECL_INIT,      /* Declaration with initialization (e.g., int x = 5) */
    NODE_ASSIGN,         /* Assignment statement (e.g., x = 10) */
    NODE_PRINT,          /* Print statement (e.g., print(x)) */
    NODE_STMT_LIST,      /* List of statements (program structure) */
    NODE_ARRAY_DECL,     /* Array declaration (e.g., int arr[3]) */
    NODE_ARRAY_ACCESS,   /* Array access (e.g., arr[0]) */
    NODE_ARRAY_ASSIGN,   /* Array assignment (e.g., arr[0] = 5) */
    NODE_ARRAY_2D_DECL,  /* 2D array declaration (e.g., int matrix[2][2]) */
    NODE_ARRAY_2D_ACCESS,/* 2D array access (e.g., matrix[0][1]) */
    NODE_ARRAY_2D_ASSIGN, /* 2D array assignment (e.g., matrix[0][1] = 5) */
    NODE_WHILE          /* While loop node */
} NodeType;

/* AST NODE STRUCTURE
 * Uses a union to efficiently store different node data
 * Only the relevant fields for each node type are used
 */
typedef struct ASTNode {
    NodeType type;  /* Identifies what kind of node this is */
    
    /* Union allows same memory to store different data types */
    union {
        /* Literal number value (NODE_NUM) */
        int num;
        
        /* Literal floating-point value (NODE_FLOAT_NUM) */
        double fnum;
        
        /* Variable or declaration name (NODE_VAR, NODE_DECL, NODE_DECL_DOUBLE) */
        char* name;
        
        /* Binary operation structure (NODE_BINOP) */
        struct {
            char op;                    /* Operator character ('+') */
            struct ASTNode* left;       /* Left operand */
            struct ASTNode* right;      /* Right operand */
        } binop;
        
        /* Assignment structure (NODE_ASSIGN) */
        struct {
            char* var;                  /* Variable being assigned to */
            struct ASTNode* value;      /* Expression being assigned */
        } assign;
        
        /* Print expression (NODE_PRINT) */
        struct ASTNode* expr;
        
        /* Statement list structure (NODE_STMT_LIST) */
        struct {
            struct ASTNode* stmt;       /* Current statement */
            struct ASTNode* next;       /* Rest of the list */
        } stmtlist;

        /* -------- ADDITIONS PROJECT 2 (some features partially disabled) --------*/
        /* If/If-Else structures are defined here so other compilation units
           that reference `node->data.ifstmt` or `node->data.ifelsestmt`
           can compile even when higher-level creation functions are
           intentionally disabled. Implementations can remain commented
           in `ast.c` until the feature is re-enabled. */
        struct {
            struct ASTNode* condition;  /* Condition expression */
            struct ASTNode* thenBlock;  /* Then-block statements */
        } ifstmt;
        struct {
            struct ASTNode* condition;  /* Condition expression */
            struct ASTNode* thenBlock;  /* Then-block statements */
            struct ASTNode* elseBlock;  /* Else-block statements */
        } ifelsestmt;

        /* Declaration with initialization (NODE_DECL_INIT) */
        struct {
            char* name;                 /* Variable name */
            struct ASTNode* value;      /* Initial value expression */
        } decl_init;

        /* Array declaration (NODE_ARRAY_DECL) */
        struct {
            char* name;                 /* Array name */
            int size;                   /* Array size */
        } array_decl;

        /* Array access structure (NODE_ARRAY_ACCESS) */
        struct {
            char* name;                 /* Array name */
            struct ASTNode* index;      /* Index expression */
        } array_access;

        /* Array assignment (NODE_ARRAY_ASSIGN) */
        struct {
            char* name;                 /* Array name */
            struct ASTNode* index;      /* Index expression */
            struct ASTNode* value;      /* Value to assign */
        } array_assign;

        /* 2D Array declaration (NODE_ARRAY_2D_DECL) */
        struct {
            char* name;                 /* Array name */
            int rows;                   /* Number of rows */
            int cols;                   /* Number of columns */
        } array_2d_decl;

        /* 2D Array access (NODE_ARRAY_2D_ACCESS) */
        struct {
            char* name;                 /* Array name */
            struct ASTNode* row;        /* Row index expression */
            struct ASTNode* col;        /* Column index expression */
        } array_2d_access;

        /* 2D Array assignment (NODE_ARRAY_2D_ASSIGN) */
        struct {
            char* name;                 /* Array name */
            struct ASTNode* row;        /* Row index expression */
            struct ASTNode* col;        /* Column index expression */
            struct ASTNode* value;      /* Value to assign */
        } array_2d_assign;
    } data;
} ASTNode;

/* AST CONSTRUCTION FUNCTIONS
 * These functions are called by the parser to build the tree
 */
ASTNode* createNum(int value);                                   /* Create number node */
ASTNode* createFloatNum(double value);                           /* Create float number node */
ASTNode* createVar(char* name);                                  /* Create variable node */
ASTNode* createBinOp(char op, ASTNode* left, ASTNode* right);   /* Create binary op node */
ASTNode* createDecl(char* name);                                 /* Create declaration node */
ASTNode* createDeclDouble(char* name);                           /* Create double declaration node */
ASTNode* createAssign(char* var, ASTNode* value);               /* Create assignment node */
ASTNode* createPrint(ASTNode* expr);                            /* Create print node */
ASTNode* createStmtList(ASTNode* stmt1, ASTNode* stmt2);        /* Create statement list */
ASTNode* createWhile(ASTNode* condition, ASTNode* body);        /* Create while loop node */

/* Array-related functions */
ASTNode* createDeclInit(char* name, ASTNode* value);                          /* Create declaration with init */
ASTNode* createArrayDecl(char* name, int size);                                /* Create array declaration */
ASTNode* createArrayAccess(char* name, ASTNode* index);                        /* Create array access node */
ASTNode* createArrayAssign(char* name, ASTNode* index, ASTNode* value);       /* Create array assignment */
ASTNode* createArray2DDecl(char* name, int rows, int cols);                    /* Create 2D array declaration */
ASTNode* createArray2DAccess(char* name, ASTNode* row, ASTNode* col);         /* Create 2D array access */
ASTNode* createArray2DAssign(char* name, ASTNode* row, ASTNode* col, ASTNode* value); /* Create 2D array assignment */

/* -------- ADDITIONS PROJECT 2 (if/else disabled) --------
ASTNode* createIf(ASTNode* condition, ASTNode* thenBlock);       Create if statement node 
ASTNode* createIfElse(ASTNode* condition, ASTNode* thenBlock, ASTNode* elseBlock);  Create if-else statement node */

/* AST DISPLAY FUNCTION */
void printAST(ASTNode* node, int level);                        /* Pretty-print the AST */

#endif