#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 16
using namespace std;
int main()
{
    int n, m;
    int f[MAXN][MAXN][MAXN];
    while (scanf("%d%d", &n, &m))
    {
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= j; ++k)
                for (int l = 0; l <= k; ++l)
                    f[i][j][k] += f[i - 1][j - k][l];
    printf("%d\n", f[1][1][1]);
    int res = 0;
    for (int i = 1; i <= m; ++i)
        res += f[n][m][i];
    printf("%d\n", res);
    }
    return 0;
}
