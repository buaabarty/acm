#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c, g, zero = 7500;
int dp[21][15001], dc[21], dg[21];
int main()
{
    while (~scanf("%d%d", &c, &g))
    {
        for (int i = 1; i <= c; ++i) scanf("%d", &dc[i]);
        for (int i = 1; i <= g; ++i) scanf("%d", &dg[i]);
        memset(dp, 0, sizeof(dp));
        dp[0][zero] = 1;
        for (int i = 1; i <= g; ++i)
            for (int j = 0; j <= 15000; ++j)
                if (dp[i - 1][j])
                    for (int k = 1; k <= c; ++k)
                        dp[i][j + dc[k] * dg[i]] += dp[i - 1][j];
        printf("%d\n", dp[g][zero]);
    }
    return 0;
}
