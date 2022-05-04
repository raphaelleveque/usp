.data
	inteiro: .word 5				# Uma palavra de dados tem o tamanho de 32b, ou seja, 4B, o sizeof(int)

.text
	li $v0, 1					# Imprime um inteiro
	lw $a0, inteiro					# Não é mais Load Address, é Load Word; Pega o valor de 'inteiro' e coloca em $a0
	syscall 