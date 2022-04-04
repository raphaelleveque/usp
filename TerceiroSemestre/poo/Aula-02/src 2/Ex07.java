import java.io.IOException;

public class Ex07 {
	
	public static double bissecao(double a) {
		return Math.pow(a, 3) - Math.pow(a, 2) - 13 * a + 8;
	}

	public static void main(String[] args) throws IOException {
		System.out.println("Digite o intervalo de interesse: ");
		  double tolerancia = Math.pow(10, -7);
		  double a = EntradaTeclado.leDouble();
		  double b = EntradaTeclado.leDouble();
		  int i = 0;
		  double c;
		  
		  while (true) {
			i++;
			 c = (a + b)/2;
			if (bissecao(c) == 0 || Math.abs(b - a) < tolerancia) {
				break;
			}
			double res = bissecao(a) * bissecao(c);
			if (res < 0)
				b = c;
			else
				a = c;
		}
			System.out.println("A raíz é '" + c + "'");
			System.out.println("Foram utilizadas " + i + " repetições");
	}

}
