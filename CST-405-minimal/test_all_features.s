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
    # Global int globalX at offset 0
    # Global int globalY at offset 4
    # Global array globalArray[10] at offset 8

# Function: testArithmetic returns int
testArithmetic:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int sum at offset 16
    # Declared int diff at offset 20
    # Declared int prod at offset 24
    # Declared int quot at offset 28
    # Declared int mod at offset 32
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    add $t2, $t0, $t1
    sw $t2, 16($sp)
    lw $t3, 8($sp)
    lw $t4, 12($sp)
    sub $t5, $t3, $t4
    sw $t5, 20($sp)
    lw $t6, 8($sp)
    lw $t7, 12($sp)
    mul $t0, $t6, $t7
    sw $t0, 24($sp)
    lw $t1, 8($sp)
    lw $t2, 12($sp)
    div $t3, $t1, $t2
    sw $t3, 28($sp)
    lw $t4, 8($sp)
    lw $t5, 12($sp)
    rem $t6, $t4, $t5
    sw $t6, 32($sp)
    lw $t7, 16($sp)
    lw $t0, 20($sp)
    add $t1, $t7, $t0
    lw $t2, 24($sp)
    add $t3, $t1, $t2
    lw $t4, 28($sp)
    add $t5, $t3, $t4
    move $v0, $t5
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: testRelational returns int
testRelational:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int result at offset 16
    li $t6, 0
    sw $t6, 16($sp)
    lw $t7, 8($sp)
    lw $t0, 12($sp)
    slt $t1, $t7, $t0
    # if condition result in $t1
    beq $t1, $zero, Lend_if_0
    lw $t2, 16($sp)
    li $t3, 1
    add $t4, $t2, $t3
    sw $t4, 16($sp)
Lend_if_0:
    lw $t5, 8($sp)
    lw $t6, 12($sp)
    sle $t7, $t5, $t6
    # if condition result in $t7
    beq $t7, $zero, Lend_if_1
    lw $t0, 16($sp)
    li $t1, 10
    add $t2, $t0, $t1
    sw $t2, 16($sp)
Lend_if_1:
    lw $t3, 8($sp)
    lw $t4, 12($sp)
    sgt $t5, $t3, $t4
    # if condition result in $t5
    beq $t5, $zero, Lend_if_2
    lw $t6, 16($sp)
    li $t7, 100
    add $t0, $t6, $t7
    sw $t0, 16($sp)
Lend_if_2:
    lw $t1, 8($sp)
    lw $t2, 12($sp)
    sge $t3, $t1, $t2
    # if condition result in $t3
    beq $t3, $zero, Lend_if_3
    lw $t4, 16($sp)
    li $t5, 1000
    add $t6, $t4, $t5
    sw $t6, 16($sp)
Lend_if_3:
    lw $t7, 8($sp)
    lw $t0, 12($sp)
    seq $t1, $t7, $t0
    # if condition result in $t1
    beq $t1, $zero, Lend_if_4
    lw $t2, 16($sp)
    li $t3, 10000
    add $t4, $t2, $t3
    sw $t4, 16($sp)
Lend_if_4:
    lw $t5, 8($sp)
    lw $t6, 12($sp)
    sne $t7, $t5, $t6
    # if condition result in $t7
    beq $t7, $zero, Lend_if_5
    lw $t0, 16($sp)
    li $t1, 100000
    add $t2, $t0, $t1
    sw $t2, 16($sp)
Lend_if_5:
    lw $t3, 16($sp)
    move $v0, $t3
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: testIfElse returns int
testIfElse:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int result at offset 12
    lw $t4, 8($sp)
    li $t5, 50
    sgt $t6, $t4, $t5
    # if-else condition result in $t6
    beq $t6, $zero, Lelse_6
    li $t7, 1
    sw $t7, 12($sp)
    j Lend_if_6
Lelse_6:
    li $t0, 0
    sw $t0, 12($sp)
Lend_if_6:
    lw $t1, 8($sp)
    li $t2, 100
    sgt $t3, $t1, $t2
    # if-else condition result in $t3
    beq $t3, $zero, Lelse_7
    li $t4, 100
    sw $t4, 12($sp)
    j Lend_if_7
Lelse_7:
    lw $t5, 8($sp)
    li $t6, 50
    sgt $t7, $t5, $t6
    # if-else condition result in $t7
    beq $t7, $zero, Lelse_8
    li $t0, 50
    sw $t0, 12($sp)
    j Lend_if_8
Lelse_8:
    li $t1, 0
    sw $t1, 12($sp)
Lend_if_8:
Lend_if_7:
    lw $t2, 12($sp)
    move $v0, $t2
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: testWhileLoop returns int
testWhileLoop:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int sum at offset 12
    # Declared int i at offset 16
    li $t3, 0
    sw $t3, 12($sp)
    li $t4, 1
    sw $t4, 16($sp)
