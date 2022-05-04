.text
	li $t0, 32				# Carrega 32 no registrador $t0
	li $t1, 5 				# Carrega 5 no registrador $t1
	
	div $t0, $t1 				# lo = t0 / t1;  hi = t0 % t1
	
	mflo $s0				# $s0 recebe a divisao;  int s0 = t0 / t1
	mfhi $s1 				# $s1 recebe o módulo;   int s1 = t0 % t1
	
	
	li $t2, 128				# Carrega o número 128 para o registrador $t2
	srl $s2, $t2, 3				# Faz o shift right, ou seja, divide 128 por 2^3, que resulta em 16
						# Para fazer o shift left, basta fazer sll