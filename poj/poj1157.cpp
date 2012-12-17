#include <iostream>
#include <cstdio>
#include <cstring>
#define N 128
using namespace std;
int n, m, f[N][N], dat[N][N];
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &dat[i][j]);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                f[i][j] = f[i - 1][j - 1] + dat[i][j];
                if (i < j) f[i][j] = max(f[i][j], f[i][j - 1]);
            }
        printf("%d\n", f[n][m]);
    }
    return 0;
}
