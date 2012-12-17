#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 1024
using namespace std;
int main()
{
    long long f1[MAXN], f2[MAXN];
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    f1[1] = 1;
    for (int i = 2; i <= 1005; ++i)
        f1[i] = f1[i - 1] + i;
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= i; ++j)
            f2[i] += j * f1[j + 1];
    int t, n;
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ++ca)
    {
        scanf("%d", &n);
        printf("%d %d %lld\n", ca, n, f2[n]);
    }
    return 0;
}
