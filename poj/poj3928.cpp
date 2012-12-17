#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#define MAXN 100010
using namespace std;
long long n, res, c1[MAXN], c2[MAXN], last[MAXN], s1a[MAXN], s2a[MAXN], s1b[MAXN], s2b[MAXN], num[MAXN];
long long lowbit(long long x)
{
    return x & (x ^ (x - 1));
}
void insert1(long long x)
{
    for (; x <= 100000; x += lowbit(x)) ++c1[x];
}
void insert2(long long x)
{
    for (; x <= 100000; x += lowbit(x)) ++c2[x];
}
long long getsum1(long long x)
{
    long long s = 0;
    for (; x > 0; x -= lowbit(x)) s += c1[x];
    return s;
}
long long getsum2(long long x)
{
    long long s = 0;
    for (; x > 0; x -= lowbit(x)) s += c2[x];
    return s;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        res = 0;
        for (long long i = 1; i <= n; ++i)
        {
            scanf("%lld", &num[i]);
            insert1(num[i]);
            s1a[i] = getsum1(num[i] - 1);
            s1b[i] = getsum1(100000) - getsum1(num[i]);
        }
        for (long long i = n; i >= 1; --i)
        {
            insert2(num[i]);
            s2a[i] = getsum2(num[i] - 1);
            s2b[i] = getsum2(100000) - getsum2(num[i]);
            if ((i > 1) && (i < n)) res += (s1a[i] * s2b[i] + s1b[i] * s2a[i]);
        }
        printf("%lld\n", res);
    }
    return 0;
}
