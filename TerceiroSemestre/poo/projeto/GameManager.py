import Player
import JsonManager
import random


class GameManager:

    def __init__(self):
        self.__deck_size = 24
        self.__total_attributes = 5
        self.__all_cards = []
        self.__player = Player.Player()
        self.__opponent = Player.Player()
        self.__selected_attribute: int = 0
        self.__file_name = 'trunfo.json'



    def get_cards_left_player(self) -> int:
        return self.__player.cards_left
    
    def get_cards_left_opponent(self) -> int:
        return self.__opponent.cards_left

    def select_attribute(self, att_n: int):
        self.__selected_attribute = att_n

    def get_card_info(self, player: bool = True) -> dict:
        card: JsonManager.Card = self.__player.cards[-1] if player else self.__opponent.cards[-1]
        return {
            "name": card.name,
            "img_source": card.img_source,
            "attributes": card.attributes
        }


    def compare_cards(self) -> int:
        attribute = self.select_attribute()
        
        player_card = self.__player.cards[-1]
        opponent_card = self.__opponent.cards[-1]

        positions = {
            "Presidente" : 9,
            "Senador" : 5
        }

        player_win:int = 0

        if attribute in [1, 4, 5]:
            player_card_value = int(player_card.attributes[attribute].replace('.', ''))
            opponent_card_value = int(opponent_card.attributes[attribute].replace('.', ''))

            if player_card_value > opponent_card_value:
                player_win = 1
            elif player_card_value == opponent_card_value:
                player_win = 0
            else:
                player_win = -1

        elif attribute == 2:
            player_card_value = int(player_card.attributes[attribute].replace('.', ''))
            opponent_card_value = int(opponent_card.attributes[attribute].replace('.', ''))

            if player_card_value < opponent_card_value:
                player_win = 1
            elif player_card_value == opponent_card_value:
                player_win = 0
            else:
                player_win = -1

        else:
            position_player = player_card.attributes[attribute]
            position_opponent = opponent_card.attributes[attribute]
                
            if positions[position_player] > positions[position_opponent]:
                player_win = 1
            elif positions[position_player] == positions[position_opponent]:
                player_win = 0
            else:
                player_win = -1

        self.rearrange_cards(player_win)
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

        self.__player.cards_left = len(self.__player.cards)
        self.__opponent.cards_left = len(self.__opponent.cards)


    def start_game(self) -> None:
        self.__all_cards = JsonManager(self.__file_name).all_cards()
        self.is_on = True
        self.deal_cards()

    def deal_cards(self) -> None:
        self.shuffle_cards()
        self.__player.cards = self.__all_cards[:self.__deck_size/2]
        self.__player.cards_left = len(self.__player.cards)
        self.__opponent.cards = self.__all_cards[self.__deck_size/2:]
        self.__opponent.cards_left = len(self.__opponent.cards)


    def shuffle_cards(self) -> None:
        random.shuffle(self.__all_cards)
