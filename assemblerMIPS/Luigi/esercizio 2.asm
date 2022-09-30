.data
msg: .asciiz "Inserisci valore"

.text

la $s0, msg
for_stampa:
    lbu $s1, ($s0)
    beq $s1, $0, end_for_stampa
    move $a0, $s1
    jal putc
    addiu $s0, $s0, 1
    j for_stampa
    j get_hexint
end_for_stampa:

get_hexint:
       #vo valore ricevuto
       #v1 flag di input corretto
loop:
       jal getc
       move $t5,$0
       #controlla che $vo sia diverso da \n
       li $t0,'F'
       bgt $v0,$t0, ch_fail
       li $t1,'A'
       blt $v0,$t1,ch_fail
       sub $t0,$v0,$t1
       addi $t0,$t0,10
       j update
       
 ch_fail:
        li $t1,'9'
        bgt $v0,$t1,fail
        li $t1,'0'
        blt $v0,$t1,fail
        sub $t0,$v0,$t1
 
fail:
     li $v0,10
     syscall
update:
      sll $t5, $t5,4
      addu $t5,$t5,$t0             





getc:
    
      li $t0,0xffff0000
    
gcloop:
      lw $t1 ($t0)
      andi $t1,$t1,0x0001
      beq $t1,$0,gcloop
      lw $v0,4($t0)
      jr $ra
      
      
      
putc:
     li $t0,0xffff0008

pcloop:
      lw $t1,0($t0)
      andi $t1,$t1,0x0001
      beq $t1,$0,pcloop
      sw $a0,4($t0)
      jr $ra
      
