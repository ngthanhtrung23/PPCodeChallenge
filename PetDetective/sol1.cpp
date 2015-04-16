// Algorithm: BFS using double ended queue

#include <stdio.h>
#include <string.h>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> quad;
#define X first
#define Y second

quad rect(int x, int y, int u, int v)
    { return quad(ii(x, y), ii(u, v)); }

const int N = 40;
int m, n, k, b[123][123], bx[123][123], by[123][123], id[123][123], MaxID=0;
int a[N][4], Special[N]; //
short d[N][1<<11][1<<11];

bool minimize(short &a, int b)
    { return a>b ? a=b, true : false; }

int bfs(int u) {
    deque<quad> qu;
    memset(d, 0x3c, sizeof d);
    qu.push_back(rect(0, u, 0, 0));

    while (qu.size()) {
        quad Pop=qu.front(); qu.pop_front();
        int du=Pop.X.X, u=Pop.X.Y, u1=Pop.Y.X, u2=Pop.Y.Y;
        if (!minimize(d[u][u1][u2], du)) continue;
        if (u2==(1<<k)-1) return du;
        //printf("d[%d][%d][%d]=%d\n", u, u1, u2, du);

        if (int x=Special[u]) {
            if (x>0 && ((1<<x-1)&(~u1)) && ((1<<x-1)&~u2) && __builtin_popcount(u1)<4)
            qu.push_front(rect(du, u, u1|(1<<x-1), u2));
            if (x<0 && ((1<<-x-1)&(u1)) && ((1<<-x-1)&~u2))
            qu.push_front(rect(du, u, u1^(1<<-x-1), u2|(1<<-x-1)));
        }
        for (int i=0; i<4; i++) if (int v=a[u][i])
            qu.push_back(rect(du+1, v, u1, u2));
    }
    return -1;
}

main() {
    int sx, sy;
    scanf("%d%d", &m, &n);
    for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++) {
        scanf("%d", &b[i][j]);
        if (b[i][j]==99)
            { sx=i, sy=j; b[i][j]=0; }
        else if (b[i][j]>0)
            k++;
        id[i][j] = ++MaxID;
        Special[id[i][j]]=b[i][j];
    } // done k, id, sx, sy

    for (int i=1; i<=m; i++)
    for (int j=1; j<n; j++) {
        scanf("%d", &bx[i][j]);
        #define connect(x, y, k) a[x][k]=y
        if (bx[i][j]) {
            connect(id[i][j], id[i][j+1], 0);
            connect(id[i][j+1], id[i][j], 1);
        }
    }
    for (int i=1; i<m; i++)
    for (int j=1; j<=n; j++) {
        scanf("%d", &by[i][j]);
        if (by[i][j]) {
            connect(id[i][j], id[i+1][j], 2);
            connect(id[i+1][j], id[i][j], 3);
        }
    }
    /*
    for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
    printf(j==n ? "%d <--- id\n" : "%d ", id[i][j]);

    for (int i=1; i<=MaxID; i++)
    printf("%d %d %d %d <-- %d(%d)\n", a[i][0], a[i][1], a[i][2], a[i][3], i, Special[i]);
    */
    cout << bfs(id[sx][sy]) << endl;
}
