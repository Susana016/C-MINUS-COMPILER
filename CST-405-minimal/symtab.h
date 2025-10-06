#ifndef SYMTAB_H
#define SYMTAB_H

/* SYMBOL TABLE
 * Tracks all declared variables during compilation
 * Maps variable names to their memory locations (stack offsets)
 * Used for semantic checking and code generation
 */

#define MAX_VARS 100  /* Maximum number of variables supported */

/* Variable type enumeration */
typedef enum {
    TYPE_INT,
    TYPE_DOUBLE
} VarType;

/* SYMBOL ENTRY - Information about each variable */
typedef struct {
    char* name;     /* Variable identifier */
    int offset;     /* Stack offset in bytes (for MIPS stack frame) */
    VarType type;   /* Variable type (int or double) */
} Symbol;

/* SYMBOL TABLE STRUCTURE */
typedef struct {
    Symbol vars[MAX_VARS];  /* Array of all variables */
    int count;              /* Number of variables declared */
    int nextOffset;         /* Next available stack offset */
} SymbolTable;

/* SYMBOL TABLE OPERATIONS */
void initSymTab();               /* Initialize empty symbol table */
int addVar(char* name, VarType type);  /* Add new variable with type, returns offset or -1 if duplicate */
int getVarOffset(char* name);    /* Get stack offset for variable, -1 if not found */
VarType getVarType(char* name);  /* Get variable type */
int isVarDeclared(char* name);   /* Check if variable exists (1=yes, 0=no) */

#endif