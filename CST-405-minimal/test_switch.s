.data

.text
.globl main

main:
    # Allocate stack space
    addi $sp, $sp, -400

    # Global int x = init at offset 0
    li $t0, 5
    sw $t0, 0($sp)
    # Global int y = init at offset 4
    li $t0, 3
    sw $t0, 4($sp)
    # Global int result at offset 8
    # Declared and initialized int choice at offset 0
    li $t0, 2
    sw $t0, 0($sp)

    # Exit program
    addi $sp, $sp, 400
    li $v0, 10
    syscall
