#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long a[16][16], res[16][16], f[1000];
bool cal(long long x, long long y)
{
    long long z = x & y;
    if ((x | y) != 15) return false;
    return (z == 0) || (z == 3) || (z == 6) || (z == 12) || (z == 15);
}
void mul()
{
    long long temp[16][16];
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
            for (int k = 0; k < 16; ++k)
                temp[i][j] += res[i][k] * a[k][j];
    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j) res[i][j] = temp[i][j];
}
void pre_do()
{
    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
            res[i][j] = a[i][j] = cal(i, j);
    for (int i = 1; i <= 1000; ++i)
    {
        mul();
        f[i] = res[0][15];
    }
}
int main()
{
    pre_do();
    int t, n;
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ++ca)
    {
        scanf("%d", &n);
        printf("%d %lld\n", ca, f[n]);
    }
    return 0;
}
