.data
	msg: .asciiz "O resultado da multiplicação é: "
.text
	li $t0, 12				# Carregando 12 para o registrador $t0
	li $t1, 10				# Carregando 10 para o registrador $t1
	mul $s0, $t0, $t1			# Multiplicando $t0 e $t1 e salvando no $s0
	
	li $v0, 4				# Irei imprimir uma string
	la $a0, msg
	syscall
	
	li $v0, 1				# Irei imprimir um número inteiro
	move $a0, $s0 				# Tenho que colocar o resultado da multiplicação ($s0) no registrador $a0
	syscall 
	
	