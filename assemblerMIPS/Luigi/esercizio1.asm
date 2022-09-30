.data
password: .space 32
.text
la $s0,password
li $t2,'\n'
for:
    jal getc
    beq $v0,$t2,fine
    sb $v0,($s0)
    addiu $s0,$s0,1
    li $a0,'*'
    jal putc
    j for

fine:
    sb $zero,($s0)
    
    
    
    li $v0,10
    syscall




getc:
     li $t0,0xffff0000
loop:
     lw $t1,0($t0)
     andi $t1,$t1,1
     beq $t1,$zero,loop
     lw $v0,4($t0)
     jr $ra




putc:
     li $t0,0xffff0008
loop2:
     lw $t1,0($t0)
     andi $t1,$t1,1
     beq $t1,$zero,loop2
     sw $a0,4($t0)
     jr $ra






