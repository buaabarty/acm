#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 512
#define MAXM 65536
using namespace std;
int map[MAXN][MAXN], longest[MAXN][MAXN];
int last[MAXN], d[MAXN];
bool use[MAXN], in_mst[MAXN][MAXN];
struct edge{
    int v, next;
}e[MAXM];
int p[MAXN], eid;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
int n, m, a, b, c;
void init()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            map[i][j] = INT_MAX;
    for (int i = 1; i <= n; ++i) map[i][i] = 0;
    memset(in_mst, false, sizeof(in_mst));

    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        map[a][b] = map[b][a] = c;
    }
}
int cal_mst()
{
    for (int i = 0; i <= n; ++i)
        d[i] = INT_MAX;
    memset(use, false, sizeof(use));
    memset(last, 0, sizeof(last));
    d[1] = 0;
    int res = 0;
    last[1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        a = 0;
        for (int j = 1; j <= n; ++j)
            if (!use[j] && (d[j] < d[a])) a = j;
        res += d[a];
        use[a] = true;
        for( int j = 1; j <= n; ++j)
            if (!use[j] && (map[a][j] < d[j])){
                last[j] = a;
                d[j] = map[a][j];
            }
    }
    memset(p, -1, sizeof(p));
    eid = 0;
    for (int i = 1; i <= n; ++i)
        in_mst[last[i]][i] = in_mst[i][last[i]] = true;
    for (int i = 1; i <= n; ++i)
        if (last[i]){
            insert(last[i], i);
            insert(i, last[i]);
        }
    return res;
}
void dfs(int st, int v, int ll)
{
    use[v] = true;
    longest[st][v] = ll;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!use[e[i].v]) dfs(st, e[i].v, max(ll, map[v][e[i].v]));
}
int main()
{
    int __;
    scanf("%d", &__);
    while (__--)
    {
        init();
        int min_mst = cal_mst(), ans = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            memset(use, false, sizeof(use));
            dfs(i, i, 0);
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if ((!in_mst[i][j]) && (map[i][j] != INT_MAX)) ans = min(ans, min_mst - longest[i][j] + map[i][j]);
        if (min_mst == INT_MAX) min_mst = -1;
        if (ans == INT_MAX) ans = -1;
        if (min_mst == ans) printf("Not Unique!\n");
        else printf("%d\n", min_mst);
    }
    return 0;
}
