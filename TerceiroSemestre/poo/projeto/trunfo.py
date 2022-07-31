import Card
import GameManager
import Player
import random



def main():
    game = GameManager.GameManager()
    player = Player.Player()
    oponent = Player.Player()

    game.start_game(player, oponent)

    while game.is_on:

        
        if player.cards_left == 0:
            oponent.win = True
            game.is_on = False
        elif oponent.cards_left == 0:
            player.win = True
            game.is_on = False
    





if __name__ == "__main__":
    main()