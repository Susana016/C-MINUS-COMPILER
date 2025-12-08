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
    # Global int globalCounter at offset 0
    # Global array globalArray[20] at offset 4
    # Global int globalResult at offset 84

# Function: testArithmetic returns int
testArithmetic:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int sum at offset 0
    # Declared int diff at offset 4
    # Declared int prod at offset 8
    # Declared int quot at offset 12
    # Declared int complex at offset 16
    # Declared int temp1 at offset 20
    # Declared int temp2 at offset 24
    # Declared int temp3 at offset 28
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    add $t2, $t0, $t1
    sw $t2, 0($sp)
    lw $t3, 8($sp)
    lw $t4, 12($sp)
    sub $t5, $t3, $t4
    sw $t5, 4($sp)
    lw $t6, 8($sp)
    lw $t7, 12($sp)
    mul $t0, $t6, $t7
    sw $t0, 8($sp)
    lw $t1, 8($sp)
    lw $t2, 12($sp)
    div $t3, $t1, $t2
    sw $t3, 12($sp)
    li $t4, 3
    li $t5, 4
    mul $t6, $t4, $t5
    sw $t6, 20($sp)
    li $t7, 2
    lw $t0, 20($sp)
    add $t1, $t7, $t0
    sw $t1, 16($sp)
    li $t2, 2
    li $t3, 3
    add $t4, $t2, $t3
    sw $t4, 24($sp)
    lw $t5, 24($sp)
    li $t6, 4
    mul $t7, $t5, $t6
    sw $t7, 16($sp)
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    mul $t2, $t0, $t1
    sw $t2, 20($sp)
    lw $t3, 8($sp)
    lw $t4, 12($sp)
    div $t5, $t3, $t4
    sw $t5, 24($sp)
    lw $t6, 20($sp)
    lw $t7, 24($sp)
    add $t0, $t6, $t7
    sw $t0, 28($sp)
    lw $t1, 28($sp)
    lw $t2, 8($sp)
    sub $t3, $t1, $t2
    sw $t3, 28($sp)
    lw $t4, 28($sp)
    lw $t5, 12($sp)
    add $t6, $t4, $t5
    sw $t6, 16($sp)
    lw $t7, 0($sp)
    lw $t0, 4($sp)
    add $t1, $t7, $t0
    sw $t1, 20($sp)
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    add $t4, $t2, $t3
    sw $t4, 24($sp)
    lw $t5, 20($sp)
    lw $t6, 24($sp)
    add $t7, $t5, $t6
    sw $t7, 28($sp)
    lw $t0, 28($sp)
    move $v0, $t0
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testRelational returns int
testRelational:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int result at offset 0
    li $t1, 0
    sw $t1, 0($sp)
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    slt $t4, $t2, $t3
    # if condition result in $t4
    beq $t4, $zero, Lend_if_0
    lw $t5, 0($sp)
    li $t6, 1
    add $t7, $t5, $t6
    sw $t7, 0($sp)
Lend_if_0:
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    sle $t2, $t0, $t1
    # if condition result in $t2
    beq $t2, $zero, Lend_if_1
    lw $t3, 0($sp)
    li $t4, 10
    add $t5, $t3, $t4
    sw $t5, 0($sp)
Lend_if_1:
    lw $t6, 8($sp)
    lw $t7, 12($sp)
    sgt $t0, $t6, $t7
    # if condition result in $t0
    beq $t0, $zero, Lend_if_2
    lw $t1, 0($sp)
    li $t2, 100
    add $t3, $t1, $t2
    sw $t3, 0($sp)
Lend_if_2:
    lw $t4, 8($sp)
    lw $t5, 12($sp)
    sge $t6, $t4, $t5
    # if condition result in $t6
    beq $t6, $zero, Lend_if_3
    lw $t7, 0($sp)
    li $t0, 1000
    add $t1, $t7, $t0
    sw $t1, 0($sp)
Lend_if_3:
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    seq $t4, $t2, $t3
    # if condition result in $t4
    beq $t4, $zero, Lend_if_4
    lw $t5, 0($sp)
    li $t6, 10000
    add $t7, $t5, $t6
    sw $t7, 0($sp)
Lend_if_4:
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    sne $t2, $t0, $t1
    # if condition result in $t2
    beq $t2, $zero, Lend_if_5
    lw $t3, 0($sp)
    li $t4, 100000
    add $t5, $t3, $t4
    sw $t5, 0($sp)
Lend_if_5:
    lw $t6, 0($sp)
    move $v0, $t6
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testIfElse returns int
testIfElse:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int result at offset 4
    lw $t7, 8($sp)
    li $t0, 0
    sgt $t1, $t7, $t0
    # if condition result in $t1
    beq $t1, $zero, Lend_if_6
    li $t2, 1
    sw $t2, 4($sp)
Lend_if_6:
    lw $t3, 8($sp)
    li $t4, 0
    slt $t5, $t3, $t4
    # if-else condition result in $t5
    beq $t5, $zero, Lelse_7
    li $t6, 1
    li $t7, 0
    sub $t7, $t7, $t6
    sw $t7, 4($sp)
    j Lend_if_7
Lelse_7:
    li $t0, 0
    sw $t0, 4($sp)
Lend_if_7:
    lw $t1, 8($sp)
    li $t2, 100
    sgt $t3, $t1, $t2
    # if-else condition result in $t3
    beq $t3, $zero, Lelse_8
    lw $t4, 8($sp)
    li $t5, 200
    sgt $t6, $t4, $t5
    # if-else condition result in $t6
    beq $t6, $zero, Lelse_9
    li $t7, 200
    sw $t7, 4($sp)
    j Lend_if_9
Lelse_9:
    li $t0, 100
    sw $t0, 4($sp)
