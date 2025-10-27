#ifndef SYMTAB_H
#define SYMTAB_H

#define MAX_SYMBOLS 100

typedef enum {
    TYPE_INT,
    TYPE_DOUBLE
} VarType;

/* Symbol entry */
typedef struct {
    char* name;
    VarType type;
    int offset;
    int isFunction;      /* NEW: 1 if function, 0 if variable */
    int paramCount;      /* NEW: Number of parameters (if function) */
    char** paramTypes;   /* NEW: Parameter types (if function) */
    char* returnType;    /* NEW: Return type (if function) */
} Symbol;

/* Scope structure */
typedef struct Scope {
    Symbol symbols[MAX_SYMBOLS];
    int count;
    int nextOffset;
    struct Scope* parent;  /* NEW: Link to enclosing scope */
} Scope;

/* Symbol table with scope management */
typedef struct {
    Scope* currentScope;   /* NEW: Current scope */
    Scope* globalScope;    /* NEW: Always points to global */
} SymbolTable;

extern SymbolTable symtab;

/* Existing functions */
void initSymTab();
int addVar(char* name, VarType type);
int getVarOffset(char* name);
VarType getVarType(char* name);
int isVarDeclared(char* name);

/* NEW: Scope management functions */
void enterScope();              /* Enter a new scope (e.g., function body) */
void exitScope();               /* Exit current scope */
int addFunction(char* name, char* returnType, char** paramTypes, int paramCount);
int addParameter(char* name, char* type);
Symbol* lookupSymbol(char* name);  /* Search current + parent scopes */
int isInCurrentScope(char* name);  /* Check only current scope */
void printSymbolTable(SymbolTable* table);


#endif