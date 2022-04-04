import java.io.IOException;

public class Ex06 {

	public static void main(String[] args) throws IOException {
		double max = Double.MIN_VALUE, min = Double.MAX_VALUE;
		
		double tmp = EntradaTeclado.leDouble();
		while(tmp != 0.0) {
			if (tmp > max)
				max = tmp;
			if (tmp < min)
				min = tmp;
			tmp = EntradaTeclado.leDouble();
		}
		System.out.println("Maior: " + max);
		System.out.println("Menor: " + min);
	}

}
