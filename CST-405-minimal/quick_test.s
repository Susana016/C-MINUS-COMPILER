.data

.text
.globl main

main:
    # Allocate stack space
    addi $sp, $sp, -400

    # Global int a = init at offset 0
    li $t0, 1
    sw $t0, 0($sp)
    # Global int b = init at offset 4
    li $t0, 5
    sw $t0, 4($sp)
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    slt $t0, $t1, $t0
    # if-else condition result in $t0
    beq $t0, $zero, Lelse_0
    li $t0, 1
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j Lend_if_0
Lelse_0:
    li $t0, 0
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_0:
    li $t0, 10
    sw $t0, 0($s7)
    li $t0, 5
    sw $t0, 4($s7)
Lwhile_0:
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    slt $t0, $t1, $t0
    # while condition result in $t0
    beq $t0, $zero, Lend_while_0
    lw $t0, 0($s7)
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
    j Lwhile_0
Lend_while_0:
    # Declared array arr[5] at offset 0
    li $t0, 9
    li $t1, 0
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 0($t1)
    li $t0, 3
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 0($t1)
    li $t0, 7
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 0($t1)
    li $t0, 1
    li $t1, 3
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 0($t1)
    li $t0, 5
    li $t1, 4
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 0($t1)
    li $t0, 0
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 0($t0)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 1
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 0($t0)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 2
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 0($t0)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 3
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 0($t0)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 4
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 0($t0)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared and initialized int choice at offset 20
    li $t0, 2
    sw $t0, 20($sp)
    # Declared int result at offset 24
    lw $t0, 24($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared and initialized int x at offset 28
    li $t0, 5
    li $t1, 3
    div $t0, $t1
    mfhi $t0
    sw $t0, 28($sp)
    # Declared and initialized int y at offset 32
    li $t0, 10
    li $t1, 2
    div $t0, $t0, $t1
    sw $t0, 32($sp)
    # Declared and initialized int z at offset 36
    li $t0, 4
    li $t1, 5
    mul $t0, $t0, $t1
    sw $t0, 36($sp)
    lw $t0, 28($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 32($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 36($sp)
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
