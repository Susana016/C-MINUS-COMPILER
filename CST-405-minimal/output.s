.data

.text
.globl main

# Initialize globals
    la $s7, globals_base
    j main_start

.data
globals_base:
    .space 1024    # Reserve space for globals

.text
main_start:

# Function: testBasicWhile returns void
testBasicWhile:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int i at offset 0
    li $t0, 0
    sw $t0, 0($sp)
Lwhile_0:
    lw $t1, 0($sp)
    li $t2, 5
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_0
    lw $t0, 0($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 0($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 0($sp)
    j Lwhile_0
Lend_while_0:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testNestedWhile returns void
testNestedWhile:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int i at offset 4
    # Declared int j at offset 8
    li $t3, 0
    sw $t3, 4($sp)
Lwhile_1:
    lw $t4, 4($sp)
    li $t5, 3
    slt $t6, $t4, $t5
    # while condition result in $t6
    beq $t6, $zero, Lend_while_1
    li $t0, 0
    sw $t0, 8($sp)
Lwhile_2:
    lw $t1, 8($sp)
    li $t2, 2
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_2
    lw $t0, 4($sp)
    li $t1, 10
    mul $t2, $t0, $t1
    lw $t3, 8($sp)
    add $t4, $t2, $t3
    # Print integer
    move $a0, $t4
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 8($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 8($sp)
    j Lwhile_2
Lend_while_2:
    lw $t3, 4($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 4($sp)
    j Lwhile_1
Lend_while_1:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testWhileWithCondition returns void
testWhileWithCondition:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int sum at offset 12
    # Declared int i at offset 16
    li $t6, 0
    sw $t6, 12($sp)
    li $t7, 1
    sw $t7, 16($sp)
Lwhile_3:
    lw $t0, 16($sp)
    li $t1, 10
    sle $t2, $t0, $t1
    # while condition result in $t2
    beq $t2, $zero, Lend_while_3
    lw $t0, 12($sp)
    lw $t1, 16($sp)
    add $t2, $t0, $t1
    sw $t2, 12($sp)
    lw $t3, 16($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 16($sp)
    j Lwhile_3
Lend_while_3:
    lw $t6, 12($sp)
    # Print integer
    move $a0, $t6
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testArithmeticOrder returns void
testArithmeticOrder:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int result at offset 20
    li $t0, 2
    li $t1, 3
    li $t2, 4
    mul $t3, $t1, $t2
    add $t4, $t0, $t3
    sw $t4, 20($sp)
    lw $t5, 20($sp)
    # Print integer
    move $a0, $t5
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 20
    li $t1, 8
    li $t2, 2
    div $t3, $t1, $t2
    sub $t4, $t0, $t3
    sw $t4, 20($sp)
    lw $t5, 20($sp)
    # Print integer
    move $a0, $t5
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 10
    li $t1, 5
    sub $t2, $t0, $t1
    li $t3, 2
    sub $t4, $t2, $t3
    sw $t4, 20($sp)
    lw $t5, 20($sp)
    # Print integer
    move $a0, $t5
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 2
    li $t1, 3
    li $t2, 4
    mul $t3, $t1, $t2
    add $t4, $t0, $t3
    li $t5, 10
    li $t6, 2
    div $t7, $t5, $t6
    sub $t0, $t4, $t7
    sw $t0, 20($sp)
    lw $t1, 20($sp)
    # Print integer
    move $a0, $t1
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testParenthesesOrder returns void
testParenthesesOrder:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int result at offset 24
    li $t0, 2
    li $t1, 3
    add $t2, $t0, $t1
    li $t3, 4
    mul $t4, $t2, $t3
    sw $t4, 24($sp)
    lw $t5, 24($sp)
    # Print integer
    move $a0, $t5
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 2
    li $t1, 3
    add $t2, $t0, $t1
    li $t3, 4
    li $t4, 1
    add $t5, $t3, $t4
    mul $t6, $t2, $t5
    li $t7, 5
    div $t0, $t6, $t7
    sw $t0, 24($sp)
    lw $t1, 24($sp)
    # Print integer
    move $a0, $t1
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 10
    li $t1, 5
    sub $t2, $t0, $t1
    li $t3, 3
    li $t4, 2
    add $t5, $t3, $t4
    mul $t6, $t2, $t5
    sw $t6, 24($sp)
    lw $t7, 24($sp)
    # Print integer
    move $a0, $t7
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testComparisonOrder returns void
testComparisonOrder:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int result at offset 28
    li $t0, 2
    li $t1, 3
    add $t2, $t0, $t1
    li $t3, 4
    sgt $t4, $t2, $t3
    # if-else condition result in $t4
    beq $t4, $zero, Lelse_0
    li $t5, 1
    sw $t5, 28($sp)
    j Lend_if_0
Lelse_0:
    li $t6, 0
    sw $t6, 28($sp)
Lend_if_0:
    lw $t7, 28($sp)
    # Print integer
    move $a0, $t7
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 10
    li $t1, 5
    sub $t2, $t0, $t1
    li $t3, 3
    li $t4, 2
    mul $t5, $t3, $t4
    slt $t6, $t2, $t5
    # if-else condition result in $t6
    beq $t6, $zero, Lelse_1
    li $t7, 1
    sw $t7, 28($sp)
    j Lend_if_1
Lelse_1:
    li $t0, 0
    sw $t0, 28($sp)
Lend_if_1:
    lw $t1, 28($sp)
    # Print integer
    move $a0, $t1
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testLoopWithExpressions returns void
testLoopWithExpressions:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int i at offset 32
    # Declared int result at offset 36
    li $t0, 1
    sw $t0, 32($sp)
Lwhile_4:
    lw $t1, 32($sp)
    li $t2, 2
    mul $t3, $t1, $t2
    li $t4, 10
    slt $t5, $t3, $t4
    # while condition result in $t5
    beq $t5, $zero, Lend_while_4
    lw $t0, 32($sp)
    lw $t1, 32($sp)
    mul $t2, $t0, $t1
    li $t3, 2
    lw $t4, 32($sp)
    mul $t5, $t3, $t4
    add $t6, $t2, $t5
    sw $t6, 36($sp)
    lw $t7, 36($sp)
    # Print integer
    move $a0, $t7
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 32($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 32($sp)
    j Lwhile_4
Lend_while_4:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testLogicalOrder returns void
testLogicalOrder:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int result at offset 40
    li $t3, 5
    li $t4, 3
    sgt $t5, $t3, $t4
    li $t6, 2
    li $t7, 4
    slt $t0, $t6, $t7
    and $t1, $t5, $t0
    # if-else condition result in $t1
    beq $t1, $zero, Lelse_2
    li $t2, 1
    sw $t2, 40($sp)
    j Lend_if_2
Lelse_2:
    li $t3, 0
    sw $t3, 40($sp)
Lend_if_2:
    lw $t4, 40($sp)
    # Print integer
    move $a0, $t4
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    li $t1, 3
    slt $t2, $t0, $t1
    li $t3, 2
    li $t4, 4
    slt $t5, $t3, $t4
    or $t6, $t2, $t5
    # if-else condition result in $t6
    beq $t6, $zero, Lelse_3
    li $t7, 1
    sw $t7, 40($sp)
    j Lend_if_3
Lelse_3:
    li $t0, 0
    sw $t0, 40($sp)
Lend_if_3:
    lw $t1, 40($sp)
    # Print integer
    move $a0, $t1
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testComplexLoopCondition returns void
testComplexLoopCondition:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int i at offset 44
    # Declared int j at offset 48
    li $t0, 0
    sw $t0, 44($sp)
    li $t1, 10
    sw $t1, 48($sp)
Lwhile_5:
    lw $t2, 44($sp)
    lw $t3, 48($sp)
    slt $t4, $t2, $t3
    lw $t5, 44($sp)
    lw $t6, 48($sp)
    add $t7, $t5, $t6
    li $t0, 15
    slt $t1, $t7, $t0
    and $t2, $t4, $t1
    # while condition result in $t2
    beq $t2, $zero, Lend_while_5
    lw $t0, 44($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 48($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 44($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 44($sp)
    lw $t3, 48($sp)
    li $t4, 1
    sub $t5, $t3, $t4
    sw $t5, 48($sp)
    j Lwhile_5
Lend_while_5:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testUnaryOperations returns void
testUnaryOperations:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int result at offset 52
    # Declared int x at offset 56
    li $t6, 5
    sw $t6, 56($sp)
    lw $t7, 56($sp)
    li $t0, 0
    sub $t0, $t0, $t7
    li $t1, 10
    add $t2, $t0, $t1
    sw $t2, 52($sp)
    lw $t3, 52($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 2
    lw $t1, 56($sp)
    li $t2, 0
    sub $t2, $t2, $t1
    mul $t3, $t0, $t2
    sw $t3, 52($sp)
    lw $t4, 52($sp)
    # Print integer
    move $a0, $t4
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 0
    seq $t1, $t0, $zero
    # if-else condition result in $t1
    beq $t1, $zero, Lelse_4
    li $t2, 1
    sw $t2, 52($sp)
    j Lend_if_4
Lelse_4:
    li $t3, 0
    sw $t3, 52($sp)
Lend_if_4:
    lw $t4, 52($sp)
    # Print integer
    move $a0, $t4
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testCountdownLoop returns void
testCountdownLoop:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int count at offset 60
    li $t0, 5
    sw $t0, 60($sp)
Lwhile_6:
    lw $t1, 60($sp)
    li $t2, 0
    sgt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_6
    lw $t0, 60($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 60($sp)
    li $t1, 1
    sub $t2, $t0, $t1
    sw $t2, 60($sp)
    j Lwhile_6
Lend_while_6:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testArrayWithExpressions returns void
testArrayWithExpressions:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared array arr[5] at offset 64
    # Declared int i at offset 84
    li $t3, 0
    sw $t3, 84($sp)
Lwhile_7:
    lw $t4, 84($sp)
    li $t5, 5
    slt $t6, $t4, $t5
    # while condition result in $t6
    beq $t6, $zero, Lend_while_7
    lw $t0, 84($sp)
    li $t1, 2
    mul $t2, $t0, $t1
    li $t3, 1
    add $t4, $t2, $t3
    lw $t5, 84($sp)
    # Array assignment: arr[index] = value
    sll $t5, $t5, 2
    add $t5, $t5, $sp
    sw $t4, 64($t5)
    lw $t0, 84($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 84($sp)
    j Lwhile_7
Lend_while_7:
    li $t3, 0
    sw $t3, 84($sp)
Lwhile_8:
    lw $t4, 84($sp)
    li $t5, 5
    slt $t6, $t4, $t5
    # while condition result in $t6
    beq $t6, $zero, Lend_while_8
    lw $t0, 84($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 64($t0)
    # Print integer
    move $a0, $t1
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 84($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 84($sp)
    j Lwhile_8
Lend_while_8:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: main returns void
main:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    li $t3, 999
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testBasicWhile
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testNestedWhile
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testWhileWithCondition
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testArithmeticOrder
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testParenthesesOrder
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testComparisonOrder
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testLoopWithExpressions
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testLogicalOrder
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testComplexLoopCondition
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testUnaryOperations
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testCountdownLoop
    move $t0, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    jal testArrayWithExpressions
    move $t0, $v0
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
