import java.io.IOException;
import java.util.Arrays;

public class Ex05 {

	public static void main(String[] args) throws IOException {
		int num = EntradaTeclado.leInt();
		boolean[] array = new boolean[num];
		Arrays.fill(array, true);
		array[0] = array[1] = false;
		
		for (int i = 2; i < num; i++) {
			if (array[i] == true) {
				for (int j = 2 * i; j < num; j += i) {
					array[j] = false;
				}
			}
		}
		int i = num - 1;
		while (array[i] == false) {
			i--;
		}
		System.out.println(i + " é o número primo inferiormente mais próximo de " + num );
	}

}
