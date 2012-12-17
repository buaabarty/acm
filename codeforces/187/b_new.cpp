#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
LL map[64][64][64], n, m, r;
LL res[64][64][64];
int main()
{
    scanf("%I64d%I64d%I64d", &n, &m, &r);
    for (LL i = 1; i <= m; ++i)
    {
        for (LL j = 1; j <= n; ++j)
            for (LL k = 1; k <= n; ++k)
                scanf("%I64d", &map[i][j][k]);
        for (LL z = 1; z <= n; ++z)
            for (LL x = 1; x <= n; ++x)
                for (LL y = 1; y <= n; ++y)
                    map[i][x][y] = min(map[i][x][y], map[i][x][z] + map[i][z][y]);
    }
    memset(res, 0x3f, sizeof(res));
    for (LL x = 1; x <= n; ++x)
        for (LL y = 1; y <= n; ++y)
            for (LL i = 1; i <= m; ++i)
                res[0][x][y] = min(res[0][x][y], map[i][x][y]);
    for (LL i = 1; i <= n; ++i)
        for (LL k = 1; k <= n; ++k)
            for (LL x = 1; x <= n; ++x)
                for (LL y = 1; y <= n; ++y)
                    res[i][x][y] = min(res[i][x][y], res[i - 1][x][k] + res[0][k][y]);
    while (r--)
    {
        LL x, y, k;
        scanf("%I64d%I64d%I64d", &x, &y, &k);
        k = min(k, n);
        printf("%I64d\n", res[k][x][y]);
    }
    return 0;
}
