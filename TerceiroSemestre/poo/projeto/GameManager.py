'''
A Classe GameManager é a responsável pelo controle das ações no jogo
onde informações sobre cada jogador e cartas que ele possui são
organizadas por meio de métodos.
'''

import Player
import Card
import JsonManager
import random

class GameManager:

    def __init__(self):
        self.__deck_size = 24
        self.__all_cards = []
        self.__player = Player.Player()
        self.__opponent = Player.Player()
        self.__file_name = 'trunfo.json'
        self.__game_is_over = False
        self.__attribute_code = {
            "votos": 1,
            "carreira": 2,
            "cargo": 3,
            "nascimento": 4,
            "filiados": 5
        }
        self.start_game()

    @property
    def deck_size(self):
        return self.__deck_size

    @property
    def game_is_over(self):
        return self.__game_is_over

    def get_cards_left_player(self) -> int:
        return self.__player.cards_left
    
    def get_cards_left_opponent(self) -> int:
        return self.__opponent.cards_left

    def get_card_info(self, player: bool = True) -> dict:
        card: Card = self.__player.cards[-1] if player else self.__opponent.cards[-1]
        return {
            "name": card.name,
            "img_source": card.img_source,
            "attributes": card.attributes
        }

    def compare_cards(self, attribute_n: int) -> int:
        player_card = self.__player.cards[-1]
        opponent_card = self.__opponent.cards[-1]

        role_importance = {
            "Sem Cargo": 0,
            "Vereador": 1,
            "Deputado Estadual": 2,
            "Deputado Federal": 3,
            "Senador" : 4,
            "Ministro": 5,
            "Governador": 6,
            "Presidente" : 7,
            "Policia Federal": 8,
        }

        if attribute_n in [1, 4, 5]:
            player_card_value = player_card.attributes[attribute_n]
            opponent_card_value = opponent_card.attributes[attribute_n]

            if player_card_value > opponent_card_value:
                player_win = 1
            elif player_card_value == opponent_card_value:
                player_win = 0
            else:
                player_win = -1

        elif attribute_n == 2:
            player_card_value = player_card.attributes[attribute_n]
            opponent_card_value = opponent_card.attributes[attribute_n]

            if player_card_value < opponent_card_value:
                player_win = 1
            elif player_card_value == opponent_card_value:
                player_win = 0
            else:
                player_win = -1

        else:
            position_player = player_card.attributes[attribute_n]
            position_opponent = opponent_card.attributes[attribute_n]
                
            if role_importance[position_player] > role_importance[position_opponent]:
                player_win = 1
            elif role_importance[position_player] == role_importance[position_opponent]:
                player_win = 0
            else:
                player_win = -1

        self.rearrange_cards(player_win)
        self.__game_is_over = (self.__player.cards_left == 0 or self.__opponent.cards_left == 0)
        return player_win

    def rearrange_cards(self, player_win: int) -> None:
        player_card = self.__player.cards[-1]
        opponent_card = self.__opponent.cards[-1]
        
        if player_win == 0:
            self.__player.cards.insert(0, player_card)
            self.__opponent.cards.insert(0, opponent_card)
        elif player_win == 1:
            self.__player.cards.insert(0, player_card)
            self.__player.cards.insert(0, opponent_card)
        else:
            self.__opponent.cards.insert(0, opponent_card)
            self.__opponent.cards.insert(0, player_card)

        self.__player.cards.pop()
        self.__opponent.cards.pop()

        self.__player.update_card_counter()
        self.__opponent.update_card_counter()

    def start_game(self) -> None:
        self.__all_cards = JsonManager.JsonManager(self.__file_name).all_cards()
        self.deal_cards()

    def deal_cards(self) -> None:
        self.shuffle_cards()
        self.__player.give_cards(self.__all_cards[:self.__deck_size//2])
        self.__opponent.give_cards(self.__all_cards[self.__deck_size//2:])
        self.__player.update_card_counter()
        self.__opponent.update_card_counter()

    def shuffle_cards(self) -> None:
        random.shuffle(self.__all_cards)
