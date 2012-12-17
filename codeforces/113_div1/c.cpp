#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
LL list[9] = {2, 3, 5, 7, 11, 13, 17, 19, 61};
//6位使用2,3,5即可，10位用至7，61可用至__LL64范围
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
        if(b & 1) ret =(ret * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return ret;
}
bool is_prime(LL n)
{
    if (n == 1) return false;
    if(n == 2 || n == 3 || n == 7 || n == 11)
        return true;
    if(n & 1 == 0)
        return false;
    LL k = 0, m, a, i;
    LL t = 0;
    for(m = n-1; !(m & 1); m >>= 1, k++);
    while(t < 4)
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
LL l, r;
int main()
{
    scanf("%I64d%I64d", &l, &r);
    LL a = l - (l % 4) + 1, b = r - (r % 4) + 1;
    if (l > a) a += 4;
    if (b > r) b -= 4;
    LL cnt = 0;
    for (LL i = a; i <= b; i += 4)
        if (is_prime(i)) cnt++;//printf("%I64d\n", i);
    printf("%I64d\n", cnt);
    return 0;
}
