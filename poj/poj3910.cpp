#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#define long __int64
using namespace std;
long prime[10000], pt = 0;
bool isp[50000];
void pre_do()
{
    memset(prime, 0, sizeof(prime));
    pt = 0;
    memset(isp, true, sizeof(isp));
    for (int i = 2; i < 50000; ++i)
        if (isp[i]){
            prime[++pt] = i;
            for (int j = 2; i * j < 50000; ++j)
                isp[j * i] = false;
        }
}
long phi(long x)
{
    long res = x;
    for (int i = 1; prime[i] * prime[i] <= x; ++i)
        if (!(x % prime[i])){
            while (!(x % prime[i])) x /= prime[i];
            res = res / prime[i] * (prime[i] - 1);
        }
    if (x > 1) res = res * (x - 1) / x;
    return res;
}
int main()
{
    pre_do();
    long n, res, x;
    while (cin >> n)
    {
        res = 1;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            res = (res * phi(x)) % 1000000007LL;
        }
        cout << res << endl;
    }
    //scanf("%d", &x);
    //printf("%d\n", phi(i));
    return 0;
}
