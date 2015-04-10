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
using namespace std;

int m, n, a[11][11], ngang[11][11], doc[11][11];
pair<int,int> from[111], to[111];
int p3[111];
int d[111][111];

int getBit(int mask, int u) {
    return (mask % p3[u+1]) / p3[u];
}
int setBit(int mask, int u, int val) {
    return mask + p3[u] * (val - getBit(mask, u));
}
int getId(int u, int v) {
    return (u-1) * n + v;
}

void addEdge(int i1, int j1, int i2, int j2) {
    int u = getId(i1, j1), v = getId(i2, j2);
    d[u][v] = d[v][u] = 1;
}

struct State {
    int mask;
    int u, v;
    int cap;

    State() {}
    State(int mask, int u, int v, int cap) : mask(mask), u(u), v(v), cap(cap) {}
};

bool operator < (const State& a, const State& b) {
    if (a.mask != b.mask) return a.mask < b.mask;
    if (a.u != b.u) return a.u < b.u;
    if (a.v != b.v) return a.v < b.v;
    if (a.cap != b.cap) return a.cap < b.cap;
    return false;
}

int main() {
    p3[0] = 1; FOR(i,1,20) p3[i] = p3[i-1] * 3;
    while (cin >> m >> n) {
        int starti, startj, bound = 0;
        FOR(i,1,m) FOR(j,1,n) {
            cin >> a[i][j];
            if (a[i][j] == 99) {
                starti = i;
                startj = j;
            }
            else if (a[i][j] > 0) from[a[i][j]] = make_pair(i, j), bound = max(bound, a[i][j]);
            else if (a[i][j] < 0) to[-a[i][j]] = make_pair(i, j), bound = max(bound, -a[i][j]);
        }
        FOR(i,1,m) FOR(j,1,n-1) cin >> ngang[i][j];
        FOR(i,1,m-1) FOR(j,1,n) cin >> doc[i][j];

//        cerr << "DONE INPUT" << endl;

        FOR(i,1,100) FOR(j,1,100) d[i][j] = (i == j) ? 0 : 1000111000;
        FOR(i,1,m) FOR(j,1,n) {
            if (ngang[i][j]) addEdge(i, j, i, j+1);
            if (ngang[i][j-1]) addEdge(i, j, i, j-1);
            if (doc[i][j]) addEdge(i, j, i+1, j);
            if (doc[i-1][j]) addEdge(i, j, i-1, j);
        }
        FOR(k,1,100) FOR(i,1,100) FOR(j,1,100) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

//        FOR(i,1,m*n) {
//            FOR(j,1,m*n) cout << d[i][j] << ' ';
//            cout << endl;
//        }

//        cerr << "DONE FLOYD" << endl;

        map<State, int> dist;
        set< pair<int, State> > all;
        all.insert(make_pair(0, State(0, starti, startj, 4)));

        while (!all.empty()) {
            long long l = all.begin()->first;
            State cur = all.begin()->second;
            all.erase(all.begin());

            if (cur.mask == p3[bound]-1) {
                cout << l << endl;
//                DEBUG(l);
//                trace(cur);
                break;
            }

            if (l != dist[cur]) continue;

            FOR(i,1,bound) {
                int t = getBit(cur.mask, i-1);
                if (t == 0 && cur.cap > 0) {
                    State next(setBit(cur.mask, i-1, 1), from[i].first, from[i].second, cur.cap-1);
                    long long l2 = l + d[getId(cur.u, cur.v)][getId(from[i].first, from[i].second)];

                    if (!dist.count(next) || dist[next] > l2) {
                        dist[next] = l2;
                        all.insert(make_pair(l2, next));
                    }
                }
                else if (t == 1) {
                    State next(setBit(cur.mask, i-1, 2), to[i].first, to[i].second, cur.cap+1);
                    long long l2 = l + d[getId(cur.u, cur.v)][getId(to[i].first, to[i].second)];

                    if (!dist.count(next) || dist[next] > l2) {
                        dist[next] = l2;
                        all.insert(make_pair(l2, next));
                    }
                }
            }
        }
    }
    return 0;
}
