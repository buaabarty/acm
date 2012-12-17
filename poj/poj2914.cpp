#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 512
#define INF 1000000000
using namespace std;
int map[MAXN][MAXN], n, m, x, y, z;
bool init()
{
    memset(map, 0, sizeof(map));
    if (scanf("%d%d", &n, &m) == EOF) return false;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &x, &y, &z);
        map[x + 1][y + 1] += z;
        map[y + 1][x + 1] += z;
    }
    return true;
}
int d[MAXN], l[MAXN];
bool use[MAXN], c[MAXN];
void merge(int x, int y)
{
    for (int k = 1; k <= n; ++k)
        if (!c[k])
        {
            map[k][x] += map[k][y];
            map[x][k] += map[y][k];
        }
    c[y] = true;
}
struct node{
    int v, d;
    friend bool operator < (node n1, node n2)
    {
        return n1.d > n2.d;
    }
    node(int a, int b)
    {
        v = a, d = b;
    }
};
priority_queue<node> q;
int solve(int p)
{

    int res = 100000000;
    memset(c, false, sizeof(c));
    for (int ca = 1; ca < n; ++ca)
    {
        for (int i = 1; i <= n; ++i)
            use[i] = c[i];
        memset(d, 0, sizeof(d));
        while (!q.empty()) q.pop();
        int s = -1, t = -1, maxd, maxt, now;
        for (int i = 1; i <= n; ++i)
        {
            maxd = -INF;
            for (int j = 1; j <= n; ++j)
                if (d[j] > maxd && !use[j])
                {
                    maxd = d[j];
                    maxt = j;
                }
            if (maxt == t) break;
            s = t;
            t = maxt;
            now = maxd;
            use[t] = true;
            for (int j = 1; j <= n; ++j)
                if (!use[j]) d[j] += map[maxt][j];
        }
        if (t != 1) merge(s, t);
        else merge(t, s);
        res = min(res, now);
    }
    return res;
}
int main()
{
    while (init())
    {
        printf("%d\n", solve(1));
    }
    return 0;
}
