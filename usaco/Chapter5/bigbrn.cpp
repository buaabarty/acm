/*
ID:ybojan2
LANG:C++
TASK:bigbrn
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1024
using namespace std;
int dp[MAXN][MAXN];
bool dat[MAXN][MAXN];
int n, t, x, y;
int main()
{
    freopen("bigbrn.in", "r", stdin);
    freopen("bigbrn.out", "w", stdout);
    scanf("%d%d", &n, &t);
    memset(dat, 1, sizeof(dat));
    while (t--)
    {
        scanf("%d%d", &x, &y);
        dat[x][y] = 0;
    }
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = dat[i][j] * (min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1);
            res = max(res, dp[i][j]);
        }
    /*for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%5d", dp[i][j]);
        printf("\n");
    }*/
    printf("%d\n", res);
    return 0;
}
