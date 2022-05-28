from classes import *

def main():
    operacao = -1
    figura:FigurasGeometricas
    while operacao:
        print("Para adicionar um círculo, digite 1")
        print("Para adicionar um quadrado, digite 2")
        print("Para adicionar um retângulo, digite 3")
        print("Para encerrar o programa, digite 0")
        operacao = int(input())

        if operacao > 3 and operacao < 0:
            exit("Comando inválido")
        
        if operacao == 0:
            break

        if operacao == 1:
            cor = input("Qual a cor do círculo? ")
            preenchida = input("O círculo está preenchido (s/n)? ")
            if preenchida == "s":
                preenchida = True
            elif preenchida == "n":
                preenchida = False
            raio = int(input("Qual o raio do círculo? "))
            figura = Circulo(raio, cor, preenchida)
        
        elif operacao == 2:
            cor = input("Qual a cor do quadrado? ")
            preenchida = input("O quadrado está preenchido (s/n)? ")
            if preenchida == "s":
                preenchida = True
            elif preenchida == "n":
                preenchida = False
            lado = int(input("Qual o lado do quadrado? "))
            figura = Quadrado(lado, cor, preenchida)
        
        elif operacao == 3:
            cor = input("Qual a cor do retângulo? ")
            preenchida = input("O retângulo está preenchido (s/n)? ")
            if preenchida == "s":
                preenchida = True
            elif preenchida == "n":
                preenchida = False
            lado1, lado2 = map(int, input("Quais os lados do retângulo? ").split())
            figura = Retangulo(lado1, lado2, cor, preenchida)

        print(figura)




if __name__ == "__main__":
    main()
