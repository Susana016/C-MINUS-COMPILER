/* MINIMAL C COMPILER - EDUCATIONAL VERSION
 * Demonstrates all phases of compilation with a simple language
 * Supports: int variables, addition, assignment, print
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ast.h"
#include "codegen.h"
#include "tac.h"
#include "symtab.h"

/* Efficiency Statistics */
typedef struct {
    clock_t start_time;
    clock_t end_time;
    int ast_nodes;
    int tac_instructions;
    int optimized_tac_instructions;
    int mips_instructions;
    int variables_declared;
    int optimization_reduction;
} CompilerStats;

CompilerStats stats = {0};

extern int yyparse();
extern FILE* yyin;
extern ASTNode* root;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.c> <output.s>\n", argv[0]);
        printf("Example: ./minicompiler test.c output.s\n");
        return 1;
    }
    
    /* Start timing */
    stats.start_time = clock();
    
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Error: Cannot open input file '%s'\n", argv[1]);
        return 1;
    }

    initSymTab();

    
    printf("\n");
    printf("+============================================================+\n");
    printf("|          MINIMAL C COMPILER - EDUCATIONAL VERSION         |\n");
    printf("+============================================================+\n");
    printf("\n");
    
    /* PHASE 1: Lexical and Syntax Analysis */
    printf("+------------------------------------------------------------+\n");
    printf("| PHASE 1: LEXICAL & SYNTAX ANALYSIS                        |\n");
    printf("+------------------------------------------------------------+\n");
    printf("| * Reading source file: %s\n", argv[1]);
    printf("| * Tokenizing input (scanner.l)\n");
    printf("| * Parsing grammar rules (parser.y)\n");
    printf("| * Building Abstract Syntax Tree\n");
    printf("+------------------------------------------------------------+\n");
    
    if (yyparse() == 0) {
        printf("[OK] Parse successful - program is syntactically correct!\n\n");
        
        /* PHASE 2: AST Display */
        printf("+------------------------------------------------------------+\n");
        printf("| PHASE 2: ABSTRACT SYNTAX TREE (AST)                       |\n");
        printf("+------------------------------------------------------------+\n");
        printf("| Tree structure representing the program hierarchy:        |\n");
        printf("+------------------------------------------------------------+\n");
        stats.ast_nodes = countASTNodes(root);
        printAST(root, 0);
        printf("\n");

        printf("+------------------------------------------------------------+\n");
        printf("| PHASE 2.5: SYMBOL TABLE DUMP                              |\n");
        printf("+------------------------------------------------------------+\n");
        stats.variables_declared = getVariableCount();
        printSymbolTable(&symtab);
        printf("\n");
        
        /* PHASE 3: Intermediate Code */
        printf("+------------------------------------------------------------+\n");
        printf("| PHASE 3: INTERMEDIATE CODE GENERATION                     |\n");
        printf("+------------------------------------------------------------+\n");
        printf("| Three-Address Code (TAC) - simplified instructions:       |\n");
        printf("| * Each instruction has at most 3 operands                 |\n");
        printf("| * Temporary variables (t0, t1, ...) for expressions       |\n");
        printf("+------------------------------------------------------------+\n");
        initTAC();
        generateTAC(root);
        stats.tac_instructions = getTACInstructionCount();
        printTAC();
        printf("\n");
        
        /* PHASE 4: Optimization */
        printf("+------------------------------------------------------------+\n");
        printf("| PHASE 4: CODE OPTIMIZATION                                |\n");
        printf("+------------------------------------------------------------+\n");
        printf("| Applying optimizations:                                   |\n");
        printf("| * Constant folding (evaluate compile-time expressions)    |\n");
        printf("| * Copy propagation (replace variables with values)        |\n");
        printf("+------------------------------------------------------------+\n");
        optimizeTAC();
        stats.optimized_tac_instructions = getOptimizedTACInstructionCount();
        printOptimizedTAC();
    /* Free TAC memory allocated during generation/optimization */
    freeTAC();
        printf("\n");
        
        /* PHASE 5: Code Generation */
        printf("+------------------------------------------------------------+\n");
        printf("| PHASE 5: MIPS CODE GENERATION                             |\n");
        printf("+------------------------------------------------------------+\n");
        printf("| Translating to MIPS assembly:                             |\n");
        printf("| * Variables stored on stack                               |\n");
        printf("| * Using $t0-$t7 for temporary values                      |\n");
        printf("| * System calls for print operations                       |\n");
        printf("+------------------------------------------------------------+\n");
        generateMIPS(root, argv[2]);
        printf("[OK] MIPS assembly code generated to: %s\n", argv[2]);
        printf("\n");
        
        printf("+============================================================+\n");
        printf("|                  COMPILATION SUCCESSFUL!                   |\n");
        printf("|         Run the output file in a MIPS simulator            |\n");
        printf("+============================================================+\n");
        printf("\n");
        
        /* EFFICIENCY STATISTICS */
        stats.end_time = clock();
        double compile_time = ((double)(stats.end_time - stats.start_time)) / CLOCKS_PER_SEC * 1000.0;
        
        printf("+============================================================+\n");
        printf("|              COMPILATION EFFICIENCY REPORT                 |\n");
        printf("+============================================================+\n");
        printf("| Compilation Time:        %.2f ms\n", compile_time);
        printf("| Source File:             %s\n", argv[1]);
        printf("| Output File:             %s\n", argv[2]);
        printf("+------------------------------------------------------------+\n");
        printf("| Code Statistics:\n");
        printf("|   Variables Declared:    %d\n", stats.variables_declared);
        printf("|   AST Nodes Generated:   %d\n", stats.ast_nodes);
        printf("|   TAC Instructions:      %d (unoptimized)\n", stats.tac_instructions);
        printf("|   TAC Instructions:      %d (optimized)\n", stats.optimized_tac_instructions);
        printf("|   MIPS Instructions:     %d\n", stats.mips_instructions);
        printf("+------------------------------------------------------------+\n");
        printf("| Optimization Impact:\n");
        if (stats.tac_instructions > 0) {
            int reduction = stats.tac_instructions - stats.optimized_tac_instructions;
            double percentage = (double)reduction / stats.tac_instructions * 100.0;
            printf("|   Instructions Removed:  %d (%.1f%% reduction)\n", reduction, percentage);
        } else {
            printf("|   Instructions Removed:  0 (0.0%% reduction)\n");
        }
        printf("+------------------------------------------------------------+\n");
        printf("| Performance Metrics:\n");
        printf("|   Compile Speed:         %.0f lines/sec\n", 
               compile_time > 0 ? (stats.ast_nodes / (compile_time / 1000.0)) : 0.0);
        printf("|   Code Density:          %.2f MIPS/TAC ratio\n",
               stats.optimized_tac_instructions > 0 ? 
               (double)stats.mips_instructions / stats.optimized_tac_instructions : 0.0);
        printf("+============================================================+\n");
        
    } else {
        printf("[ERROR] Parse failed - check your syntax!\n");
        printf("Common errors:\n");
        printf("  * Missing semicolon after statements\n");
        printf("  * Undeclared variables\n");
        printf("  * Invalid syntax for print statements\n");
        return 1;
    }
    
    fclose(yyin);
    return 0;
}
