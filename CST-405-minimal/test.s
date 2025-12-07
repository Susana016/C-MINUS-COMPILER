.data

.text
.globl main

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
    beq $t5, $zero, Lelse_0
    li $t6, 1
    li $t7, 0
    sub $t7, $t7, $t6
    sw $t7, 4($sp)
    j Lend_if_0
Lelse_0:
    li $t0, 0
    sw $t0, 4($sp)
Lend_if_0:
    lw $t1, 8($sp)
    li $t2, 100
    sgt $t3, $t1, $t2
    # if-else condition result in $t3
    beq $t3, $zero, Lelse_1
    lw $t4, 8($sp)
    li $t5, 200
    sgt $t6, $t4, $t5
    # if-else condition result in $t6
    beq $t6, $zero, Lelse_2
    li $t7, 200
    sw $t7, 4($sp)
    j Lend_if_2
Lelse_2:
    li $t0, 100
    sw $t0, 4($sp)
Lend_if_2:
    j Lend_if_1
Lelse_1:
    lw $t1, 8($sp)
    li $t2, 50
    sgt $t3, $t1, $t2
    # if-else condition result in $t3
    beq $t3, $zero, Lelse_3
    li $t4, 50
    sw $t4, 4($sp)
    j Lend_if_3
Lelse_3:
    li $t5, 0
    sw $t5, 4($sp)
Lend_if_3:
Lend_if_1:
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
    beq $t2, $zero, Lelse_4
    li $t3, 1
    sw $t3, 44($sp)
    j Lend_if_4
Lelse_4:
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
Lend_if_4:
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
    beq $t7, $zero, Lelse_5
    lw $t0, 8($sp)
    sw $t0, 56($sp)
    j Lend_if_5
Lelse_5:
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
Lend_if_5:
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
    beq $t1, $zero, Lelse_6
    li $t2, 1
    sw $t2, 76($sp)
    j Lend_if_6
Lelse_6:
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
Lend_if_6:
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
