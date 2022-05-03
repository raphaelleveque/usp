
public class Bozo {

	// Método inicial do programa. Ele cuida da execução do jogo e possui um laço, no qual cada iteração representa uma rodada do jogo.
	// Em cada rodada, o jogador joga os dados até 3 vezes e depois escolhe a posição do placar que deseja preencher. No final das rodadas a pontuação total é exibida.
	public static void main(String[] args) throws java.io.IOException {
		RolaDados dados = new RolaDados(5);
		Placar placar = new Placar();
		final int numeroDeRodadas = 10;
		
		for (int i = 0; i < numeroDeRodadas; i++) {
			System.out.println("Pressione a tecla 'ENTER' para iniciar a rodada");
			String enter = EntradaTeclado.leString();
			
			int dadosFinais[] = dados.rolar();
			System.out.println(dados);
			
			for (int j = 0; j < 2; j++) {
				System.out.println("Digite os dados a serem rolados novamente. Caso deseje finalizar, pressione 'ENTER'");
				String aSerRolado = EntradaTeclado.leString();
				if (!aSerRolado.equals("")) {
					dadosFinais = dados.rolar(aSerRolado);
					System.out.println(dados);
	 			} else {
	 				System.out.println(dados);
	 				break;
	 			}
			}
			
			System.out.println(placar);
			System.out.println("Qual posição deseja ocupar? ");
			int ocupar = EntradaTeclado.leInt();
			
			try {
				placar.add(ocupar, dadosFinais);
			} catch (IllegalArgumentException e){
				System.out.println(e.getMessage());
				System.out.printf("A posição escolhida é inválida! Escolha outra posição: ");
				ocupar = EntradaTeclado.leInt();
				placar.add(ocupar, dadosFinais);
			}
			System.out.println(placar);
		}
		
		System.out.println("Partida terminada!!");
		System.out.println("Seu placar foi de " + placar.getScore() + " pontos!!");
		
	}

}
