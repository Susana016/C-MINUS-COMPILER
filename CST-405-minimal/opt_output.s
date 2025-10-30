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
    # Declared int result at offset 4
    li $t0, 100
    sw $t0, 0($sp)
    li $t0, 10
    li $t1, 5
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
    li $t0, 20
    li $t1, 3
    mul $t0, $t0, $t1
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
    li $t0, 100
    li $t1, 10
    div $t0, $t0, $t1
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
    li $t0, 15
    li $t1, 7
    sub $t0, $t0, $t1
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
    li $t0, 17
    li $t1, 5
    div $t0, $t1
    mfhi $t0
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
    li $t0, 12
    li $t1, 5
    slt $t0, $t1, $t0
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
    li $t0, 3
    li $t1, 10
    slt $t0, $t0, $t1
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
    li $t0, 5
    li $t1, 3
    slt $t0, $t1, $t0
    li $t1, 10
    li $t2, 20
    slt $t1, $t1, $t2
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
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
    li $t0, 2
    li $t1, 8
    slt $t0, $t1, $t0
    li $t1, 15
    li $t2, 20
    slt $t1, $t1, $t2
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
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
    li $t0, 1
    li $t1, 1
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
    li $t1, 1
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
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
    li $t0, 0
    li $t1, 0
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
    li $t1, 1
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
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
    li $t0, 0
    move $v0, $t0
    move $sp, $fp
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra
