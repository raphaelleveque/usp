import java.io.IOException;

public class Ex08 {
	
	public static double derivada(double a) {
		return 3 * Math.pow(a, 2) - 2 * a - 13;
	}
	
	public static double equacao(double a) {
		return Math.pow(a, 3) - Math.pow(a, 2) - 13 * a + 8;
	}

	public static void main(String[] args) throws IOException {
		double x0 = EntradaTeclado.leDouble();
		double x1 = x0 - (equacao(x0) / derivada(x0));
		double error = x0 - x1;
		double  tolerancia = Math.pow(10, -7);
		int i = 0;
		
		while (error > tolerancia) {
			i++;
			x0 = x1;
			x1 = x0 - (equacao(x0) / derivada(x0));
			error = Math.abs(x0 - x1);
		}
		System.out.println("A raíz é igual a " + x1);
		System.out.println("Foram necessárias " + i + " iterações");
	}

}
