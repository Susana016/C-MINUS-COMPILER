.data

.text
.globl main

main:
    # Allocate space for global variables
    addi $sp, $sp, -400
    move $s7, $sp    # Save global base pointer in $s7

    jal _user_main

    # Exit program
    addi $sp, $sp, 400
    li $v0, 10
    syscall


# Function: main returns int
_user_main:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int day at offset 0
    # Declared int month at offset 4
    # Declared int score at offset 8
    li $t0, 0
    sw $t0, 0($sp)
    li $t0, 2
    sw $t0, 4($sp)
    li $t0, 85
    sw $t0, 8($sp)
    # Multi-value check: expr is values...
    lw $t0, 0($sp)
    addi $sp, $sp, -4
    sw $t0, 0($sp)
    lw $t0, 0($sp)
    li $t1, 0
    seq $t2, $t0, $t1
    lw $t0, 0($sp)
    li $t3, 6
    seq $t4, $t0, $t3
    or $t5, $t2, $t4
    sne $t5, $t5, $zero
    addi $sp, $sp, 4
    # if condition result in $t5
    beq $t5, $zero, Lend_if_0
    li $t0, 1
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_0:
    # Multi-value check: expr is values...
    lw $t0, 4($sp)
    addi $sp, $sp, -4
    sw $t0, 0($sp)
    lw $t0, 0($sp)
    li $t1, 1
    seq $t2, $t0, $t1
    lw $t0, 0($sp)
    li $t3, 3
    seq $t4, $t0, $t3
    or $t5, $t2, $t4
    sne $t5, $t5, $zero
    lw $t0, 0($sp)
    li $t6, 5
    seq $t7, $t0, $t6
    or $t0, $t5, $t7
    sne $t0, $t0, $zero
    lw $t0, 0($sp)
    li $t1, 7
    seq $t2, $t0, $t1
    or $t3, $t0, $t2
    sne $t3, $t3, $zero
    lw $t0, 0($sp)
    li $t4, 8
    seq $t5, $t0, $t4
    or $t6, $t3, $t5
    sne $t6, $t6, $zero
    lw $t0, 0($sp)
    li $t7, 10
    seq $t0, $t0, $t7
    or $t1, $t6, $t0
    sne $t1, $t1, $zero
    lw $t0, 0($sp)
    li $t2, 12
    seq $t3, $t0, $t2
    or $t4, $t1, $t3
    sne $t4, $t4, $zero
    addi $sp, $sp, 4
    # if-else condition result in $t4
    beq $t4, $zero, Lelse_1
    li $t0, 31
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j Lend_if_1
Lelse_1:
    li $t0, 30
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_1:
    # Multi-value check: expr is values...
    lw $t0, 8($sp)
    addi $sp, $sp, -4
    sw $t0, 0($sp)
    lw $t0, 0($sp)
    li $t1, 85
    seq $t2, $t0, $t1
    lw $t0, 0($sp)
    li $t3, 90
    seq $t4, $t0, $t3
    or $t5, $t2, $t4
    sne $t5, $t5, $zero
    lw $t0, 0($sp)
    li $t6, 95
    seq $t7, $t0, $t6
    or $t0, $t5, $t7
    sne $t0, $t0, $zero
    lw $t0, 0($sp)
    li $t1, 100
    seq $t2, $t0, $t1
    or $t3, $t0, $t2
    sne $t3, $t3, $zero
    addi $sp, $sp, 4
    # if condition result in $t3
    beq $t3, $zero, Lend_if_2
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_2:
    # Multi-value check: expr is values...
    lw $t0, 0($sp)
    addi $sp, $sp, -4
    sw $t0, 0($sp)
    lw $t0, 0($sp)
    li $t1, 5
    seq $t2, $t0, $t1
    lw $t0, 0($sp)
    li $t3, 6
    seq $t4, $t0, $t3
    or $t5, $t2, $t4
    sne $t5, $t5, $zero
    addi $sp, $sp, 4
    # if-else condition result in $t5
    beq $t5, $zero, Lelse_3
    li $t0, 777
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j Lend_if_3
Lelse_3:
    li $t0, 888
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_3:
    li $t0, 0
    move $v0, $t0
    move $sp, $fp
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
