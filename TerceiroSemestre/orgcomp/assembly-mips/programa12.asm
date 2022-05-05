# Escreva um programa que lê um número inteiro e imprime se ele é par ou ímpar
.data
	msg: .asciiz "Digite um número"
	msgiguais: .asciiz "São iguais"
	msgdiferentes: .asciiz "São diferentes"
		
.text 	
	li $v0, 4
	la $a0, msg
	syscall
	
	li $v0, 5			# Lê um inteiro e o salva em $v0
	syscall
	move $t0, $v0			# Move o conteúdo de $v0 para $t0
	
	
	li $v0, 4
	la $a0, msg
	syscall
	
	li $v0, 5			# Lê outro inteiro
	syscall
	move $t1, $v0			# Agora $t0 e $t1 são dois registros com dois números
	
	
	
	beq $t0, $t1, iguais
	bne $t0, $t1, diferentes
	
					
iguais:
	li $v0, 4
	la $a0, msgiguais
	syscall
	
	li $v0, 10
	syscall
	
diferentes:
	li $v0, 4
	la $a0, msgdiferentes
	syscall
	
	li $v0, 10
	syscall