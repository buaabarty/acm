#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 64
#define MAXT 10
using namespace std;
int n, d, m, dat[MAXT + 1][MAXN][MAXN], dp[MAXT + 1][MAXN][MAXN];
int gcd(int x, int y)
{
    return (x) ? gcd(y % x, x) : y;
}
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int getsum(int time, int x2, int y2, int x1, int y1)
{
    if ((x1 == x2) && (y1 == y2))
    {
        return dat[time][x1][y1];
    }
    else if (x1 == x2)
    {
        int s = 0;
        if (y1 > y2) swap(y1, y2);
        for (int i = y1; i <= y2; ++i)
            s += dat[time][x1][i];
        return s;
    }
    else if (y1 == y2)
    {
        int s = 0;
        if (x1 > x2) swap(x1, x2);
        for (int i = x1; i <= x2; ++i)
            s += dat[time][i][y1];
        return s;
    }
    int dx = x2 - x1, dy = y2 - y1;
    int g = gcd(iabs(dx), iabs(dy)), s = 0;
    dx /= g, dy /= g;
    for (int i = 0; i <= g; ++i)
        s += dat[time][x1 + dx * i][y1 + dy * i];
    return s;
}
int main()
{
    while (scanf("%d%d%d", &n, &d, &m), (n + d + m))
    {
        memset(dat, 0, sizeof(dat));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; ++i)
        {
            int x, y, t;
            scanf("%d%d%d", &x, &y, &t);
            dat[t][x + d][y + d] = 1;
        }
        n = n + 2 * d;
        for (int t = 1; t <= MAXT; ++t)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    for (int x = 0; x < n; ++x)
                        for (int y = 0; y < n; ++y)
                            if ((x - i) * (x - i) + (y - j) * (y - j) <= d * d)
                            {
                                dp[t][i][j] = max(dp[t][i][j], getsum(t, i, j, x, y) + dp[t - 1][x][y]);
                            }
        int res = 0;
        for (int i = d; i < n - d; ++i)
            for (int j = d; j < n - d; ++j)
                res = max(res, dp[MAXT][i][j]);
        printf("%d\n", res);
    }
    return 0;
}
