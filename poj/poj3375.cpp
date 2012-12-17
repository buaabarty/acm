#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXM 100010
#define MAXN 2048
using namespace std;
int m, n;
long long a[MAXM], b[MAXN];
long long myabs(long long x)
{
    return (x > 0) ? x : -x;
}
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &b[i]);
    sort(b + 1, b + n + 1);
    long long res = 0;
    for (int i = 1, j = 1; i <= n; ++i)
        if (j == m) res += myabs(a[m] - b[i]);
        else
        {
            while ((myabs(a[j + 1] - b[i]) < myabs(a[j] - b[i])) && (j < m)) ++j;
            res += myabs(a[j] - b[i]);
        }
    printf("%lld\n", res);
    return 0;
}
