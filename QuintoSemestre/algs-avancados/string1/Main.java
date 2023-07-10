import java.util.Scanner;

class Main {
    static final int md = 1000000007;

    static long exp(long x, long y, int md) {
        long ans = 1;
        x = x % md;
        while (y > 0) {
            if ((y & 1) == 1)
                ans = (ans * x) % md;
            y = y >> 1;
            x = (x * x) % md;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] c = { 1, 1, 1 };
        int flag = 0;
        long sq = 1, num = 1, d = 1;

        for (int i = 0; i < n; i++) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            c[0] = (c[0] * (y + 1)) % md;
            long gsum = ((exp(x, y + 1, md) - 1 + md) % md * exp(x - 1, md - 2, md)) % md;
            c[1] = (c[1] * gsum) % md;
            sq = (sq * exp(x, y / 2, md)) % md;
            num = (num * exp(x, y, md)) % md;
            if ((y & 1) == 1 && flag == 0) {
                d = (d * ((y + 1) / 2)) % (md - 1);
                flag = 1;
            } else
                d = (d * (y + 1)) % (md - 1);
        }

        if (flag == 1)
            c[2] = exp(num, d, md);
        else
            c[2] = exp(sq, d, md);

        System.out.println(c[0] + " " + c[1] + " " + c[2]);

        scanner.close();
    }
}
