'''
A Classe Player se refere a cada jogador de forma genérica
definindo alguns métodos sobre as cartas que ele possui.
'''

import Card


class Player:

    def __init__(self):
        self.__cards: list[Card.Card] = []
        self.__cards_left: int = 0

    @property
    def cards(self):
        return self.__cards
    
    @property
    def cards_left(self):
        return self.__cards_left

    def update_card_counter(self):
        self.__cards_left = len(self.__cards)

    def give_cards(self, cards: list):
        self.__cards = cards
