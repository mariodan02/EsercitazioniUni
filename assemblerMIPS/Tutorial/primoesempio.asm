.data
a: .word 4
b: .space 4
c: .space 4

.text
li $v0, 5
syscall

la $t0, a
sw $v0, 0($t0)
add $t1, $v0,$zero

li $v0, 5
syscall

la $t2, b
sw $v0, 0($t2)

add $t3, $t1, $v0

la $t4, c
sw $t3, 0($t4)

add $a0, $t3, $zero

li $v0, 1
syscall

li $v0, 10
syscall
