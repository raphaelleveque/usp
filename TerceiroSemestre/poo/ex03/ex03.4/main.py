from classes import *

def main():
    loja = Loja()
    operacao = -1
    while operacao:
        print("Digite qual operação deseja realizar: ")
        print("1: Adicionar um produto")
        print("2: Buscar/Vender um produto por código de barras")
        print("3: Buscar/Vender um produto por nome")
        print("4: Ver o estoque")
        print("0: Encerrar o programa")
        operacao = int(input())
        if operacao == 1:
            produto = input("Deseja adicionar um livro, dvd ou cd? ")
            codigo_de_barras = int(input("Digite o código de barras do produto: "))
            quantidade = int(input(f"Quantos {produto}s deseja adicionar? "))
            nome = input(f"Qual o nome do {produto}? ")
            print("\n")

            loja.adicionar_produto(produto, codigo_de_barras, quantidade, nome)
        
        elif operacao == 2:
            codigo_de_barras = int(input("Digite o código de barras do produto: "))
            loja.buscar_produto(codigo_de_barras=codigo_de_barras)

        elif operacao == 3:
            nome = input("Digite o nome do produto: ")
            loja.buscar_produto(nome=nome)

        elif operacao == 4:
            loja.mostrar_estoque()




if __name__ == "__main__":
    main()