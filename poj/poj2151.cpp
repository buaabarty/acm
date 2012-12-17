#include <iostream>
#include <cstdio>
#include <cstring>
#define N 32
#define T 1024
using namespace std;
int n, t, m;
double f[N], dp[T][N][N], a, b;
int main()
{
    while (scanf("%d%d%d", &n, &t, &m), (n + t + m))
    {
        memset(dp, 0, sizeof(dp));
        a = 1; b = 1;
        for (int i = 1; i <= t; ++i)
        {
            dp[i][0][0] = 1;
            for (int j = 1; j <= n; ++j)
            {
                scanf("%lf", &f[j]);
                for (int k = 0; k <= j; ++k)
                    dp[i][j][k] = dp[i][j - 1][k] * (1 - f[j]) + dp[i][j - 1][k - 1] * f[j];
            }
            a *= (1 - dp[i][n][0]);
            double s = 0;
            for (int j = 1; j < m; ++j)
                s += dp[i][n][j];
            b *= s;
        }
        printf("%.3f\n", a - b);
    }
    return 0;
}
