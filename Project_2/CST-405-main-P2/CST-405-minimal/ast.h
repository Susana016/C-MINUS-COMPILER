#ifndef AST_H
#define AST_H

/* ABSTRACT SYNTAX TREE (AST)
 * The AST is an intermediate representation of the program structure
 * It represents the hierarchical syntax of the source code
 * Each node represents a construct in the language
 */

/* NODE TYPES - Different kinds of AST nodes in our language */
typedef enum {
    NODE_NUM,       /* Numeric literal (e.g., 42) */
    NODE_VAR,       /* Variable reference (e.g., x) */
    NODE_BINOP,     /* Binary operation (e.g., x + y) */
    NODE_DECL,      /* Variable declaration (e.g., int x) */
    NODE_DECL_INIT, /* Variable declaration with initialization (e.g., int x = 5) */
    NODE_ASSIGN,    /* Assignment statement (e.g., x = 10) */
    NODE_PRINT,     /* Print statement (e.g., print(x)) */
    NODE_ARRAY_DECL,/* Array declaration (e.g., int a[10]) */
    NODE_ARRAY_ACCESS, /* Array element access (e.g., a[2]) */
    NODE_ARRAY_ASSIGN, /* Array element assignment (e.g., a[2] = 5) */
    NODE_STMT_LIST,  /* List of statements (program structure) */
    NODE_RETURN,    /* Return statement (e.g., return x) */
    NODE_MAIN_FUNC  /* Main function (program entry point) */
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
        
        /* Variable or declaration name (NODE_VAR, NODE_DECL) */
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
        /* Array declaration structure (NODE_ARRAY_DECL) */
        struct {
            char* name;                /* Array name */
            int size;                  /* Array size */
        } array_decl;

        struct {
            char* name;
            struct ASTNode* value;
        } decl_init;

        /* Array access structure (NODE_ARRAY_ACCESS) */
        struct {
            char* name;                /* Array name */
            struct ASTNode* index;     /* Index expression */
        } array_access;

        /* Array assignment structure (NODE_ARRAY_ASSIGN) */
        struct {
            char* name;                /* Array name */
            struct ASTNode* index;     /* Index expression */
            struct ASTNode* value;     /* Value expression */
        } array_assign;
        
        /* Print expression (NODE_PRINT) */
        struct ASTNode* expr;
        
        /* Statement list structure (NODE_STMT_LIST) */
        struct {
            struct ASTNode* stmt;       /* Current statement */
            struct ASTNode* next;       /* Rest of the list */
        } stmtlist;

        /* Return statement (NODE_PRINT) */
        struct {
            struct ASTNode* expr;      /* Expression to print */
        } print;  
        
    } data;
} ASTNode;

/* AST CONSTRUCTION FUNCTIONS
 * These functions are called by the parser to build the tree
 */
ASTNode* createNum(int value);                                   /* Create number node */
ASTNode* createVar(char* name);                                  /* Create variable node */
ASTNode* createBinOp(char op, ASTNode* left, ASTNode* right);   /* Create binary op node */
ASTNode* createDecl(char* name);                                 /* Create declaration node */
ASTNode* createAssign(char* var, ASTNode* value);               /* Create assignment node */
ASTNode* createPrint(ASTNode* expr);                            /* Create print node */
ASTNode* createStmtList(ASTNode* stmt1, ASTNode* stmt2);        /* Create statement list */
ASTNode* createArrayDecl(char* name, int size);                /* Create array declaration node */
ASTNode* createArrayAccess(char* name, ASTNode* index);        /* Create array access node */
ASTNode* createArrayAssign(char* name, ASTNode* index, ASTNode* value); /* Create array assign node */


/* AST DISPLAY FUNCTION */
void printAST(ASTNode* node, int level);                        /* Pretty-print the AST */

#endif