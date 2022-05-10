from carta import *
from Random import *

class Baralho:
    cartas = [2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K', 'A']
    def __init__(self):
        self.baralho = [Carta()] * 52
        self.mao = [Carta()] * 5
        for i in range(4):
            for j in range(13):
                self.baralho[j+i*13] = Carta(j, i)

    def inicia_mao(self):
        rand = Random()
        for i in range(5):
            posicao = rand.get_int_rand(51)
            while self.baralho[posicao].em_uso == True:
                posicao = rand.get_int_rand(51)
            self.baralho[posicao].em_uso = True
            self.mao[i] = self.baralho[posicao]
        return self.mao

    def renova_mao(self, troca_cartas):
        for i in range(len(troca_cartas)):
            troca_cartas[i] = int(troca_cartas[i]) - 1
            print(f"\n\n{troca_cartas}\n\n")
            if troca_cartas[i] >= len(self.mao) + 1 or troca_cartas[i] < 0:
                print("Carta Inválida")
                break
            rand = Random()
            posicao = rand.get_int_rand(51)
            while self.baralho[posicao].em_uso == False:
                posicao = rand.get_int_rand(51)
            self.baralho[posicao].em_uso = True
            self.mao[troca_cartas[i]] = self.baralho[posicao]
        return self.mao

    def __str__(self):
        for i in range(5):
            print(self.mao[i], end="        ")
        return ""

    def verifica_resultados(self, aposta):
        self.mao.sort(key=lambda x: x.numero)
        for i in range(5):
            print(self.mao[i], end="        ")

        quantidade = [0] * 13
        for i in range(5):
            quantidade[self.mao[i].numero] += 1
        naipes = [0] * 4 
        for i in range(5):
            naipes[self.mao[i].naipe] += 1

        mesmo_nipe = naipes.count(5) > 0
        mesmo_nipe_sem_ordem = False
        if mesmo_nipe:
            if all(x <= 1 for x in quantidade):
                if self.mao[0].numero == 10:
                    return 200 * aposta
                if self.mao[4].numero == self.mao[0].numero + 4:
                    return 100 * aposta
                mesmo_nipe_sem_ordem = True
        
        if naipes.count(4) > 0:
            return aposta * 50
        
        if quantidade.count(3) > 0 and quantidade.count(2) > 0:
            return aposta * 20

        if mesmo_nipe and mesmo_nipe_sem_ordem:
            return aposta * 10
        
        seguidas = True
        for i in range(4):
            if not (self.mao[i].numero == self.mao[i + 1].numero):
                seguidas = False
                break
        if seguidas:
            return 5 * aposta

        if quantidade.count(3) > 0:
            return aposta * 2
        
        if quantidade.count(2) == 2:
            return aposta
        
        return -aposta
        

        


        


        

    



