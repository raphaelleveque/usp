x = float(input("Digite um número: "))
error = 0.00000001
x0, x1 = 10, 20

while abs(x1 - x0) > error :
    x0 = x1
    x1 = (x0 + x / x0) / 2.0

print(f"Raíz: {x1}")
