#ifndef AST_H
#define AST_H

/* ABSTRACT SYNTAX TREE (AST)
 * The AST is an intermediate representation of the program structure
 * It represents the hierarchical syntax of the source code
 * Each node represents a construct in the language
 */

/* NODE TYPES - Different kinds of AST nodes in our language */
typedef enum {
    NODE_NUM,        /* Numeric literal (e.g., 42) */
    NODE_FLOAT_NUM,  /* Floating-point literal (e.g., 3.14) */
    NODE_VAR,        /* Variable reference (e.g., x) */
    NODE_BINOP,      /* Binary operation (e.g., x + y) */
    NODE_DECL,       /* Variable declaration (e.g., int x) */
    NODE_DECL_DOUBLE,/* Double variable declaration (e.g., double x) */
    NODE_ASSIGN,     /* Assignment statement (e.g., x = 10) */
    NODE_PRINT,      /* Print statement (e.g., print(x)) */
    NODE_STMT_LIST,  /* List of statements (program structure) */
    NODE_ARRAY_ACCESS   /* Array access (e.g., arr[0]) */
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

        /* Array access structure (NODE_ARRAY_ACCESS) */
        struct {
            struct ASTNode* index;      /* Index expression */
        } arrayaccess;
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

/* -------- ADDITIONS PROJECT 2 --------
ASTNode* createIf(ASTNode* condition, ASTNode* thenBlock);       Create if statement node 
ASTNode* createIfElse(ASTNode* condition, ASTNode* thenBlock, ASTNode* elseBlock);  Create if-else statement node */
ASTNode* createArrayAccess(ASTNode* index);                    /* Create array access node */

/* AST DISPLAY FUNCTION */
void printAST(ASTNode* node, int level);                        /* Pretty-print the AST */

#endif