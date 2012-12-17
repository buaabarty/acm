#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 32768
using namespace std;
int cmp(long long x, long long y)
{
    return y - x;
}
int main()
{
    int n;
    long long b;
    long long h[MAXN];
    while (scanf("%d%lld", &n, &b) != EOF)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &h[i]);
        sort(h + 1, h + 1 + n, greater<int>());
        long long s = 0LL;
        for (int i = 1; i <= n; ++i)
        {
            s += h[i];
            if (s >= b)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
