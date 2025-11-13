.data

.text
.globl main

main:
    # Allocate stack space
    addi $sp, $sp, -400
    move $s7, $sp    # Save global base pointer in $s7

    # Global int x = init at offset 0
    li $t0, 5
    sw $t0, 0($sp)
    # Global int y = init at offset 4
    li $t0, 3
    sw $t0, 4($sp)
    # Global int result at offset 8
    lw $t0, 0($s7)
    # switch expression result in $t0
    # case 1:
    li $t1, 1
    beq $t0, $t1, Lcase_0_0
    # case 2:
    li $t2, 2
    beq $t0, $t2, Lcase_0_1
    # case 5:
    li $t3, 5
    beq $t0, $t3, Lcase_0_2
    j Ldefault_0
Lcase_0_0:
    li $t4, 10
    sw $t4, 8($s7)
    j Lend_switch_0
Lcase_0_1:
    li $t0, 20
    sw $t0, 8($s7)
    j Lend_switch_0
Lcase_0_2:
    li $t0, 50
    sw $t0, 8($s7)
    lw $t0, 8($s7)
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j Lend_switch_0
Ldefault_0:
    li $t0, 0
    sw $t0, 8($s7)
    j Lend_switch_0
Lend_switch_0:
    # Declared and initialized int choice at offset 0
    li $t0, 2
    sw $t0, 0($sp)
    lw $t0, 0($sp)
    # switch expression result in $t0
    # case 1:
    li $t1, 1
    beq $t0, $t1, Lcase_1_0
    # case 2:
    li $t2, 2
    beq $t0, $t2, Lcase_1_1
    # case 3:
    li $t3, 3
    beq $t0, $t3, Lcase_1_2
    j Lend_switch_1
Lcase_1_0:
    li $t4, 100
    # Print integer
    move $a0, $t4
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j Lend_switch_1
Lcase_1_1:
    li $t0, 200
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j Lend_switch_1
Lcase_1_2:
    li $t0, 300
    # Print integer
    move $a0, $t0
    li $v0, 1
    syscall
    # Print newline
    li $v0, 11
    li $a0, 10
    syscall
    j Lend_switch_1
Lend_switch_1:

    # Exit program
    addi $sp, $sp, 400
    li $v0, 10
    syscall
