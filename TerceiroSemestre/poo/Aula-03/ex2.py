import math

def lendoEntrada() :
    x = 0
    inputRead = False
    while not inputRead:
        try:
            x = float(input("Digite um número: "))
            inputRead = True 
        except:
            print("Digite um número válido: ")

    return x 


def bhaskara(a, b, c) :
    delta = b * b - 4 * a * c 

    if delta < 0 :
        print("Nenhuma solução possível")
    elif delta == 0:
        print("Solução com apenas uma solução possível")
        print(f"x = {-b / 2 * a}")
    else :
        print("Duas soluções possíveis")
        print(f"x1 = {-b + math.sqrt(delta) / 2 * a}")
        print(f"x2 = {-b - math.sqrt(delta) / 2 * a}")


a = lendoEntrada()
b = lendoEntrada()
c = lendoEntrada()

bhaskara(a, b, c)
