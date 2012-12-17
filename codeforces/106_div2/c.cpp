#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define N 1024
#define M 16
using namespace std;
int n, m, c0, d0, dp[M][N], ai, bi, ci, di;
int main()
{
    while (~scanf("%d%d%d%d", &n, &m, &c0, &d0))
    {
        memset(dp, 0, sizeof(dp));
        for (int i = c0; i <= n; ++i) dp[0][i] = max(dp[0][i], dp[0][i - c0] + d0);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d%d", &ai, &bi, &ci, &di);
            for (int j = 0; j <= n; ++j)
                for (int k = 0; k <= ai / bi; ++k)
                    if (j >= k * ci)
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * ci] + k * di);
        }
        int res = 0;
        for (int i = 0; i <= n; ++i) res = max(res, dp[m][i]);
        printf("%d\n", res);
    }
    return 0;
}
