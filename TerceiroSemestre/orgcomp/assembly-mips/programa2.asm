.data
	caractere: .byte 'A'				# Nome da variável: caractere; Tipo: .byte

.text 
	li $v0, 4					# Imprimir char ou string
	la $a0, caractere				# Carrega para o $a0 o caractere
	syscall
	
	li $v0, 10					# Encerra o programa principal
	syscall						# Chamada para ação, ou seja, de fato encerrá-lo