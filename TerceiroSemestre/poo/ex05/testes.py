# Raphael Leveque 12542522
import unittest as ut
from Placar import Placar


class Testes(ut.TestCase):
    placar:Placar

    def __init__(self) -> None:
        self.placar = Placar()

    '''
		A funcao a ser testada abaixo é a funcao add da classe Placar
		Ela recebe como parametro a posicao e os dados, sendo um inteiro e um array
	'''

	#Teste para saber se o codigo aceita posicoes erradas na funcao add
    def testAddInvalido1(self):
        placar = Placar()
        self.assertRaises(IndexError, placar.add, 0, [1, 1, 1, 1, 1])

    # Teste para adicionar um novo dado em uma posição já ocupada
    def testAddInvalido2(self):
        placar = Placar()
        placar.add(1, [1, 1, 1, 1, 1])
        self.assertRaises(ValueError, placar.add, 1, [1, 1, 1, 1, 1])
    
    # Teste para ver o score, o somatório dos inteiros
    def testAdd1(self):
        placar = Placar()
        placar.add(1, [1, 1, 1, 1, 1])
        score = placar.getScore()
        placar.assertEquals(5, score)
        
    def testAdd2(self):
        placar = Placar()
        placar.add(2, [2, 2, 2, 2, 2])
        score = placar.getScore()
        placar.assertEquals(10, score)
        
    def testAdd3(self):
        placar = Placar()
        placar.add(3, [3, 3, 3, 3, 3])
        score = placar.getScore()
        placar.assertEquals(15, score)
        
    def testAdd4(self):
        placar = Placar()
        placar.add(4, [4, 4, 4, 4, 4])
        score = placar.getScore()
        placar.assertEquals(20, score)
        
    def testAdd5(self):
        placar = Placar()
        placar.add(5, [5, 5, 5, 5, 5])
        score = placar.getScore()
        placar.assertEquals(25, score)
        
    def testAdd6(self):
        placar = Placar()
        placar.add(6, [6, 6, 6, 6, 6])
        score = placar.getScore()
        placar.assertEquals(30, score)
        
    def scoreFullHand(self):
        placar = Placar()
        placar.add(7, [5, 5, 5, 4, 4])
        score = placar.getScore()
        placar.assertEquals(15, score)
        
    def testAddInvalidFH(self):
        placar = Placar()
        placar.add(7, [5, 5, 5, 5, 4])
        score = placar.getScore()
        placar.assertEquals(0, score)
        
    def testAddSeq(self):
        placar = Placar()
        placar.add(8, [1, 2, 3, 4, 5])
        score = placar.getScore()
        placar.assertEquals(20, score)
        
    def testAddInvalidSeq(self):
        placar = Placar()
        placar.add(8, [1, 2, 3, 4, 4])
        score = placar.getScore()
        placar.assertEquals(0, score)
        
    def testAddQuadra(self):
        placar = Placar()
        placar.add(9, [6, 6, 6, 6, 4])
        score = placar.getScore()
        placar.assertEquals(30, score)
        
    def testAddInvalidQuadra(self):
        placar = Placar()
        placar.add(9, [6, 6, 6, 4, 4])
        score = placar.getScore()
        placar.assertEquals(0, score)
        
    def testAddQuina(self):
        placar = Placar()
        placar.add(10, [5, 5, 5, 5, 5])
        score = placar.getScore()
        placar.assertEquals(40, score)
        
    def testAddInvalidQuina(self):
        placar = Placar()
        placar.add(10, [5, 5, 5, 5, 1])
        score = placar.getScore()
        placar.assertEquals(0, score)
    
    # Teste para computar o score igual a zero
    def testScoreVazio(self):
        placar = Placar()
        score = placar.getScore()
        self.assertEquals(0, score)

    
    # Teste para computar o score maximo    
    def testScoreMaximo(self):
        placar = Placar()
        placar.add(1, [1, 1, 1, 1, 1])
        placar.add(2, [2, 2, 2, 2, 2])
        placar.add(3, [3, 3, 3, 3, 3])
        placar.add(4, [4, 4, 4, 4, 4])
        placar.add(5, [5, 5, 5, 5, 5])
        placar.add(6, [6, 6, 6, 6, 6])
        placar.add(7, [1, 1, 1, 2, 2])
        placar.add(8, [1, 2, 3, 4, 5])
        placar.add(9, [1, 1, 1, 1, 2])
        placar.add(10, [1, 1, 1, 1, 1])
        score = placar.getScore()
        self.assertEquals(210, score)


    # Testando a funcao str da classe Placar     
    def testToStr(self):
        placar = Placar()
        placar.add(2, [2, 1, 2, 2, 5])
        placar.add(10, [1, 1, 1, 1, 2])
        placar.add(3, [3, 1, 1, 1, 1])
        placar.add(9, [4, 4, 4, 4, 1])
        placar.add(6, [6, 6, 1, 1, 6])
        string = "(1)    |   (7)    |  (4) \n" + "-------|----------|-------" + " 6     |   (8)    |  (5) \n" + "-------|----------|-------" + " 3     |    30    |  (6) \n" + "-------|----------|-------" + "       |    0     |\n" + "       +----------+\n"
        stringObtida = str(placar)
        self.assertEquals(string, stringObtida)
        

if __name__ == '__main__':
    ut.main()
