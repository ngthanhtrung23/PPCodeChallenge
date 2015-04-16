// Author: Nguyen Thanh Trung
// Algorithm: Dijkstra
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

int m, n;        // number of rows and columns of input board
int a[11][11];   // the input board
int horizontal_roads[11][11], vertical_roads[11][11]; // the roads
pair<int,int> from[111], to[111];  // we must move the k-th animal from "from[k]" --> "to[k]"
int power_of_3[111];
int d[111][111];

// Get the u-th digit in base-3 of the number mask
int getDigit(int mask, int u) {
    return (mask % power_of_3[u+1]) / power_of_3[u];
}

// Set the u-th digit in base-3 of the number mask to new value "val"
int setBit(int mask, int u, int val) {
    return mask + power_of_3[u] * (val - getDigit(mask, u));
}

// Get the ID of the cell (u, v)
int getId(int u, int v) {
    return (u-1) * n + v;
}

// Add edge between 2 cells
void addEdge(int i1, int j1, int i2, int j2) {
    int u = getId(i1, j1), v = getId(i2, j2);
    d[u][v] = d[v][u] = 1;
}

// A node in our grap
struct State {
    int mask;
    int u, v;
    int cap;  // empty seats in our car

    State() {}
    State(int mask, int u, int v, int cap) : mask(mask), u(u), v(v), cap(cap) {}
};

// Compare two node. This is required for storing nodes in STL
bool operator < (const State& a, const State& b) {
    if (a.mask != b.mask) return a.mask < b.mask;
    if (a.u != b.u) return a.u < b.u;
    if (a.v != b.v) return a.v < b.v;
    if (a.cap != b.cap) return a.cap < b.cap;
    return false;
}

int main() {
    power_of_3[0] = 1; FOR(i,1,20) power_of_3[i] = power_of_3[i-1] * 3;


    while (cin >> m >> n) {
        // Read input
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
        FOR(i,1,m) FOR(j,1,n-1) cin >> horizontal_roads[i][j];
        FOR(i,1,m-1) FOR(j,1,n) cin >> vertical_roads[i][j];


        // Initialize the distance
        FOR(i,1,100) FOR(j,1,100) {
            d[i][j] = (i == j) ? 0 : 1000111000;
        }

        // Add edges between cells
        FOR(i,1,m) FOR(j,1,n) {
            if (horizontal_roads[i][j]) addEdge(i, j, i, j+1);
            if (horizontal_roads[i][j-1]) addEdge(i, j, i, j-1);
            if (vertical_roads[i][j]) addEdge(i, j, i+1, j);
            if (vertical_roads[i-1][j]) addEdge(i, j, i-1, j);
        }

        // Use floyd to determine the shortest path between 2 cells
        FOR(k,1,100) FOR(i,1,100) FOR(j,1,100) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


        // Main part: Dijkstra
        map<State, int> dist;        // This maps from vertex to its distance (from start vertex)
        set< pair<int, State> > all; // This stores all the vertices in ascending order of distance
                                     // so that we can do Dijkstra
        all.insert(make_pair(0, State(0, starti, startj, 4)));

        while (!all.empty()) {
            // Get one vertex with shortest distance
            long long l = all.begin()->first;
            State cur = all.begin()->second;
            all.erase(all.begin());

            // If it is final vertex, we are done
            if (cur.mask == power_of_3[bound]-1) {
                cout << l << endl;
                break;
            }

            if (l != dist[cur]) continue;

            // Consider each animal
            FOR(i,1,bound) {
                // t = 0 if i-th animal is not yet picked up
                // t = 1 if i-th animal is already picked up but not yet returned home
                // t = 2 if i-th animal is already returned home
                int t = getDigit(cur.mask, i-1);
                if (t == 0 && cur.cap > 0) {
                    // If we still have empty seat, try pick up this animal
                    State next(setBit(cur.mask, i-1, 1), from[i].first, from[i].second, cur.cap-1);
                    long long l2 = l + d[getId(cur.u, cur.v)][getId(from[i].first, from[i].second)];

                    if (!dist.count(next) || dist[next] > l2) {
                        dist[next] = l2;
                        all.insert(make_pair(l2, next));
                    }
                }
                else if (t == 1) {
                    // If we already picked up this animal, try return him to home
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
