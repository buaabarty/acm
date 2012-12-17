#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int p[1000], pcnt = 0;
int dp[200][20][1200], n, k;
bool ip[2000];
int main()
{
    memset(ip, 1, sizeof(ip));
    for (int i = 2; i <= 1120; ++i)
        if (ip[i])
        {
            for (int j = i << 1; j <= 1120; j += i)
                ip[j] = 0;
            p[++pcnt] = i;
        }
    p[++pcnt] = 100000000;
//    printf("%d\n", pcnt);
    while (scanf("%d%d", &n, &k), (n + k))
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        int res = 0;
        for (int i = 1; p[i] <= n; ++i)
        {
            for (int j = 0; j <= k; ++j)
                for (int t = 0; t <= n; ++t)
                {

                    dp[i][j][t] = dp[i - 1][j][t];
                    if (j && (t >= p[i])) dp[i][j][t] += dp[i - 1][j - 1][t - p[i]];
                    //printf("%d %d %d->%d\n", p[i], j, t, dp[i][j][t]);
                }
            //printf("%d\n", dp[i][k][n]);
            res = dp[i][k][n];
        }
        printf("%d\n", res);
    }
    return 0;
}
