#include <iostream>
#include <cstdio>
#include <cstring>
#define N 256
#define INF 1000000000
using namespace std;
int n, m;
int dp[N][N][2], l[N], r[N];
int dat[N][N];
char str[N];
int print(int a, int b)
{
    if (a == INF) a = -1;
    if (b == INF) b = -1;
    printf("%3d%3d   ", a, b);
}
int main()
{
    int lastcut = 1;
    scanf("%d%d", &n, &m);
    memset(dat, 0, sizeof(dat));
    for (int i = 1; i <= n; ++i)
    {
        l[i] = n; r[i] = 0;
        scanf("%s", str);
        for (int j = 1; j <= m; ++j)
        {
            dat[i][j] = (str[j - 1] == 'W');
            if (dat[i][j])
            {
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
                lastcut = max(lastcut, i);
            }
        }
        //printf("%d %d\n", l[i], r[i]);
    }
    for (int i = 1; i <= m; ++i)
        dp[0][i][0] = dp[0][i][1] = INF;
    dp[0][1][0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            dp[i][j][0] = dp[i][j][1] = INF;
        for (int j = r[i]; j <= m; ++j)
            for (int k = 1; k <= l[i]; ++k) if (j >= k)
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][k][0] + j - k + 1);
        for (int j = 1; j <= l[i]; ++j)
            for (int k = r[i]; k <= m; ++k) if (j <= k)
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][k][1] + k - j + 1);
        //for (int j = 1; j <= m; ++j)
        //    print(dp[i][j][0], dp[i][j][1]);
//        puts("\n\n");
    }
    int res = INF;
    for (int i = 1; i <= m; ++i)
        res = min(res, min(dp[lastcut][i][0], dp[lastcut][i][1]));
    printf("%d\n", res);
    return 0;
}
