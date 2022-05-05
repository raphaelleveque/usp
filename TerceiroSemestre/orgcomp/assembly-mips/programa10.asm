.data
	msg: .asciiz "Forneça um número decimal: "
	zero: .float 0.0			# Os coprocessadores n possuem um $zero

.text
	li $v0, 4				# Imprimindo a mensagem para o usuário
	la $a0, msg
	syscall
	
	li $v0, 6				# Lendo o float e o salva em $f0
	syscall
	
	lwc1 $f1, zero				# Aqui carregando o valor 0.0 para o registrador $f1
	add.s $f12, $f1, $f0			# Para imprimir um float, o número deve estar no $f12
						# Para mover o conteúdo de $f0 para $f12, eu necessito adicionar $f0 com 0.0 e salvar em $f12
	
	li $v0, 2				# Imprime o float que estiver em $f12
	syscall
	