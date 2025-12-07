#ifndef AST_H
#define AST_H

/* ABSTRACT SYNTAX TREE (AST) */

/* NODE TYPES */
typedef enum {
    NODE_NUM,
    NODE_FLOAT_NUM,
    NODE_VAR,
    NODE_BINOP,
    NODE_UNARY_OP,        // Add this
    NODE_DECL,
    NODE_DECL_DOUBLE,
    NODE_DECL_INIT,
    NODE_ASSIGN,
    NODE_PRINT,
    NODE_STMT_LIST,
    NODE_ARRAY_DECL,
    NODE_ARRAY_ACCESS,
    NODE_ARRAY_ASSIGN,
    NODE_ARRAY_2D_DECL,
    NODE_ARRAY_2D_ACCESS,
    NODE_ARRAY_2D_ASSIGN,
    NODE_WHILE,
    NODE_FOR,
    NODE_IF,
    NODE_IF_ELSE,
    NODE_LABEL,
    NODE_GOTO,

    /* Global and Function Support */
    NODE_PROGRAM,
    NODE_GLOBAL_DECL,
    NODE_GLOBAL_DECL_DOUBLE,
    NODE_GLOBAL_DECL_INIT,
    NODE_GLOBAL_ARRAY_DECL,
    NODE_GLOBAL_ARRAY_2D_DECL,
    
    NODE_FUNCTION,
    NODE_FUNCTION_LIST,
    NODE_PARAMETER,
    NODE_RETURN,
    NODE_CALL,
    NODE_CALL_EXPR,

    /* Multi-value equality check */
    NODE_MULTI_VALUE_CHECK,
    NODE_VALUE_LIST,
    
    /* Switch-Case */
    NODE_SWITCH,
    NODE_CASE_LIST,
    NODE_CASE,
    NODE_DEFAULT,
    NODE_BREAK,

    NODE_ARG_LIST
} NodeType;

/* Forward declaration */
typedef struct ASTNode ASTNode;

/* AST NODE STRUCTURE */
struct ASTNode {
    NodeType type;
    
    union {
        int num;
        double fnum;
        char* name;
        
        struct {
            int op;
            struct ASTNode* left;
            struct ASTNode* right;
        } binop;
        
        struct {
            char* var;
            struct ASTNode* value;
        } assign;
        
        struct ASTNode* expr;
        
        struct {
            struct ASTNode* stmt;
            struct ASTNode* next;
        } stmtlist;
        
        struct {
            char* name;
            struct ASTNode* value;
        } decl_init;
        
        struct {
            char* name;
            int size;
        } array_decl;
        
        struct {
            char* name;
            struct ASTNode* index;
        } array_access;
        
        struct {
            char* name;
            struct ASTNode* index;
            struct ASTNode* value;
        } array_assign;
        
        struct {
            char* name;
            int rows;
            int cols;
        } array_2d_decl;
        
        struct {
            char* name;
            struct ASTNode* row;
            struct ASTNode* col;
        } array_2d_access;
        
        struct {
            char* name;
            struct ASTNode* row;
            struct ASTNode* col;
            struct ASTNode* value;
        } array_2d_assign;
        
        
        struct {
            struct ASTNode* globals;
            struct ASTNode* functions;
        } program;
        
        struct {
            char* name;
            char* returnType;
            struct ASTNode* params;
            struct ASTNode* body;
        } function;
        
        struct {
            struct ASTNode* head;
            struct ASTNode* tail;
        } funclist;
        
        struct {
            char* name;
            char* type;
            struct ASTNode* next;
        } parameter;
        
        struct {
            struct ASTNode* value;
        } returnstmt;
        
        struct {
            char* funcName;
            struct ASTNode* args;
        } call;
        
        struct {
            char* funcName;
            struct ASTNode* args;
        } call_expr;

        struct {
            struct ASTNode* condition;
            struct ASTNode* thenBlock;
            struct ASTNode* elseBlock; /* optional */
        } ifstmt;

        struct {
            struct ASTNode* init;
            struct ASTNode* condition;
            struct ASTNode* update;
            struct ASTNode* body;
        } forstmt;

        struct {
            char* name;
        } label;

        struct {
            char* name;
        } gotostmt;

