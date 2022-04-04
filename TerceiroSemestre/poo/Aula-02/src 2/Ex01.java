import java.io.IOException;

public class Ex01 {

	public static void main(String[] args) throws IOException {
		double x = EntradaTeclado.leDouble();
		final double error = 0.00000001;
		
		double x0 = 10, x1 = 20;
		
		while (Math.abs(x1 - x0) > error) {
			x0 = x1;
	        x1 = (x0 + x/x0) / 2.0;
		}
		System.out.println("Raíz: " + x1);
		
	}

}
