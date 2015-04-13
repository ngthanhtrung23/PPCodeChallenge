import java.io.*;
import java.math.*;
import java.util.*;

public class four {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();
        long[] f = new long[4011];
        long[] g = new long[4011];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                ++g[a[i] + a[j]];

        for(int i = 1; i <= (n<<1); ++i)
            for(int j = 1; j <= (n<<1); ++j)
                f[i+j] += g[i] * g[j];

        for(int i = 1; i <= (n<<2); ++i)
            System.out.print(f[i] + " ");
        System.out.println();
        sc.close();
    }
}
