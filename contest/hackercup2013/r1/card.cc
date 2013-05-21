#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long typec;

///Lib functions
typec GCD(typec a, typec b)
{
    return b ? GCD(b, a % b) : a;
}
typec extendGCD(typec a, typec b, typec& x, typec& y)
{
    if(!b) return x = 1, y = 0, a;
    typec res = extendGCD(b, a % b, x, y), tmp = x;
    x = y, y = tmp - (a / b) * y;
    return res;
}
///for x^k
typec power(typec x, typec k)
{
    typec res = 1;
    while(k)
    {
        if(k&1) res *= x;
        x *= x, k >>= 1;
    }
    return res;
}
///for x^k mod m
typec powerMod(typec x, typec k, typec m)
{
    typec res = 1;
    while(x %= m, k)
    {
        if(k&1) res *= x, res %= m;
        x *= x, k >>=1;
    }
    return res;
}
/***************************************
Inverse in mod p^t system
***************************************/
typec inverse(typec a, typec p, typec t = 1)
{
    typec pt = power(p, t);
    typec x, y;
    y = extendGCD(a, pt, x, y);
    return x < 0 ? x += pt : x;
}
/***************************************
Linear congruence theorem
x = a (mod p)
x = b (mod q)
for gcd(p, q) = 1, 0 <= x < pq
***************************************/
typec linearCongruence(typec a, typec b, typec p, typec q)
{
    typec x, y;
    y = extendGCD(p, q, x, y);
    while(b < a) b += q / y;
    x *= b - a, x = p * x + a, x %= p * q;
    if(x < 0) x += p * q;
    return x;
}
/***************************************
prime table
O(n)
***************************************/
const typec PRIMERANGE = 1000000;
typec prime[PRIMERANGE + 1];
typec getPrime()
{
    memset (prime, 0, sizeof (typec) * (PRIMERANGE + 1));
    for (typec i = 2; i <= PRIMERANGE; i++)
    {
        if (!prime[i]) prime[++prime[0]] = i;
        for (typec j = 1; j <= prime[0] && prime[j] <= PRIMERANGE / i; j++)
        {
            prime[prime[j]*i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return prime[0];
}
typec combinationModPri (typec n, typec k, typec m)
{
    if(k > n || m == 1) return 0;
    typec result = 1, cnt = 0, temp;
    for(typec i = 1; i < prime[0] && prime[i] <= n; i++)
    {
        temp = n, cnt = 0;
        while(temp)
            temp /= prime[i], cnt += temp;
        temp = n - k;
        while(temp)
            temp /= prime[i], cnt -= temp;
        temp = k;
        while(temp)
            temp /= prime[i], cnt -= temp;
        temp = prime[i];
        while(cnt)
        {
            if(cnt & 1)
                result *= temp, result %= m;
            temp *= temp, cnt >>= 1, temp %= m;
        }
        if(result == 0) return 0;
    }
    return result;
}

typec dat[10010];

typec module = 1000000007;

int main() {
    freopen("card_game.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    getPrime();
    typec T, n, k;
    scanf("%lld", &T);
    for (typec ca = 1; ca <= T; ++ca) {
        scanf("%lld%lld", &n, &k);
        for (typec i = 1; i <= n; ++i) {
            scanf("%lld", &dat[i]);
        }
        sort(dat + 1, dat + n + 1);
        typec ans = 0;
        for (typec i = k; i <= n; ++i) {
            ans += dat[i] * combinationModPri(i - 1, k - 1, module);
            ans %= module;
        }
        printf("Case #%lld: %lld\n", ca, ans);
    }
    return 0;
}
