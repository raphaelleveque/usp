'''
A interface.py é utilizada para conexão da biblioteca Kivy
com alguns métodos utilizados no jogo, sendo a responsável
pelo envio de informações à interface gráfica.
'''
from GameManager import GameManager
from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.uix.popup import Popup
from kivy.config import Config
Config.set('graphics', 'resizable', False)


class StartWindow(GridLayout):
    button_color = "#506c7a"
    background_color = "#2c282d"
    instructions_text = "Cada Jogador Inicia com 12 cartas.\nO jogador escolhe um atributo e a carta do topo de seu baralho é comparada com a carta no topo do baralho do oponente. A carta com o melhor atributo vence, e o vencedor recebe a carta do perdedor.\nQuando um dos jogadores não tiver mais cartas o jogo acaba e o jogador com cartas restantes será o vencedor.\n\nAtributos:\nAno de nascimento: Cartas com canditados mais jovens vencem.\nInício da carreira: Cartas cujos candidatos iniciaram a carreira antes vencem.\nNúmero de votos: Cartas com maior número de votos vencem.\nNúmero de filiados no partido: Cartas com maior número de filiados vencem.\nCargo: Cartas com melhor cargo vencem.\n\nMelhores cargos em ordem decrescente: Polícia federal, Presidente, Governador, Ministro, Senador, Deputado Federal, Deputado Estadual, Vereador, Sem Cargo."

    @classmethod
    def show_instructions(cls):
        Popup(title='Instruções',
              content=Label(text=cls.instructions_text, text_size=(500, None), halign='left', valign='center'),
              size_hint=(None, None),
              size=(600, 600)).open()

    @staticmethod
    def start_game():
        MainWindowApp().run()


