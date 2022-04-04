x = int(input())
menorDivisor = -1

for i in range(2, x) :
    if x % i == 0 :
        menorDivisor = i
        break

if menorDivisor == -1 :
    print(f"{x} é primo")
else :
    print(f"{menorDivisor} é seu menor divisor")
