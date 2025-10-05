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
    NODE_VAR,        /* Variable reference (e.g., x) */
    NODE_BINOP,      /* Binary operation (e.g., x + y) */
    NODE_DECL,       /* Variable declaration (e.g., int x) */
    NODE_ASSIGN,     /* Assignment statement (e.g., x = 10) */
    NODE_PRINT,      /* Print statement (e.g., print(x)) */
    NODE_STMT_LIST,  /* List of statements (program structure) */
    NODE_IF,         /* If statement */
    NODE_IF_ELSE        /* If-else statement */
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
        
        /* Print expression (NODE_PRINT) */
        struct ASTNode* expr;
        
        /* Statement list structure (NODE_STMT_LIST) */
        struct {
            struct ASTNode* stmt;       /* Current statement */
            struct ASTNode* next;       /* Rest of the list */
        } stmtlist;

        /* -------- ADDITIONS PROJECT 2 --------*/
        /* If statement structure (NODE_IF) */
        struct {
            struct ASTNode* condition;  /* Condition expression */
            struct ASTNode* thenBlock; /* Statements to execute if true */
        } ifstmt;
        /* If-else statement structure (NODE_IF_ELSE) */
        struct {
            struct ASTNode* condition;  /* Boolean condition */
            struct ASTNode* thenBlock;  /* Statements to execute if true */
            struct ASTNode* elseBlock;  /* Statements to execute if false */
        } ifelsestmt;
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

/* -------- ADDITIONS PROJECT 2 --------*/
ASTNode* createIf(ASTNode* condition, ASTNode* thenBlock);      /* Create if statement node */
ASTNode* createIfElse(ASTNode* condition, ASTNode* thenBlock, ASTNode* elseBlock); /* Create if-else statement node */

/* AST DISPLAY FUNCTION */
void printAST(ASTNode* node, int level);                        /* Pretty-print the AST */

#endif