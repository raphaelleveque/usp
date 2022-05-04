# Exercício: Escreva um programa que lê uma idade e a imprime, no formato abaixo
# Fornaça sua idade: 
# Sua idade é: 

.data
	saudacao: .asciiz "Forneça sua idade: "
	finalizacao: .asciiz "Sua idade é: "

.text 
	li $v0, 4			# Imprime uma string
	la $a0, saudacao		# Carrega a string para o $a0
	syscall				# De fato a imprime
	
	li $v0, 5			# Leitura de inteiros
	syscall				# Lê o inteiro
	move $t0, $v0			# Salva o valor do inteiro em um outro registrador
	
	li $v0, 4			# Altero o valor de $v0, por isso foi necessário salvar o número em outro reg
	la $a0, finalizacao
	syscall
	
	li $v0, 1			# Imprime um inteiro
	move $a0, $t0			# Esse inteiro já está no registrador $t0, então basta mover de $t0 para $a0
	syscall