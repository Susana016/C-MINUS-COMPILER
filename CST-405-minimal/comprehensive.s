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

# Function: testScope returns int
testScope:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    # Declared int gx at offset 0
    li $t1, 100
    sw $t1, 0($sp)
    lw $t0, 0($sp)
    move $v0, $t0
    move $sp, $fp
    lw $fp, 400($sp)
    lw $ra, 404($sp)
    addi $sp, $sp, 408
    jr $ra

# Function: addGlobals returns int
addGlobals:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    lw $t1, 0($s7)
    lw $t2, 4($s7)
    add $t1, $t1, $t2
    move $v0, $t1
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
    lw $t2, 0($s7)
    lw $t3, 4($s7)
    add $t2, $t2, $t3
    sw $t2, 0($sp)
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
    li $t1, 5
    slt $t0, $t1, $t0
    # if condition result in $t0
    beq $t0, $zero, Lend_if_0
    li $t0, 100
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_0:
    lw $t0, 72($sp)
    li $t1, 7
    slt $t0, $t1, $t0
    # if-else condition result in $t0
    beq $t0, $zero, Lelse_1
    li $t0, 200
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j Lend_if_1
Lelse_1:
    li $t0, 300
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_1:
    # Declared and initialized int x at offset 76
    li $t0, 10
    sw $t0, 76($sp)
    # Declared and initialized int y at offset 80
    li $t0, 20
    sw $t0, 80($sp)
    lw $t0, 76($sp)
    lw $t1, 80($sp)
    slt $t0, $t0, $t1
    # if-else condition result in $t0
    beq $t0, $zero, Lelse_2
    lw $t0, 76($sp)
    li $t1, 5
    slt $t0, $t1, $t0
    # if-else condition result in $t0
    beq $t0, $zero, Lelse_3
    li $t0, 400
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j Lend_if_3
Lelse_3:
    li $t0, 500
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_3:
    j Lend_if_2
Lelse_2:
    li $t0, 600
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_2:
    # Declared and initialized int a at offset 84
    li $t0, 1
    sw $t0, 84($sp)
    # Declared and initialized int b at offset 88
    li $t0, 1
    sw $t0, 88($sp)
    lw $t0, 84($sp)
    lw $t1, 88($sp)
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
    # if condition result in $t0
    beq $t0, $zero, Lend_if_4
    li $t0, 700
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_4:
    # Declared and initialized int c at offset 92
    li $t0, 0
    sw $t0, 92($sp)
    # Declared and initialized int d at offset 96
    li $t0, 1
    sw $t0, 96($sp)
    lw $t0, 92($sp)
    lw $t1, 96($sp)
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
    # if condition result in $t0
    beq $t0, $zero, Lend_if_5
    li $t0, 800
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_5:
    # Declared and initialized int e at offset 100
    li $t0, 0
    sw $t0, 100($sp)
    lw $t0, 100($sp)
    seq $t0, $t0, $zero
    # if condition result in $t0
    beq $t0, $zero, Lend_if_6
    li $t0, 900
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_6:
    # Declared and initialized int p at offset 104
    li $t0, 1
    sw $t0, 104($sp)
    # Declared and initialized int q at offset 108
    li $t0, 0
    sw $t0, 108($sp)
    # Declared and initialized int r at offset 112
    li $t0, 1
    sw $t0, 112($sp)
    lw $t0, 104($sp)
    lw $t1, 112($sp)
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
    lw $t1, 108($sp)
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
    # if condition result in $t0
    beq $t0, $zero, Lend_if_7
    li $t0, 1000
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_7:
    lw $t0, 104($sp)
    lw $t1, 108($sp)
    seq $t1, $t1, $zero
    sne $t0, $t0, $zero
    sne $t1, $t1, $zero
    and $t0, $t0, $t1
    # if condition result in $t0
    beq $t0, $zero, Lend_if_8
    lw $t0, 112($sp)
    lw $t1, 108($sp)
    or $t0, $t0, $t1
    sne $t0, $t0, $zero
    # if condition result in $t0
    beq $t0, $zero, Lend_if_9
    li $t0, 1100
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
Lend_if_9:
Lend_if_8:
    # Declared and initialized int forSum at offset 116
    li $t0, 0
    sw $t0, 116($sp)
    # Declared int j at offset 120
    li $t0, 0
    sw $t0, 120($sp)
Lfor_0:
    lw $t0, 120($sp)
    li $t1, 5
    slt $t0, $t0, $t1
    # for condition result in $t0
    beq $t0, $zero, Lend_for_0
    lw $t0, 116($sp)
    lw $t1, 120($sp)
    add $t0, $t0, $t1
    sw $t0, 116($sp)
    lw $t0, 120($sp)
    li $t1, 1
    add $t0, $t0, $t1
    sw $t0, 120($sp)
    j Lfor_0
Lend_for_0:
    lw $t0, 116($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared and initialized int scopeTest at offset 124
    jal testScope
    move $t0, $v0
    sw $t0, 124($sp)
    lw $t0, 124($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared and initialized int globalSum at offset 128
    jal addGlobals
    move $t0, $v0
    sw $t0, 128($sp)
    lw $t0, 128($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    # Declared int localGx at offset 132
    li $t0, 999
    sw $t0, 132($sp)
    lw $t0, 132($sp)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 0($s7)
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
