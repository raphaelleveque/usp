# Escreva um programa que  leia um número inteiro positivo e imprime todos os números inteiros de zero até o número lido
.data
	msg: .asciiz "Digite um número inteiro: "
	espaco: .byte '\n'
.text
	li $v0, 4				# Imprime a mensagem "Digite um inteiro"
	la $a0, msg
	syscall
	
	li $v0, 5				# Lê um inteiro
	syscall
	move $t0, $v0				# Salva o inteiro lido em $t0
	
	move $t1, $zero				# Inicia uma variável em 0;  int t1 = 0
while:
	bgt $t1, $t0, saida			# Se o iterador for maior ou igual ao número, então sair do loop
	
	li $v0, 1				# Imprime o iterador t1
	move $a0, $t1
	syscall
	
	li $v0, 4				# Imprime o \n
	la $a0, espaco
	syscall
	
	addi $t1, $t1, 1			# Adiciona um no iterador
	j while					# Continuar o loop com um 'jump' while
	
saida:
	li $v0, 10				# Finaliza o programa
	syscall