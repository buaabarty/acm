#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define INF 1000000000000000000LL
#define LL long long
using namespace std;
LL n, m;
LL num[1001][1001];
LL sum[1001], res, resx, resy;
LL iabs(LL x) {
    if (x > 0) return x; else return -x;
}
LL sqr(LL x) {return x * x; }
void gao(LL size, bool flag) {
    LL mm = INF;
    for (LL i = 0; i <= size; ++i)
    {
        LL now = 0;
        for (LL j = 1; j <= size; ++j)
            now += sqr(iabs(i * 4 + 2 - j * 4)) * sum[j];
        if (now < mm) {
            mm = now;
            if (flag) resx = i; else resy = i;
        }
    }
    res += mm;
}
int main() {
    res = 0;
    scanf("%I64d%I64d", &n, &m);
    for (LL i = 1; i <= n; ++i)
        for (LL j = 1; j <= m; ++j)
            scanf("%I64d", &num[i][j]);
    memset(sum, 0, sizeof(sum));
    for (LL i = 1; i <= n; ++i)
        for (LL j = 1; j <= m; ++j)
            sum[i] += num[i][j];
    gao(n, true);
    memset(sum, 0, sizeof(sum));
    for (LL i = 1; i <= n; ++i)
        for (LL j = 1; j <= m; ++j)
            sum[j] += num[i][j];
    gao(m, false);
    printf("%I64d\n%I64d %I64d\n", res, resx, resy);
    return 0;
}
