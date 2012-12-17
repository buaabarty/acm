#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXT 1024
#define MAXW 32
using namespace std;
int dp[MAXT][MAXW][2], t, w, dat[MAXT][2], x;
int main()
{
    memset(dp, 0x80, sizeof(dp));
    memset(dat, 0, sizeof(dat));
    scanf("%d%d", &t, &w);
    for (int i = 1; i <= t; ++i)
    {
        scanf("%d", &x);
        if (x == 1) dat[i][0] = 1;
        else dat[i][1] = 1;
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= t; ++i)
        for (int j = 0; j <= w; ++j)
            for (int k = 0; k <= 1; ++k)
            {
                dp[i][j][k] = dp[i - 1][j][k] + dat[i][k];
                if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][1 - k] + dat[i][k]);
            }
    int res = 0;
    for (int i = 0; i <= w; ++i)
        for (int j = 0; j <= 1; ++j)
            res = max(res, dp[t][i][j]);
    printf("%d\n", res);
    return 0;
}
