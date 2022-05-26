import java.io.IOException;

public class Ex04_1 {

	public static void main(String[] args) throws IOException {
		int tam = EntradaTeclado.leInt();
		for (int i = tam; i > 0; i--) {
			String s1 = "*";
			String s2 = " ";
			
			System.out.println(s2.repeat(tam - i) + s1.repeat(i) + "\n");
		}
	}
}
