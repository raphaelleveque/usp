.data
	array:
		.align 2
		.word 10 20 90 80 50 60 70 30 40 100
	espaco: .byte ' '

.text
.globl main
main:
	

	li $t0, 0					# i = $t0
	li $t1, 0					# j = $t1
	li $t2, 10					# $t2 = tamanho
	li $t3, 0					# $t3 = swap
	addi $t4, $t1, 4				# $t4 = j+4 (4B)
		
	loop_i:
		bge $t0, $t2, sai_loop_i		# Se i >= TAM, sai do loop
		move $t1, $zero				# j = 0
		loop_j :
			bge $t1, $t2, sai_loop_i	# Se j >= TAM, sai do loop
			lw $t5, array($t1)		# $t5 = array[j]
			lw $t6, array($t4)		# $t6 = array[j+1]
			bgt $t5, $t6, swap		# Se array[j] > array[j+1], swap
			addi $t1, $t1, 4		# j++
			addi $t4, $t4, 4		# (j+1)++
			j loop_j
			
			swap:
				add $t3, $t5, $zero 	# tmp = array[j]
				move $t5, $t6		# array[j] = array[j+1]
				move $t6, $t3		# array[j+1] = tmp
				
				sw $t5, array($t1)
				sw $t6, array($t4)
				
				addi $t1, $t1, 4		# j++
				addi $t4, $t4, 4		# (j+1)++
				j loop_j
				
				
		
		sai_loop_j:
		addi $t0, $t0, 4			# i++
		j loop_i
	
	sai_loop_i:
	
	jal imprimeVetor
		
		

	imprimeVetor:
		move $t0, $zero
		loop:
			bge $t0, $t2, sai_loop
			lw $t1, array($t0)
			
			li $v0, 1
			move $a0, $t1
			syscall
			
			li $v0, 4
			la $a0, espaco
			syscall
			
			addi $t0, $t0, 4
			j loop
		sai_loop:
		jal fim
	
	fim:
		li $v0, 10
		syscall
	
		
		
		
		
		
		
		
		
		
		
		
	