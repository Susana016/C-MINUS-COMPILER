.data

.text
.globl main

main:
    # Allocate space for global variables
    addi $sp, $sp, -400
    move $s7, $sp    # Save global base pointer in $s7

    # Global array num[5] at offset 0
    jal _user_main

    # Exit program
    addi $sp, $sp, 400
    li $v0, 10
    syscall


# Function: swap returns void
swap:
    addi $sp, $sp, -408
    sw $ra, 404($sp)
    sw $fp, 400($sp)
    move $fp, $sp
    sw $a0, 8($sp)
    # Declared int temp at offset 0
    lw $t0, 8($sp)
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
    lw $t0, 0($t0)
    sw $t0, 0($sp)
    lw $t0, 8($sp)
    li $t1, 1
    add $t0, $t0, $t1
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
    lw $t0, 0($t0)
    lw $t1, 8($sp)
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $s7
    sw $t0, 0($t1)
    lw $t0, 0($sp)
    lw $t1, 8($sp)
    li $t2, 1
    add $t1, $t1, $t2
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $s7
    sw $t0, 0($t1)
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
    # Declared and initialized int numLength at offset 0
    li $t0, 5
    sw $t0, 0($sp)
    # Declared int x at offset 4
    # Declared int i at offset 8
    li $t0, 64
    li $t1, 0
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $s7
    sw $t0, 0($t1)
    li $t0, 34
    li $t1, 1
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $s7
    sw $t0, 0($t1)
    li $t0, 25
    li $t1, 2
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $s7
    sw $t0, 0($t1)
    li $t0, 12
    li $t1, 3
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $s7
    sw $t0, 0($t1)
    li $t0, 22
    li $t1, 4
    # Array assignment: num[index] = value
    sll $t1, $t1, 2
    add $t1, $t1, $s7
    sw $t0, 0($t1)
    li $t0, 1111
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 0
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
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
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
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
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
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
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
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
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
    lw $t0, 0($t0)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 0
    sw $t0, 8($sp)
Lwhile_0:
    lw $t0, 8($sp)
    lw $t1, 0($sp)
    slt $t0, $t0, $t1
    # while condition result in $t0
    beq $t0, $zero, Lend_while_0
    li $t0, 0
    sw $t0, 4($sp)
Lwhile_1:
    lw $t0, 4($sp)
    lw $t1, 0($sp)
    li $t2, 1
    sub $t1, $t1, $t2
    slt $t0, $t0, $t1
    # while condition result in $t0
    beq $t0, $zero, Lend_while_1
    lw $t0, 4($sp)
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
    lw $t0, 0($t0)
    lw $t1, 4($sp)
    li $t2, 1
    add $t1, $t1, $t2
    # Array access: num[index]
    sll $t1, $t1, 2
    add $t1, $t1, $s7
    lw $t1, 0($t1)
    slt $t0, $t1, $t0
    # if condition result in $t0
    beq $t0, $zero, Lend_if_0
    lw $t0, 4($sp)
    move $a0, $t0
    jal swap
Lend_if_0:
    lw $t1, 4($sp)
    li $t2, 1
    add $t1, $t1, $t2
    sw $t1, 4($sp)
    j Lwhile_1
Lend_while_1:
    lw $t0, 8($sp)
    li $t1, 1
    add $t0, $t0, $t1
    sw $t0, 8($sp)
    j Lwhile_0
Lend_while_0:
    li $t0, 2222
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    li $t0, 0
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
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
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
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
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
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
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
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
    # Array access: num[index]
    sll $t0, $t0, 2
    add $t0, $t0, $s7
    lw $t0, 0($t0)
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
