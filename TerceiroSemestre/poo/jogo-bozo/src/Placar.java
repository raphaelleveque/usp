
public class Placar {
    int placar[];
    
    public Placar () {
        placar = new int[10];
        for (int i = 0; i < 10; i++) placar[i] = -1;
    }
	
    // Adiciona uma sequencia de dados em uma determinada posição do placar. Após a chamada, aquela posição torna-se ocupada e não pode ser usada uma segunda vez.
    // Parâmetros: 
        // posicao - Posição a ser preenchida. As posições 1 a 6 correspondem às quantidas de uns até seis, ou seja, as laterais do placar. As outas posições são: 7 - full hand; 8 - sequencia; 9 - quadra; e 10 - quina
        // dados - um array de inteiros, de tamanho 5. Cada posição corresponde a um valor de um dado. Supões-se que cada dado pode ter valor entre 1 e 6.
	public void add(int posicao, int[] dados) throws java.lang.IllegalArgumentException {
		if (posicao <= 0 || posicao > 10)
            throw new IllegalArgumentException("Essa posição do placar não existe\n");
		else {

			switch (posicao) {
            case 1:
                if (placar[0] != -1) throw new IllegalArgumentException("Essa posição está ocupada.\n");
                else {
                    int resposta = 0;
                    for(int i = 0; i<5; i++){
                        if(dados[i] == 1) resposta += 1;
                    }
                    placar[0] = resposta;
                }
                break;

            case 2:
                if (placar[1] != -1) throw new IllegalArgumentException("Essa posição está ocupada.\n");
                else {
                    int resposta = 0;
                    for(int i = 0; i<5; i++){
                        if(dados[i] == 2) resposta += 2;
                    }
                    placar[1] = resposta;
                }
                break;

            case 3:
                if (placar[2] != -1) throw new IllegalArgumentException("Essa posição está ocupada.\n");
                else {
                    int resposta = 0;
                    for(int i = 0; i<5; i++){
                        if(dados[i] == 3) resposta += 3;
                    }
                    placar[2] = resposta;
                }
                break;

            case 4:
                if (placar[3] != -1) throw new IllegalArgumentException("Essa posição está ocupada.\n");
                else {
                    int resposta = 0;
                    for(int i = 0; i<5; i++){
                        if(dados[i] == 4) resposta += 4;
                    }
                    placar[3] = resposta;
                }
                break;

            case 5:
                if (placar[4] != -1) throw new IllegalArgumentException("Essa posição está ocupada.\n");
                else {
                    int resposta = 0;
                    for(int i = 0; i<5; i++){
                        if(dados[i] == 5) resposta += 5;
                    }
                    placar[4] = resposta;
                }
                break;

            case 6:
                if (placar[5] != -1) throw new IllegalArgumentException("Essa posição está ocupada.\n");
                else {
                    int resposta = 0;
                    for(int i = 0; i<5; i++){
                        if(dados[i] == 6) resposta += 6;
                    }
                    placar[5] = resposta;
                }
                break;

            case 7:
                int flagFull = 0, tresIguais = 0, doisIguais = 0;
                int fullHand[] = new int[6];
                for(int i=0; i<5; i++) fullHand[dados[i] - 1]++;

                for(int i=0; i<6; i++){
                    if(fullHand[i] == 3) tresIguais = 1;
                    if(fullHand[i] == 2) doisIguais = 1;
                    if(fullHand[i] == 5) flagFull = 1;
                }

                if(doisIguais == 1 && tresIguais == 1) placar[6] = 15;
                else if(flagFull == 1) placar[6] = 15;
                else placar[6] = 0;

                break;

            case 8: 
                int sequencia[] = new int[6];
                for(int i=0; i<5; i++) sequencia[dados[i] - 1]++;

                for(int i=0; i<6; i++){
                    if(sequencia[i] > 1) placar[7] = 0;
                }
                if(placar[7] != 0) placar[7] = 20;

                break;

            case 9:
                int quadra[] = new int[6];
                for(int i=0; i<5; i++) quadra[dados[i] - 1]++;

                for(int i=0; i<6; i++){
                    if(quadra[i] >= 4) placar[8] = 30;
                }
                if(placar[8] != 30) placar[8] = 0;

                break;

            case 10: 
                int general[] = new int[6];
                for(int i=0; i<5; i++) general[dados[i] - 1]++;

                for(int i=0; i<6; i++){
                    if(general[i] == 5) placar[9] = 40;
                }
                if(placar[9] != 40) placar[9] = 0;

                break;
			}
		}		
	}
	
    // Computa a soma dos valores obtidos, considerando apenas as posições que já estão ocupadas.
	public int getScore() {
		int soma = 0;
		for (int i = 0; i < 10; i++)
			soma += placar[i];
		return soma;
	}
	
    // A representação na forma de string, mostra o placar completo, indicando quais são as posições livres (com seus respectivos números) e o valor obtido nas posições já ocupadas. Por exemplo:
	@Override
	public String toString() {
		String ret = "\n\n";
		
		ret += (placar[0] == -2) ? " (1) " : " "+ placar[0] +" ";
		ret += " | ";
		ret += (placar[6] == -2) ? " (7) " : " "+ placar[6] +" ";
		ret += " | ";
		ret += (placar[3] == -2) ? " (4) " : " "+ placar[3] +" ";
		ret += "\n";
		ret+= "---------------------\n";
		ret += (placar[1] == -2) ? " (2) " : " "+ placar[1] +" ";
		ret += " | ";
		ret += (placar[7] == -2) ? " (8) " : " "+ placar[7] +" ";
		ret += " | ";
		ret += (placar[4] == -2) ? " (5) " : " "+ placar[4] +" ";
		ret += "\n";
		ret+= "---------------------\n";
		ret += (placar[2] == -2) ? " (3) " : " "+ placar[2] +" ";
		ret += " | ";
		ret += (placar[8] == -2) ? " (9) " : " "+ placar[8] +" ";
		ret += " | ";
		ret += (placar[5] == -2) ? " (6) " : " "+ placar[5] +" ";
		ret += "\n";
		ret+= "---------------------\n";
		ret += (placar[9] == -2) ? "      | (10)  |" : "      | "+ placar[9] +"  |";
		ret += "\n";
		ret+= "      +-------+ \n\n";
	
		return ret;
	}
}
