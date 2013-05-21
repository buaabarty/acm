#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define N 1024
#define S 128
using namespace std;
int n, f[S][N], la, lb, num[N], s;
int main()
{
    while (scanf("%d", &n), n)
    {
        scanf("%d%d%d", &lb, &la, &s);
        for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
        memset(f, 0x7f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i)
            f[0][i] = f[0][i - 1] + num[i];
        for (int i = 1; i <= s; ++i)
            for (int j = 1; j <= n; ++j)
            {
                f[i][j] = f[i][j - 1] + num[j];
                for (int k = la; k <= lb; ++k)
                    if (j >= k) f[i][j] = min(f[i][j], f[i - 1][j - k]);
            }
        int res = f[0][n];
        for (int i = 0; i <= s; ++i)
            res = min(res, f[i][n]);
        printf("%d\n", res);

    }
    return 0;
}
