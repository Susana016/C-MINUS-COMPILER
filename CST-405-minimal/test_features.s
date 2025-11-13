.data

.text
.globl main

main:
    # Allocate stack space
    addi $sp, $sp, -400

    # Global int x = init at offset 0
    li $t0, 10
    sw $t0, 0($sp)
    # Global int y = init at offset 4
    li $t0, 3
    sw $t0, 4($sp)
    # Global int sum = init at offset 8
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    add $t0, $t0, $t1
    sw $t0, 8($sp)
    # Global int diff = init at offset 12
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    sub $t0, $t0, $t1
    sw $t0, 12($sp)
    # Global int prod = init at offset 16
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    mul $t0, $t0, $t1
    sw $t0, 16($sp)
    # Global int quot = init at offset 20
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    div $t0, $t0, $t1
    sw $t0, 20($sp)
    # Global int mod = init at offset 24
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    div $t0, $t1
    mfhi $t0
    sw $t0, 24($sp)
    lw $t0, 8($s7)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 12($s7)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 16($s7)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 20($s7)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 24($s7)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared and initialized int choice at offset 0
    li $t0, 2
    sw $t0, 0($sp)
    # Declared int result at offset 4

    # Exit program
    addi $sp, $sp, 400
    li $v0, 10
    syscall
