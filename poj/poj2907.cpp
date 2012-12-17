#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int dist(int x1, int y1, int x2, int y2)
{
    return iabs(x1 - x2) + iabs(y1 - y2);
}
int lowbit(int x)
{
    return x & (x ^ (x - 1));
}
int bitcnt(int x)
{
    int s = 0;
    while (x)
    {
        s++;
        x -= lowbit(x);
    }
    return s;
}
void update(int &x, int y)
{
    if (y < x) x = y;
}
int f[11][11][1<<10], n, sx, sy, x[20], y[20];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &sx, &sy);
        scanf("%d%d", &sx, &sy);
        scanf("%d", &n);
        memset(f, 0x3f, sizeof(f));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &x[i], &y[i]);
            f[1][i][1<<i] = dist(sx, sy, x[i], y[i]);
            //printf("%d\n", f[1][i][1<<i]);
        }
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < (1<<n); ++j) if (bitcnt(j) == i)
                for (int k = 0; k < n; ++k) if (!(j & (1 << k)))
                    for (int s = 0; s < n; ++s) if (j & (1 << s))
                    {
                        update(f[i + 1][k][j|(1<<k)], f[i][s][j] + dist(x[s], y[s], x[k], y[k]));
             //           printf("%d %d %d->%d\n", i + 1, k, j|(1<<k), f[i + 1][k][j|(1<<k)]);
                    }
        int res = 1000000000;
        for (int i = 0; i < n; ++i)
            update(res, f[n][i][(1<<n)-1] + dist(x[i], y[i], sx, sy));
        printf("The shortest path has length %d\n", res);
    }
    return 0;
}
