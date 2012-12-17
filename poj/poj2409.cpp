#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007
#define LL long long
using namespace std;
//LL mod;
LL gcd(LL x, LL y)
{
    return (x) ? gcd(y % x, x) : y;
}
LL pow(LL x, LL y)
{
    LL res = 1LL, temp = x;
    while (y)
    {
        if (y & 1LL) res = (res * temp);// % mod;
        temp = (temp * temp);// % mod;
        y >>= 1LL;
    }
    return res;
}
LL calc(LL n, LL m)
{
    LL sum = 0;
    for (LL i = 1LL; i <= m; ++i)
        sum = (sum + pow(n, gcd(i, m)));// % mod;
    if (m & 1LL)
    {
        sum = (sum + m * pow(n, (m + 1LL) / 2LL));// % mod;
    }
    else
    {
        sum = (sum + m / 2LL * (pow(n, (m / 2LL + 1LL)) + pow(n, m / 2LL)));// % mod;
    }
    return sum;
}
int main()
{
    LL T, n, m, ca = 0;
    //scanf("%I64d", &T);
    while (cin >> n >> m)
    {
        if (!(n + m)) break;
//        mod = 2LL * m * MOD;
        cout << (calc(n, m) / 2LL / m) << endl;// % MOD << endl;
    }
    return 0;
}
