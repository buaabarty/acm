#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 1024
#define MAXM 1048576
using namespace std;
struct edge{
    int v, d, next;
}e[MAXM];
int p[MAXN], eid;
inline void insert1(int x, int y, int d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
    e[eid].v = x;
    e[eid].d = 0;
    e[eid].next = p[y];
    p[y] = eid++;
}
int n, m, h[MAXN], gap[MAXN];
int source, sink;
inline int dfs(int pos, int cost)
{
    if (pos == sink) return cost;
    int j, minh = n - 1, lv = cost, d;
    for (j = p[pos]; j != -1; j = e[j].next)
    {
        int v = e[j].v, val = e[j].d;
        if (val > 0){
            if (h[v] + 1 == h[pos]){
                if (lv < e[j].d) d = lv;
                else d = e[j].d;
                d = dfs(v, d);
                e[j].d -= d;
                e[j ^ 1].d += d;
                lv -= d;
                if (h[source] >= n) return cost - lv;
                if (lv == 0) break;
            }
            if (h[v] < minh) minh = h[v];
        }
    }
    if (lv == cost){
        --gap[h[pos]];
        if (gap[h[pos]] == 0) h[source] = n;
        h[pos] = minh + 1;
        ++gap[h[pos]];
    }
    return cost - lv;
}
int sap(int st, int ed)
{
    n = n * 2;
    source = st;
    sink = ed;
    int ret = 0;
    memset(gap, 0, sizeof(gap));
    memset(h, 0, sizeof(h));
    while (h[st] < n) ret += dfs(st, INT_MAX);
    return ret;
}
int map[MAXN][MAXN];

void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}
int x[MAXM], y[MAXM];
bool init()
{
    int k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) map[i][j] = 100000000;
    for (int i = 1; i <= n; ++i) map[i][i] = 0;
    memset(p, -1, sizeof(p));
    eid = 0;
    if (n + m + k == 0) return false;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
        map[x[i]][y[i]] = 1;
    }
    floyd();
    for (int i = 1; i <= m; ++i)
        if (map[1][x[i]] + map[y[i]][n] < k) insert1(x[i] + n, y[i], INT_MAX);
    for (int i = 1; i <= n; ++i)
        insert1(i, i + n, 1);
    source = n + 1, sink = n;
    n = n * 2;
    return true;
}
int main()
{
    while (init())
    {
        printf("%d\n", sap(source, sink));
    }
    return 0;
}
