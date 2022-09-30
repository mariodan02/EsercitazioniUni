.data
	a:	.word 1
	n:	.word 10
	msg:	.asciiz "a = "

.text 
	la $t1, a
	lw $t1, 0($t1)
	la $s6, n
	lw $s6, 0($s6)
	
	li $s3, 0		# $s3=0 i = 0
ciclo: 	slt $t0, $s3, $s6	# $t0 = 1 se i < n  
	beq $t0, $zero, end	# se i >= n esce dal ciclo  
	add $t1, $t1, $s3	# a=a+i
	addi $s3, $s3, 1	# i=i+1
	j ciclo			# ritorna a inizio ciclo
end: 
	# STAMPO IL RISULTATO DEL CALCOLO!!!
	li $v0, 4
	la $a0, msg
	syscall
	
	li $v0, 1
	add $a0, $t1, $zero
	syscall 
	
	li $v0, 10
	syscall

