import java.io.*;
import java.math.*;
import java.util.*;

public class pet {
    public static void main(String[] args) {
        (new Solver()).go();
    }
}

class Solver {
    final int N = 40;
    int[][] b = new int[123][123];
    int[][] bx = new int[123][123];
    int[][] by = new int[123][123];
    int[][] id = new int[123][123];
    int[][] a = new int[N][4];
    int[] special = new int[N];
    byte[][][] d = new byte[N][1<<10][1<<10];
    int m, n, k, MaxId;

    int[] qu1 = new int[3500111];
    int[] qu2 = new int[3500111];
    int[] qu3 = new int[3500111];
    int[] qu4 = new int[3500111];

    int bitcount(int i) {
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }

    int bfs(int startu) {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < (1<<10); ++j)
                for(int k = 0; k < (1<<10); ++k)
                    d[i][j][k] = 100;
        int first = 100111, last = 100111;
        qu1[first] = 0;
        qu2[first] = startu;
        qu3[first] = 0;
        qu4[first] = 0;

        while (first <= last) {
            int du = qu1[first];
            int u = qu2[first];
            int u1 = qu3[first];
            int u2 = qu4[first];
            ++first;

            if (d[u][u1][u2] > du) {
                d[u][u1][u2] = (byte)du;
            }
            else continue;

//            System.out.println(u + " " + u1 + " " + u2 + " --> " + du);

            if (u2 == (1<<k) - 1) return du;

            int x = special[u];
            if (x != 0) {
                if (x > 0 && ((1<<x-1) & (~u1)) != 0
                        && ((1<<x-1)&~u2) != 0
                        && bitcount(u1) < 4) {
                    --first;
                    qu1[first] = du;
                    qu2[first] = u;
                    qu3[first] = u1 | (1<<x-1);
                    qu4[first] = u2;
                }
                if (x < 0 && ((1<<-x-1) & (u1)) != 0
                        && ((1<<-x-1)&~u2) != 0) {
                    --first;
                    qu1[first] = du;
                    qu2[first] = u;
                    qu3[first] = u1 ^ (1<<-x-1);
                    qu4[first] = u2 | (1<<-x-1);
                }
            }
            for(int i = 0; i < 4; ++i) {
                int v = a[u][i];
                if (v != 0) {
                    ++last;
                    qu1[last] = du+1;
                    qu2[last] = v;
                    qu3[last] = u1;
                    qu4[last] = u2;
                }
            }
        }
        return -1;
    }

    void connect(int x, int y, int k) {
        a[x][k] = y;
    }

    public void go() {
        int sx = 0, sy = 0;
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();

        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j) {
                b[i][j] = sc.nextInt();
                if (b[i][j] == 99) {
                    sx = i;
                    sy = j;
                    b[i][j] = 0;
                }
                else if (b[i][j] > 0)
                    ++k;
                id[i][j] = ++MaxId;
                special[id[i][j]] = b[i][j];
            }

        for(int i = 1; i <= m; ++i)
            for(int j = 1; j < n; ++j) {
                bx[i][j] = sc.nextInt();
                if (bx[i][j] != 0) {
                    connect(id[i][j], id[i][j+1], 0);
                    connect(id[i][j+1], id[i][j], 1);
                }
            }

        for(int i = 1; i < m; ++i)
            for(int j = 1; j <= n; ++j) {
                by[i][j] = sc.nextInt();
                if (by[i][j] != 0) {
                    connect(id[i][j], id[i+1][j], 2);
                    connect(id[i+1][j], id[i][j], 3);
                }
            }

        System.out.println(bfs(id[sx][sy]));
    }
}
