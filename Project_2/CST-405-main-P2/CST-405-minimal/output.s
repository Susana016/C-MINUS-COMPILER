.data

.text
.globl main
main:
    # Allocate stack space
    addi $sp, $sp, -400

    # Declared x at offset 0
    # Declared y at offset 4
    # Declared z at offset 8
    li $t0, 10
    sw $t0, 0($sp)
    li $t0, 20
    sw $t0, 4($sp)
    lw $t0, 0($sp)
    lw $t1, 4($sp)
    add $t0, $t0, $t1
    sw $t0, 8($sp)
    lw $t0, 8($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 0($sp)
    # If statement
    beqz $t0, end_if_0
    lw $t0, 0($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
end_if_0:
    lw $t0, 8($sp)
    li $t1, 5
    add $t0, $t0, $t1
    sw $t0, 0($sp)
    lw $t0, 0($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 4($sp)
    # If-Else statement
    beqz $t0, else_1
    lw $t0, 4($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j end_if_1
else_1:
    lw $t0, 0($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
end_if_1:
    lw $t0, 0($sp)
    lw $t1, 4($sp)
    add $t0, $t0, $t1
    lw $t1, 8($sp)
    add $t0, $t0, $t1
    sw $t0, 4($sp)
    lw $t0, 4($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 8($sp)
    # If-Else statement
    beqz $t0, else_2
    # Declared a at offset 12
    li $t0, 100
    sw $t0, 12($sp)
    lw $t0, 12($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j end_if_2
else_2:
    # Declared b at offset 16
    li $t0, 200
    sw $t0, 16($sp)
    lw $t0, 16($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
end_if_2:

    # Exit program
    addi $sp, $sp, 400
    li $v0, 10
    syscall
