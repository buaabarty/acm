#include <iostream>
#include <cstdio>
#include <cstring>
#define N 128
using namespace std;
int num[N][N], n, f[N][N];
int main()
{
    while (~scanf("%d", &n))
    {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                scanf("%d", &num[i][j]);
        for (int i = n; i >= 1; --i)
            for (int j = 1; j <= i; ++j)
                f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + num[i][j];
            printf("%d\n", f[1][1]);

    }
    return 0;
}
