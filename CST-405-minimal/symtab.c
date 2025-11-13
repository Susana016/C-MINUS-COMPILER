#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

SymbolTable symtab;

void initSymTab() {
    /* Create global scope */
    symtab.globalScope = malloc(sizeof(Scope));
    symtab.globalScope->count = 0;
    symtab.globalScope->nextOffset = 0;
    symtab.globalScope->parent = NULL;
    
    symtab.currentScope = symtab.globalScope;
}

void enterScope() {
    Scope* newScope = malloc(sizeof(Scope));
    newScope->count = 0;
    newScope->nextOffset = 0;
    newScope->parent = symtab.currentScope;  /* Link to parent */
    
    symtab.currentScope = newScope;  /* Push onto scope stack */
}

void exitScope() {
    if (symtab.currentScope == symtab.globalScope) {
        fprintf(stderr, "Error: Cannot exit global scope\n");
        return;
    }
    
    Scope* oldScope = symtab.currentScope;
    symtab.currentScope = symtab.currentScope->parent;  /* Pop */
    
    /* Free the old scope (optional - may want to keep for debugging) */
    free(oldScope);
}

Symbol* lookupSymbol(char* name) {
    Scope* scope = symtab.currentScope;
    
    /* Search from current scope up to global */
    while (scope != NULL) {
        for (int i = 0; i < scope->count; i++) {
            if (strcmp(scope->symbols[i].name, name) == 0) {
                return &scope->symbols[i];  /* Found */
            }
        }
        scope = scope->parent;  /* Move to parent scope */
    }
    
    return NULL;  /* Not found in any scope */
}

int isInCurrentScope(char* name) {
    for (int i = 0; i < symtab.currentScope->count; i++) {
        if (strcmp(symtab.currentScope->symbols[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

int addVar(char* name, VarType type) {
    /* Check if already in CURRENT scope (skip check for unnamed/reserved variables) */
    if (strlen(name) > 0 && isInCurrentScope(name)) {
        return -1;  /* Duplicate in this scope */
    }

    Scope* scope = symtab.currentScope;
    scope->symbols[scope->count].name = strdup(name);
    scope->symbols[scope->count].type = type;
    scope->symbols[scope->count].offset = scope->nextOffset;
    scope->symbols[scope->count].isFunction = 0;

    if (type == TYPE_DOUBLE) {
        scope->nextOffset += 8;
    } else {
        scope->nextOffset += 4;
    }

    scope->count++;
    return scope->symbols[scope->count - 1].offset;
}

int addFunction(char* name, char* returnType, char** paramTypes, int paramCount) {
    /* Functions go in global scope */
    if (isInCurrentScope(name)) {
        return -1;  /* Already declared */
    }
    
    Scope* scope = symtab.globalScope;
    scope->symbols[scope->count].name = strdup(name);
    scope->symbols[scope->count].isFunction = 1;
    scope->symbols[scope->count].returnType = strdup(returnType);
    scope->symbols[scope->count].paramCount = paramCount;
    scope->symbols[scope->count].paramTypes = paramTypes;
    scope->symbols[scope->count].offset = -1;  /* Functions don't have offsets */
    
    scope->count++;
    return 0;  /* Success */
}

int addParameter(char* name, char* type) {
    /* Parameters have positive offsets (above frame pointer) */
    if (isInCurrentScope(name)) {
        return -1;
    }
    
    Scope* scope = symtab.currentScope;
    scope->symbols[scope->count].name = strdup(name);
    scope->symbols[scope->count].type = (strcmp(type, "double") == 0) ? TYPE_DOUBLE : TYPE_INT;
    scope->symbols[scope->count].isFunction = 0;
    
    /* Parameters start at offset +8 (after $ra and $fp) */
    static int paramOffset = 8;
    scope->symbols[scope->count].offset = paramOffset;
    paramOffset += 4;  /* Each param is 4 bytes */
    
    scope->count++;
    return 0;
}

int getVarOffset(char* name) {
    Symbol* sym = lookupSymbol(name);
    return sym ? sym->offset : -1;
}

VarType getVarType(char* name) {
    Symbol* sym = lookupSymbol(name);
    return sym ? sym->type : TYPE_INT;
}

int isVarDeclared(char* name) {
    return lookupSymbol(name) != NULL;
}

void printScope(Scope* scope, int level) {
    if (!scope) return;
    for (int i = 0; i < scope->count; i++) {
        Symbol s = scope->symbols[i];
        for (int j = 0; j < level; j++) printf("  ");  // Indent per scope
        printf("| %-15s | %-10s | %-5s | %-6d |\n",
               s.name,
               s.isFunction ? "Function" : "Variable",
               s.type == TYPE_INT ? "int" : "double",
               s.offset);
    }
    printScope(scope->parent, level + 1);
}

void printSymbolTable(SymbolTable* table) {
    printf("| %-15s | %-10s | %-5s | %-6s |\n", "Identifier", "Kind", "Type", "Offset");
    printf("|---------------------------------------------|\n");
    printScope(table->currentScope, 0);
}

/* Get total variable count for statistics */
int getVariableCount() {
    int count = 0;
    Scope* current = symtab.currentScope;
    while (current) {
        for (int i = 0; i < current->count; i++) {
            if (!current->symbols[i].isFunction) {
                count++;
            }
        }
        current = current->parent;
    }
    return count;
}

