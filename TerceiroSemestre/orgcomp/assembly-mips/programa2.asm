.data
	caractere: .byte 'A'				# Nome da variável: caractere; Tipo: .byte

.text 
	li $v0, 4					# Imprimir char ou string
	la $a0, caractere				# Carrega para o $a0 o caractere
	syscall