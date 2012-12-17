#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define MAXL 512
using namespace std;
int list[9] = {2, 3, 5, 7, 11, 13, 17, 19, 61};
//6位使用2,3,5即可，10位用至7，61可用至__int64范围


__int64 mod_pro(__int64 x, __int64 y, __int64 n)
{
    __int64 ret = 0, tmp = x % n;
    while(y)
    {
        if((y & 1) && ((ret += tmp)>n)) ret -= n;
        if((tmp <<= 1) > n) tmp -= n;
        y >>= 1;
    }
    return ret;
}
__int64 mod(__int64 a, __int64 b, __int64 c)
{
    __int64 ret = 1;
    while(b)
    {
        if(b & 1) ret = mod_pro(ret, a, c);
        a = mod_pro(a, a, c);
        b >>= 1;
    }
    return ret;
}

bool is_prime(__int64 n)
{
    if(n == 2 || n == 3 || n == 7 || n == 11)
        return true;
    if(n & 1 == 0)
        return false;
    __int64 k = 0, m, a, i;
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
__int64 GCD(__int64 x, __int64 y)
{
    return y ? GCD(y, x % y) : x;
}
__int64 pollard_rho(__int64 n, int c)
{
    __int64 x, y, d, i = 1, k = 2;
    x = rand() % (n - 1) + 1;
    y = x;
    while(true)
    {
        ++i;
        x = (mod_pro(x, x, n) + c) % n;
        d = GCD(y - x, n);
        if (1 < d && d < n) return d;
        if (x == y) return n;
        if (i == k) y = x, k <<= 1;
    }
}
__int64 factor[MAXL];
int facl = 0;
void findFactor(__int64 n, int k)
{
    //factor[++facl] = n;因数
    if (n == 1) return;
    if (is_prime(n))
    {
        //factor[++facl] = n;素因数
        res = min(res, n);
        return ;
    }
    __int64 p = n;
    while(p >= n)
        p = pollard_rho(p, k--);
    findFactor(p, k);
    findFactor(n / p, k);
}
