.data
	msg: .asciiz "Forneça um número decimal: "
	zero: .double 0.0			# Troque de .float para .double

.text
	li $v0, 4				# Imprimindo a mensagem para o usuário
	la $a0, msg
	syscall
	
	li $v0, 7				# Lendo o double e o salva em $f0, troquei de 6 para 7
	syscall
	
	ldc1 $f2, zero				# Como os registradores de um double variam de dois em dois, ent ldc1 $f2, e n $f1
	add.d $f12, $f1, $f0			# Troquei o add.s por add.d

	
	li $v0, 3				# Imprime o double que estiver em $f12
	syscall
	