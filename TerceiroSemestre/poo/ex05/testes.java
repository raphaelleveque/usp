// Raphael Leveque 12542522
package ProjetoBozo;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Test;

class TestesPlacar {
	private Placar placar;
    private int score;

	@BeforeEach
	void setUp() throws Exception {
		placar = new Placar();
        this.score = 0;
	}

	@AfterEach
	void tearDown() throws Exception {
		placar = null;
	}

	// Testa se o score está vazio
	@Test
	public void scoreNulo() {
		this.score = placar.getScore();
		assertEquals(0, this.score);
	}

	// Teste para verificar o score maximo
	@Test
	public void scoreMaximo() {
		placar.add(1, new int [] {1, 1, 1, 1, 1});
		placar.add(2, new int [] {2, 2, 2, 2, 2});
		placar.add(3, new int [] {3, 3, 3, 3, 3});
		placar.add(4, new int [] {4, 4, 4, 4, 4});
		placar.add(5, new int [] {5, 5, 5, 5, 5});
		placar.add(6, new int [] {6, 6, 6, 6, 6});
		placar.add(7, new int [] {1, 1, 1, 2, 2});
		placar.add(8, new int [] {1, 2, 3, 4, 5});
		placar.add(9, new int [] {1, 1, 1, 1, 2});
		placar.add(10, new int [] {1, 1, 1, 1, 1});
		this.score = placar.getScore();
		assertEquals(210, this.score);
	}

	
	/*
		A funcao a ser testada abaixo é a funcao add da classe Placar
		Ela recebe como parametro a posicao e os dados, sendo um inteiro e um array
	*/
	
	// Teste para saber se o codigo aceita posicoes negativas na funcao add
	@Test
	public void posicaoNegativa() {
	assertThrows(IllegalArgumentException.class, () -> placar.add(-5, new int[]{1, 1, 1, 1, 1}));
	}

	// Como as posicoes variam de 1 a 10, scoree para posicoes fora desse escopo
	@Test
	public void posicaoForaDoEscopo() {
	    assertThrows(IllegalArgumentException.class, () -> placar.add(20, new int[]{1, 1, 1, 1, 1}));
	}

	// Teste para adicionar placares iguais
	@Test
	public void placaresIguais() {
	assertThrows(IllegalArgumentException.class, () ->  {
		// posicao = 10, testa uma quina
		placar.add(10, new int[]{1, 1, 1, 1, 1}); 
		placar.add(10, new int[]{1, 1, 1, 1, 1});
		});
	}

	// Teste para ver o score é 5, o somatório dos inteiros
	@Test 
	public void score5() {
		// posicao = 1, testa quantidade de numeros 1
		placar.add(1, new int [] {1, 1, 1, 1, 1});
		this.score = placar.getScore();
		assertEquals(5, this.score);
	}

	// Teste para ver o score é 10, o somatório dos inteiros
	@Test 
	public void score10() {
		// posicao = 2, testa quantidade de numeros 2
		placar.add(2, new int [] {2, 2, 2, 2, 2});
		this.score = placar.getScore();
		assertEquals(10, this.score);
	}

	// Teste para ver se o score é 15, o somatório dos inteiros
	@Test 
	public void score15() {
		// posicao = 3, testa quantidade de numeros 3
		placar.add(3, new int [] {3, 3, 3, 3, 3});
		this.score = placar.getScore();
		assertEquals(15, this.score);
	}

	// Teste para ver se o score é 20, o somatório dos inteiros
	@Test 
	public void score20() {
		// posicao = 4, testa quantidade de numeros 4
		placar.add(4, new int [] {4, 4, 4, 4, 4});
		this.score = placar.getScore();
		assertEquals(20, this.score);
	}

	// Teste para ver se o score é 25, o somatório dos inteiros
	@Test 
	public void score25() {
		// posicao = 5, testa quantidade de numeros 5
		placar.add(5, new int [] {5, 5, 5, 5, 5});
		this.score = placar.getScore();
		assertEquals(25, this.score);
	}
	
	// Teste para ver se o score é 30, o somatório dos inteiros
	@Test 
	public void score30() {
		// posicao = 6, testa quantidade de numeros 6
		placar.add(6, new int [] {6, 6, 6, 6, 6});
		this.score = placar.getScore();
		assertEquals(30, this.score);
	}

	// Teste para verificar um Full Hand com 1 1 1
	@Test 
	public void scoreFullHand1() {
		// posicao = 7, testa um Full Hand
		placar.add(7, new int [] {1, 1, 1, 2, 2});
		this.score = placar.getScore();
		assertEquals(15, this.score);
	}

	// Teste para verificar um Full Hand com 2 2 2
	@Test 
	public void scoreFullHand2() {
		// posicao = 7, testa um Full Hand
		placar.add(7, new int [] {1, 1, 2, 2, 2});
		this.score = placar.getScore();
		assertEquals(15, this.score);
	}

	// Teste para verificar se nao existe full hand nessa jogada
	@Test 
	public void fullHandErrado() {
		// posicao = 7, testa um Full Hand
		placar.add(7, new int [] {2, 1, 2, 2, 2});
		this.score = placar.getScore();
		// Como nao ha um full hand, o score e 0
		assertEquals(0, this.score);
	}

	// Teste para verificar caso as cartas formem uma sequencia
	@Test 
	public void cartasSequenciais() {
		// posicao = 8, testa uma sequencia
		placar.add(8, new int [] {1, 2, 3, 4, 5});
		this.score = placar.getScore();
		assertEquals(20, this.score);
	}

