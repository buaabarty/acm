#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
__int64 powi(__int64 x, __int64 i)
{
    __int64 res = 1;
    __int64 temp = x;
    while (i > 0)
    {
        if (i % 2) res *= temp;
        temp *= temp;
        i /= 2;
    }
    return res;
}
__int64 iabs(__int64 x)
{
    return (x > 0) ? x : -x;
}
__int64 root(__int64 b, __int64 n)
{
    __int64 x = (__int64)pow(b, 1 / (double)n);
    for (__int64 i = x - 3; i <= x + 3; ++i)
    {
        if (i <= 0) continue;
        if (iabs(powi(i - 1, n) - b) < iabs(powi(i, n) - b)) return i - 1;
    }
    return 1;
}
int main()
{
    __int64 b, n;
    while (scanf("%lld%lld", &b, &n))
    {
        if (b + n == 0) break;
        printf("%lld\n", root(b, n));
    }
    return 0;
}
