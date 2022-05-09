from carta import *
from Random import *

class Baralho:
    def __init__(self):
        self.baralho = [Carta()] * 52
        self.mao = [Carta()] * 5
        for i in range(4):
            for j in range(13):
                self.baralho[j+i*13] = Carta(j, i)

    def inicia_mao(self):
        rand = Random()
        for i in range(5):
            print("Bar.py:: 15")
            posicao = rand.get_int_rand(51)
            while self.baralho[posicao].em_uso == True:
                posicao = rand.get_int_rand(51)
            self.baralho[posicao].em_uso = True
            self.mao[i] = self.baralho[posicao]
        print("Bar.py:: 21")
        return self.mao

    def renova_mao(self, troca_cartas):
        for i in range(len(troca_cartas)):
            if troca_cartas[i] > len(self.mao) + 1 or troca_cartas <= 0:
                print("Carta Inválida")
                break
            rand = Random()
            posicao = rand.get_int_rand(51)
            while self.baralho[posicao].em_uso == False:
                posicao = rand.get_int_rand(51)
            self.baralho[posicao].em_uso = True
            self.mao[troca_cartas[i]] = self.baralho[posicao]
        return self.mao

    def imprime_mao(self):
        line1:str
        line2:str
        line3:str
        line4:str
        line5:str
        for i in range(5):
            lines = self.mao[i].imprime_carta
            line1 += lines[0]
            line2 += lines[1]
            line3 += lines[2]
            line4 += lines[3]
            line5 += lines[4]
        
        print(line1)
        print(line2)
        print(line3)
        print(line4)
        print(line5)
        print(f"\n\n")

    def verifica_resultados(self):
        
    



