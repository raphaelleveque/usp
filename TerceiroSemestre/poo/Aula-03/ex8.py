
import math

def derivada(a) :
    return 3 * math.pow(a, 2) - 2 * a - 13

def equacao(a) :
    return math.pow(a, 3) - math.pow(a, 2) - 13 * a + 8

x0 = float(input("Cute inicial: "))
x1 = x0 - ( equacao(x0) / derivada(x0) )
tolerancia = math.pow(10, -7)
i = 0

while abs(equacao(x1)) > tolerancia :
    i += 1
    x0 = x1
    x1 = x0 - (equacao(x0) / derivada(x0))

print(f"A raíz é igual a {x1}")
print(f"Foram necessárias {i} iterações")

