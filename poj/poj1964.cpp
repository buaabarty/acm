#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define LL long long
#define MAXN 100010
using namespace std;
LL n, m, num[MAXN], a[MAXN], b[MAXN];
LL get_ans()
{
    for (LL i = 1; i <= n; ++i) { a[i] = i; b[i] = i; }
    num[0] = num[n + 1] = -INT_MAX;
    a[0] = b[n + 1] = -1;
    for (LL i = 1; i <= n; ++i)
        while (num[a[i] - 1] >= num[i]) a[i] = a[a[i] - 1];
    for (LL i = n; i >= 1; --i)
        while (num[b[i] + 1] >= num[i]) b[i] = b[b[i] + 1];
    LL now_max = 0;
    for (LL i = 1; i <= n; ++i)
        now_max = max(now_max, (b[i] - a[i] + 1) * num[i]);
    return now_max;
}
int main()
{
    LL t;
    char c[10];
    while (~scanf("%lld%lld", &m, &n))
    {
        memset(num, 0, sizeof(num));
        LL res = 0;
        while (m--)
        {
            for (LL i = 1; i <= n; ++i)
            {
                scanf("%s", c);
                if (c[0] == '1') ++num[i];
                else num[i] = 0;
            }
            res = max(res, get_ans());
        }
        printf("%lld\n", res);
    }
    return 0;
}
