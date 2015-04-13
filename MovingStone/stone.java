import java.io.*;
import java.math.*;
import java.util.*;

public class stone {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            if (n < 0) break;

            long[] a = new long[n];
            long total = 0;
            for(int i = 0; i < n; ++i) {
                a[i] = sc.nextLong();
                total += a[i];
            }

            long res = 0;
            if (total % n == 0) {
                long each = total / n;
                long l = 0, r = 0;
                for(int i = 0; i < n; ++i) {
                    a[i] += r - l;
                    if (a[i] > each) {
                        l = 0;
                        r = a[i] - each;
                    }
                    else {
                        l = each - a[i];
                        r = 0;
                    }

                    res = Math.max(res, Math.max(l, r));
                }
            }
            else res = -1;
            System.out.println(res);
        }
        sc.close();
    }
}
