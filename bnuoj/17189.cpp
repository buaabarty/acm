#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define INF 1000000000
using namespace std;
struct edge
{
    int v, d, next;
}e[1000];
int p[110], eid, n, tot;
int dp[110][1<<7];
int color[110], qua[110], cost[110], sum[110];
int totmin[110][1<<7];
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y)
{
    insert(x, y);
    insert(y, x);
}
int getcolor(char c)
{
    switch (c)
    {
        case 'R': return 0;
        case 'O': return 1;
        case 'Y': return 2;
        case 'G': return 3;
        case 'B': return 4;
        case 'I': return 5;
        case 'V': return 6;
    }
}
void dfs(int v, int last, int limit)
{
    dp[v][0] = 0;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        int u = e[i].v;
        if (u == last) continue;
        dfs(u, v, limit);
        sum[v] |= sum[u];
        for (int x = 0; x < (1<<7); ++x)
            if (dp[v][x] < INF)
                for (int y = 0; y < (1<<7); ++y)
                    dp[v][x|y] = min(dp[v][x|y], dp[v][x] + dp[u][y]);
    }
    if (qua[v] >= limit)
    {
        sum[v] |= color[v];
    }
    dp[v][sum[v]] = min(dp[v][sum[v]], cost[v]);
}
bool okay(int limit)
{
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < (1 << 7); ++j)
            dp[i][j] = INF;
    memset(sum, 0, sizeof(sum));
    dfs(0, -1, limit);
    return (dp[0][(1<<7)-1] <= tot);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(cost, 0, sizeof(cost));
        memset(qua, 0, sizeof(qua));
        scanf("%d%d", &n, &tot);
        mapinit();
        for (int i = 1; i <= n; ++i)
        {
            char str[10];
            int a, b, c;
            scanf("%s%d%d%d", str, &qua[i], &b, &cost[i]);
            insert(b, i);
            insert(i, b);
            color[i] = (1 << getcolor(str[0]));
        }
        cost[0] = INF;
        int left = 1, right = 1000;
        while (left < right)
        {
            if (left + 1 == right)
            {
                if (okay(right)) left = right;
                break;
            }
            int mid = (left + right + 1) >> 1;
            if (okay(mid)) left = mid;
            else right = mid - 1;
        }
        if (okay(left)) printf("%d\n", left);
        else printf("Stay hungry\n");
    }
    return 0;
}
