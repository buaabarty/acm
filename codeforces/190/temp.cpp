#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 1000000000
using namespace std;
int f[1<<15], n, i, j, k, dat[15], sm[1<<15][15];
int map[15][15];
int cnt(int x)
{
    int s = 0;
    while (x)
    {
        s += (x & 1);
        x >>= 1;
    }
    return s;
}
int upb(int x, int y)
{
    if (y == 0) return INF;
    int d = x / y;
    if (x % y) d++;
    return d;
}
int main()
{
    int T;
    char str[100];
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca)
    {
        for (int j = 0; j < (1 << 15); ++j)
                f[j] = INF;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &dat[i]);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", str);
            for (int j = 0; j < n; ++j)
                map[i][j] = str[j] - '0';
        }
        memset(sm, 0, sizeof(sm));
        for (int i = 0; i < (1 << n); ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    if ((i & (1<<k)) && !(i & (1<<j))) sm[i][j] = max(sm[i][j], map[k][j]);
        for (int i = 0; i < n; ++i) f[1<<i] = dat[i];
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < (1<<n); ++j) if (cnt(j) == i)
            {
                for (int k = 0; k < n; ++k) if (!(j & (1<<k)))
                {
                    f[j|(1<<k)] = min(f[j|(1<<k)], f[j] + upb(dat[k], sm[j][k]));
                    f[j|(1<<k)] = min(f[j|(1<<k)], f[j] + dat[k]);
                }
            }
        }
        printf("Case %d: %d\n", ca, f[(1<<n) - 1]);
    }
    return 0;
}
