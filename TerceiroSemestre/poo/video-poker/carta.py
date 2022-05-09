from Random import *
class Carta:
    numero = None
    naipe = None
    em_uso = False

    def __init__(self, numero = None, naipe = None):
        self.numero = numero
        self.naipe = naipe
        
    def imprime_carta(self): 
        if self.naipe == 0:
            naipe_img = '♣️'
        elif self.naipe == 1:
            naipe_img = '♦️'
        elif self.naipe == 2:
            naipe_img = '❤️'
        else:
            naipe_img = '♠️'
        
        line1 = "+-----------+  "
        line2 = "|           |  "
        line3 = f"|     {self.numero}{naipe_img}     |  "
        line4 = "|           |  "
        line5 = "+-----------+  "
        return [line1, line2, line3, line4, line5]