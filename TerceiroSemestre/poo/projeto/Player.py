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
    