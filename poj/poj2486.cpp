#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define N 128
#define K 256
#define M 256
using namespace std;
struct edge
{
    int v, next;
}e[M];
int p[N], eid;
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
void update(int &x, int y)
{
    if (y > x) x = y;
}
int d[N], n, k, dp[2][N][K];
bool vst[N];
void dfs(int v)
{
    vst[v] = true;
    dp[0][v][0] = dp[1][v][0] = d[v];
    for (int i = 1; i <= k; ++i) dp[1][v][i] = dp[0][v][i] = d[v];
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v])
        {
            int now = e[i].v;
            dfs(now);
            for (int t = k; t >= 1; --t)
            {
                for (int l = 0; l <= t - 2; ++l)
                    update(dp[0][v][t], dp[0][now][l] + dp[0][v][t - l - 2]);
                for (int l = 0; l <= t - 1; ++l)
                    update(dp[1][v][t], dp[1][now][l] + dp[0][v][t - l - 1]);
                for (int l = 0; l <= t - 2; ++l)
                    update(dp[1][v][t], dp[0][now][l] + dp[1][v][t - l - 2]);
            }
        }
    vst[v] = false;
}
int main()
{
    int x, y;
    while (~scanf("%d%d", &n, &k))
    {
        mapinit();
        for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &x, &y);
            insert2(x, y);
        }
        memset(vst, 0, sizeof(vst));
        dfs(1);
        printf("%d\n", dp[1][1][k]);
    }
    return 0;
}
