import java.io.*;
import java.util.*;
import java.math.*;

public class jump {
    public static void main(String[] args) {
        (new Solver()).go();
    }
}

class Solver {
    int[] di = new int[] {-1, 1, 0, 0};
    int[] dj = new int[] {0, 0, -1, 1};

    double[][][] f = new double [55][33][33];
    double[][][][] a = new double [33][33][33][33];

    public void go() {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            // Read input
            int N = sc.nextInt(), T = sc.nextInt();

            // We start at cell (starti, startj)
            for(int starti = 0; starti < N; ++starti)
                for(int startj = 0; startj < N; ++startj) {
                    // DP: f(T, i, j) = probability that we end up at position (i, j)
                    //                  after jumping T times

                    // Initialize the DP array
                    for(int i = 0; i < 55; ++i)
                        for(int j = 0; j < 33; ++j)
                            for(int k = 0; k < 33; ++k)
                                f[i][j][k] = 0.0;
                    f[0][starti][startj] = 1.0;

                    // Calculate DP function
                    for(int turn = 0; turn < T; ++turn) {
                        for(int i = 0; i < N; ++i)
                            for(int j = 0; j < N; ++j) {
                                // Count number of neighbours of cell (i, j)
                                int cnt = 0;
                                for(int dir = 0; dir < 4; ++dir) {
                                    int ii = i + di[dir], jj = j + dj[dir];
                                    if (ii < 0 || ii >= N || jj < 0 || jj >= N) continue;
                                    cnt += 1;
                                }

                                // Consider each neighbour, jumps to it and update the DP values
                                for(int dir = 0; dir < 4; ++dir) {
                                    int ii = i + di[dir], jj = j + dj[dir];
                                    if (ii < 0 || ii >= N || jj < 0 || jj >= N) continue;

                                    f[turn+1][ii][jj] += f[turn][i][j] / cnt;
                                }
                            }
                    }

                    // Store the calculated values
                    for(int i = 0; i < N; ++i)
                        for(int j = 0; j < N; ++j)
                            a[starti][startj][i][j] = f[T][i][j];
                }

            // Calculate final result using the formula:
            // result = product( probability that cell (i, j) is empty )
            double res = 0.0;
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j) {
                    double prod = 1.0;
                    for(int u = 0; u < N; ++u)
                        for(int v = 0; v < N; ++v)
                            prod *= 1.0 - a[u][v][i][j];
                    res += prod;
                }
            
            // Print result
            int x = (int) (res * 1000000 + 1e-6);
            System.out.printf("%d.%06d\n", x / 1000000, x % 1000000);
        }
        sc.close();
    }
}