class MainWindow(GridLayout):
    game: GameManager = GameManager()

    green_hex = "#009c3b"
    yellow_hex = "#ffdf00"

    n_cards = game.deck_size
    player_card_img_source = "images/" + game.get_card_info(player=True)["img_source"]
    label_bg_color = "#506c7a"
    show_button = True
    selected_attribute_desc_n = -1
    attribute_descs = {
        1: "Número de votos",
        2: "Ano de início da carreira",
        3: "Cargo mais alto alcançado",
        4: "Ano de nascimento",
        5: "Filiados do partido"
    }
    player_card_info = game.get_card_info(player=True)
    opponent_card_info = game.get_card_info(player=False)

    def select(self, selected_n: int):
        self.selected_attribute_desc_n = selected_n
        self.ids.opponent_card_image.source = "images/" + self.opponent_card_info["img_source"]

        self.ids.opponent_attributes_label_1.text = str(self.attribute_descs[1]) + ": " + \
            str(self.opponent_card_info["attributes"][1])
        self.ids.opponent_attributes_label_2.text = str(self.attribute_descs[2]) + ": " + \
            str(self.opponent_card_info["attributes"][2])
        self.ids.opponent_attributes_label_3.text = str(self.attribute_descs[3]) + ": " + \
            str(self.opponent_card_info["attributes"][3])
        self.ids.opponent_attributes_label_4.text = str(self.attribute_descs[4]) + ": " + \
            str(self.opponent_card_info["attributes"][4])
        self.ids.opponent_attributes_label_5.text = str(self.attribute_descs[5]) + ": " + \
            str(self.opponent_card_info["attributes"][5])

        self.ids.opponent_card_name_label.text = "Carta do oponente: " + self.opponent_card_info["name"]

        self.ids.top_left_grid.opacity = 1
        self.ids.winner_name_label.opacity = 1
        self.ids.winner_desc_label.opacity = 1
        self.ids.next_round_button.opacity = 1

        self.ids.next_round_button.disabled = False
        self.ids.select_btn1.disabled = True
        self.ids.select_btn2.disabled = True
        self.ids.select_btn3.disabled = True
        self.ids.select_btn4.disabled = True
        self.ids.select_btn5.disabled = True

        winner = self.game.compare_cards(selected_n)

        if winner == 0:
            self.ids.winner_name_label.text = "A RODADA TERMINOU EMPATADA"
            self.ids.winner_desc_label.text = "O valor do atributo \"" + \
                self.attribute_descs[self.selected_attribute_desc_n] + \
                "\" é igual nas duas cartas."
        elif winner == 1:
            self.ids.winner_name_label.text = "VOCÊ VENCEU A RODADA"
            self.ids.winner_desc_label.text = "O valor do atributo \"" + \
                self.attribute_descs[self.selected_attribute_desc_n] + \
                "\" é melhor na sua carta."
        else:
            self.ids.winner_name_label.text = "OPONENTE VENCEU A RODADA"
            self.ids.winner_desc_label.text = "O valor do atributo \"" + \
                self.attribute_descs[self.selected_attribute_desc_n] + \
                "\" é melhor na carta do oponente."

        player_labels = {
            1: self.ids.player_attributes_label_1,
            2: self.ids.player_attributes_label_2,
            3: self.ids.player_attributes_label_3,
            4: self.ids.player_attributes_label_4,
            5: self.ids.player_attributes_label_5
        }

        opponent_labels = {
            1: self.ids.opponent_attributes_label_1,
            2: self.ids.opponent_attributes_label_2,
            3: self.ids.opponent_attributes_label_3,
            4: self.ids.opponent_attributes_label_4,
            5: self.ids.opponent_attributes_label_5
        }

        player_labels[self.selected_attribute_desc_n].text_color = "#ff0000"
        opponent_labels[self.selected_attribute_desc_n].text_color = "#ff0000"

    def get_player_card_name(self) -> str:
        return "Sua carta: " + self.player_card_info["name"]

    def get_player_att(self, n_att: int) -> str:
        return self.attribute_descs[n_att] + ": " + \
            str(self.player_card_info["attributes"][n_att])

    def get_cards_left_player(self) -> str:
        return "Cartas restantes para o jogador: " + str(self.game.get_cards_left_player())

    def get_cards_left_opponent(self) -> str:
        return "Cartas restantes para o oponente: " + str(self.game.get_cards_left_opponent())

    def next_round(self):
        if self.game.game_is_over:
            if self.game.get_cards_left_player() > 0:
                winner_txt = "O jogador venceu."
            else:
                winner_txt = "O jogador perdeu."

            Popup(title='FIM DE JOGO',
                content=Label(text=winner_txt),
                size_hint=(None, None),
                size=(400, 400),
                on_dismiss=App.get_running_app().stop()).open()
            return

        self.ids.opponent_card_image.source = "images/unknown_card.png"

        self.ids.top_left_grid.opacity = 0
        self.ids.winner_name_label.opacity = 0
        self.ids.winner_desc_label.opacity = 0
        self.ids.next_round_button.opacity = 0

        self.ids.select_btn1.disabled = False
        self.ids.select_btn2.disabled = False
        self.ids.select_btn3.disabled = False
        self.ids.select_btn4.disabled = False
        self.ids.select_btn5.disabled = False

        self.player_card_info = self.game.get_card_info(player=True)
        self.opponent_card_info = self.game.get_card_info(player=False)

        self.ids.player_card_image.source = "images/" + self.player_card_info["img_source"]

        self.ids.player_attributes_label_1.text = str(self.attribute_descs[1]) + ": " + \
            str(self.player_card_info["attributes"][1])
        self.ids.player_attributes_label_2.text = str(self.attribute_descs[2]) + ": " + \
            str(self.player_card_info["attributes"][2])
        self.ids.player_attributes_label_3.text = str(self.attribute_descs[3]) + ": " + \
            str(self.player_card_info["attributes"][3])
        self.ids.player_attributes_label_4.text = str(self.attribute_descs[4]) + ": " + \
            str(self.player_card_info["attributes"][4])
        self.ids.player_attributes_label_5.text = str(self.attribute_descs[5]) + ": " + \
            str(self.player_card_info["attributes"][5])

        self.ids.player_card_name_label.text = "Sua carta: " + self.player_card_info["name"]
        self.ids.opponent_card_name_label.text = "Carta do oponente: ?"

        self.ids.cards_left_player_label.text = "Cartas restantes para o jogador: " + str(self.game.get_cards_left_player())
        self.ids.cards_left_opponent_label.text = "Cartas restantes para o oponente: " + str(self.game.get_cards_left_opponent())


class StartWindowApp(App):
    def build(self):
        self.title = "TRUNFO ELEIÇÕES"
        self.icon = "bolsonaro.png"
        return StartWindow()


class MainWindowApp(App):
    def build(self):
        self.title = "TRUNFO ELEIÇÕES"
        self.icon = "bolsonaro.png"
        return MainWindow()
