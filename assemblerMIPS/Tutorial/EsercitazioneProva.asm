.data
a: .word -1,2,-3,4,5  #vettore a
stmp: .asciiz "Somma elementi: "
CTRL: .asciiz "\n"

.text
main:
li $a0,5 #dimensione del vettore a
la $a1,a #caricamento in $a1 del vettore a

jal addiziona_positivi

add $t0,$v0,$zero #ritorno del valore della funzione

#stampa stringa
li $v0,4
la $a0,stmp
syscall

#stampa valore di ritorno
li $v0,1
add $a0,$t0,$zero
syscall

# Termine del programma
li $v0,10
syscall  



addiziona_positivi:
li $t1,0 #contatore del ciclo i
li $t2,0 #variabile di somma

for:
bge $t1,$a0,end_for
lw $t3,($a1) #caricamento del valore puntato dell'array a

#condizione if($t3<0)
blt $t3,0,else
add $t2,$t2,$t3 # somma = somma + a[i]
else:

addi $a1,$a1,4 #aumento del puntatore del vettora a
addi $t1,$t1,1 #aumento del contatore i
j for

end_for:
add $v0,$t2,$zero #copia del valore di $t2 in $v0
jr $ra

