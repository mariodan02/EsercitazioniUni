.data
msg: .asciiz "Inserisci la password: " 
psw: .space 32

.text
    li $s5,'\n'
    la $s0,msg
for_stampa:
          lbu $s1,($s0)
          beq $s1,$0,end_for_stampa
          move $a0,$s1
          jal putc
          addiu $s0,$s0,1
          j for_stampa

end_for_stampa:
#lettura password
la $s0,psw
for_lettura:
           jal getc
           beq $v0,$s5,endfor_lettura
           sb $v0,($s0)
           addiu $s0,$s0,1
           li $a0, '*'
           jal putc
           j for_lettura
endfor_lettura:
           sb $0, ($s0)
           
           li $v0,10
           syscall
           
           
           
           
#gestione della tastiera
getc:
                          # $v0 byte ricevuto
    li $t0,0xffff0000
loop:    
    lw $t1,0($t0)
                           #estraiamo il bit meno significativo che è il bit di ready
    andi $t1,$t1,0x0001
    beq $t1,$zero,loop
    lw $v0,4($t0)
    jr $ra  
    
    
    
#gestione del display   
putc:
     li $t0,0xffff0008
     
loop2:
     lw $t1,0($t0)
     andi $t1,$t1,0x0001
     beq $t1,$zero,loop2
     sw $a0,4($t0)
     jr $ra