        struct {
            struct ASTNode* expr;      /* Expression to check */
            struct ASTNode* values;    /* List of values to compare against */
        } multiValueCheck;

        struct {
            struct ASTNode* value;     /* Current value */
            struct ASTNode* next;      /* Next value in list */
        } valueList;

        /* Switch-Case structures */
        struct {
            struct ASTNode* expr;      /* Switch expression */
            struct ASTNode* cases;     /* List of case statements */
        } switchstmt;

        struct {
            int value;                 /* Case value (constant) */
            struct ASTNode* body;      /* Case body */
            struct ASTNode* next;      /* Next case */
        } casestmt;

        struct {
            struct ASTNode* body;      /* Default body */
        } defaultstmt;

        struct {
            int op;
            struct ASTNode* operand;
        } unary_op;

        struct {
            struct ASTNode* arg;
            struct ASTNode* next;
        } arg_list;

    } data;
};

/* ============================================
   FUNCTION DECLARATIONS - ALL AST FUNCTIONS
   ============================================ */

/* Basic nodes */
ASTNode* createNum(int value);
ASTNode* createFloatNum(double value);
ASTNode* createVar(char* name);
ASTNode* createBinOp(int op, ASTNode* left, ASTNode* right);

/* Create a unary operation node (for NOT, negation) */
ASTNode* createUnaryOp(int op, ASTNode* operand);

ASTNode* createDecl(char* name);
ASTNode* createDeclDouble(char* name);
ASTNode* createAssign(char* var, ASTNode* value);
ASTNode* createPrint(ASTNode* expr);
ASTNode* createStmtList(ASTNode* stmt1, ASTNode* stmt2);
ASTNode* createWhile(ASTNode* condition, ASTNode* body);
ASTNode* createFor(ASTNode* init, ASTNode* condition, ASTNode* update, ASTNode* body);

/* Array functions */
ASTNode* createDeclInit(char* name, ASTNode* value);
ASTNode* createArrayDecl(char* name, int size);
ASTNode* createArrayAccess(char* name, ASTNode* index);
ASTNode* createArrayAssign(char* name, ASTNode* index, ASTNode* value);
ASTNode* createArray2DDecl(char* name, int rows, int cols);
ASTNode* createArray2DAccess(char* name, ASTNode* row, ASTNode* col);
ASTNode* createArray2DAssign(char* name, ASTNode* row, ASTNode* col, ASTNode* value);

/* Program and global functions */
ASTNode* createProgram(ASTNode* globals, ASTNode* functions);
ASTNode* createGlobalDecl(char* name);
ASTNode* createGlobalDeclDouble(char* name);
ASTNode* createGlobalDeclInit(char* name, ASTNode* value);
ASTNode* createGlobalArrayDecl(char* name, int size);
ASTNode* createGlobalArray2DDecl(char* name, int rows, int cols);

/* Function support */
ASTNode* createFunction(char* name, char* returnType, ASTNode* params, ASTNode* body);
ASTNode* createFunctionList(ASTNode* func1, ASTNode* func2);
ASTNode* createParameter(char* name, char* type, ASTNode* next);
ASTNode* createReturn(ASTNode* value);
ASTNode* createCall(char* funcName, ASTNode* args);
ASTNode* createCallExpr(char* funcName, ASTNode* args);
ASTNode* createArgList(ASTNode* arg, ASTNode* next);

ASTNode* createIf(ASTNode* condition, ASTNode* thenBlock);
ASTNode* createIfElse(ASTNode* condition, ASTNode* thenBlock, ASTNode* elseBlock);
ASTNode* createLabel(char* name);
ASTNode* createGoto(char* name);

/* Multi-value equality check */
ASTNode* createMultiValueCheck(ASTNode* expr, ASTNode* values);
ASTNode* createValueList(ASTNode* value, ASTNode* next);

/* Switch-Case functions */
ASTNode* createSwitch(ASTNode* expr, ASTNode* cases);
ASTNode* createCase(int value, ASTNode* body, ASTNode* next);
ASTNode* createDefault(ASTNode* body);
ASTNode* createBreak();

/* Display function */
void printAST(ASTNode* node, int level);

/* Statistics */
int countASTNodes(ASTNode* node);


/* Built-in function constructors */
ASTNode* createOutput(ASTNode* expr);
ASTNode* createInput(void);


#endif