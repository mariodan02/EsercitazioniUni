.data
	a:		.word 3
	b:		.word 2
	c:		.space 4
	msg:	.asciiz "c = "

.text 
	la $s1,a
	lw $s1, 0($s1)
	la $s2,b
	lw $s2, 0($s2)
	bne $s1, $s2, else	# se a!=b salta a else
	add $s0, $s1, $s2	# c=a+b
	j end			# esce dall’if
else:	sub $s0, $s1, $s2	# c=a-b
end:	la $s3,c
	sw $s0, 0($s3) 	
	# STAMPO IL RISULTATO DEL CALCOLO!!!
	li $v0, 4
	la $a0, msg
	syscall
	
	li $v0, 1
	add $a0, $s0, $zero
	syscall 
	
	li $v0, 10
	syscall
