from Random import *
class Carta:
    numero = None
    naipe = None
    em_uso = False

    def __init__(self, numero = None, naipe = None):
        self.numero = numero
        self.naipe = naipe
        
    def __str__(self): 
        if self.naipe == 0:
            naipe_img = '♣'
        elif self.naipe == 1:
            naipe_img = '♦'
        elif self.naipe == 2:
            naipe_img = '♥'
        else:
            naipe_img = '♠'

        cartas = [2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K', 'A']
        carta = cartas[self.numero]

        return f"{carta}{naipe_img}"