#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define N 256
using namespace std;
int p, n;
double d[N][N], f[N][N];
int main()
{
    while (~scanf("%d", &p), (p != -1))
    {
        n = 1 << p;
        //printf("%d\n", n);
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%lf", &d[i][j]);
        for (int i = 0; i < n; ++i) f[0][i] = 1;
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    if (((j >> i) ^ 1) == (k >> i))
                    {
                        //printf("%d %d %d\n", i, j, k);
                        f[i + 1][j] += f[i][j] * f[i][k] * d[j][k];
                        //printf("%lf %lf %lf %lf\n", f[i + 1][j], f[i][j], f[i][k], d[j][k]);
                    }
        int res = 0;
        for (int i = 1; i < n; ++i)
            if (f[p][i] > f[p][res]) res = i;
        printf("%d\n", res + 1);
    }
    return 0;
}
