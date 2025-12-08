#ifndef SYMTAB_H
#define SYMTAB_H

typedef enum { TYPE_INT, TYPE_DOUBLE } VarType;
typedef VarType DataType;  // Alias for compatibility

// SINGLE Symbol struct with ALL fields
typedef struct Symbol {
    char* name;
    VarType type;
    int offset;
    int isArray;        // ADD THIS
    int isFunction;
    char* returnType;
    char** paramTypes;
    int paramCount;
} Symbol;

typedef struct Scope {
    Symbol symbols[100];
    int count;
    int nextOffset;
    struct Scope* parent;
} Scope;

typedef struct {
    Scope* globalScope;
    Scope* currentScope;
} SymbolTable;

extern SymbolTable symtab;

/* Symbol table functions */
void initSymTab();
Symbol* lookupSymbol(char* name);
Symbol* addSymbol(const char* name, DataType type);
int isInCurrentScope(char* name);
int addVar(char* name, VarType type);
int addFunction(char* name, char* returnType, char** paramTypes, int paramCount);
int addParameter(char* name, char* type);
int getVarOffset(char* name);
VarType getVarType(char* name);
int isVarDeclared(char* name);

/* Scope management */
void enterScope();
void exitScope();
void pushScope();
void popScope();

/* Debug/statistics functions */
void printSymbolTable(SymbolTable* table);
int getVariableCount();

#endif