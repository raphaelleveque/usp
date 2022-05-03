
public class RolaDados {
	
	private Dado[] dados;
	private int numeroDados;

	// Construtor que cria e armazena vários objetos do tipo Dado.
	public RolaDados(int n) {
		this.numeroDados = n;
		dados = new Dado[n];
		for (int i = 0; i < n; i++)
			dados[i] = new Dado();
		
	}
	
	// Rola todos os dados.
	// Retorna o valor de cada um dos dados, inclusive os que não foram rolados. Nesse caso, o valor retornado é o valor anterior que ele já possuia.
	public int[] rolar() {
		int[] dadosRetornados = new int [numeroDados];
		for (int i = 0; i < numeroDados; i++)
			dadosRetornados[i] = dados[i].rolar();
		
		return dadosRetornados;	
	}
	
	// Parâmetros: 
		// jaRolados - É um array de booleanos que indica quais dados devem ser rolados. Cada posição representa um dos dados. Ou seja, a posição 0 do array indica se o dado 1 deve ser rolado ou não, e assim por diante.
	// Retorna o valor de cada um dos dados, inclusive os que não foram rolados. Nesse caso, o valor retornado é o valor anterior que ele já possuia.
	public int[] rolar(boolean[] jaRolados) {
		int[] dadosRetornados = new int [numeroDados];
		
		for (int i = 0; i < numeroDados; i++) {
			if (jaRolados[i])
				dadosRetornados[i] = dados[i].getLado();
			else
				dadosRetornados[i] = dados[i].rolar();
		}
		
		return dadosRetornados;
	}
	// Parâmetros:
		// s - É um String que possui o número dos dados a serem rolados. Por exemplo "1 4 5" indica que os dados 1 4 e cinco devem ser rolados. Os números devem ser separados por espaços. Se o valor passado no string estiver fora do intervalo válido, ele é ignorado simplesmente.
	// Retorna o valor de cada um dos dados, inclusive os que não foram rolados. Nesse caso, o valor retornado é o valor anterior que ele já possuia.
	public int[] rolar(java.lang.String s) {
		int[] dadosRetornados = new int [numeroDados];
		boolean[] aSerRolado = new boolean[numeroDados];
		String separados[] = s.split(" ");
		for (String c : separados) {
			aSerRolado[Integer.parseInt(c) - 1] = true;
		}
		for (int i = 0; i < numeroDados; i++) {
			if (aSerRolado[i])
				dadosRetornados[i] = dados[i].rolar();
			else
				dadosRetornados[i] = dados[i].getLado();
		}
		
		return dadosRetornados;
	}
	
	//Usa a representação em string do dados, para mostrar o valor de todos os dados do conjunto. Exibe os dados horisontalmente, por exemplo:
	@Override
    public String toString () {

        String result = " 1        2        3        4        5\n+-----+  +-----+  +-----+  +-----+  +-----+\n";
        for(int i=0; i< 5; i++) {
            if (dados[i].getLado() == 1) result +="|     |  ";
            else if (dados[i].getLado() == 2 || dados[i].getLado() == 3) result+="|*    |  ";
            else result+="|*   *|  ";
            if (i == 4) result+="\n";
        }

        for(int i=0; i< 5; i++) {
            if (dados[i].getLado() == 1 || dados[i].getLado() == 3 || dados[i].getLado() == 5) result+="|  *  |  ";
            else if (dados[i].getLado() == 6) result+="|*   *|  ";
            else result+="|     |  ";
            if (i == 4) result+="\n";
        }

        for(int i=0; i< 5; i++) {
            if (dados[i].getLado() == 2 || dados[i].getLado() == 3) result+="|    *|  ";
            else if (dados[i].getLado() == 1) result+="|     |  ";
            else result+="|*   *|  ";
            if (i == 4) result+="\n";
        }

        result+="+-----+  +-----+  +-----+  +-----+  +-----+\n";
        return result;
    }
}
