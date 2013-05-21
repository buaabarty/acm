#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
LL n, m, k;
LL q[100010], s[100010];
struct query {
    LL l, r, d;
} d[100010];
LL a[100010];
int main() {
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    for (LL i = 1; i <= n; ++i)
        scanf("%I64d", &a[i]);
    for (LL i = 1; i <= m; ++i)
        scanf("%I64d%I64d%I64d", &d[i].l, &d[i].r, &d[i].d);
    for (LL i = 1; i <= k; ++i) {
        LL x, y;
        scanf("%I64d%I64d", &x, &y);
        s[x]++; s[y+1]--;
    }
    for (LL i = 1; i <= m; ++i) q[i] = q[i-1] + s[i];
    memset(s, 0, sizeof(s));
    for (LL i = 1; i <= m; ++i)
        s[d[i].l] += d[i].d * q[i], s[d[i].r+1] -= d[i].d * q[i];
    LL now = 0;
    for (LL i = 1; i <= n; ++i) {
        now = now + s[i];
        printf("%I64d%c", now + a[i], " \n"[i==n]);
    }
    return 0;
}
