import java.io.*;
import java.util.*;
import java.math.*;

public class inversion {
    public static void main(String[] args) {
        (new Solver()).go();
    }
}

class Solver {
    int MN = 250111;
    int MAXV = 50111;
    int BLOCK = 777;

    int n, q, nblock;
    long res;
    int[] a = new int[MN];
    int[] ind = new int[MN];
    int[][] sl = new int[411][MAXV];
    int[] start = new int[411];
    int[] last = new int[411];
    int[] len = new int[411];

    void update(int x, int u, int k) {
        for(int v = u; v <= MAXV; v += v & (-v)) {
            sl[x][v] += k;
        }
    }

    int get(int x, int u) {
        int res = 0;
        for(int v = u; v > 0; v -= v & (-v)) {
            res += sl[x][v];
        }
        return res;
    }

    public void go() {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int n = in.nextInt();
        for(int i = 1; i <= n; ++i)
            a[i] = in.nextInt();

        for(int i = n; i >= 1; --i) {
            update(0, a[i], 1);
            res += get(0, a[i] - 1);
        }

        nblock = 1;
        int c = 0;
        for(int i = 1; i <= n; ++i) {
            if (c == 0) start[nblock] = i;
            ind[i] = nblock; len[nblock]++;
            ++c;

            if (c == BLOCK) {
                last[nblock] = i;
                ++nblock; c = 0;
            }
        }
        last[nblock] = n;
        for(int i = 1; i <= n; ++i)
            update(ind[i], a[i], 1);

        int q = in.nextInt();
        for(int qq = 0; qq < q; ++qq) {
            int u = in.nextInt(), val = in.nextInt();
            int p = ind[u];

            // block before u
            for(int i = 1; i < p; ++i) {
                res -= len[i] - get(i, a[u]);
                res += len[i] - get(i, val);
            }
            // block after u
            for(int i = p+1; i <= nblock; ++i) {
                res -= get(i, a[u] - 1);
                res += get(i, val - 1);
            }

            // block containing u
            for(int i = start[p]; i <= u-1; ++i) {
                if (a[i] > a[u]) --res;
                if (a[i] > val) ++res;
            }
            for(int i = u + 1; i <= last[p]; ++i) {
                if (a[i] < a[u]) --res;
                if (a[i] < val) ++res;
            }

            // update block u
            update(p, a[u], -1);
            a[u] = val;
            update(p, val, +1);

            System.out.println(res);
        }
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}
