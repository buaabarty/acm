#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
using namespace std;
#define N 512
#define M 32
int n, m, f[N][M], dat[N], s[N][N];
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; ++i) scanf("%d", &dat[i]);
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
            {
                int d = dat[(i + j) / 2];
                for (int k = i; k <= j; ++k)
                    s[i][j] += iabs(dat[k] - d);
            }
        for (int i = 1; i <= n; ++i) f[i][1] = s[1][i];
        for (int i = 2; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
            {
                f[j][i] = INT_MAX / 3;
                for (int k = 1; k < j; ++k)
                    f[j][i] = min(f[j][i], f[k][i - 1] + s[k + 1][j]);
            }
        int res = INT_MAX;
        for (int i = 1; i <= m; ++i) res = min(res, f[n][i]);
        printf("%d\n", res);
    }
    return 0;
}
