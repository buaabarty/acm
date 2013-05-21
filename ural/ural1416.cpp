#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 512
using namespace std;
int map[MAXN][MAXN], longest[MAXN][MAXN];
int last[MAXN], d[MAXN];
bool use[MAXN], in_mst[MAXN][MAXN];
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
    for (int i = 1; i <= n; ++i)
        in_mst[last[i]][i] = in_mst[i][last[i]] = true;
    return res;
}
void dfs(int st, int v, int ll)
{
    use[v] = true;
    longest[st][v] = ll;
    for (int i = 1; i <= n; ++i)
        if (!use[i] && in_mst[v][i])
            dfs(st, i, max(map[v][i], ll));
}
int main()
{
    int __;
    //scanf("%d", &__);
    //while (__--)
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
        printf("Cost: %d\n", min_mst);
        printf("Cost: %d\n", ans);
    }
    return 0;
}
