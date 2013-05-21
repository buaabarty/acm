#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL a[100010];
int main() {
    LL n;
    scanf("%I64d", &n);
    for (LL i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
    LL m, mm = 0, lh = 0;
    scanf("%I64d", &m);
    for (LL i = 1; i <= m; ++i) {
        LL x, y, nowh = lh;
        scanf("%I64d%I64d", &x, &y);
        while (mm < x) {
            nowh = max(nowh, a[++mm]);
        }
        printf("%I64d\n", nowh);
        nowh += y;
        lh = nowh;
    }
    return 0;
}
