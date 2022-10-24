import java.util.Scanner;
import java.lang.String;

class Main {
    public static int minimumDist(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        int[][] cache = new int[n+1][m+1];
        
        for (int i = 0; i < m + 1; i++)
            cache[0][i] = i;
        for (int i = 0; i < n + 1; i++)
            cache[i][0] = i;

        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (s1.charAt(i) == s2.charAt(j)) 
                    cache[i+1][j+1] = cache[i][j];
                else
                    cache[i+1][j+1] = 1 + Math.min(Math.min(cache[i+1][j], cache[i][j+1]), cache[i][j]);
            }
        }
        return cache[n][m];
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            String s1 = sc.next();
            String s2 = sc.next();
            System.out.println(minimumDist(s1, s2));
        }

        sc.close();
    }

}