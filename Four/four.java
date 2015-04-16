import java.io.*;
import java.math.*;
import java.util.*;

public class four {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read input
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();

        // g(v) = number of pair (i, j) such that a(i) + a(j) = v
        long[] g = new long[4011];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                ++g[a[i] + a[j]];

        // f(v) = number of quad (i, j, k, l) such that a(i) + a(j) + a(k) + a(l) = v
        long[] f = new long[4011];
        for(int i = 1; i <= (n<<1); ++i)
            for(int j = 1; j <= (n<<1); ++j)
                f[i+j] += g[i] * g[j];

        // Print result
        for(int i = 1; i <= (n<<2); ++i)
            System.out.print(f[i] + " ");
        System.out.println();
        sc.close();
    }
}
