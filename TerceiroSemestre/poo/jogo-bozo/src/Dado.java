
public class Dado {
	private int lados;
	private int ultimoLancamento;
	
	// Cria um dado com 6 lados (um cubo)
	public Dado() {
		this.lados = 6;
	}

    // Cria objeto com um número qualquer de lados
	public Dado(int lados) {
		this.lados = lados;
	}
	
    // Retorna o número do último lado selecionado.
	public int getLado() {
		return ultimoLancamento;
	}
	
	private Random random = new Random();

    // Simula a rolagem do dado por meio de um gerador aleatório. O número selecionado pode posteriormente ser recuperado com a chamada a getLado()
    // Retorna o número que foi sorteado
	public int rolar() {
		ultimoLancamento = random.getIntRand(this.lados) + 1;
		return getLado();
	}
	

    // Transforma representação do dado em String. É mostrada uma representação do dado que está para cima. Note que só funciona corretamente para dados de 6 lados.
	@Override
    public String toString() {
        switch (ultimoLancamento) {
            case 1:
                return "+-----+" +
                        "|     |" +
                        "|  *  |" +
                        "|     |" +
                        "+-----+";
            case 2:
                return "+-----+" +
                        "|*    |" +
                        "|     |" +
                        "|    *|" +
                        "+-----+";
            case 3:
                return "+-----+" +
                        "|*    |" +
                        "|  *  |" +
                        "|    *|" +
                        "+-----+";
            case 4:
                return "+-----+" +
                        "|*   *|" +
                        "|     |" +
                        "|*   *|" +
                        "+-----+";
            case 5:
                return "+-----+" +
                        "|*   *|" +
                        "|  *  |" +
                        "|*   *|" +
                        "+-----+";
            case 6:
                return "+-----+" +
                        "|*   *|" +
                        "|*   *|" +
                        "|*   *|" +
                        "+-----+";
        }
        return null;
	}
}
