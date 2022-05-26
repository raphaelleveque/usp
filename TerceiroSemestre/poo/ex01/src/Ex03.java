import java.io.IOException;

public class Ex03 {

	public static void main(String[] args) throws IOException {
		int tam = EntradaTeclado.leInt();
		for (int i = tam; i > 0; i--) {
			String s = "*";
			System.out.println(s.repeat(i) + "\n");
		}
	}
}
