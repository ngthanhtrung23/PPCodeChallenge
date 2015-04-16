// Author: Nguyen Thanh Trung
#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define TWO(X) (1LL<<(X))
#define CONTAIN(S,X) (S & TWO(X))

// Assert with message
#define ASSERT(b, mess) { \
    if (!(b)) { \
        cout << mess << endl; \
        assert((b));\
    } \
}
using namespace std;

int N, T;

const int di[] = {-1,1,0,0};
const int dj[] = {0,0,-1,1};

double f[55][33][33];
double a[33][33][33][33];

void solve() {
    // Expected value(empty cells)
    // = sum( probability_is_empty(i, j) )

    // Find probability that cell(i, j) is empty
    // = product( (1 - probability that we go from (u, v) to (i, j)) )

    REP(starti,N) REP(startj,N) {
        // we start at cell (starti, startj)
        
        // Initialize our DP array
        memset(f, 0, sizeof f);
        f[0][starti][startj] = 1.0;


        // f(turn, i, j) = probability that we end up at cell (i, j) after jumping 'turn' times
        REP(turn,T) {
            REP(i,N) REP(j,N) {
                // Count how many neighbours
                int cnt = 0;
                REP(dir,4) {
                    int ii = i + di[dir], jj = j + dj[dir];
                    if (ii < 0 || ii >= N || jj < 0 || jj >= N) continue;
                    ++cnt;
                }
                
                // For each neighbour, jumps to it and update the DP value
                REP(dir,4) {
                    int ii = i + di[dir], jj = j + dj[dir];
                    if (ii < 0 || ii >= N || jj < 0 || jj >= N) continue;

                    f[turn+1][ii][jj] += f[turn][i][j] / cnt;
                }
            }
        }

        // Store the result for later
        REP(i,N) REP(j,N)
            a[starti][startj][i][j] = f[T][i][j];
    }
    // cout << "DONE PART 1" << endl;

    double res = 0.0;
    REP(i,N) REP(j,N) {
        double prod = 1.0;
        REP(u,N) REP(v,N)
            prod *= 1.0 - a[u][v][i][j];
        res += prod;
    }
    cout << res << endl;
    // DEBUG(res);
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    while (cin >> N >> T) solve();

    // cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}
