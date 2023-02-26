'''
A classe JsonManager serve para leitura do banco de cartas
em um arquivo JSON e instanciar cada carta em um objeto da classe Card
'''


import json
import Card

class JsonManager(object):

    def __init__(self, filename):
        self.__filename: str = filename
    
    @property
    def filename(self):
        return self.__filename

    def all_cards(self):

        with open(self.__filename, encoding='utf-8') as arq_json:
            data = json.load(arq_json)

        all_cards: list[Card] = []

        for card_dict in data['cartas']:
            selected_attributes = {
                1: card_dict['votos'],
                2: card_dict['carreira'],
                3: card_dict['cargo'],
                4: card_dict['nascimento'],
                5: card_dict['filiados']
            }
            all_cards.append(Card.Card(card_dict['nome'], card_dict['imagem'], selected_attributes))

        return all_cards

