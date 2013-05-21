#include <iostream>
#include <cstdio>
#include <cstring>
#define N 16
using namespace std;
int MOD;
struct matrix
{
    int n, m, num[N][N];
    matrix(){}
    matrix(int x, int y)
    {
        n = x, m = y;
        memset(num, 0, sizeof(num));
    }
    matrix operator *(matrix a)
    {
        matrix temp(n, a.m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= a.m; ++j)
                for (int k = 1; k <= m; ++k)
                {
                    temp.num[i][j] += num[i][k] * a.num[k][j];
                    temp.num[i][j] %= MOD;
                }
        return temp;
    }
    void print()
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                printf("%5d", num[i][j]);
            puts("");
        }
        puts("");
    }
};
int main()
{
    int n = 10, k;
    matrix a, b;
    while (~scanf("%d%d", &k, &MOD))
    {
        if (k < 10)
        {
            printf("%d\n", k);
            continue;
        }
        a = matrix(n, n);
        for (int i = 2; i <= n; ++i) a.num[i][i - 1] = 1;
        for (int i = 1; i <= n; ++i) scanf("%d", &a.num[1][i]);
        b = matrix(n, 1);
        for (int i = 1; i <= n; ++i) b.num[i][1] = n - i;
        while (k)
        {
            if (k & 1) b = a * b;
            a = a * a;
            k >>= 1;
        }
        int sum = 0;
        printf("%d\n", b.num[n][1]);
    }
    return 0;
}
