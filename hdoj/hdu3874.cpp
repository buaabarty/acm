#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define N 1000010
using namespace std;
LL p[N], num[N], c[N], app[N], n, m;
bool okay[N];
struct quote
{
    LL l, r, o, ans;
}q[N];
bool cmp1(quote a, quote b)
{
    return a.l < b.l;
}
bool cmp2(quote a, quote b)
{
    return a.o < b.o;
}
LL lowbit(LL x)
{
    return x & (x ^ (x - 1));
}
LL getsum(LL k)
{
    LL s = 0;
    while (k > 0)
    {
        s += c[k];
        k -= lowbit(k);
    }
    return s;
}
void insert(LL k, LL delta)
{
    while (k <= n)
    {
        c[k] += delta;
        k += lowbit(k);
    }
}
int main()
{
    LL T;
    scanf("%I64d", &T);
    while (T--)
    {
        scanf("%I64d", &n);
        memset(p, -1, sizeof(p));
        memset(app, -1, sizeof(app));
        memset(okay, true, sizeof(okay));
        for (LL i = 1; i <= n; ++i) scanf("%I64d", &num[i]);
        for (LL i = n; i >= 1; --i)
            if (app[num[i]] < 0) app[num[i]] = i;
            else
            {
                p[i] = app[num[i]];
                okay[p[i]] = false;
                app[num[i]] = i;
            }
        memset(c, 0, sizeof(c));
        for (LL i = 1; i <= n; ++i)
            if (okay[i]) insert(i, num[i]);
        scanf("%I64d", &m);
        for (LL i = 1; i <= m; ++i)
        {
            scanf("%I64d%I64d", &q[i].l, &q[i].r);
            q[i].o = i;
        }
        sort(q + 1, q + m + 1, cmp1);
        LL last = 1;
        for (LL i = 1; i <= m; ++i)
        {
            if (q[i].l != last)
            {
                for (LL j = last; j < q[i].l; ++j)
                {
                    insert(j, -num[j]);
                    if (p[j] > 0) insert(p[j], num[j]);
                }
                last = q[i].l;
            }
            q[i].ans = getsum(q[i].r) - getsum(q[i].l - 1);
        }
        sort(q + 1, q + m + 1, cmp2);
        for (LL i = 1; i <= m; ++i)
            printf("%I64d\n", q[i].ans);
    }
    return 0;
}
