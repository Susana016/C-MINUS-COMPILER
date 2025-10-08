.data

.text
.globl main
main:
    # Allocate stack space
    addi $sp, $sp, -400

    # Declared and initialized int a at offset 0
    li $t0, 10
    sw $t0, 0($sp)
    # Declared and initialized int b at offset 4
    li $t0, 3
    sw $t0, 4($sp)
    # Declared and initialized int c at offset 8
    lw $t0, 0($sp)
    lw $t1, 4($sp)
    div $t0, $t1
    mfhi $t0
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
    # Declared and initialized int d at offset 12
    li $t0, 17
    li $t1, 5
    div $t0, $t1
    mfhi $t0
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
    # Declared and initialized int e at offset 16
    li $t0, 100
    li $t1, 7
    div $t0, $t1
    mfhi $t0
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
    # Declared and initialized int result at offset 20
    li $t0, 20
    li $t1, 6
    div $t0, $t1
    mfhi $t0
    sw $t0, 20($sp)
    lw $t0, 20($sp)
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
