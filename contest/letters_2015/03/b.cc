#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
typedef long long LL;
map<LL, LL> last;
LL n, f[300000 + 9], ans = -2000000001, l, r, d[300000 + 9], cnt = 0;
int main() {
    memset(f, 0, sizeof(f));
    scanf("%lld", &n);
    for (LL i = 1; i <= n; ++i) {
        scanf("%lld", &d[i]);
        f[i] = f[i-1] + max(d[i], 0LL);
        auto p = last.find(d[i]);
        if (p != last.end()) {
            if (ans < f[i-1] - f[p -> second] + d[i] * 2LL) {
                ans = f[i-1] - f[p -> second] + d[i] * 2LL;
                l = p -> second;
                r = i;
            }
        } else {
            last[d[i]] = i;
        }
    }
    cnt = l - 1 + n - r;
    for (LL i = l + 1; i < r; ++i)
        if (d[i] < 0) ++cnt;
    printf("%lld %lld\n", ans, cnt);
    for (LL i = 1; i <= n; ++i)
        if (i != l && i != r && (i < l || i > r || d[i] < 0)) printf("%lld ", i);
    puts("");
    return 0;
}
