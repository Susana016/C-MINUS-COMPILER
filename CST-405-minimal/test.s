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
    # Declared int x at offset 0
    # Declared int y at offset 4
    # Declared int result at offset 8
    li $t0, 10
    sw $t0, 0($sp)
    li $t0, 5
    sw $t0, 4($sp)
    lw $t0, 0($sp)
    li $t1, 5
    slt $t0, $t1, $t0
    lw $t1, 4($sp)
    li $t2, 10
    slt $t1, $t1, $t2
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
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
    li $t1, 5
    slt $t0, $t0, $t1
    lw $t1, 4($sp)
    li $t2, 3
    slt $t1, $t2, $t1
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
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
    li $t0, 12
    li $t1, 5
    slt $t0, $t1, $t0
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
    li $t0, 12
    li $t1, 5
    slt $t0, $t1, $t0
    lw $t1, 0($sp)
    li $t2, 20
    slt $t1, $t1, $t2
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
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
    li $t0, 3
    li $t1, 10
    slt $t0, $t1, $t0
    lw $t1, 0($sp)
    li $t2, 20
    slt $t1, $t1, $t2
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
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
    li $t0, 12
    li $t1, 5
    slt $t0, $t1, $t0
    lw $t1, 0($sp)
    li $t2, 2
    slt $t1, $t1, $t2
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
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
    li $t0, 3
    li $t1, 10
    slt $t0, $t1, $t0
    lw $t1, 4($sp)
    li $t2, 2
    slt $t1, $t2, $t1
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
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
    li $t1, 5
    slt $t0, $t1, $t0
    lw $t1, 4($sp)
    li $t2, 10
    slt $t1, $t1, $t2
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
    lw $t1, 0($sp)
    li $t2, 3
    slt $t1, $t1, $t2
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
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
    li $t1, 5
    slt $t0, $t1, $t0
    lw $t1, 4($sp)
    li $t2, 3
    slt $t1, $t2, $t1
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
    lw $t1, 0($sp)
    li $t2, 20
    slt $t1, $t1, $t2
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
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
    li $t1, 5
    slt $t0, $t0, $t1
    lw $t1, 4($sp)
    li $t2, 3
    slt $t1, $t1, $t2
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
    lw $t1, 0($sp)
    li $t2, 8
    slt $t1, $t2, $t1
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
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
    li $t1, 5
    slt $t0, $t1, $t0
    lw $t1, 4($sp)
    li $t2, 10
    slt $t1, $t2, $t1
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
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
    li $t1, 5
    slt $t0, $t0, $t1
    lw $t1, 4($sp)
    li $t2, 10
    slt $t1, $t2, $t1
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
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
    li $t0, 5
    li $t1, 3
    slt $t0, $t1, $t0
    li $t1, 10
    li $t2, 20
    slt $t1, $t1, $t2
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
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
    li $t0, 5
    li $t1, 3
    slt $t0, $t0, $t1
    li $t1, 10
    li $t2, 20
    slt $t1, $t2, $t1
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
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
    li $t0, 1
    lw $t1, 0($sp)
    li $t2, 5
    slt $t1, $t2, $t1
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
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
    li $t0, 0
    lw $t1, 0($sp)
    li $t2, 5
    slt $t1, $t2, $t1
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
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
    li $t0, 0
    lw $t1, 0($sp)
    li $t2, 5
    slt $t1, $t2, $t1
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
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
    li $t0, 3
    sw $t0, 0($sp)
Lwhile_0:
    lw $t0, 0($sp)
    li $t1, 0
    slt $t0, $t1, $t0
    lw $t1, 0($sp)
    li $t2, 10
    slt $t1, $t1, $t2
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
    # while condition result in $t0
    beq $t0, $zero, Lend_while_0
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
    add $t0, $t0, $t1
    sw $t0, 0($sp)
    lw $t0, 0($sp)
    li $t1, 5
    slt $t0, $t1, $t0
    # if condition result in $t0
    beq $t0, $zero, Lend_if_0
    li $t0, 0
    sw $t0, 0($sp)
Lend_if_0:
    j Lwhile_0
Lend_while_0:
    li $t0, 0
    move $v0, $t0
    move $sp, $fp
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
