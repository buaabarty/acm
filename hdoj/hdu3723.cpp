#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1024
using namespace std;
int f[N][N], n;
int main()
{
    while (~scanf("%d", &n))
    {
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= i && j <= n - i; ++j)
            {
                f[i][j] = f[i - 1][j] + f[i - 1][j + 1];
                if (j) f[i][j] += f[i - 1][j - 1];
            }
        printf("%d\n", f[n][0]);
    }
    return 0;
}
