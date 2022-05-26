num = int(input("Digite um inteiro: "))
array = [True for i in range(num)]
array[0] = array[1] = False

for i in range(2, num) :
    if array[i] == True :
        for j in range(2 * i, num, i) :
            array[j] = False 

i = num - 1
while array[i] == False :
    i -= 1

print(f"{i} é o número primo inferiormente mais próximo de {num}")