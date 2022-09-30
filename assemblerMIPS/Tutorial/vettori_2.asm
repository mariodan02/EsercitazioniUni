.data
a: .word 0,1,2,3,4,5,6,7,8,9
b: .word 9,8,7,6,5,4,3,2,1,0
c: .space 40

.text
main:	li $t0, 0 			# inizializzazione di i
	li $t1, 10 			# inizializzazione del numero di ripetizioni
	li $t2, 36			# inizializzazione offset per elementi di B
	la $a1, a
	la $a2, b
	la $a3, c

	
loop:
	lw $t3, 0($a1) 			# leggo A[i]
	add $t4,$a2,$t2			# indirizzo elemento (9-i)-esimo di 	
	lw $t4, 0($t4) 			# leggo B[9-i]
	add $t3, $t3, $t4 		# A[i] + B[9-i]
	sw $t3, 0($a3) 			# C[i] = A[i] + B[9-i]
	addi $a1, $a1,4 		# indirizzo i+1-esimo elemento di A
	addi $a3,$a3,4			# indirizzoi-esimo elemento di C
	addi $t0,$t0,1			# i=i+1
	addi $t2, $t2,-4 		# aggiorno offset $t2=9-i
	bne $t0, $t1, loop 		# se I < 10 ripeti

li $v0,10
syscall