Lend_if_9:
    j Lend_if_8
Lelse_8:
    lw $t1, 8($sp)
    li $t2, 50
    sgt $t3, $t1, $t2
    # if-else condition result in $t3
    beq $t3, $zero, Lelse_10
    li $t4, 50
    sw $t4, 4($sp)
    j Lend_if_10
Lelse_10:
    li $t5, 0
    sw $t5, 4($sp)
Lend_if_10:
Lend_if_8:
    lw $t6, 4($sp)
    move $v0, $t6
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testWhileLoop returns int
testWhileLoop:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int sum at offset 8
    # Declared int i at offset 12
    li $t7, 0
    sw $t7, 8($sp)
    li $t0, 1
    sw $t0, 12($sp)
Lwhile_0:
    lw $t1, 12($sp)
    lw $t2, 8($sp)
    sle $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_0
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    add $t2, $t0, $t1
    sw $t2, 8($sp)
    lw $t3, 12($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 12($sp)
    j Lwhile_0
Lend_while_0:
    lw $t6, 8($sp)
    move $v0, $t6
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testNestedLoops returns int
testNestedLoops:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int total at offset 16
    # Declared int i at offset 20
    # Declared int j at offset 24
    li $t7, 0
    sw $t7, 16($sp)
    li $t0, 0
    sw $t0, 20($sp)
Lwhile_1:
    lw $t1, 20($sp)
    lw $t2, 8($sp)
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_1
    li $t0, 0
    sw $t0, 24($sp)
Lwhile_2:
    lw $t1, 24($sp)
    lw $t2, 12($sp)
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_2
    lw $t0, 16($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 16($sp)
    lw $t3, 24($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 24($sp)
    j Lwhile_2
Lend_while_2:
    lw $t6, 20($sp)
    li $t7, 1
    add $t0, $t6, $t7
    sw $t0, 20($sp)
    j Lwhile_1
Lend_while_1:
    lw $t1, 16($sp)
    move $v0, $t1
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testArrayOperations returns void
testArrayOperations:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int i at offset 28
    # Declared int temp at offset 32
    li $t2, 0
    sw $t2, 28($sp)
Lwhile_3:
    lw $t3, 28($sp)
    lw $t4, 12($sp)
    slt $t5, $t3, $t4
    # while condition result in $t5
    beq $t5, $zero, Lend_while_3
    lw $t0, 28($sp)
    li $t1, 2
    mul $t2, $t0, $t1
    sw $t2, 32($sp)
    lw $t3, 32($sp)
    lw $t4, 28($sp)
    # Array assignment: arr[index] = value
    sll $t4, $t4, 2
    add $t4, $t4, $sp
    sw $t3, 8($t4)
    lw $t0, 28($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 28($sp)
    j Lwhile_3
Lend_while_3:
    li $t3, 0
    sw $t3, 28($sp)
Lwhile_4:
    lw $t4, 28($sp)
    lw $t5, 12($sp)
    slt $t6, $t4, $t5
    # while condition result in $t6
    beq $t6, $zero, Lend_while_4
    lw $t0, 28($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    sw $t1, 32($sp)
    lw $t2, 32($sp)
    li $t3, 1
    add $t4, $t2, $t3
    lw $t5, 28($sp)
    # Array assignment: arr[index] = value
    sll $t5, $t5, 2
    add $t5, $t5, $sp
    sw $t4, 8($t5)
    lw $t0, 28($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 28($sp)
    j Lwhile_4
Lend_while_4:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: sumArray returns int
sumArray:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int sum at offset 36
    # Declared int i at offset 40
    li $t3, 0
    sw $t3, 36($sp)
    li $t4, 0
    sw $t4, 40($sp)
Lwhile_5:
    lw $t5, 40($sp)
    lw $t6, 12($sp)
    slt $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_5
    lw $t0, 36($sp)
    lw $t1, 40($sp)
    # Array access: arr[index]
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    lw $t2, 8($t1)
    add $t3, $t0, $t2
    sw $t3, 36($sp)
    lw $t4, 40($sp)
    li $t5, 1
    add $t6, $t4, $t5
    sw $t6, 40($sp)
    j Lwhile_5
Lend_while_5:
    lw $t7, 36($sp)
    move $v0, $t7
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: factorial returns int
factorial:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int result at offset 44
    # Declared int nMinus1 at offset 48
    # Declared int factResult at offset 52
    lw $t0, 8($sp)
    li $t1, 1
    sle $t2, $t0, $t1
    # if-else condition result in $t2
    beq $t2, $zero, Lelse_11
    li $t3, 1
    sw $t3, 44($sp)
    j Lend_if_11
Lelse_11:
    lw $t4, 8($sp)
    li $t5, 1
    sub $t6, $t4, $t5
    sw $t6, 48($sp)
    lw $t7, 48($sp)
    move $a0, $t7
    jal factorial
    move $t0, $v0
    sw $t0, 52($sp)
    lw $t1, 8($sp)
    lw $t2, 52($sp)
    mul $t3, $t1, $t2
    sw $t3, 44($sp)
Lend_if_11:
    lw $t4, 44($sp)
    move $v0, $t4
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: fibonacci returns int
fibonacci:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int result at offset 56
    # Declared int nMinus1 at offset 60
    # Declared int nMinus2 at offset 64
    # Declared int fib1 at offset 68
    # Declared int fib2 at offset 72
    lw $t5, 8($sp)
    li $t6, 1
    sle $t7, $t5, $t6
    # if-else condition result in $t7
    beq $t7, $zero, Lelse_12
    lw $t0, 8($sp)
    sw $t0, 56($sp)
    j Lend_if_12
Lelse_12:
    lw $t1, 8($sp)
    li $t2, 1
    sub $t3, $t1, $t2
    sw $t3, 60($sp)
    lw $t4, 8($sp)
    li $t5, 2
    sub $t6, $t4, $t5
    sw $t6, 64($sp)
    lw $t7, 60($sp)
    move $a0, $t7
    jal fibonacci
    move $t0, $v0
    sw $t0, 68($sp)
    lw $t1, 64($sp)
    move $a0, $t1
    jal fibonacci
    move $t2, $v0
    sw $t2, 72($sp)
    lw $t3, 68($sp)
    lw $t4, 72($sp)
    add $t5, $t3, $t4
    sw $t5, 56($sp)
Lend_if_12:
    lw $t6, 56($sp)
    move $v0, $t6
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: power returns int
power:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int result at offset 76
    # Declared int expMinus1 at offset 80
    # Declared int powerResult at offset 84
    lw $t7, 12($sp)
    li $t0, 0
    seq $t1, $t7, $t0
    # if-else condition result in $t1
    beq $t1, $zero, Lelse_13
    li $t2, 1
    sw $t2, 76($sp)
    j Lend_if_13
Lelse_13:
    lw $t3, 12($sp)
    li $t4, 1
    sub $t5, $t3, $t4
    sw $t5, 80($sp)
    lw $t6, 8($sp)
    move $a0, $t6
    lw $t7, 80($sp)
    move $a1, $t7
    jal power
    move $t0, $v0
    sw $t0, 84($sp)
    lw $t1, 8($sp)
    lw $t2, 84($sp)
    mul $t3, $t1, $t2
    sw $t3, 76($sp)
Lend_if_13:
    lw $t4, 76($sp)
    move $v0, $t4
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: gcd returns int
gcd:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int remainder at offset 88
    # Declared int temp1 at offset 92
    # Declared int temp2 at offset 96
Lwhile_6:
    lw $t5, 12($sp)
    li $t6, 0
    sne $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_6
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    div $t2, $t0, $t1
    sw $t2, 92($sp)
    lw $t3, 92($sp)
    lw $t4, 12($sp)
    mul $t5, $t3, $t4
    sw $t5, 96($sp)
    lw $t6, 8($sp)
    lw $t7, 96($sp)
    sub $t0, $t6, $t7
    sw $t0, 88($sp)
    lw $t1, 12($sp)
    sw $t1, 8($sp)
    lw $t2, 88($sp)
    sw $t2, 12($sp)
    j Lwhile_6
Lend_while_6:
    lw $t3, 8($sp)
    move $v0, $t3
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: linearSearch returns int
linearSearch:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int i at offset 100
    # Declared int found at offset 104
    li $t4, 0
    sw $t4, 100($sp)
    li $t5, 1
    li $t6, 0
    sub $t6, $t6, $t5
    sw $t6, 104($sp)
Lwhile_7:
    lw $t7, 100($sp)
    lw $t0, 12($sp)
    slt $t1, $t7, $t0
    # while condition result in $t1
    beq $t1, $zero, Lend_while_7
    lw $t0, 100($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    lw $t2, 16($sp)
    seq $t3, $t1, $t2
    # if-else condition result in $t3
    beq $t3, $zero, Lelse_14
    lw $t4, 100($sp)
    sw $t4, 104($sp)
    lw $t5, 12($sp)
    sw $t5, 100($sp)
    j Lend_if_14
Lelse_14:
    lw $t6, 100($sp)
    li $t7, 1
    add $t0, $t6, $t7
    sw $t0, 100($sp)
Lend_if_14:
    j Lwhile_7
Lend_while_7:
    lw $t1, 104($sp)
    move $v0, $t1
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: bubbleSort returns void
bubbleSort:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int i at offset 108
    # Declared int j at offset 112
    # Declared int temp at offset 116
    # Declared int limit1 at offset 120
    # Declared int limit2 at offset 124
    # Declared int jPlus1 at offset 128
    li $t2, 0
    sw $t2, 108($sp)
    lw $t3, 12($sp)
    li $t4, 1
    sub $t5, $t3, $t4
    sw $t5, 120($sp)
Lwhile_8:
    lw $t6, 108($sp)
    lw $t7, 120($sp)
    slt $t0, $t6, $t7
    # while condition result in $t0
    beq $t0, $zero, Lend_while_8
    li $t0, 0
    sw $t0, 112($sp)
    lw $t1, 12($sp)
    lw $t2, 108($sp)
    sub $t3, $t1, $t2
    sw $t3, 124($sp)
    lw $t4, 124($sp)
    li $t5, 1
    sub $t6, $t4, $t5
    sw $t6, 124($sp)
Lwhile_9:
    lw $t7, 112($sp)
    lw $t0, 124($sp)
    slt $t1, $t7, $t0
    # while condition result in $t1
    beq $t1, $zero, Lend_while_9
    lw $t0, 112($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 128($sp)
    lw $t3, 112($sp)
    # Array access: arr[index]
    sll $t3, $t3, 2
    add $t3, $t3, $sp
    lw $t4, 8($t3)
    lw $t5, 128($sp)
    # Array access: arr[index]
    sll $t5, $t5, 2
    add $t5, $t5, $sp
    lw $t6, 8($t5)
    sgt $t7, $t4, $t6
    # if condition result in $t7
    beq $t7, $zero, Lend_if_15
    lw $t0, 112($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    sw $t1, 116($sp)
    lw $t2, 128($sp)
    # Array access: arr[index]
    sll $t2, $t2, 2
    add $t2, $t2, $sp
    lw $t3, 8($t2)
    lw $t4, 112($sp)
    # Array assignment: arr[index] = value
    sll $t4, $t4, 2
    add $t4, $t4, $sp
    sw $t3, 8($t4)
    lw $t0, 116($sp)
    lw $t1, 128($sp)
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 8($t1)
Lend_if_15:
    lw $t0, 112($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 112($sp)
    j Lwhile_9
Lend_while_9:
    lw $t3, 108($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 108($sp)
    j Lwhile_8
Lend_while_8:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: findMax returns int
findMax:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int max at offset 132
    # Declared int i at offset 136
    li $t6, 0
    # Array access: arr[index]
    sll $t6, $t6, 2
    add $t6, $t6, $sp
    lw $t7, 8($t6)
    sw $t7, 132($sp)
    li $t0, 1
    sw $t0, 136($sp)
Lwhile_10:
    lw $t1, 136($sp)
    lw $t2, 12($sp)
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_10
    lw $t0, 136($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    lw $t2, 132($sp)
    sgt $t3, $t1, $t2
    # if condition result in $t3
    beq $t3, $zero, Lend_if_16
    lw $t4, 136($sp)
    # Array access: arr[index]
    sll $t4, $t4, 2
    add $t4, $t4, $sp
    lw $t5, 8($t4)
    sw $t5, 132($sp)
Lend_if_16:
    lw $t6, 136($sp)
    li $t7, 1
    add $t0, $t6, $t7
    sw $t0, 136($sp)
    j Lwhile_10
Lend_while_10:
    lw $t1, 132($sp)
    move $v0, $t1
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: findMin returns int
findMin:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int min at offset 140
    # Declared int i at offset 144
    li $t2, 0
    # Array access: arr[index]
    sll $t2, $t2, 2
    add $t2, $t2, $sp
    lw $t3, 8($t2)
    sw $t3, 140($sp)
    li $t4, 1
    sw $t4, 144($sp)
Lwhile_11:
    lw $t5, 144($sp)
    lw $t6, 12($sp)
    slt $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_11
    lw $t0, 144($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    lw $t2, 140($sp)
    slt $t3, $t1, $t2
    # if condition result in $t3
    beq $t3, $zero, Lend_if_17
    lw $t4, 144($sp)
    # Array access: arr[index]
    sll $t4, $t4, 2
    add $t4, $t4, $sp
    lw $t5, 8($t4)
    sw $t5, 140($sp)
Lend_if_17:
    lw $t6, 144($sp)
    li $t7, 1
    add $t0, $t6, $t7
    sw $t0, 144($sp)
    j Lwhile_11
Lend_while_11:
    lw $t1, 140($sp)
    move $v0, $t1
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: isPrime returns int
isPrime:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int i at offset 148
    # Declared int result at offset 152
    # Declared int temp1 at offset 156
    # Declared int temp2 at offset 160
    lw $t2, 8($sp)
    li $t3, 1
    sle $t4, $t2, $t3
    # if-else condition result in $t4
    beq $t4, $zero, Lelse_18
    li $t5, 0
    sw $t5, 152($sp)
    j Lend_if_18
Lelse_18:
    li $t6, 1
    sw $t6, 152($sp)
    li $t7, 2
    sw $t7, 148($sp)
Lwhile_12:
    lw $t0, 148($sp)
    lw $t1, 8($sp)
    slt $t2, $t0, $t1
    # while condition result in $t2
    beq $t2, $zero, Lend_while_12
    lw $t0, 8($sp)
    lw $t1, 148($sp)
    div $t2, $t0, $t1
    sw $t2, 156($sp)
    lw $t3, 156($sp)
    lw $t4, 148($sp)
    mul $t5, $t3, $t4
    sw $t5, 160($sp)
    lw $t6, 160($sp)
    lw $t7, 8($sp)
    seq $t0, $t6, $t7
    # if-else condition result in $t0
    beq $t0, $zero, Lelse_19
    li $t1, 0
    sw $t1, 152($sp)
    lw $t2, 8($sp)
    sw $t2, 148($sp)
    j Lend_if_19
Lelse_19:
    lw $t3, 148($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 148($sp)
Lend_if_19:
    j Lwhile_12
Lend_while_12:
Lend_if_18:
    lw $t6, 152($sp)
    move $v0, $t6
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: countPrimes returns int
countPrimes:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int count at offset 164
    # Declared int i at offset 168
    # Declared int primeCheck at offset 172
    li $t7, 0
    sw $t7, 164($sp)
    li $t0, 2
    sw $t0, 168($sp)
Lwhile_13:
    lw $t1, 168($sp)
    lw $t2, 8($sp)
    sle $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_13
    lw $t0, 168($sp)
    move $a0, $t0
    jal isPrime
    move $t1, $v0
    sw $t1, 172($sp)
    lw $t2, 172($sp)
    li $t3, 1
    seq $t4, $t2, $t3
    # if condition result in $t4
    beq $t4, $zero, Lend_if_20
    lw $t5, 164($sp)
    li $t6, 1
    add $t7, $t5, $t6
    sw $t7, 164($sp)
Lend_if_20:
    lw $t0, 168($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 168($sp)
    j Lwhile_13
Lend_while_13:
    lw $t3, 164($sp)
    move $v0, $t3
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: reverseArray returns void
reverseArray:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int left at offset 176
    # Declared int right at offset 180
    # Declared int temp at offset 184
    li $t4, 0
    sw $t4, 176($sp)
    lw $t5, 12($sp)
    li $t6, 1
    sub $t7, $t5, $t6
    sw $t7, 180($sp)
Lwhile_14:
    lw $t0, 176($sp)
    lw $t1, 180($sp)
    slt $t2, $t0, $t1
    # while condition result in $t2
    beq $t2, $zero, Lend_while_14
    lw $t0, 176($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    sw $t1, 184($sp)
    lw $t2, 180($sp)
    # Array access: arr[index]
    sll $t2, $t2, 2
    add $t2, $t2, $sp
    lw $t3, 8($t2)
    lw $t4, 176($sp)
    # Array assignment: arr[index] = value
    sll $t4, $t4, 2
    add $t4, $t4, $sp
    sw $t3, 8($t4)
    lw $t0, 184($sp)
    lw $t1, 180($sp)
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 8($t1)
    lw $t0, 176($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 176($sp)
    lw $t3, 180($sp)
    li $t4, 1
    sub $t5, $t3, $t4
    sw $t5, 180($sp)
    j Lwhile_14
Lend_while_14:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testComplexExpressions returns int
testComplexExpressions:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int result at offset 188
    # Declared int temp1 at offset 192
    # Declared int temp2 at offset 196
    # Declared int temp3 at offset 200
    # Declared int temp4 at offset 204
    # Declared int temp5 at offset 208
    lw $t6, 12($sp)
    lw $t7, 16($sp)
    mul $t0, $t6, $t7
    sw $t0, 192($sp)
    lw $t1, 8($sp)
    lw $t2, 12($sp)
    div $t3, $t1, $t2
    sw $t3, 196($sp)
    lw $t4, 8($sp)
    lw $t5, 192($sp)
    add $t6, $t4, $t5
    sw $t6, 200($sp)
    lw $t7, 200($sp)
    lw $t0, 196($sp)
    sub $t1, $t7, $t0
    sw $t1, 188($sp)
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    add $t4, $t2, $t3
    sw $t4, 192($sp)
    lw $t5, 16($sp)
    lw $t6, 8($sp)
    sub $t7, $t5, $t6
    sw $t7, 196($sp)
    lw $t0, 192($sp)
    lw $t1, 196($sp)
    mul $t2, $t0, $t1
    sw $t2, 200($sp)
    lw $t3, 12($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 204($sp)
    lw $t6, 200($sp)
    lw $t7, 204($sp)
    div $t0, $t6, $t7
    sw $t0, 188($sp)
    lw $t1, 8($sp)
    lw $t2, 12($sp)
    mul $t3, $t1, $t2
    sw $t3, 192($sp)
    lw $t4, 16($sp)
    lw $t5, 8($sp)
    mul $t6, $t4, $t5
    sw $t6, 196($sp)
    lw $t7, 12($sp)
    lw $t0, 16($sp)
    div $t1, $t7, $t0
    sw $t1, 200($sp)
    lw $t2, 192($sp)
    lw $t3, 196($sp)
    add $t4, $t2, $t3
    sw $t4, 204($sp)
    lw $t5, 204($sp)
    lw $t6, 200($sp)
    sub $t7, $t5, $t6
    sw $t7, 204($sp)
    lw $t0, 204($sp)
    lw $t1, 8($sp)
    add $t2, $t0, $t1
    sw $t2, 204($sp)
    lw $t3, 204($sp)
    lw $t4, 12($sp)
    sub $t5, $t3, $t4
    sw $t5, 204($sp)
    lw $t6, 204($sp)
    lw $t7, 16($sp)
    add $t0, $t6, $t7
    sw $t0, 188($sp)
    lw $t1, 188($sp)
    move $v0, $t1
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: testVoidFunction returns void
testVoidFunction:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int y at offset 212
    lw $t2, 8($sp)
    li $t3, 2
    mul $t4, $t2, $t3
    sw $t4, 212($sp)
    lw $t5, 212($sp)
    # Print integer
    move $a0, $t5
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

# Function: printArray returns void
printArray:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int i at offset 216
    li $t0, 0
    sw $t0, 216($sp)
Lwhile_15:
    lw $t1, 216($sp)
    lw $t2, 12($sp)
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_15
    lw $t0, 216($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    # Print integer
    move $a0, $t1
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 216($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 216($sp)
    j Lwhile_15
Lend_while_15:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: multiply3 returns int
multiply3:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int temp at offset 220
    # Declared int result at offset 224
    lw $t3, 8($sp)
    lw $t4, 12($sp)
    mul $t5, $t3, $t4
    sw $t5, 220($sp)
    lw $t6, 220($sp)
    lw $t7, 16($sp)
    mul $t0, $t6, $t7
    sw $t0, 224($sp)
    lw $t1, 224($sp)
    move $v0, $t1
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: add4 returns int
add4:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    sw $a3, 20($sp)
    # Declared int temp1 at offset 228
    # Declared int temp2 at offset 232
    # Declared int result at offset 236
    lw $t2, 8($sp)
    lw $t3, 12($sp)
    add $t4, $t2, $t3
    sw $t4, 228($sp)
    lw $t5, 16($sp)
    lw $t6, 20($sp)
    add $t7, $t5, $t6
    sw $t7, 232($sp)
    lw $t0, 228($sp)
    lw $t1, 232($sp)
    add $t2, $t0, $t1
    sw $t2, 236($sp)
    lw $t3, 236($sp)
    move $v0, $t3
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: max3 returns int
max3:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int max at offset 240
    lw $t4, 8($sp)
    sw $t4, 240($sp)
    lw $t5, 12($sp)
    lw $t6, 240($sp)
    sgt $t7, $t5, $t6
    # if condition result in $t7
    beq $t7, $zero, Lend_if_21
    lw $t0, 12($sp)
    sw $t0, 240($sp)
Lend_if_21:
    lw $t1, 16($sp)
    lw $t2, 240($sp)
    sgt $t3, $t1, $t2
    # if condition result in $t3
    beq $t3, $zero, Lend_if_22
    lw $t4, 16($sp)
    sw $t4, 240($sp)
Lend_if_22:
    lw $t5, 240($sp)
    move $v0, $t5
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: fillArray returns void
fillArray:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int i at offset 244
    li $t6, 0
    sw $t6, 244($sp)
Lwhile_16:
    lw $t7, 244($sp)
    lw $t0, 12($sp)
    slt $t1, $t7, $t0
    # while condition result in $t1
    beq $t1, $zero, Lend_while_16
    lw $t0, 16($sp)
    lw $t1, 244($sp)
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 8($t1)
    lw $t0, 244($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 244($sp)
    j Lwhile_16
Lend_while_16:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: copyArray returns void
copyArray:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int i at offset 248
    li $t3, 0
    sw $t3, 248($sp)
Lwhile_17:
    lw $t4, 248($sp)
    lw $t5, 16($sp)
    slt $t6, $t4, $t5
    # while condition result in $t6
    beq $t6, $zero, Lend_while_17
    lw $t0, 248($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    lw $t2, 248($sp)
    # Array assignment: arr[index] = value
    sll $t2, $t2, 2
    add $t2, $t2, $sp
    sw $t1, 12($t2)
    lw $t0, 248($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 248($sp)
    j Lwhile_17
Lend_while_17:
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: arrayEqual returns int
arrayEqual:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int i at offset 252
    # Declared int equal at offset 256
    li $t3, 1
    sw $t3, 256($sp)
    li $t4, 0
    sw $t4, 252($sp)
Lwhile_18:
    lw $t5, 252($sp)
    lw $t6, 16($sp)
    slt $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_18
    lw $t0, 252($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    lw $t2, 252($sp)
    # Array access: arr[index]
    sll $t2, $t2, 2
    add $t2, $t2, $sp
    lw $t3, 12($t2)
    sne $t4, $t1, $t3
    # if-else condition result in $t4
    beq $t4, $zero, Lelse_23
    li $t5, 0
    sw $t5, 256($sp)
    lw $t6, 16($sp)
    sw $t6, 252($sp)
    j Lend_if_23
Lelse_23:
    lw $t7, 252($sp)
    li $t0, 1
    add $t1, $t7, $t0
    sw $t1, 252($sp)
Lend_if_23:
    j Lwhile_18
Lend_while_18:
    lw $t2, 256($sp)
    move $v0, $t2
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: absoluteValue returns int
absoluteValue:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int result at offset 260
    # Declared int negX at offset 264
    lw $t3, 8($sp)
    li $t4, 0
    slt $t5, $t3, $t4
    # if-else condition result in $t5
    beq $t5, $zero, Lelse_24
    li $t6, 0
    lw $t7, 8($sp)
    sub $t0, $t6, $t7
    sw $t0, 264($sp)
    lw $t1, 264($sp)
    sw $t1, 260($sp)
    j Lend_if_24
Lelse_24:
    lw $t2, 8($sp)
    sw $t2, 260($sp)
Lend_if_24:
    lw $t3, 260($sp)
    move $v0, $t3
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: sign returns int
sign:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int result at offset 268
    lw $t4, 8($sp)
    li $t5, 0
    slt $t6, $t4, $t5
    # if-else condition result in $t6
    beq $t6, $zero, Lelse_25
    li $t7, 1
    li $t0, 0
    sub $t0, $t0, $t7
    sw $t0, 268($sp)
    j Lend_if_25
Lelse_25:
    lw $t1, 8($sp)
    li $t2, 0
    sgt $t3, $t1, $t2
    # if-else condition result in $t3
    beq $t3, $zero, Lelse_26
    li $t4, 1
    sw $t4, 268($sp)
    j Lend_if_26
Lelse_26:
    li $t5, 0
    sw $t5, 268($sp)
Lend_if_26:
Lend_if_25:
    lw $t6, 268($sp)
    move $v0, $t6
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: sumOfSquares returns int
sumOfSquares:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int sum at offset 272
    # Declared int i at offset 276
    # Declared int iSquared at offset 280
    li $t7, 0
    sw $t7, 272($sp)
    li $t0, 1
    sw $t0, 276($sp)
Lwhile_19:
    lw $t1, 276($sp)
    lw $t2, 8($sp)
    sle $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_19
    lw $t0, 276($sp)
    lw $t1, 276($sp)
    mul $t2, $t0, $t1
    sw $t2, 280($sp)
    lw $t3, 272($sp)
    lw $t4, 280($sp)
    add $t5, $t3, $t4
    sw $t5, 272($sp)
    lw $t6, 276($sp)
    li $t7, 1
    add $t0, $t6, $t7
    sw $t0, 276($sp)
    j Lwhile_19
Lend_while_19:
    lw $t1, 272($sp)
    move $v0, $t1
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: sumOfCubes returns int
sumOfCubes:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int sum at offset 284
    # Declared int i at offset 288
    # Declared int iSquared at offset 292
    # Declared int iCubed at offset 296
    li $t2, 0
    sw $t2, 284($sp)
    li $t3, 1
    sw $t3, 288($sp)
Lwhile_20:
    lw $t4, 288($sp)
    lw $t5, 8($sp)
    sle $t6, $t4, $t5
    # while condition result in $t6
    beq $t6, $zero, Lend_while_20
    lw $t0, 288($sp)
    lw $t1, 288($sp)
    mul $t2, $t0, $t1
    sw $t2, 292($sp)
    lw $t3, 292($sp)
    lw $t4, 288($sp)
    mul $t5, $t3, $t4
    sw $t5, 296($sp)
    lw $t6, 284($sp)
    lw $t7, 296($sp)
    add $t0, $t6, $t7
    sw $t0, 284($sp)
    lw $t1, 288($sp)
    li $t2, 1
    add $t3, $t1, $t2
    sw $t3, 288($sp)
    j Lwhile_20
Lend_while_20:
    lw $t4, 284($sp)
    move $v0, $t4
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: calculateMean returns int
calculateMean:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int sum at offset 300
    # Declared int i at offset 304
    li $t5, 0
    sw $t5, 300($sp)
    li $t6, 0
    sw $t6, 304($sp)
Lwhile_21:
    lw $t7, 304($sp)
    lw $t0, 12($sp)
    slt $t1, $t7, $t0
    # while condition result in $t1
    beq $t1, $zero, Lend_while_21
    lw $t0, 300($sp)
    lw $t1, 304($sp)
    # Array access: arr[index]
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    lw $t2, 8($t1)
    add $t3, $t0, $t2
    sw $t3, 300($sp)
    lw $t4, 304($sp)
    li $t5, 1
    add $t6, $t4, $t5
    sw $t6, 304($sp)
    j Lwhile_21
Lend_while_21:
    lw $t7, 300($sp)
    lw $t0, 12($sp)
    div $t1, $t7, $t0
    move $v0, $t1
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: countOccurrences returns int
countOccurrences:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int count at offset 308
    # Declared int i at offset 312
    li $t2, 0
    sw $t2, 308($sp)
    li $t3, 0
    sw $t3, 312($sp)
Lwhile_22:
    lw $t4, 312($sp)
    lw $t5, 12($sp)
    slt $t6, $t4, $t5
    # while condition result in $t6
    beq $t6, $zero, Lend_while_22
    lw $t0, 312($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    lw $t2, 16($sp)
    seq $t3, $t1, $t2
    # if condition result in $t3
    beq $t3, $zero, Lend_if_27
    lw $t4, 308($sp)
    li $t5, 1
    add $t6, $t4, $t5
    sw $t6, 308($sp)
Lend_if_27:
    lw $t7, 312($sp)
    li $t0, 1
    add $t1, $t7, $t0
    sw $t1, 312($sp)
    j Lwhile_22
Lend_while_22:
    lw $t2, 308($sp)
    move $v0, $t2
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: leftShift returns int
leftShift:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int result at offset 316
    # Declared int i at offset 320
    lw $t3, 8($sp)
    sw $t3, 316($sp)
    li $t4, 0
    sw $t4, 320($sp)
Lwhile_23:
    lw $t5, 320($sp)
    lw $t6, 12($sp)
    slt $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_23
    lw $t0, 316($sp)
    li $t1, 2
    mul $t2, $t0, $t1
    sw $t2, 316($sp)
    lw $t3, 320($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 320($sp)
    j Lwhile_23
Lend_while_23:
    lw $t6, 316($sp)
    move $v0, $t6
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: rightShift returns int
rightShift:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int result at offset 324
    # Declared int i at offset 328
    lw $t7, 8($sp)
    sw $t7, 324($sp)
    li $t0, 0
    sw $t0, 328($sp)
Lwhile_24:
    lw $t1, 328($sp)
    lw $t2, 12($sp)
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_24
    lw $t0, 324($sp)
    li $t1, 2
    div $t2, $t0, $t1
    sw $t2, 324($sp)
    lw $t3, 328($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 328($sp)
    j Lwhile_24
Lend_while_24:
    lw $t6, 324($sp)
    move $v0, $t6
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: arrayLength returns int
arrayLength:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int length at offset 332
    li $t7, 0
    sw $t7, 332($sp)
Lwhile_25:
    lw $t0, 332($sp)
    lw $t1, 12($sp)
    slt $t2, $t0, $t1
    # while condition result in $t2
    beq $t2, $zero, Lend_while_25
    lw $t0, 332($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 8($t0)
    li $t2, 0
    seq $t3, $t1, $t2
    # if-else condition result in $t3
    beq $t3, $zero, Lelse_28
    lw $t4, 12($sp)
    sw $t4, 332($sp)
    j Lend_if_28
Lelse_28:
    lw $t5, 332($sp)
    li $t6, 1
    add $t7, $t5, $t6
    sw $t7, 332($sp)
Lend_if_28:
    j Lwhile_25
Lend_while_25:
    lw $t0, 332($sp)
    move $v0, $t0
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
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
    # Declared array testArray[10] at offset 336
    # Declared array testArray2[10] at offset 376
    # Declared int i at offset 416
    # Declared int result at offset 420
    # Declared int a at offset 424
    # Declared int b at offset 428
    # Declared int choice at offset 432
    # Declared int temp at offset 436
    li $t1, 0
    sw $t1, 0($sp)
    li $t2, 1
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 10
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal testArithmetic
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 2
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    move $a0, $t0
    li $t1, 10
    move $a1, $t1
    jal testRelational
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 3
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 75
    move $a0, $t0
    jal testIfElse
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 4
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 10
    move $a0, $t0
    jal testWhileLoop
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal testNestedLoops
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 6
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 336($sp)
    move $a0, $t0
    li $t1, 10
    move $a1, $t1
    jal testArrayOperations
    move $t2, $v0
    lw $t0, 336($sp)
    move $a0, $t0
    li $t1, 10
    move $a1, $t1
    jal sumArray
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 7
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    move $a0, $t0
    jal factorial
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 8
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 7
    move $a0, $t0
    jal fibonacci
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 9
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 2
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal power
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 10
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 48
    move $a0, $t0
    li $t1, 18
    move $a1, $t1
    jal gcd
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 11
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 0
    sw $t0, 416($sp)
Lwhile_26:
    lw $t1, 416($sp)
    li $t2, 10
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_26
    lw $t0, 416($sp)
    li $t1, 3
    mul $t2, $t0, $t1
    sw $t2, 436($sp)
    lw $t3, 436($sp)
    lw $t4, 416($sp)
    # Array assignment: arr[index] = value
    sll $t4, $t4, 2
    add $t4, $t4, $sp
    sw $t3, 336($t4)
    lw $t0, 416($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 416($sp)
    j Lwhile_26
Lend_while_26:
    move $a0, $t2
    li $t3, 15
    move $a1, $t3
    jal linearSearch
    move $t4, $v0
    sw $t4, 420($sp)
    lw $t5, 420($sp)
    # Print integer
    move $a0, $t5
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 12
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    li $t1, 0
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 336($t1)
    li $t0, 2
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 336($t1)
    li $t0, 8
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 336($t1)
    li $t0, 1
    li $t1, 3
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 336($t1)
    li $t0, 9
    li $t1, 4
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 336($t1)
    lw $t0, 336($sp)
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal bubbleSort
    move $t2, $v0
    lw $t0, 336($sp)
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal printArray
    move $t2, $v0
    li $t0, 13
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 336($sp)
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal findMax
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 336($sp)
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal findMin
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 14
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 17
    move $a0, $t0
    jal isPrime
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 18
    move $a0, $t0
    jal isPrime
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 15
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 20
    move $a0, $t0
    jal countPrimes
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 16
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 0
    sw $t0, 416($sp)
Lwhile_27:
    lw $t1, 416($sp)
    li $t2, 5
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_27
    lw $t0, 416($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 436($sp)
    lw $t3, 436($sp)
    lw $t4, 416($sp)
    # Array assignment: arr[index] = value
    sll $t4, $t4, 2
    add $t4, $t4, $sp
    sw $t3, 336($t4)
    lw $t0, 416($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 416($sp)
    j Lwhile_27
Lend_while_27:
    lw $t3, 336($sp)
    move $a0, $t3
    li $t4, 5
    move $a1, $t4
    jal reverseArray
    move $t5, $v0
    lw $t0, 336($sp)
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal printArray
    move $t2, $v0
    li $t0, 17
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    move $a0, $t7
    li $t0, 4
    move $a1, $t0
    jal multiply3
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    move $a0, $t7
    li $t0, 4
    move $a1, $t0
    jal add4
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    move $a0, $t7
    li $t0, 3
    move $a1, $t0
    jal max3
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 18
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    move $a0, $t7
    li $t0, 7
    move $a1, $t0
    jal fillArray
    move $t1, $v0
    move $a0, $t7
    li $t0, 10
    move $a1, $t0
    jal copyArray
    move $t1, $v0
    move $a0, $t7
    li $t0, 10
    move $a1, $t0
    jal arrayEqual
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 19
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 15
    li $t1, 0
    sub $t1, $t1, $t0
    move $a0, $t1
    jal absoluteValue
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    li $t1, 0
    sub $t1, $t1, $t0
    move $a0, $t1
    jal sign
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    move $a0, $t0
    jal sign
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 0
    move $a0, $t0
    jal sign
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 20
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    move $a0, $t0
    jal sumOfSquares
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    move $a0, $t0
    jal sumOfCubes
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 21
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 0
    sw $t0, 416($sp)
Lwhile_28:
    lw $t1, 416($sp)
    li $t2, 5
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_28
    lw $t0, 416($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 436($sp)
    lw $t3, 436($sp)
    li $t4, 2
    mul $t5, $t3, $t4
    sw $t5, 436($sp)
    lw $t6, 436($sp)
    lw $t7, 416($sp)
    # Array assignment: arr[index] = value
    sll $t7, $t7, 2
    add $t7, $t7, $sp
    sw $t6, 336($t7)
    lw $t0, 416($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 416($sp)
    j Lwhile_28
Lend_while_28:
    lw $t3, 336($sp)
    move $a0, $t3
    li $t4, 5
    move $a1, $t4
    jal calculateMean
    move $t5, $v0
    sw $t5, 420($sp)
    lw $t6, 420($sp)
    # Print integer
    move $a0, $t6
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    li $t1, 0
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 336($t1)
    li $t0, 5
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 336($t1)
    li $t0, 3
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 336($t1)
    li $t0, 5
    li $t1, 3
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 336($t1)
    li $t0, 7
    li $t1, 4
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 336($t1)
    move $a0, $t7
    li $t0, 5
    move $a1, $t0
    jal countOccurrences
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 22
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 3
    move $a0, $t0
    li $t1, 2
    move $a1, $t1
    jal leftShift
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 16
    move $a0, $t0
    li $t1, 2
    move $a1, $t1
    jal rightShift
    move $t2, $v0
    sw $t2, 420($sp)
    lw $t3, 420($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 23
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    move $a0, $t7
    li $t0, 3
    move $a1, $t0
    jal testComplexExpressions
    move $t1, $v0
    sw $t1, 420($sp)
    lw $t2, 420($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 24
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 100
    sw $t0, 0($sp)
    li $t1, 10
    li $t2, 0
    # Array assignment: arr[index] = value
    sll $t2, $t2, 2
    add $t2, $t2, $s7
    sw $t1, 4($t2)
    li $t0, 20
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $s7
    sw $t0, 4($t1)
    li $t0, 30
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $s7
    sw $t0, 4($t1)
    lw $t0, 0($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 0
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t1, 4($t0)
    li $t2, 1
    # Array access: arr[index]
    sll $t2, $t2, 2
    add $t2, $t2, $sp
    lw $t3, 4($t2)
    add $t4, $t1, $t3
    sw $t4, 436($sp)
    lw $t5, 436($sp)
    li $t6, 2
    # Array access: arr[index]
    sll $t6, $t6, 2
    add $t6, $t6, $sp
    lw $t7, 4($t6)
    add $t0, $t5, $t7
    sw $t0, 436($sp)
    lw $t1, 436($sp)
    # Print integer
    move $a0, $t1
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 25
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 5
    move $a0, $t0
    jal testVoidFunction
    move $t1, $v0
    li $t0, 999
    # Print integer
    move $a0, $t0
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
