from baralho import Baralho

def main():
    print("Bem Vindo ao VideoPoker!!")
    creditos = 200
    aposta = 0
    continua = True
    while continua:
        print(f"Seu saldo é de {creditos} créditos")
        print("Digite o valor da aposta ou digite 'F' para terminar: ", end="")
        resposta = input()
        if resposta == 'F' or resposta == 'f':
            continua = False
            break

        aposta = int(resposta)
        while aposta > creditos:
            print("Valor de aposta inferior ao número de créditos, tente outra aposta!")
            print(f"Digite um número menor ou igual a {creditos} para sua nova aposta: ", end="")
            aposta = int(input())
        creditos -= aposta
    
        mao = Baralho()
        mao.inicia_mao()
        print("Sua mão é: ")
        print(mao)
        print()
        for _ in range(2):
            print("Digite o número das cartas que você deseja trocar. Caso não deseje trocar nenhuma, digite 0: ", end="")
            troca_cartas_tmp = input()
            if troca_cartas_tmp != "0":
                troca_cartas = []
                troca_cartas = troca_cartas_tmp.split()
                mao.renova_mao(troca_cartas)
                print(mao)
            else:
                break

        creditos += mao.verifica_resultados(aposta)

        if creditos <= 0:
            continua = False

        
        






if __name__ == "__main__":
    main()