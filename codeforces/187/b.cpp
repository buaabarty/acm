#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 1000000000
using namespace std;
struct data
{
    int d, last, t;
    data(int _d, int _last, int _t)
    {
        d = _d, last = _last, t = _t;
    }
    data(){}
};
int n, m, r, dat[61][61][61];
bool inq[61][61][61];
int dist[61][61][61];
int map[61][61][61];
void print(data x)
{
    printf("%d\t%d\t%d:%d\n", x.d, x.last, x.t, dist[x.d][x.last][x.t]);
}
void spfa(int v)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= n; ++k)
                dist[i][j][k] = INF;
    memset(inq, 0, sizeof(inq));
    queue<data> q;
    for (int i = 1; i <= m; ++i)
    {
        dist[v][i][0] = 0;
        q.push(data(v, i, 0));
        inq[v][i][0] = 1;
    }
    while (!q.empty())
    {
        data now = q.front(); q.pop();
        //print(now);
        for (int i = 1; i <= n; ++i) if (i != now.d)
            for (int j = 1; j <= m; ++j)
            {
                data next = data(i, j, now.t + (now.last != j));
                if (now.t + (now.last != j) > n) continue;
                if (dist[now.d][now.last][now.t] + dat[j][now.d][i] < dist[next.d][next.last][next.t])
                {
                    dist[next.d][next.last][next.t] = dist[now.d][now.last][now.t] + dat[j][now.d][i];
                    if  (!inq[next.d][next.last][next.t])
                    {
                        inq[next.d][next.last][next.t] = 1;
                        q.push(next);
                    }
                }
            }
        inq[now.d][now.last][now.t] = 0;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 1; k <= m; ++k)
            {
                map[v][i][j] = min(map[v][i][j], dist[i][k][j]);
                //printf("%d %d %d:%d\n", v, i, j, map[v][i][j]);
            }
}
int main()
{
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 1; i <= m; ++i)
        for (int x = 1; x <= n; ++x)
            for (int y = 1; y <= n; ++y)
                scanf("%d", &dat[i][x][y]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 0; k <= n; ++k)
                map[i][j][k] = INF;
    for (int i = 1; i <= n; ++i)
        spfa(i);
    for (int i = 1; i <= r; ++i)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        k = min(k, n);
        int res = INF;
        for (int j = 0; j <= k; ++j)
            res = min(res, map[x][y][j]);
        printf("%d\n", res);
    }
    return 0;
}
