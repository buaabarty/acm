#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;
int list[9] = {2, 3, 5, 7, 11, 13, 17, 19, 61};
//6位使用2,3,5即可，10位用至7，61可用至LL范围
LL mod_pro(LL x, LL y, LL n)
{
    LL ret = 0, tmp = x % n;
    while(y)
    {
        if((y & 1) && ((ret += tmp) > n)) ret -= n;
        if((tmp <<= 1) > n) tmp -= n;
        y >>= 1;
    }
    return ret;
}
LL mod(LL a, LL b, LL c)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = mod_pro(ret, a, c);
        a = mod_pro(a, a, c);
        b >>= 1;
    }
    return ret;
}

bool isprime(LL n)
{
    if (n == 1) return false;
    if(n == 2 || n == 3 || n == 7 || n == 11)
        return true;
    if(n & 1 == 0)
        return false;
    LL k = 0, m, a, i;
    int t = 0;
    for(m = n-1; !(m & 1); m >>= 1, k++);
    while(t < 9)
    {
        a = mod(list[t] % (n - 2) + 2, m, n);
        if(a != 1)
        {
            for(i = 0;(i < k) && (a != n - 1); i++)
                a = mod_pro(a, a, n);
            if(i >= k)return false;
        }
        t++;
    }
    return true;
}
LL mypow(LL x, LL y)
{
    LL a = 1LL, b = x;
    while (y)
    {
        if (y & 1LL) a *= b;
        b *= b;
        y >>= 1LL;
    }
    return a;
}
LL n, m;
int main()
{
    while (~scanf("%lld%lld", &n, &m))
    {
        if (isprime(m))
        {
            printf("%lld\n", mypow(m, n) - 1LL);
            continue;
        }
        LL res = 1;
        for (LL i = 2; i <= m; ++i)
            if (m % i == 0)
            {
                LL cnt = 0, s = 1;
                while (m % i == 0)
                {
                    cnt++;
                    s *= i;
                    m /= i;
                }
                //printf("%lld %lld %lld\n", i, cnt, s);
                res *= (mypow(s, n) - mypow(i, cnt));
            }
        printf("%lld\n", res);
    }

    return 0;
}
