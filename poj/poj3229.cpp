#include <iostream>
#include <cstdio>
#include <cstring>
#define eps 1e-6
#define MAXN 16
using namespace std;
double map[MAXN][MAXN];
double f[MAXN][(1 << MAXN)];
bool dp[MAXN][(1 << MAXN)];
double t[MAXN], v[2] = {80.0, 120.0};
int p2[MAXN], d[(1 << MAXN)];
int n, m, k, must, limit;
double times;
int lowbit(int x)
{
    return x & (x ^ (x - 1));
}
int getbit(int x)
{
    int s = 0;
    while (x > 0)
    {
        s++;
        x -= lowbit(x);
    }
    return s;
}
bool init()
{
    scanf("%d%d%d", &n, &m, &k);
    if (n + m + k == 0) return false;
    times = (double)k * 12.0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j) map[i][j] = INF;
            else map[i][j] = 0;
    must = 0;
    int x, y, kind;
    double len;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &x);
        must |= (1 << (x - 1));
    }
    for (int i = 1; i <= n; ++i)
        scanf("%lf", &t[i]);
    while (scanf("%d%d%lf%d", &x, &y, &len, &kind))
    {
        if (x + y == 0) break;
        map[x][y] = min(map[x][y], len / v[kind]);
        map[y][x] = min(map[y][x], map[x][y]);
    }
    limit = (1 << n);
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
    memset(dp, false, sizeof(dp));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < limit; ++j)
            f[i][j] = INF;
    return true;
}
void pre_doit()
{
    for (int i = 0; i < (1 << MAXN); ++i)
        d[i] = getbit(i);
    p2[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        p2[i] = p2[i - 1] * 2;
}
int main_do()
{
    dp[1][1] = true;
    f[1][1] = t[1];
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < limit; ++j)
            if (d[j] == i)
                for (int k = 1; k <= n; ++k)
                    if ((j | (1 << (k - 1))) == j)
                    {
                        if (dp[k][j])
                            for (int s = 1; s <= n; ++s)
                                if ((j | (1 << (s - 1))) != j)
                                {
                                    if (map[k][s] < 1e20)
                                    {
                                        dp[s][j | (1 << (s - 1))] = true;
                                        f[s][j | (1 << (s - 1))] = f[k][j] + map[k][s] + t[s];
                                    }
                                }
                    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < limit; ++j)
            if (f[i][j] < 1e8) printf("%.3f ", f[i][j]);
            else printf("-1 ");
        printf("\n");
    }
    int res = -1;
    for (int i = 0; i < limit; ++i)
        if ((i | must) == i)
            for (int j = 1; j <= n; ++j)
                if (dp[j][i] && (f[j][i] + map[j][1] <= times + eps)) res = max(res, d[i]);
    return res;
}
int main()
{
    pre_doit();
    while (init())
    {
        int res = main_do();
        if (res > 0) printf("%d\n", res);
        else printf("No Solution\n");
    }
    return 0;
}
