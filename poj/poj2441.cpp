#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 21
using namespace std;
int n, m, k;
int l[MAXN], d[MAXN][MAXN], bi[MAXN];
int dp[2][1 << 20];
int main()
{
    for (int i = 0; i < MAXN; ++i)
        bi[i] = (1 << i);
    memset(dp, 0, sizeof(dp));
    memset(d, 0, sizeof(d));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &l[i]);
        for (int j = 1; j <= l[i]; ++j)
        {
            scanf("%d", &d[i][j]);
            d[i][j] = bi[d[i][j] - 1];
        }
    }
    dp[0][0] = 1;
    int flag = 1, x, lastf = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < bi[m]; ++j)
            if (dp[lastf][j])
                for (int k = 1; k <= l[i]; ++k)
                {
                    x = (j | d[i][k]);
                    if (x != j)
                    {
                        dp[flag][x] += dp[lastf][j];
                    }
                }
        if (i == n) break;
        swap(flag, lastf);
        memset(dp[flag], 0, sizeof(dp[flag]));
    }
    int res = 0;
    for (int i = 0; i < bi[m]; ++i)
        res += dp[flag][i];
    printf("%d\n", res);
    return 0;
}
