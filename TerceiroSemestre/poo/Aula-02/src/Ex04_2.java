import java.io.IOException;

public class Ex04_2 {

	public static void main(String[] args) throws IOException {
		int x = EntradaTeclado.leInt();
		int menorDivisor = -1;
		
		for (int i = 2; i < x; i++) {
			if (x % i == 0) {
				menorDivisor = i;
				break;
			}
		}
		if (menorDivisor == -1) {
			System.out.println(x + " é primo\n");
		} else {
			System.out.println(menorDivisor + " é seu menor divisor\n");
		}
	}
}
