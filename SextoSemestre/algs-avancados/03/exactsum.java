import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            int N = scanner.nextInt();
            ArrayList<Long> livros = new ArrayList<>();

            for (int i = 0; i < N; ++i) {
                livros.add(scanner.nextLong());
            }

            Collections.sort(livros);

            long M = scanner.nextLong();
            int i = 0, j = N - 1;
            int bI = 0, bJ = 0;

            while (i < j) {
                long soma = livros.get(i) + livros.get(j);
                if (soma < M) {
                    ++i;
                } else if (soma == M) {
                    bI = i;
                    bJ = j;
                    ++i;
                    --j;
                } else {
                    --j;
                }
            }

            System.out.println("Peter deve comprar os livros com preços " + livros.get(bI) + " e " + livros.get(bJ) + ".\n");
        }
    }
}