	// Teste para verificar caso as cartas nao formem uma sequencia
	@Test 
	public void cartasNaoSequenciais() {
		// posicao = 8, testa uma sequencia
		placar.add(8, new int [] {1, 1, 3, 4, 5});
		this.score = placar.getScore();
		// Como as cartas nao sao sequenciais, o score e 0
		assertEquals(0, this.score);
	}
	
	// Teste para verificar quatro elementos repetidos (quadra)
	@Test 
	public void scoreQuadra() {
		// posicao = 9, testa uma quadra
		placar.add(9, new int [] {1, 1, 1, 1, 2});
		this.score = placar.getScore();
		assertEquals(30, this.score);
	}

	// Teste para verificar quatro elementos repetidos (quadra)
	@Test 
	public void testAddQuadra2() {
		// posicao = 9, testa uma quadra
		placar.add(9, new int [] {2, 1, 1, 1, 1});
		this.score = placar.getScore();
		assertEquals(30, this.score);
	}

	// Teste para verificar quatro elementos repetidos (quadra)
	@Test 
	public void testAddQuadraERRO() {
		// posicao = 9, testa uma quadra
		placar.add(9, new int [] {2, 2, 1, 1, 1});
		this.score = placar.getScore();
		// Como não existe quadra, então o score é 0
		assertEquals(0, this.score);
	}

	// Teste para verificar se há uma quina (elementos iguais)
	@Test 
	public void scoreQuina() {
		// posicao = 10, testa uma quina
		placar.add(10, new int [] {1, 1, 1, 1, 1});
		this.score = placar.getScore();
		assertEquals(40, this.score);
	}

	// Teste para verificar se há uma quina (elementos iguais)
	@Test 
	public void testAddQuinaERRO() {
		// posicao = 10, testa uma quina
		placar.add(10, new int [] {2, 1, 1, 1, 1});
		this.score = placar.getScore();
		// Como nao ha uma quina, entao o score e 0
		assertEquals(0, this.score);
	}


	/*
		A funcao a ser testada abaixo é a funcao toString da classe Placar
		Compara a string esperada com a string retornada pela funcao toString()
	*/

	
	@Test
	public void testToString1() {
		String resultadoEsperado = "(1)    |   (7)    |   (4) \n--------------------------\n(2)    |   (8)    |   (5) \n--------------------------\n(3)    |   (9)    |   (6) \n--------------------------\n       |   (10)   |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}
	@Test
	public void testToString2() {
		placar.add(1, new int [] {1, 1, 1, 1, 1});
		String resultadoEsperado = "5      |   (7)    |   (4) \n--------------------------\n(2)    |   (8)    |   (5) \n--------------------------\n(3)    |   (9)    |   (6) \n--------------------------\n       |   (10)   |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}
	@Test
	public void testToString3() {
		placar.add(2, new int [] {2, 2, 2, 2, 2});
		String resultadoEsperado = "(1)    |   (7)    |   (4) \n--------------------------\n10     |   (8)    |   (5) \n--------------------------\n(3)    |   (9)    |   (6) \n--------------------------\n       |   (10)   |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}
	@Test
	public void testToString4() {
		placar.add(3, new int [] {3, 3, 3, 3, 3});
		String resultadoEsperado = "(1)    |   (7)    |   (4) \n--------------------------\n(2)    |   (8)    |   (5) \n--------------------------\n15     |   (9)    |   (6) \n--------------------------\n       |   (10)   |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}
	@Test
	public void testToString5() {
		placar.add(4, new int [] {4, 4, 4, 4, 4});
		String resultadoEsperado = "(1)    |   (7)    |   20  \n--------------------------\n(2)    |   (8)    |   (5) \n--------------------------\n(3)    |   (9)    |   (6) \n--------------------------\n       |   (10)   |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}
	@Test
	public void testToString6() {
		placar.add(5, new int [] {5, 5, 5, 5, 5});
		String resultadoEsperado = "(1)    |   (7)    |   (4) \n--------------------------\n(2)    |   (8)    |   25  \n--------------------------\n(3)    |   (9)    |   (6) \n--------------------------\n       |   (10)   |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}
	@Test
	public void testToString7() {
		placar.add(6, new int [] {6, 6, 6, 6, 6});
		String resultadoEsperado = "(1)    |   (7)    |   (4) \n--------------------------\n(2)    |   (8)    |   (5) \n--------------------------\n(3)    |   (9)    |   30  \n--------------------------\n       |   (10)   |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}
	@Test
	public void testToString8() {
		placar.add(7, new int [] {1, 1, 1, 2, 2});
		String resultadoEsperado = "(1)    |   15     |   (4) \n--------------------------\n(2)    |   (8)    |   (5) \n--------------------------\n(3)    |   (9)    |   (6) \n--------------------------\n       |   (10)   |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}
	@Test
	public void testToString9() {
		placar.add(8, new int [] {1, 2, 3, 4, 5});
		String resultadoEsperado = "(1)    |   (7)    |   (4) \n--------------------------\n(2)    |   20     |   (5) \n--------------------------\n(3)    |   (9)    |   (6) \n--------------------------\n       |   (10)   |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}
	@Test
	public void testToString10() {
		placar.add(9, new int [] {1, 1, 1, 1, 2});
		String resultadoEsperado = "(1)    |   (7)    |   (4) \n--------------------------\n(2)    |   (8)    |   (5) \n--------------------------\n(3)    |   30     |   (6) \n--------------------------\n       |   (10)   |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}
	@Test
	public void testToString11() {
		placar.add(10, new int [] {1, 1, 1, 1, 1});
		String resultadoEsperado = "(1)    |   (7)    |   (4) \n--------------------------\n(2)    |   (8)    |   (5) \n--------------------------\n(3)    |   (9)    |   (6) \n--------------------------\n       |   40     |\n       +----------+\n";
		assertEquals(resultadoEsperado, placar.toString());
	}

}
