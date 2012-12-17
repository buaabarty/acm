#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define LL long long
#define MAXN 100010
using namespace std;
LL n, num[MAXN], a[MAXN], b[MAXN], sum[MAXN];
int main()
{
    scanf("%lld", &n);
    sum[0] = 0;
    for (LL i = 1; i <= n; ++i)
    {
        scanf("%lld", &num[i]);
        sum[i] = sum[i - 1] + num[i];
    }
    num[0] = num[n + 1] = -INT_MAX;
    a[0] = -1;
    for (LL i = 1; i <= n; ++i) a[i] = i;
    for (LL i = 1; i <= n; ++i)
        while (num[a[i] - 1] >= num[i]) a[i] = a[a[i] - 1];
    b[n + 1] = -1;
    for (LL i = 1; i <= n; ++i) b[i] = i;
    for (LL i = n; i >= 1; --i)
        while (num[b[i] + 1] >= num[i]) b[i] = b[b[i] + 1];
    LL max_res = 0;
    for (LL i = 1; i <= n; ++i)
        max_res = max(max_res, (sum[b[i]] - sum[a[i] - 1]) * num[i]);
    printf("%lld\n", max_res);
    for (LL i = 1; i <= n; ++i)
        if ((sum[b[i]] - sum[a[i] - 1]) * num[i] == max_res)
        {
            printf("%lld %lld\n", a[i], b[i]);
            break;
        }
    return 0;
}
