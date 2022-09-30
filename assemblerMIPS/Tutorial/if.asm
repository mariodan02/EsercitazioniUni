.data
	a:	.word 1
	b:	.word 2
	c:	.word 0
	msg1:	.asciiz "c = "
	msg2:	.asciiz "nessun risultato"

.text 
	la $s1,a
	lw $s1, 0($s1)
	la $s2,b
	lw $s2, 0($s2)
	slt $t0,$s1,$s2		# $t0=1 se a<b
	beq $t0,$zero,noout	# se $t0=0 esce dall’if
	add $s0, $s1, $s2	# $s0=a+b
	la $s3,c
	sw $s0, 0($s3) 		#c=$s0
	
	# STAMPO IL RISULTATO DEL CALCOLO!!!
	li $v0, 4
	la $a0, msg1
	syscall			# stampo c=
	li $v0, 1
	add $a0, $s0, $zero
	syscall 		# stampo c
	j fine
	noout:	li $v0, 4
	la $a0, msg2
	syscall			# stampo "nessun risultato"
fine:	li $v0, 10
	syscall
