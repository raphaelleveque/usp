# Escreva uma função que verifica se um número inteiro positivo é par ou ímpar

.data
	fornecer_int: .asciiz "Forneça um número positivo: "
	par: .asciiz "É par"
	impar: .asciiz "É impar"

.text
.globl main
main:
	li $v0, 4			# Printa "Forneça um número positivo"
	la $a0, fornecer_int
	syscall
	
	li $v0, 5			# Lê um número em $v0 e move ele para $a0
	syscall
	move $a0, $v0
	
	jal is_pair			# jump and link para a função is_pair, passando como parâmetro $a0
	ja

	is_pair:
		li $t0, 2		# Coloco o número 2 num registrador temporário para posteriormente dividir $a0 por 2
		div $a0, $t0		# Divido $a0 por 2 para saber se o número digitado é par ou ímpar
		mfhi $v1		# $v1 recebe o resto da divisão de $a0 por 2
		
		beqz $v1, printarPar	# Se $v1 for igual a 0, então printa par
		bnez $v1, printarImpar	# Se $v1 não for igual a 0, então printa ímpar
		
		
		
		printarPar:
			li $v0, 4
			la $a0, par
			syscall
			
			j end		# Assim que terminar, vai fazer um jump para o fim, e encerrar o programa
		
		printarImpar:
			li $v0, 4
			la $a0, impar
			syscall
			
			j end
			
		end:
			li $v0, 10
			syscall
		
		
		
		
		
