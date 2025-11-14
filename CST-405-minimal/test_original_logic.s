.data

.text
.globl main

main:
    # Allocate stack space
    addi $sp, $sp, -400

    # Global int a at offset 0
    # Global int b at offset 4
    # Global int c at offset 8
    # Global int d at offset 12
    li $t0, 10
    sw $t0, 0($s7)
    li $t0, 5
    sw $t0, 4($s7)
    li $t0, 20
    sw $t0, 8($s7)
    li $t0, 10
    sw $t0, 12($s7)
Lwhile_0:
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    slt $t0, $t1, $t0
    # while condition result in $t0
    beq $t0, $zero, Lend_while_0
    lw $t0, 8($s7)
    lw $t1, 12($s7)
    slt $t0, $t1, $t0
    # if condition result in $t0
    beq $t0, $zero, Lend_if_0
    li $t0, 114
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 61
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared and initialized int result at offset 0
    li $t0, 0
    sw $t0, 0($sp)
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    slt $t0, $t1, $t0
    # if condition result in $t0
    beq $t0, $zero, Lend_if_1
    lw $t0, 8($s7)
    lw $t1, 12($s7)
    slt $t0, $t1, $t0
    # if condition result in $t0
    beq $t0, $zero, Lend_if_2
    li $t0, 1
    sw $t0, 0($sp)
Lend_if_2:
Lend_if_1:
    lw $t0, 0($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 0($s7)
    li $t1, 1
    sub $t0, $t0, $t1
    sw $t0, 0($s7)
Lend_if_0:
    j Lwhile_0
Lend_while_0:
    li $t0, 999
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall

    # Exit program
    addi $sp, $sp, 400
    li $v0, 10
    syscall
