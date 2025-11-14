.data

.text
.globl main

main:
    # Allocate stack space
    addi $sp, $sp, -400

    # Global int a at offset 0
    # Global int b at offset 4
    # Global int c at offset 8
    # Global int d at offset 12
    li $t0, 1
    sw $t0, 0($s7)
    li $t0, 5
    sw $t0, 4($s7)
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
    li $t0, 20
    sw $t0, 8($s7)
    li $t0, 10
    sw $t0, 12($s7)
Lwhile_0:
    lw $t0, 0($s7)
    lw $t1, 4($s7)
    slt $t0, $t1, $t0
    # while condition result in $t0
    beq $t0, $zero, Lend_while_0
    lw $t0, 8($s7)
    lw $t1, 12($s7)
    slt $t0, $t1, $t0
    # if condition result in $t0
    beq $t0, $zero, Lend_if_1
    lw $t0, 0($s7)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    lw $t0, 4($s7)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
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
    lw $t0, 0($s7)
    li $t1, 1
    sub $t0, $t0, $t1
    sw $t0, 0($s7)
Lend_if_1:
    j Lwhile_0
Lend_while_0:
    # Declared and initialized int x at offset 0
    li $t0, 0
    sw $t0, 0($sp)
    # Declared and initialized int numLength at offset 4
    li $t0, 5
    sw $t0, 4($sp)
    # Declared array num[10] at offset 8
    li $t0, 5
    li $t1, 0
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 8($t1)
    li $t0, 2
    li $t1, 1
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 8($t1)
    li $t0, 8
    li $t1, 2
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 8($t1)
    li $t0, 1
    li $t1, 3
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 8($t1)
    li $t0, 9
    li $t1, 4
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 8($t1)
Lwhile_1:
    lw $t0, 0($sp)
    lw $t1, 4($sp)
    slt $t0, $t0, $t1
    # while condition result in $t0
    beq $t0, $zero, Lend_while_1
    # Declared and initialized int next at offset 48
    lw $t0, 0($sp)
    li $t1, 1
    add $t0, $t0, $t1
    sw $t0, 48($sp)
    lw $t0, 0($sp)
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 8($t0)
    lw $t1, 48($sp)
    # Array access: num[index]
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    lw $t1, 8($t1)
    slt $t0, $t0, $t1
    # if condition result in $t0
    beq $t0, $zero, Lend_if_2
    # Declared and initialized int temp at offset 52
    lw $t0, 0($sp)
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 8($t0)
    sw $t0, 52($sp)
    lw $t0, 48($sp)
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 8($t0)
    lw $t1, 0($sp)
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 8($t1)
    lw $t0, 52($sp)
    lw $t1, 48($sp)
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $sp
    sw $t0, 8($t1)
Lend_if_2:
    lw $t0, 0($sp)
    li $t1, 1
    add $t0, $t0, $t1
    sw $t0, 0($sp)
    j Lwhile_1
Lend_while_1:
    li $t0, 0
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 8($t0)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 1
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 8($t0)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 2
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 8($t0)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 3
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 8($t0)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 4
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $sp
    lw $t0, 8($t0)
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
