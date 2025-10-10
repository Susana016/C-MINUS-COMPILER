.data

.text
.globl main
main:
    # Allocate stack space
    addi $sp, $sp, -400

    # Declared and initialized int x at offset 0
    li $t0, 5
    sw $t0, 0($sp)
    # Declared and initialized int y at offset 4
    lw $t0, 0($sp)
    li $t1, 3
    add $t0, $t0, $t1
    sw $t0, 4($sp)
    # Declared array arr[3] at offset 8
    lw $t0, 0($sp)
    li $t1, 0
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    addi $t1, $sp, 8
    sw $t0, 0($t1)
    lw $t0, 4($sp)
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    addi $t1, $sp, 8
    sw $t0, 0($t1)
    li $t0, 0
    # Array access: arr[index]
    sll $t0, $t0, 2
    addi $t0, $sp, 8
    lw $t0, 0($t0)
    li $t1, 1
    # Array access: arr[index]
    sll $t1, $t1, 2
    addi $t1, $sp, 8
    lw $t1, 0($t1)
    add $t0, $t0, $t1
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    addi $t1, $sp, 8
    sw $t0, 0($t1)
    # Declared int total at offset 16
    li $t0, 0
    # Array access: arr[index]
    sll $t0, $t0, 2
    addi $t0, $sp, 8
    lw $t0, 0($t0)
    li $t1, 1
    # Array access: arr[index]
    sll $t1, $t1, 2
    addi $t1, $sp, 8
    lw $t1, 0($t1)
    add $t0, $t0, $t1
    li $t1, 2
    # Array access: arr[index]
    sll $t1, $t1, 2
    addi $t1, $sp, 8
    lw $t1, 0($t1)
    add $t0, $t0, $t1
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
    # Declared 2D array matrix[2][2] at offset 20
    li $t0, 1
    li $t1, 0
    li $t2, 0
    # 2D Array assignment: matrix[row][col] = value
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    addi $t1, $sp, 20
    sw $t0, 0($t1)
    li $t0, 2
    li $t1, 0
    li $t2, 1
    # 2D Array assignment: matrix[row][col] = value
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    addi $t1, $sp, 20
    sw $t0, 0($t1)
    li $t0, 3
    li $t1, 1
    li $t2, 0
    # 2D Array assignment: matrix[row][col] = value
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    addi $t1, $sp, 20
    sw $t0, 0($t1)
    li $t0, 4
    li $t1, 1
    li $t2, 1
    # 2D Array assignment: matrix[row][col] = value
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    addi $t1, $sp, 20
    sw $t0, 0($t1)
    # Declared int sum at offset 24
    li $t0, 0
    li $t1, 0
    # 2D Array access: matrix[row][col]
    sll $t0, $t0, 1
    add $t0, $t0, $t1
    sll $t0, $t0, 2
    addi $t0, $sp, 20
    lw $t0, 0($t0)
    li $t1, 0
    li $t2, 1
    # 2D Array access: matrix[row][col]
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    addi $t1, $sp, 20
    lw $t1, 0($t1)
    add $t0, $t0, $t1
    sw $t0, 24($sp)
    lw $t0, 24($sp)
    li $t1, 1
    li $t2, 0
    # 2D Array access: matrix[row][col]
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    addi $t1, $sp, 20
    lw $t1, 0($t1)
    add $t0, $t0, $t1
    sw $t0, 24($sp)
    lw $t0, 24($sp)
    li $t1, 1
    li $t2, 1
    # 2D Array access: matrix[row][col]
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    addi $t1, $sp, 20
    lw $t1, 0($t1)
    add $t0, $t0, $t1
    sw $t0, 24($sp)
    lw $t0, 24($sp)
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
