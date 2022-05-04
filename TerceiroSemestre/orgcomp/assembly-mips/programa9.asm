# Leitura de strings
.data
	pergunta: .asciiz "Qual é o seu nome? "
	saudacao: .asciiz "Olá, "
	nome: .space 25					# .space serve para dizer qual o tamanho máximo da string
	
.text
	li $v0, 4					# Imprime a pergunta
	la $a0, pergunta
	syscall
	
	
	li $v0, 8					# Comando para ler string
	la $a0, nome 					# Carregando para o $a0 o nome que foi lido
	la $a1, 25 					# Informando para o registrador $a1 o tamanho para ser lido
	syscall
	
	
	li $v0, 4					# Mostrar a saudação
	la $a0, saudacao				# O nome estava salvo no $a0, e, com esse comando, eu perdi o antigo conteúdo de a0
	syscall						# Entretanto, o nome continua salvo na variável 'nome'
	
	li $v0, 4
	la $a0, nome
	syscall