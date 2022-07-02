import java.io.FileNotFoundException;
import java.util.*;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner stdin = new Scanner(System.in);
		System.out.printf("Digite o caminho do arquivo: ");
		String filename = stdin.nextLine();
		
		ContaPalavra contador = new ContaPalavra(filename);
		contador.criaMapa();
		contador.mostraMapa();
		
		stdin.close();
	}

}