Lwhile_0:
    lw $t5, 16($sp)
    lw $t6, 8($sp)
    sle $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_0
    lw $t0, 12($sp)
    lw $t1, 16($sp)
    add $t2, $t0, $t1
    sw $t2, 12($sp)
    lw $t3, 16($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 16($sp)
    j Lwhile_0
Lend_while_0:
    lw $t6, 12($sp)
    move $v0, $t6
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: testNestedLoops returns int
testNestedLoops:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
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
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: testLocalArray returns int
testLocalArray:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    # Declared array arr[5] at offset 8
    # Declared int i at offset 28
    # Declared int sum at offset 32
    li $t2, 0
    sw $t2, 28($sp)
Lwhile_3:
    lw $t3, 28($sp)
    li $t4, 5
    slt $t5, $t3, $t4
    # while condition result in $t5
    beq $t5, $zero, Lend_while_3
    lw $t0, 28($sp)
    li $t1, 2
    mul $t2, $t0, $t1
    lw $t3, 28($sp)
    # Array assignment: arr[index] = value
    sll $t3, $t3, 2
    add $t3, $t3, $sp
    sw $t2, 8($t3)
    lw $t0, 28($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 28($sp)
    j Lwhile_3
Lend_while_3:
    li $t3, 0
    sw $t3, 32($sp)
    li $t4, 0
    sw $t4, 28($sp)
Lwhile_4:
    lw $t5, 28($sp)
    li $t6, 5
    slt $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_4
    lw $t0, 32($sp)
    lw $t1, 28($sp)
    # Array access: arr[index]
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    lw $t2, 8($t1)
    add $t3, $t0, $t2
    sw $t3, 32($sp)
    lw $t4, 28($sp)
    li $t5, 1
    add $t6, $t4, $t5
    sw $t6, 28($sp)
    j Lwhile_4
Lend_while_4:
    lw $t7, 32($sp)
    move $v0, $t7
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: fillArray returns void
fillArray:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int i at offset 16
    li $t0, 0
    sw $t0, 16($sp)
Lwhile_5:
    lw $t1, 16($sp)
    lw $t2, 12($sp)
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_5
    lw $t0, 16($sp)
    li $t1, 1
    add $t2, $t0, $t1
    lw $t3, 16($sp)
    # Array assignment: arr[index] = value
    sll $t3, $t3, 2
    lw $t4, 8($sp)
    add $t3, $t3, $t4
    sw $t2, 0($t3)
    lw $t0, 16($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 16($sp)
    j Lwhile_5
Lend_while_5:
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: sumArray returns int
sumArray:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int sum at offset 16
    # Declared int i at offset 20
    li $t3, 0
    sw $t3, 16($sp)
    li $t4, 0
    sw $t4, 20($sp)
Lwhile_6:
    lw $t5, 20($sp)
    lw $t6, 12($sp)
    slt $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_6
    lw $t0, 16($sp)
    lw $t1, 20($sp)
    # Array access: arr[index]
    sll $t1, $t1, 2
    lw $t2, 8($sp)
    add $t1, $t1, $t2
    lw $t2, 0($t1)
    add $t3, $t0, $t2
    sw $t3, 16($sp)
    lw $t4, 20($sp)
    li $t5, 1
    add $t6, $t4, $t5
    sw $t6, 20($sp)
    j Lwhile_6
Lend_while_6:
    lw $t7, 16($sp)
    move $v0, $t7
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: factorial returns int
factorial:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int result at offset 12
    # Declared int temp at offset 16
    lw $t0, 8($sp)
    li $t1, 1
    sle $t2, $t0, $t1
    # if-else condition result in $t2
    beq $t2, $zero, Lelse_9
    li $t3, 1
    sw $t3, 12($sp)
    j Lend_if_9
Lelse_9:
    lw $t4, 8($sp)
    li $t5, 1
    sub $t6, $t4, $t5
    sw $t6, 16($sp)
    lw $t7, 8($sp)
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    lw $t0, 16($sp)
    move $a0, $t0
    jal factorial
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    mul $t2, $t7, $t1
    sw $t2, 12($sp)
Lend_if_9:
    lw $t3, 12($sp)
    move $v0, $t3
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: fibonacci returns int
fibonacci:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int result at offset 12
    # Declared int n1 at offset 16
    # Declared int n2 at offset 20
    lw $t4, 8($sp)
    li $t5, 1
    sle $t6, $t4, $t5
    # if-else condition result in $t6
    beq $t6, $zero, Lelse_10
    lw $t7, 8($sp)
    sw $t7, 12($sp)
    j Lend_if_10
Lelse_10:
    lw $t0, 8($sp)
    li $t1, 1
    sub $t2, $t0, $t1
    sw $t2, 16($sp)
    lw $t3, 8($sp)
    li $t4, 2
    sub $t5, $t3, $t4
    sw $t5, 20($sp)
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    lw $t6, 16($sp)
    move $a0, $t6
    jal fibonacci
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t7, $v0
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    lw $t0, 20($sp)
    move $a0, $t0
    jal fibonacci
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    add $t2, $t7, $t1
    sw $t2, 12($sp)
Lend_if_10:
    lw $t3, 12($sp)
    move $v0, $t3
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: power returns int
power:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int result at offset 16
    # Declared int temp at offset 20
    lw $t4, 12($sp)
    li $t5, 0
    seq $t6, $t4, $t5
    # if-else condition result in $t6
    beq $t6, $zero, Lelse_11
    li $t7, 1
    sw $t7, 16($sp)
    j Lend_if_11
Lelse_11:
    lw $t0, 12($sp)
    li $t1, 1
    sub $t2, $t0, $t1
    sw $t2, 20($sp)
    lw $t3, 8($sp)
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    lw $t4, 8($sp)
    move $a0, $t4
    lw $t5, 20($sp)
    move $a1, $t5
    jal power
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t6, $v0
    mul $t7, $t3, $t6
    sw $t7, 16($sp)
Lend_if_11:
    lw $t0, 16($sp)
    move $v0, $t0
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: gcd returns int
gcd:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int temp at offset 16
    # Declared int remainder at offset 20
Lwhile_7:
    lw $t1, 12($sp)
    li $t2, 0
    sne $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_7
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    div $t2, $t0, $t1
    sw $t2, 16($sp)
    lw $t3, 8($sp)
    lw $t4, 16($sp)
    lw $t5, 12($sp)
    mul $t6, $t4, $t5
    sub $t7, $t3, $t6
    sw $t7, 20($sp)
    lw $t0, 12($sp)
    sw $t0, 8($sp)
    lw $t1, 20($sp)
    sw $t1, 12($sp)
    j Lwhile_7
Lend_while_7:
    lw $t2, 8($sp)
    move $v0, $t2
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: findMax returns int
findMax:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int max at offset 16
    # Declared int i at offset 20
    li $t3, 0
    # Array access: arr[index]
    sll $t3, $t3, 2
    lw $t4, 8($sp)
    add $t3, $t3, $t4
    lw $t4, 0($t3)
    sw $t4, 16($sp)
    li $t5, 1
    sw $t5, 20($sp)
Lwhile_8:
    lw $t6, 20($sp)
    lw $t7, 12($sp)
    slt $t0, $t6, $t7
    # while condition result in $t0
    beq $t0, $zero, Lend_while_8
    lw $t0, 20($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    lw $t1, 8($sp)
    add $t0, $t0, $t1
    lw $t1, 0($t0)
    lw $t2, 16($sp)
    sgt $t3, $t1, $t2
    # if condition result in $t3
    beq $t3, $zero, Lend_if_12
    lw $t4, 20($sp)
    # Array access: arr[index]
    sll $t4, $t4, 2
    lw $t5, 8($sp)
    add $t4, $t4, $t5
    lw $t5, 0($t4)
    sw $t5, 16($sp)
Lend_if_12:
    lw $t6, 20($sp)
    li $t7, 1
    add $t0, $t6, $t7
    sw $t0, 20($sp)
    j Lwhile_8
Lend_while_8:
    lw $t1, 16($sp)
    move $v0, $t1
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: findMin returns int
findMin:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int min at offset 16
    # Declared int i at offset 20
    li $t2, 0
    # Array access: arr[index]
    sll $t2, $t2, 2
    lw $t3, 8($sp)
    add $t2, $t2, $t3
    lw $t3, 0($t2)
    sw $t3, 16($sp)
    li $t4, 1
    sw $t4, 20($sp)
Lwhile_9:
    lw $t5, 20($sp)
    lw $t6, 12($sp)
    slt $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_9
    lw $t0, 20($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    lw $t1, 8($sp)
    add $t0, $t0, $t1
    lw $t1, 0($t0)
    lw $t2, 16($sp)
    slt $t3, $t1, $t2
    # if condition result in $t3
    beq $t3, $zero, Lend_if_13
    lw $t4, 20($sp)
    # Array access: arr[index]
    sll $t4, $t4, 2
    lw $t5, 8($sp)
    add $t4, $t4, $t5
    lw $t5, 0($t4)
    sw $t5, 16($sp)
Lend_if_13:
    lw $t6, 20($sp)
    li $t7, 1
    add $t0, $t6, $t7
    sw $t0, 20($sp)
    j Lwhile_9
Lend_while_9:
    lw $t1, 16($sp)
    move $v0, $t1
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: isPrime returns int
isPrime:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int i at offset 12
    # Declared int temp at offset 16
    # Declared int result at offset 20
    lw $t2, 8($sp)
    li $t3, 1
    sle $t4, $t2, $t3
    # if-else condition result in $t4
    beq $t4, $zero, Lelse_14
    li $t5, 0
    sw $t5, 20($sp)
    j Lend_if_14
Lelse_14:
    li $t6, 1
    sw $t6, 20($sp)
    li $t7, 2
    sw $t7, 12($sp)
Lwhile_10:
    lw $t0, 12($sp)
    lw $t1, 8($sp)
    slt $t2, $t0, $t1
    # while condition result in $t2
    beq $t2, $zero, Lend_while_10
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    div $t2, $t0, $t1
    sw $t2, 16($sp)
    lw $t3, 16($sp)
    lw $t4, 12($sp)
    mul $t5, $t3, $t4
    sw $t5, 16($sp)
    lw $t6, 16($sp)
    lw $t7, 8($sp)
    seq $t0, $t6, $t7
    # if-else condition result in $t0
    beq $t0, $zero, Lelse_15
    li $t1, 0
    sw $t1, 20($sp)
    lw $t2, 8($sp)
    sw $t2, 12($sp)
    j Lend_if_15
Lelse_15:
    lw $t3, 12($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 12($sp)
Lend_if_15:
    j Lwhile_10
Lend_while_10:
Lend_if_14:
    lw $t6, 20($sp)
    move $v0, $t6
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: countPrimes returns int
countPrimes:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int count at offset 12
    # Declared int i at offset 16
    # Declared int primeCheck at offset 20
    li $t7, 0
    sw $t7, 12($sp)
    li $t0, 2
    sw $t0, 16($sp)
Lwhile_11:
    lw $t1, 16($sp)
    lw $t2, 8($sp)
    sle $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_11
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    lw $t0, 16($sp)
    move $a0, $t0
    jal isPrime
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 20($sp)
    lw $t2, 20($sp)
    li $t3, 1
    seq $t4, $t2, $t3
    # if condition result in $t4
    beq $t4, $zero, Lend_if_16
    lw $t5, 12($sp)
    li $t6, 1
    add $t7, $t5, $t6
    sw $t7, 12($sp)
Lend_if_16:
    lw $t0, 16($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 16($sp)
    j Lwhile_11
Lend_while_11:
    lw $t3, 12($sp)
    move $v0, $t3
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: linearSearch returns int
linearSearch:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int i at offset 20
    # Declared int found at offset 24
    li $t4, 0
    sw $t4, 20($sp)
    li $t5, 1
    li $t6, 0
    sub $t6, $t6, $t5
    sw $t6, 24($sp)
Lwhile_12:
    lw $t7, 20($sp)
    lw $t0, 12($sp)
    slt $t1, $t7, $t0
    # while condition result in $t1
    beq $t1, $zero, Lend_while_12
    lw $t0, 20($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    lw $t1, 8($sp)
    add $t0, $t0, $t1
    lw $t1, 0($t0)
    lw $t2, 16($sp)
    seq $t3, $t1, $t2
    # if-else condition result in $t3
    beq $t3, $zero, Lelse_17
    lw $t4, 20($sp)
    sw $t4, 24($sp)
    lw $t5, 12($sp)
    sw $t5, 20($sp)
    j Lend_if_17
Lelse_17:
    lw $t6, 20($sp)
    li $t7, 1
    add $t0, $t6, $t7
    sw $t0, 20($sp)
Lend_if_17:
    j Lwhile_12
Lend_while_12:
    lw $t1, 24($sp)
    move $v0, $t1
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: bubbleSort returns void
bubbleSort:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int i at offset 16
    # Declared int j at offset 20
    # Declared int temp at offset 24
    # Declared int limit1 at offset 28
    # Declared int limit2 at offset 32
    # Declared int jPlus1 at offset 36
    li $t2, 0
    sw $t2, 16($sp)
    lw $t3, 12($sp)
    li $t4, 1
    sub $t5, $t3, $t4
    sw $t5, 28($sp)
Lwhile_13:
    lw $t6, 16($sp)
    lw $t7, 28($sp)
    slt $t0, $t6, $t7
    # while condition result in $t0
    beq $t0, $zero, Lend_while_13
    li $t0, 0
    sw $t0, 20($sp)
    lw $t1, 12($sp)
    lw $t2, 16($sp)
    sub $t3, $t1, $t2
    sw $t3, 32($sp)
    lw $t4, 32($sp)
    li $t5, 1
    sub $t6, $t4, $t5
    sw $t6, 32($sp)
Lwhile_14:
    lw $t7, 20($sp)
    lw $t0, 32($sp)
    slt $t1, $t7, $t0
    # while condition result in $t1
    beq $t1, $zero, Lend_while_14
    lw $t0, 20($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 36($sp)
    lw $t3, 20($sp)
    # Array access: arr[index]
    sll $t3, $t3, 2
    lw $t4, 8($sp)
    add $t3, $t3, $t4
    lw $t4, 0($t3)
    lw $t5, 36($sp)
    # Array access: arr[index]
    sll $t5, $t5, 2
    lw $t6, 8($sp)
    add $t5, $t5, $t6
    lw $t6, 0($t5)
    sgt $t7, $t4, $t6
    # if condition result in $t7
    beq $t7, $zero, Lend_if_18
    lw $t0, 20($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    lw $t1, 8($sp)
    add $t0, $t0, $t1
    lw $t1, 0($t0)
    sw $t1, 24($sp)
    lw $t2, 36($sp)
    # Array access: arr[index]
    sll $t2, $t2, 2
    lw $t3, 8($sp)
    add $t2, $t2, $t3
    lw $t3, 0($t2)
    lw $t4, 20($sp)
    # Array assignment: arr[index] = value
    sll $t4, $t4, 2
    lw $t5, 8($sp)
    add $t4, $t4, $t5
    sw $t3, 0($t4)
    lw $t0, 24($sp)
    lw $t1, 36($sp)
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    lw $t2, 8($sp)
    add $t1, $t1, $t2
    sw $t0, 0($t1)
Lend_if_18:
    lw $t0, 20($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 20($sp)
    j Lwhile_14
Lend_while_14:
    lw $t3, 16($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 16($sp)
    j Lwhile_13
Lend_while_13:
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: reverseArray returns void
reverseArray:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int left at offset 16
    # Declared int right at offset 20
    # Declared int temp at offset 24
    li $t6, 0
    sw $t6, 16($sp)
    lw $t7, 12($sp)
    li $t0, 1
    sub $t1, $t7, $t0
    sw $t1, 20($sp)
Lwhile_15:
    lw $t2, 16($sp)
    lw $t3, 20($sp)
    slt $t4, $t2, $t3
    # while condition result in $t4
    beq $t4, $zero, Lend_while_15
    lw $t0, 16($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    lw $t1, 8($sp)
    add $t0, $t0, $t1
    lw $t1, 0($t0)
    sw $t1, 24($sp)
    lw $t2, 20($sp)
    # Array access: arr[index]
    sll $t2, $t2, 2
    lw $t3, 8($sp)
    add $t2, $t2, $t3
    lw $t3, 0($t2)
    lw $t4, 16($sp)
    # Array assignment: arr[index] = value
    sll $t4, $t4, 2
    lw $t5, 8($sp)
    add $t4, $t4, $t5
    sw $t3, 0($t4)
    lw $t0, 24($sp)
    lw $t1, 20($sp)
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    lw $t2, 8($sp)
    add $t1, $t1, $t2
    sw $t0, 0($t1)
    lw $t0, 16($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 16($sp)
    lw $t3, 20($sp)
    li $t4, 1
    sub $t5, $t3, $t4
    sw $t5, 20($sp)
    j Lwhile_15
Lend_while_15:
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: copyArray returns void
copyArray:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int i at offset 20
    li $t6, 0
    sw $t6, 20($sp)
Lwhile_16:
    lw $t7, 20($sp)
    lw $t0, 16($sp)
    slt $t1, $t7, $t0
    # while condition result in $t1
    beq $t1, $zero, Lend_while_16
    lw $t0, 20($sp)
    # Array access: source[index]
    sll $t0, $t0, 2
    lw $t1, 8($sp)
    add $t0, $t0, $t1
    lw $t1, 0($t0)
    lw $t2, 20($sp)
    # Array assignment: dest[index] = value
    sll $t2, $t2, 2
    lw $t3, 12($sp)
    add $t2, $t2, $t3
    sw $t1, 0($t2)
    lw $t0, 20($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 20($sp)
    j Lwhile_16
Lend_while_16:
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: arrayEqual returns int
arrayEqual:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int i at offset 20
    # Declared int equal at offset 24
    li $t3, 1
    sw $t3, 24($sp)
    li $t4, 0
    sw $t4, 20($sp)
Lwhile_17:
    lw $t5, 20($sp)
    lw $t6, 16($sp)
    slt $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_17
    lw $t0, 20($sp)
    # Array access: arr1[index]
    sll $t0, $t0, 2
    lw $t1, 8($sp)
    add $t0, $t0, $t1
    lw $t1, 0($t0)
    lw $t2, 20($sp)
    # Array access: arr2[index]
    sll $t2, $t2, 2
    lw $t3, 12($sp)
    add $t2, $t2, $t3
    lw $t3, 0($t2)
    sne $t4, $t1, $t3
    # if-else condition result in $t4
    beq $t4, $zero, Lelse_19
    li $t5, 0
    sw $t5, 24($sp)
    lw $t6, 16($sp)
    sw $t6, 20($sp)
    j Lend_if_19
Lelse_19:
    lw $t7, 20($sp)
    li $t0, 1
    add $t1, $t7, $t0
    sw $t1, 20($sp)
Lend_if_19:
    j Lwhile_17
Lend_while_17:
    lw $t2, 24($sp)
    move $v0, $t2
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: absoluteValue returns int
absoluteValue:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int result at offset 12
    # Declared int negX at offset 16
    lw $t3, 8($sp)
    li $t4, 0
    slt $t5, $t3, $t4
    # if-else condition result in $t5
    beq $t5, $zero, Lelse_20
    li $t6, 0
    lw $t7, 8($sp)
    sub $t0, $t6, $t7
    sw $t0, 16($sp)
    lw $t1, 16($sp)
    sw $t1, 12($sp)
    j Lend_if_20
Lelse_20:
    lw $t2, 8($sp)
    sw $t2, 12($sp)
Lend_if_20:
    lw $t3, 12($sp)
    move $v0, $t3
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: sign returns int
sign:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int result at offset 12
    lw $t4, 8($sp)
    li $t5, 0
    slt $t6, $t4, $t5
    # if-else condition result in $t6
    beq $t6, $zero, Lelse_21
    li $t7, 1
    li $t0, 0
    sub $t0, $t0, $t7
    sw $t0, 12($sp)
    j Lend_if_21
Lelse_21:
    lw $t1, 8($sp)
    li $t2, 0
    sgt $t3, $t1, $t2
    # if-else condition result in $t3
    beq $t3, $zero, Lelse_22
    li $t4, 1
    sw $t4, 12($sp)
    j Lend_if_22
Lelse_22:
    li $t5, 0
    sw $t5, 12($sp)
Lend_if_22:
Lend_if_21:
    lw $t6, 12($sp)
    move $v0, $t6
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: sumOfSquares returns int
sumOfSquares:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int sum at offset 12
    # Declared int i at offset 16
    # Declared int iSquared at offset 20
    li $t7, 0
    sw $t7, 12($sp)
    li $t0, 1
    sw $t0, 16($sp)
Lwhile_18:
    lw $t1, 16($sp)
    lw $t2, 8($sp)
    sle $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_18
    lw $t0, 16($sp)
    lw $t1, 16($sp)
    mul $t2, $t0, $t1
    sw $t2, 20($sp)
    lw $t3, 12($sp)
    lw $t4, 20($sp)
    add $t5, $t3, $t4
    sw $t5, 12($sp)
    lw $t6, 16($sp)
    li $t7, 1
    add $t0, $t6, $t7
    sw $t0, 16($sp)
    j Lwhile_18
Lend_while_18:
    lw $t1, 12($sp)
    move $v0, $t1
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: sumOfCubes returns int
sumOfCubes:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int sum at offset 12
    # Declared int i at offset 16
    # Declared int iSquared at offset 20
    # Declared int iCubed at offset 24
    li $t2, 0
    sw $t2, 12($sp)
    li $t3, 1
    sw $t3, 16($sp)
Lwhile_19:
    lw $t4, 16($sp)
    lw $t5, 8($sp)
    sle $t6, $t4, $t5
    # while condition result in $t6
    beq $t6, $zero, Lend_while_19
    lw $t0, 16($sp)
    lw $t1, 16($sp)
    mul $t2, $t0, $t1
    sw $t2, 20($sp)
    lw $t3, 20($sp)
    lw $t4, 16($sp)
    mul $t5, $t3, $t4
    sw $t5, 24($sp)
    lw $t6, 12($sp)
    lw $t7, 24($sp)
    add $t0, $t6, $t7
    sw $t0, 12($sp)
    lw $t1, 16($sp)
    li $t2, 1
    add $t3, $t1, $t2
    sw $t3, 16($sp)
    j Lwhile_19
Lend_while_19:
    lw $t4, 12($sp)
    move $v0, $t4
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: calculateMean returns int
calculateMean:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int sum at offset 16
    # Declared int i at offset 20
    li $t5, 0
    sw $t5, 16($sp)
    li $t6, 0
    sw $t6, 20($sp)
Lwhile_20:
    lw $t7, 20($sp)
    lw $t0, 12($sp)
    slt $t1, $t7, $t0
    # while condition result in $t1
    beq $t1, $zero, Lend_while_20
    lw $t0, 16($sp)
    lw $t1, 20($sp)
    # Array access: arr[index]
    sll $t1, $t1, 2
    lw $t2, 8($sp)
    add $t1, $t1, $t2
    lw $t2, 0($t1)
    add $t3, $t0, $t2
    sw $t3, 16($sp)
    lw $t4, 20($sp)
    li $t5, 1
    add $t6, $t4, $t5
    sw $t6, 20($sp)
    j Lwhile_20
Lend_while_20:
    lw $t7, 16($sp)
    lw $t0, 12($sp)
    div $t1, $t7, $t0
    move $v0, $t1
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: countOccurrences returns int
countOccurrences:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int count at offset 20
    # Declared int i at offset 24
    li $t2, 0
    sw $t2, 20($sp)
    li $t3, 0
    sw $t3, 24($sp)
Lwhile_21:
    lw $t4, 24($sp)
    lw $t5, 12($sp)
    slt $t6, $t4, $t5
    # while condition result in $t6
    beq $t6, $zero, Lend_while_21
    lw $t0, 24($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    lw $t1, 8($sp)
    add $t0, $t0, $t1
    lw $t1, 0($t0)
    lw $t2, 16($sp)
    seq $t3, $t1, $t2
    # if condition result in $t3
    beq $t3, $zero, Lend_if_23
    lw $t4, 20($sp)
    li $t5, 1
    add $t6, $t4, $t5
    sw $t6, 20($sp)
Lend_if_23:
    lw $t7, 24($sp)
    li $t0, 1
    add $t1, $t7, $t0
    sw $t1, 24($sp)
    j Lwhile_21
Lend_while_21:
    lw $t2, 20($sp)
    move $v0, $t2
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: leftShift returns int
leftShift:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int result at offset 16
    # Declared int i at offset 20
    lw $t3, 8($sp)
    sw $t3, 16($sp)
    li $t4, 0
    sw $t4, 20($sp)
Lwhile_22:
    lw $t5, 20($sp)
    lw $t6, 12($sp)
    slt $t7, $t5, $t6
    # while condition result in $t7
    beq $t7, $zero, Lend_while_22
    lw $t0, 16($sp)
    li $t1, 2
    mul $t2, $t0, $t1
    sw $t2, 16($sp)
    lw $t3, 20($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 20($sp)
    j Lwhile_22
Lend_while_22:
    lw $t6, 16($sp)
    move $v0, $t6
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: rightShift returns int
rightShift:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int result at offset 16
    # Declared int i at offset 20
    lw $t7, 8($sp)
    sw $t7, 16($sp)
    li $t0, 0
    sw $t0, 20($sp)
Lwhile_23:
    lw $t1, 20($sp)
    lw $t2, 12($sp)
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_23
    lw $t0, 16($sp)
    li $t1, 2
    div $t2, $t0, $t1
    sw $t2, 16($sp)
    lw $t3, 20($sp)
    li $t4, 1
    add $t5, $t3, $t4
    sw $t5, 20($sp)
    j Lwhile_23
Lend_while_23:
    lw $t6, 16($sp)
    move $v0, $t6
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: add3 returns int
add3:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    lw $t7, 8($sp)
    lw $t0, 12($sp)
    add $t1, $t7, $t0
    lw $t2, 16($sp)
    add $t3, $t1, $t2
    move $v0, $t3
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: max3 returns int
max3:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int max at offset 20
    lw $t4, 8($sp)
    sw $t4, 20($sp)
    lw $t5, 12($sp)
    lw $t6, 20($sp)
    sgt $t7, $t5, $t6
    # if condition result in $t7
    beq $t7, $zero, Lend_if_24
    lw $t0, 12($sp)
    sw $t0, 20($sp)
Lend_if_24:
    lw $t1, 16($sp)
    lw $t2, 20($sp)
    sgt $t3, $t1, $t2
    # if condition result in $t3
    beq $t3, $zero, Lend_if_25
    lw $t4, 16($sp)
    sw $t4, 20($sp)
Lend_if_25:
    lw $t5, 20($sp)
    move $v0, $t5
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: multiply3 returns int
multiply3:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int temp at offset 20
    # Declared int result at offset 24
    lw $t6, 8($sp)
    lw $t7, 12($sp)
    mul $t0, $t6, $t7
    sw $t0, 20($sp)
    lw $t1, 20($sp)
    lw $t2, 16($sp)
    mul $t3, $t1, $t2
    sw $t3, 24($sp)
    lw $t4, 24($sp)
    move $v0, $t4
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: testComplexExpressions returns int
testComplexExpressions:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    # Declared int result at offset 20
    # Declared int temp1 at offset 24
    # Declared int temp2 at offset 28
    # Declared int temp3 at offset 32
    # Declared int temp4 at offset 36
    lw $t5, 12($sp)
    lw $t6, 16($sp)
    mul $t7, $t5, $t6
    sw $t7, 24($sp)
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    div $t2, $t0, $t1
    sw $t2, 28($sp)
    lw $t3, 8($sp)
    lw $t4, 24($sp)
    add $t5, $t3, $t4
    sw $t5, 32($sp)
    lw $t6, 32($sp)
    lw $t7, 28($sp)
    sub $t0, $t6, $t7
    sw $t0, 20($sp)
    lw $t1, 8($sp)
    lw $t2, 12($sp)
    add $t3, $t1, $t2
    sw $t3, 24($sp)
    lw $t4, 16($sp)
    lw $t5, 8($sp)
    sub $t6, $t4, $t5
    sw $t6, 28($sp)
    lw $t7, 24($sp)
    lw $t0, 28($sp)
    mul $t1, $t7, $t0
    sw $t1, 32($sp)
    lw $t2, 12($sp)
    li $t3, 1
    add $t4, $t2, $t3
    sw $t4, 36($sp)
    lw $t5, 32($sp)
    lw $t6, 36($sp)
    div $t7, $t5, $t6
    sw $t7, 20($sp)
    lw $t0, 8($sp)
    lw $t1, 12($sp)
    mul $t2, $t0, $t1
    sw $t2, 24($sp)
    lw $t3, 16($sp)
    lw $t4, 8($sp)
    mul $t5, $t3, $t4
    sw $t5, 28($sp)
    lw $t6, 12($sp)
    lw $t7, 16($sp)
    div $t0, $t6, $t7
    sw $t0, 32($sp)
    lw $t1, 24($sp)
    lw $t2, 28($sp)
    add $t3, $t1, $t2
    sw $t3, 36($sp)
    lw $t4, 36($sp)
    lw $t5, 32($sp)
    sub $t6, $t4, $t5
    sw $t6, 36($sp)
    lw $t7, 36($sp)
    lw $t0, 8($sp)
    add $t1, $t7, $t0
    sw $t1, 36($sp)
    lw $t2, 36($sp)
    lw $t3, 12($sp)
    sub $t4, $t2, $t3
    sw $t4, 36($sp)
    lw $t5, 36($sp)
    lw $t6, 16($sp)
    add $t7, $t5, $t6
    sw $t7, 20($sp)
    lw $t0, 20($sp)
    move $v0, $t0
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: add4 returns int
add4:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    sw $a2, 16($sp)
    sw $a3, 20($sp)
    # Declared int temp1 at offset 24
    # Declared int temp2 at offset 28
    # Declared int result at offset 32
    lw $t1, 8($sp)
    lw $t2, 12($sp)
    add $t3, $t1, $t2
    sw $t3, 24($sp)
    lw $t4, 16($sp)
    lw $t5, 20($sp)
    add $t6, $t4, $t5
    sw $t6, 28($sp)
    lw $t7, 24($sp)
    lw $t0, 28($sp)
    add $t1, $t7, $t0
    sw $t1, 32($sp)
    lw $t2, 32($sp)
    move $v0, $t2
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: printValue returns void
printValue:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    lw $t3, 8($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: printArray returns void
printArray:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    sw $a1, 12($sp)
    # Declared int i at offset 16
    li $t0, 0
    sw $t0, 16($sp)
Lwhile_24:
    lw $t1, 16($sp)
    lw $t2, 12($sp)
    slt $t3, $t1, $t2
    # while condition result in $t3
    beq $t3, $zero, Lend_while_24
    lw $t0, 16($sp)
    # Array access: arr[index]
    sll $t0, $t0, 2
    lw $t1, 8($sp)
    add $t0, $t0, $t1
    lw $t1, 0($t0)
    # Print integer
    move $a0, $t1
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 16($sp)
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, 16($sp)
    j Lwhile_24
Lend_while_24:
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra

# Function: main returns void
main:
    addi $sp, $sp, -2048
    sw $ra, 2044($sp)
    sw $fp, 2040($sp)
    move $fp, $sp
    # Declared int result at offset 8
    # Declared array arr[10] at offset 12
    # Declared array arr2[10] at offset 52
    # Declared int i at offset 92
    # Declared int temp at offset 96
    li $t3, 1
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 20
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal testArithmetic
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 5
    move $a0, $t0
    li $t1, 10
    move $a1, $t1
    jal testRelational
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 10
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal testRelational
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
    # Print integer
    move $a0, $t3
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 75
    move $a0, $t0
    jal testIfElse
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 10
    move $a0, $t0
    jal testWhileLoop
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
    # Print integer
    move $a0, $t2
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 3
    move $a0, $t0
    li $t1, 4
    move $a1, $t1
    jal testNestedLoops
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    jal testLocalArray
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t0, $v0
    sw $t0, 8($sp)
    lw $t1, 8($sp)
    # Print integer
    move $a0, $t1
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    jal fillArray
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    jal sumArray
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 5
    move $a0, $t0
    jal factorial
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
    # Print integer
    move $a0, $t2
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 7
    move $a0, $t0
    jal fibonacci
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
    # Print integer
    move $a0, $t2
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 2
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    jal power
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
    # Print integer
    move $a0, $t3
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 48
    move $a0, $t0
    li $t1, 18
    move $a1, $t1
    jal gcd
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 13
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 3
    li $t1, 0
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 7
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 2
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 9
    li $t1, 3
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 5
    li $t1, 4
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    jal findMax
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
    # Print integer
    move $a0, $t2
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    jal findMin
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 17
    move $a0, $t0
    jal isPrime
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 18
    move $a0, $t0
    jal isPrime
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 17
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 20
    move $a0, $t0
    jal countPrimes
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    li $t1, 9
    move $a2, $t1
    jal linearSearch
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
    # Print integer
    move $a0, $t3
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
    li $t0, 5
    li $t1, 0
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 2
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 8
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 1
    li $t1, 3
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 9
    li $t1, 4
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    jal bubbleSort
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    jal printArray
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    li $t0, 20
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 1
    li $t1, 0
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 2
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 3
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 4
    li $t1, 3
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 5
    li $t1, 4
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    jal reverseArray
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    jal printArray
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    li $t0, 21
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    # Pass local array address: arr2
    addi $a1, $sp, 52
    li $t0, 5
    move $a2, $t0
    jal copyArray
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    # Pass local array address: arr2
    addi $a1, $sp, 52
    li $t0, 5
    move $a2, $t0
    jal arrayEqual
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 15
    li $t1, 0
    sub $t1, $t1, $t0
    move $a0, $t1
    jal absoluteValue
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 5
    li $t1, 0
    sub $t1, $t1, $t0
    move $a0, $t1
    jal sign
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 5
    move $a0, $t0
    jal sign
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 0
    move $a0, $t0
    jal sign
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 5
    move $a0, $t0
    jal sumOfSquares
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
    # Print integer
    move $a0, $t2
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
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 5
    move $a0, $t0
    jal sumOfCubes
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 26
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 2
    li $t1, 0
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 4
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 6
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 8
    li $t1, 3
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 10
    li $t1, 4
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    jal calculateMean
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    sw $t1, 8($sp)
    lw $t2, 8($sp)
    # Print integer
    move $a0, $t2
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 27
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
    sw $t0, 12($t1)
    li $t0, 5
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 3
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 5
    li $t1, 3
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    li $t0, 7
    li $t1, 4
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 12($t1)
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    # Pass local array address: arr
    addi $a0, $sp, 12
    li $t0, 5
    move $a1, $t0
    li $t1, 5
    move $a2, $t1
    jal countOccurrences
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 28
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 3
    move $a0, $t0
    li $t1, 2
    move $a1, $t1
    jal leftShift
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 29
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 16
    move $a0, $t0
    li $t1, 2
    move $a1, $t1
    jal rightShift
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t2, $v0
    sw $t2, 8($sp)
    lw $t3, 8($sp)
    # Print integer
    move $a0, $t3
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 30
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 10
    move $a0, $t0
    li $t1, 20
    move $a1, $t1
    li $t2, 30
    move $a2, $t2
    jal add3
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t3, $v0
    sw $t3, 8($sp)
    lw $t4, 8($sp)
    # Print integer
    move $a0, $t4
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 31
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 5
    move $a0, $t0
    li $t1, 12
    move $a1, $t1
    li $t2, 8
    move $a2, $t2
    jal max3
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t3, $v0
    sw $t3, 8($sp)
    lw $t4, 8($sp)
    # Print integer
    move $a0, $t4
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 32
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 2
    move $a0, $t0
    li $t1, 3
    move $a1, $t1
    li $t2, 4
    move $a2, $t2
    jal multiply3
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t3, $v0
    sw $t3, 8($sp)
    lw $t4, 8($sp)
    # Print integer
    move $a0, $t4
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 33
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 1
    move $a0, $t0
    li $t1, 2
    move $a1, $t1
    li $t2, 3
    move $a2, $t2
    li $t3, 4
    move $a3, $t3
    jal add4
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t4, $v0
    sw $t4, 8($sp)
    lw $t5, 8($sp)
    # Print integer
    move $a0, $t5
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 34
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 10
    move $a0, $t0
    li $t1, 5
    move $a1, $t1
    li $t2, 3
    move $a2, $t2
    jal testComplexExpressions
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t3, $v0
    sw $t3, 8($sp)
    lw $t4, 8($sp)
    # Print integer
    move $a0, $t4
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 35
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
    li $t1, 200
    sw $t1, 4($sp)
    lw $t2, 0($sp)
    lw $t3, 4($sp)
    add $t4, $t2, $t3
    sw $t4, 8($sp)
    lw $t5, 8($sp)
    # Print integer
    move $a0, $t5
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 36
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Save caller-saved temp registers before call
    sw $t0, 2000($sp)
    sw $t1, 2004($sp)
    sw $t2, 2008($sp)
    sw $t3, 2012($sp)
    sw $t4, 2016($sp)
    sw $t5, 2020($sp)
    sw $t6, 2024($sp)
    sw $t7, 2028($sp)
    li $t0, 999
    move $a0, $t0
    jal printValue
    # Restore caller-saved temp registers after call
    lw $t0, 2000($sp)
    lw $t1, 2004($sp)
    lw $t2, 2008($sp)
    lw $t3, 2012($sp)
    lw $t4, 2016($sp)
    lw $t5, 2020($sp)
    lw $t6, 2024($sp)
    lw $t7, 2028($sp)
    move $t1, $v0
    li $t0, 0
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $fp, 2040($sp)
    lw $ra, 2044($sp)
    addi $sp, $sp, 2048
    jr $ra
