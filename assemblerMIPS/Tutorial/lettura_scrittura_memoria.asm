# Esempio di lettura/scrittura di variabili allocate in memoria
.data
	a: 	.word 3
	vett1: 	.space 12
	vett2: 	.word 1,2,3
.text
main:	
	la $t1, a		# indirizzo di a in $t1
	la $t2, vett1		# indirizzo base di vett1 in $t2
	la $t6, vett2		# indirizzo base di vett2 in $t6
	lw $t3, 0($t1)		# $t3=a
	addi $t3,$t3,1		
	sw $t3, 0($t1)		# a=$t3
	li $t4, 1
	sw $t4, 0($t2)		# vett1[0]=1
	addi $t4,$t4,10
	sw $t4, 4($t2)		# vett1[1]=11
	addi $t4,$t4,20
	sw $t4, 8($t2)		# vett1[2]=31
fine: 	li $v0,10
	syscall
