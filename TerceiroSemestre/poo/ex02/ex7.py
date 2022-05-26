import math

def bissecao(a) :
    return math.pow(a, 3) - math.pow(a, 2) - 13 * a + 8

tolerancia = math.pow(10, -7)
a = float(input())
b = float(input())
i = 0

while True :
    i += 1
    c = (a + b) / 2
    if bissecao(c) == 0 or abs(b - a) < tolerancia :
        break
    res = bissecao(a) * bissecao(c)
    if res < 0 :
        b = c
    else :
        a = c

print(f"A raíz é '{c}'")
print(f"Foram utilizadas {i} repetições")
