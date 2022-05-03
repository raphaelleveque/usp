.data							# Área para dados na memória principal
	msg: .asciiz "Hello, World!\n"			# msg é uma variável que contem caracteres ascii

.text						        # Área para instruções do programa
	li $v0, 4					# Instrução para impressão de String
	la $a0, msg					# Load adress; Indica o endereço da msg no registrador $a0
	syscall						# syscall imprime o que estiver dentro do registrador $a0