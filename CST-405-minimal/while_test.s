.data

.text
.globl main
main:
    # Allocate stack space
    addi $sp, $sp, -400

    # Declared int x at offset 0
    # Declared int i at offset 4
    # Declared int sum at offset 8
    li $t0, 0
    sw $t0, 0($sp)
    li $t0, 0
    sw $t0, 4($sp)
    li $t0, 0
    sw $t0, 8($sp)
Lwhile_0:
    lw $t0, 4($sp)
    li $t1, 5
    # while condition result in $t0
    beq $t0, $zero, Lend_while_0
    lw $t0, 0($sp)
    li $t1, 1
    add $t0, $t0, $t1
    sw $t0, 0($sp)
    lw $t0, 8($sp)
    lw $t1, 0($sp)
    add $t0, $t0, $t1
    sw $t0, 8($sp)
    lw $t0, 4($sp)
    li $t1, 1
    add $t0, $t0, $t1
    sw $t0, 4($sp)
    j Lwhile_0
Lend_while_0:
    lw $t0, 8($sp)
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
