# Esempio di uso dello stack per il passaggio dei parametri. 
# Si vuole che il valore ritornato dalla funzione sia passato sul fondo (indirizzo piu' alto) dello stack 
# Come e' possibile verificare eseguendo il codice il risultato non e' corretto. Trova gli errori e correggili
.data

.text
.globl main
main:
	li $a0,2		# primo parametro effettivo da passare alla procedura (a)
	li $a1,3		# secondo parametro effettivo da passare alla procedura (b)
	li $a2,4		# terzo parametro effettivo da passare alla procedura (c)
	li $a3,5		# quarto parametro effettivo da passare alla procedura (d)

	# uso di registri che devono essere conservati nella chiamata
	li $s0,100		
	li $s1,200
	li $s2,300
	
	# alloco spazio sullo stack per passare i valori dei parametri da passare alla procedura
	addi $sp,$sp,-16
	
	sw $a0, 12($sp)		# carico sullo stack il valore del primo parametro
	sw $a1, 8($sp)		# carico sullo stack il valore del secondo parametro
	sw $a2, 4($sp)		# carico sullo stack il valore del terzo parametro
	sw $a3, 0($sp)		# carico sullo stack il valore del quarto parametro
	
	jal fun			# salto alla procedura 
	
	lw $a0, 0($sp)		# copia del valore di ritorno in $a0 per la stampa del risultato
	li   $v0, 1          	# system call per la stampa 
	syscall  
	li   $v0, 10         	# system call per la stampa
	syscall  
	
fun:
	# g,h,i,j associati a $a0 ... $a3, f associata a $v0
 	# i valori contenuti nei registri $s0, $s1, $s2 DEVONO essere salvati nello stack PRIMA del loro uso

	addi $sp,$sp,-12 	# alloca nello stack lo spazio per salvare il contenuto dei registri
       
       	sw $s0, 8($sp) 		# salvataggio di $s0
       	sw $s1, 4($sp) 		# salvataggio di $s1
       	sw $s2, 0($sp) 		# salvataggio di $s2
       	
       	lw $t0, 28($sp)		# carico in $t0 il primo parametro effettivo
       	lw $t1, 24($sp)		# poi il secondo ...
       	lw $t2, 20($sp)		# il terzo ...
       	lw $t3, 16($sp)		# e infine il quarto
       	
	add $s0,$t0,$t1		# $s0 = g+h
	add $s1,$t2,$t3 	# $s1 = i+j
	sub $s2,$s0,$s1 	# $s2 = f
	sw $s2, 12 ($sp) 	# carico sullo stack il valore di f
	
	# ripristino del contenuto dei registri $s0, $s1, $s2 PRIMA di uscire dalla procedura
	lw $s2, 0($sp) # ripristino di $s2
  	lw $s1, 4($sp) # ripristino di $s1
  	lw $s0, 8($sp) # ripristino di $s0
  	addiu $sp, $sp, 12 # deallocazione dello stack per eliminare 3 registri
  	jr $ra #ritorno al prog. chiamante


