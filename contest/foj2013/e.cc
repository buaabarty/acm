#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 128
#define L UL
#define UL unsigned long long
using namespace std;
UL list[9] = {2, 3, 5, 7, 11, 13, 17, 19, 61};
//6位使用2,3,5即可，10位用至7，61可用至__UL64范围


UL mod_pro(UL x, UL y, UL n)
{
    UL ret = 0, tmp = x % n;
    while(y)
    {
        if((y & 1) && ((ret += tmp) > n)) ret -= n;
        if((tmp <<= 1) > n) tmp -= n;
        y >>= 1;
    }
    return ret;
}
UL mod(UL a, UL b, UL c)
{
    UL ret = 1;
    while(b)
    {
        if(b & 1) ret = mod_pro(ret, a, c);
        a = mod_pro(a, a, c);
        b >>= 1;
    }
    return ret;
}

bool is_prime(UL n)
{
    if(n == 2 || n == 3 || n == 7 || n == 11)
        return true;
    if(n & 1 == 0)
        return false;
    UL k = 0, m, a, i;
    UL t = 0;
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
UL GCD(UL x, UL y)
{
    return y ? GCD(y, x % y) : x;
}
UL pollard_rho(UL n, UL c)
{
    UL x, y, d, i = 1, k = 2;
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
UL res;
UL rx, ry;
UL facl = 0, nl = 0;
struct data {
    UL d;
    UL c;
    bool operator < (const data &a) const {
        return d < a.d;
    }
} d[MAXN];
UL num[MAXN], cnt[MAXN], factor[MAXN];//factor生成的是有重复的质因数表，需要进一步计算
UL g, l;//gcd, lcm
UL ans = 10000000000000000000ULL;
UL n, m;
UL calc(UL x, UL m) {
    UL tot = 0;
    while (x) {
        tot += (x % m);
        x /= m;
    }
    return tot;
}
void findFactor(UL x, UL k)
{
    if (x<=n/x && x < ans && x*(x+calc(x, m)) == n) ans = x;
    if (x == 1) return;
    if (is_prime(x))
    {
        return ;
    }
    UL p = x;
    while(p >= x)
        p = pollard_rho(p, k--);
    findFactor(p, k);
    findFactor(x / p, k);
}




int main() {
    UL T;
    cin >> T;
    while (T--) {
        facl = 0;
        cin >> n >> m;
        ans = 10000000000000000000ULL;
        findFactor(n, 107);
        if (ans < 10000000000000000000ULL) cout << ans << endl;
        else cout << "-1" << endl;
    }
    return 0;
}

//使用时调用
//9findFactor(temp, 107);
