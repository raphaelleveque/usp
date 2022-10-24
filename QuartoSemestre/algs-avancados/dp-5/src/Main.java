import java.util.Scanner;
import java.lang.String;
class Main {

    public static int sequence(String s1, String s2, int[] weight, int n, int m) {
        int[][] cache = new int[n+1][m+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s1.charAt(i) == s2.charAt(j))
                    cache[i+1][j+1] = cache[i][j] + weight[(int)(s1.charAt(i))-97];
                else if (cache[i][j+1] > cache[i+1][j])
                    cache[i+1][j+1] = cache[i][j+1];
                else
                    cache[i+1][j+1] = cache[i+1][j];
            }
        }
        return cache[n][m];
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int weight[] = new int[26];
        for (int i = 0; i < 26; i++) {
            weight[i] = sc.nextInt();
        }
        String s1 = sc.next();
        String s2 = sc.next();

        System.out.println(sequence(s1, s2, weight, n, m));

        sc.close();
    }
}