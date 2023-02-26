'''
A classe Card é usada para facilitar o acesso
às informações de cada carta contida no jogo via
arquivo JSON.
'''

class Card(object):

    def __init__(self, nome=None, img_source=None, attributes=None):
        self.__name: str = nome
        self.__img_source: str = img_source
        self.__attributes: dict = attributes

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, nome):
        self.__name = nome

    @property
    def img_source(self):
        return self.__img_source

    @img_source.setter
    def img_src(self, img_source):
        self.__img_source = img_source

    @property
    def attributes(self):
        return self.__attributes

    @attributes.setter
    def attributes(self, attributes):
        self.__attributes = attributes
