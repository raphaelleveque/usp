import json

class Card(object):

    def __init__(self,nome = None, img_src = None, atributos = None):

        self.__name : str = nome
        self.__img_src: str = img_src
        self.__attributes: dict = atributos

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, nome):
        self.__name = nome

    @property
    def img_src(self):
        return self.__img_src
    
    @img_src.setter
    def img_src(self, img_src):
        self.__img_src = img_src

    @property
    def attributes(self):
        return self.__attributes

    @attributes.setter
    def attributes(self, atributos):
        self.__attributes = atributos

class JsonManager(object):

    def __init__(self, filename):
        self.__filename: str = filename
    
    @property
    def filename(self):
        return self.__filename

    @filename.setter
    def filename(self, filename):
        self.__filename = filename


    def all_Cards(self):

        with open(self.__filename, encoding='utf-8') as arq_json:
            data = json.load(arq_json)

        all_cards :list[Card] = []

        for i in data['cartas']:
            atr = {
            'nascimento':i['nascimento'],
            'votos':     i['votos'],
            'cargo':     i['cargo'],
            'carreira':  i['carreira'],
            'filiados':  i['filiados']
            }
            all_cards.append(Card(i['nome'], i['imagem'], atr))

        return all_cards

