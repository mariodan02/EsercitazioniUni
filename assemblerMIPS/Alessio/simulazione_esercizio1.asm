.data

# nada
# hakuna matata

.text
 lw $s0, 0($sp)
 lw $s1, 4($sp) # y
 lw $s2, 8($sp) # z
 
 addi $s4, $zero, 1
 slt $s3, $s0, $s1 # y > max
 bne $s3, $s4, yMax
 slt $s3, $s0, $s2
 bne $s3, $s4, zMax
 
 yMax:
 	addi $sp, $sp, 8
 	sw $s1, 0($sp)
 	jr $ra
 
 zMax:
 	addi $sp, $sp, 8
 	sw $s2, 0($sp)
 	jr $ra
 	
 