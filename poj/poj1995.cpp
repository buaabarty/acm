#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
__int64 pow(__int64 a, __int64 b, __int64 m)
{
    __int64 res = 1;
    while (b)
    {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
int main()
{
    __int64 t, m, n, sum, a, b;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &m, &n);
        sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld%lld", &a, &b);
            sum = (sum + pow(a, b, m)) % m;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
