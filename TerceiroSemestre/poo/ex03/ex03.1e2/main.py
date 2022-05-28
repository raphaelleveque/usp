from classes import *
from funcoes import *
import sys

def comando_invalido():
    sys.exit("Comando inválido, programa encerrado! ")


def main():
    agenda_pf = []
    agenda_pj = []
    operacao = -1
    while operacao:
        print("\nDigite a operação de deseja realizar: ")
        print("1 - Adicionar contato")
        print("2 - Remover contato")
        print("3 - Visualizar todos os contatos")
        print("4 - Pesquisar contato por nome")
        print("5 - Pesquisar contato por CPF/CNPJ")
        print("0 - Encerrar programa")

        operacao = int(input())
        if operacao > 5 and operacao < 0:
            comando_invalido()

        if operacao == 1:
            print("\nPara adicionar contato de pessoa física, digite 1.")
            print("Para adicionar contato de pessoa jurídica, digite 2")
            tipo_pessoa = int(input())
            if tipo_pessoa == 1:
                operacao1(agenda_pf, tipo_pessoa)
            elif tipo_pessoa == 2:
                operacao1(agenda_pj, tipo_pessoa)
            else:
                comando_invalido()
        
        elif operacao == 2:
            print("\nPara remover contato de pessoa física, digite 1.")
            print("Para remover contato de pessoa jurídica, digite 2")
            tipo_pessoa = int(input())
            if tipo_pessoa == 1:
                operacao2(agenda_pf, tipo_pessoa)
            elif tipo_pessoa == 2:
                operacao2(agenda_pj, tipo_pessoa)
            else:
                comando_invalido()

        elif operacao == 3:
            operacao3(agenda_pf, agenda_pj)

        elif operacao == 4:
            print("Para pesquisar por uma pessoa física, digite 1")
            print("Para pesquisar por uma pessoa jurídica, digite 2")
            tipo_pessoa = int(input())
            if tipo_pessoa == 1:
                operacao4(agenda_pf)
            elif tipo_pessoa == 2:
                operacao4(agenda_pj)
            else:
                comando_invalido()

        elif operacao == 5:
            id = input("Digite o CPF/CNPJ do contato a ser procurado (apenas os números): ")
            if len(id) == 11:
                operacao5(agenda_pf, int(id))
            elif len(id) == 14:
                operacao5(agenda_pj, int(id))
            else:
                comando_invalido()
            
            



if __name__ == "__main__":
    main()