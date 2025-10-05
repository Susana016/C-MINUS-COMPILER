.data

.text
.globl main
main:
    # Allocate stack space
    addi $sp, $sp, -400

    # Declared x at offset 0
    li $t0, 5
    sw $t0, 0($sp)
    # Declared y at offset 4
    lw $t0, 0($sp)
    li $t1, 3
    add $t0, $t0, $t1
    sw $t0, 4($sp)
    # Declared array arr of size 3 at offset 8
    li $t0, 0
    lw $t1, 0($sp)
    # Array assignment: arr[index] = value
    sll $t0, $t0, 2    # index * 4
    addi $t2, $sp, 8   # base address
    add $t2, $t2, $t0 # base + index*4
    sw $t1, 0($t2)     # store to array[index]
    li $t0, 1
    lw $t1, 4($sp)
    # Array assignment: arr[index] = value
    sll $t0, $t0, 2    # index * 4
    addi $t2, $sp, 8   # base address
    add $t2, $t2, $t0 # base + index*4
    sw $t1, 0($t2)     # store to array[index]
    li $t0, 2
    li $t1, 0
    # Array access: arr[index]
    sll $t1, $t1, 2    # index * 4
    addi $t2, $sp, 8   # base address
    add $t2, $t2, $t1 # base + index*4
    lw $t1, 0($t2)     # load array[index]
    li $t2, 1
    # Array access: arr[index]
    sll $t2, $t2, 2    # index * 4
    addi $t3, $sp, 8   # base address
    add $t3, $t3, $t2 # base + index*4
    lw $t2, 0($t3)     # load array[index]
    add $t1, $t1, $t2
    # Array assignment: arr[index] = value
    sll $t0, $t0, 2    # index * 4
    addi $t2, $sp, 8   # base address
    add $t2, $t2, $t0 # base + index*4
    sw $t1, 0($t2)     # store to array[index]
    # Declared total at offset 20
    li $t0, 0
    # Array access: arr[index]
    sll $t0, $t0, 2    # index * 4
    addi $t1, $sp, 8   # base address
    add $t1, $t1, $t0 # base + index*4
    lw $t0, 0($t1)     # load array[index]
    li $t1, 1
    # Array access: arr[index]
    sll $t1, $t1, 2    # index * 4
    addi $t2, $sp, 8   # base address
    add $t2, $t2, $t1 # base + index*4
    lw $t1, 0($t2)     # load array[index]
    add $t0, $t0, $t1
    li $t1, 2
    # Array access: arr[index]
    sll $t1, $t1, 2    # index * 4
    addi $t2, $sp, 8   # base address
    add $t2, $t2, $t1 # base + index*4
    lw $t1, 0($t2)     # load array[index]
    add $t0, $t0, $t1
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
