#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
LL n, d;
LL a[100010];
int main() {
    scanf("%I64d%I64d", &n, &d);
    for (LL i = 1; i <= n; ++i)
        scanf("%I64d", &a[i]);
    LL ans = 0;
    for (LL i = 1; i < n; ++i)
    {
        LL l = 1, r = i, mid;
        l = i; r = n;
        while (l < r) {
            if (l + 1 == r) {
                if (a[r] - a[i] <= d) l = r;
                break;
            }
            mid = (l + r + 1) >> 1;
            if (a[mid] - a[i] <= d) l = mid;
            else r = mid - 1;
        }
        LL cnt = l - i;
        if (cnt >= 2) ans += (cnt - 1) * cnt / 2;
    }
    printf("%I64d\n", ans);
    return 0;
}
