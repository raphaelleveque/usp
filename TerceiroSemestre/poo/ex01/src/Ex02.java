
public class Ex02 {
	
	static double lendoEntrada() {
		double x = 0;
		boolean inputRead = false;
		while (!inputRead) {
			try {
				x = EntradaTeclado.leDouble();
				inputRead = true;
			} catch (Exception e) {
			}
		}
		return x;
	}
	
	static void bhaskara(double a, double b, double c) {
		double delta =  b * b - 4 * a * c;
		
		if (delta < 0)
			System.out.println("Nenhuma solução Real");
		
		else if (delta == 0) {
			System.out.println("Solução com apenas uma solução possível");
			System.out.println("x = " + (-b / (double)(2 * a)));
			
		} else {
			System.out.println("Duas soluções possíveis");
			System.out.println("x1 = " + (-b + Math.sqrt(delta)) / (double)(2 * a));
			System.out.println("x2 = " + (-b - Math.sqrt(delta)) / (double)(2 * a));
		}
		
	}
	

	public static void main(String[] args) {
		double a, b, c;
		a = lendoEntrada();
		b = lendoEntrada();
		c = lendoEntrada();
		
		bhaskara(a, b, c);
		
	}

}
