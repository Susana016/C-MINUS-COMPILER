.data

.text
.globl main

main:
    # Allocate space for global variables
    addi $sp, $sp, -400
    move $s7, $sp    # Save global base pointer in $s7

    # Global int gx = init at offset 0
    li $t0, 5
    sw $t0, 0($sp)
    # Global int gy = init at offset 4
    li $t0, 3
    sw $t0, 4($sp)
    jal _user_main

    # Exit program
    addi $sp, $sp, 400
    li $v0, 10
    syscall


# Function: getNumber returns int
getNumber:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int result at offset 0
    li $t0, 42
    sw $t0, 0($sp)
    lw $t0, 0($sp)
    move $v0, $t0
    move $sp, $fp
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: main returns int
_user_main:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared and initialized int sum at offset 0
    lw $t1, 0($s7)
    lw $t2, 4($s7)
    add $t1, $t1, $t2
    sw $t1, 0($sp)
    # Declared and initialized int diff at offset 4
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    sub $t0, $t0, $t1
    sw $t0, 4($sp)
    # Declared and initialized int prod at offset 8
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    mul $t0, $t0, $t1
    sw $t0, 8($sp)
    # Declared and initialized int quot at offset 12
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    div $t0, $t0, $t1
    sw $t0, 12($sp)
    # Declared and initialized int mod at offset 16
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    div $t0, $t1
    mfhi $t0
    sw $t0, 16($sp)
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
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 8($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 12($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 16($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared and initialized int funcResult at offset 20
    jal getNumber
    move $t0, $v0
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
    # Declared array arr[3] at offset 24
    li $t0, 10
    li $t1, 0
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 24($t1)
    li $t0, 20
    li $t1, 1
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 24($t1)
    li $t0, 30
    li $t1, 2
    # Array assignment: arr[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 24($t1)
    # Declared and initialized int arrSum at offset 36
    li $t0, 0
    # Array access: arr[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 24($t0)
    li $t1, 1
    # Array access: arr[index]
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    lw $t1, 24($t1)
    add $t0, $t0, $t1
    li $t1, 2
    # Array access: arr[index]
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    lw $t1, 24($t1)
    add $t0, $t0, $t1
    sw $t0, 36($sp)
    lw $t0, 36($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared 2D array matrix[2][2] at offset 40
    li $t0, 1
    li $t1, 0
    li $t2, 0
    # 2D Array assignment: matrix[row][col] = value
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 40($t1)
    li $t0, 2
    li $t1, 0
    li $t2, 1
    # 2D Array assignment: matrix[row][col] = value
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 40($t1)
    li $t0, 3
    li $t1, 1
    li $t2, 0
    # 2D Array assignment: matrix[row][col] = value
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 40($t1)
    li $t0, 4
    li $t1, 1
    li $t2, 1
    # 2D Array assignment: matrix[row][col] = value
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 40($t1)
    # Declared and initialized int diagonal at offset 56
    li $t0, 0
    li $t1, 0
    # 2D Array access: matrix[row][col]
    sll $t0, $t0, 1
    add $t0, $t0, $t1
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 40($t0)
    li $t1, 1
    li $t2, 1
    # 2D Array access: matrix[row][col]
    sll $t1, $t1, 1
    add $t1, $t1, $t2
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    lw $t1, 40($t1)
    add $t0, $t0, $t1
    sw $t0, 56($sp)
    lw $t0, 56($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared and initialized int i at offset 60
    li $t0, 0
    sw $t0, 60($sp)
    # Declared and initialized int loopSum at offset 64
    li $t0, 0
    sw $t0, 64($sp)
Lwhile_0:
    lw $t0, 60($sp)
    li $t1, 5
    slt $t0, $t0, $t1
    # while condition result in $t0
    beq $t0, $zero, Lend_while_0
    lw $t0, 64($sp)
    lw $t1, 60($sp)
    add $t0, $t0, $t1
    sw $t0, 64($sp)
    lw $t0, 60($sp)
    li $t1, 1
    add $t0, $t0, $t1
    sw $t0, 60($sp)
    j Lwhile_0
Lend_while_0:
    lw $t0, 64($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared and initialized int complex at offset 68
    lw $t0, 0($s7)
    li $t1, 2
    mul $t0, $t0, $t1
    li $t1, 1
    # Array access: arr[index]
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    lw $t1, 24($t1)
    li $t2, 2
    div $t1, $t1, $t2
    add $t0, $t0, $t1
    lw $t1, 16($sp)
    sub $t0, $t0, $t1
    sw $t0, 68($sp)
    lw $t0, 68($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared and initialized int testVal at offset 72
    li $t0, 7
    sw $t0, 72($sp)
    lw $t0, 72($sp)
    li $t1, 7
    slt $t0, $t1, $t0
    # if-else condition result in $t0
    beq $t0, $zero, Lelse_0
    li $t0, 100
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
    li $t0, 200
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_0:
    # Declared and initialized int forSum at offset 76
    li $t0, 0
    sw $t0, 76($sp)
    # Declared int j at offset 80
    li $t0, 0
    sw $t0, 80($sp)
Lfor_0:
    lw $t0, 80($sp)
    li $t1, 5
    slt $t0, $t0, $t1
    # for condition result in $t0
    beq $t0, $zero, Lend_for_0
    lw $t0, 76($sp)
    lw $t1, 80($sp)
    add $t0, $t0, $t1
    sw $t0, 76($sp)
    lw $t0, 80($sp)
    li $t1, 1
    add $t0, $t0, $t1
    sw $t0, 80($sp)
    j Lfor_0
Lend_for_0:
    lw $t0, 76($sp)
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
