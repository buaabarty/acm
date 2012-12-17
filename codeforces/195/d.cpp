#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
class data
{
public:
    LL k, b;
    bool operator < (const data a) const
    {
        if (k * a.k < 0) return (b * a.k < a.b * k);
        else return (b * a.k > a.b * k);
    }
    bool operator == (const data a) const
    {
        return b * a.k == a.b * k;
    }
}d[100010];
LL n, tot = 0;
int main()
{
    LL x, y, cnt = 0;
    scanf("%I64d", &n);
    for (LL i = 1; i <= n; ++i)
    {
        ++tot;
        scanf("%I64d%I64d", &d[tot].k, &d[tot].b);
        if (d[tot].k == 0)
        {
            --tot;
            continue;
        }
    }
    n =  tot;
    sort(d + 1, d + tot + 1);
    LL nowk = 0;
    for (LL i = 1; i <= n; ++i)
        if ((d[i - 1] == d[i]) && (i > 1))
        {
            nowk += abs(d[i].k);
        }
        else
        {
            if (nowk > 0) cnt++;
            nowk = abs(d[i].k);
        }
    if (nowk) cnt++;
    printf("%I64d\n", cnt);
    return 0;
}
