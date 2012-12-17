#include <iostream>
#include <cstdio>
#include <cmath>
#define mod 10007
using namespace std;
long long mypow(long long x, long long y)
{
    long long res = 1;
    while (y > 0)
    {
        if (y % 2) res = (res * x) % mod;
        y /= 2;
        x = (x * x) % mod;
    }
    return res;
}
int main()
{
    int t;
    long long x;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &x);
        printf("%lld\n", (mypow(2, x - 1) + mypow(4, x - 1)) % mod);
    }
    return 0;
}
