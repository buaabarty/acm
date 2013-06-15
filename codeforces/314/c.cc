#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
const LL N = 1000000 + 9;
LL n;
LL c[N];
LL lowbit(LL x) {
    return x & (-x);
}
LL getsum(LL k) {
    ++k;
    LL s = 0;
    while (k) {
        s = (s + c[k]) % mod;
        k -= lowbit(k);
    }
    return s;
}
void insert(LL k, LL delta) {
    ++k;
    delta %= mod;
    while (k <= n+1LL) {
        c[k] = (c[k] + delta) % mod;
        k += lowbit(k);
    }
}
struct data {
    LL d, loc;
    bool operator < (const data &a) const {
        if (d != a.d) return d < a.d;
        return loc < a.loc;
    }
} d[N];
int main() {
    while (scanf("%I64d", &n) == 1) {
        for (LL i = 1; i <= n; ++i) {
            scanf("%I64d", &d[i].d);
            d[i].loc = i;
        }
        sort(d + 1, d + n + 1);
        memset(c, 0, sizeof(c));
        insert(0, 1LL);
        for (LL i = 1, j; i <= n; i = j) {
            LL last = 0;
            for (j = i; d[j].d == d[i].d; ++j) {
                insert(d[j].loc, d[j].d * (getsum(d[j].loc) - getsum(last-1LL)));
                last = d[j].loc;
            }
        }
        printf("%I64d\n", (getsum(n)+mod-1)%mod);
    }
    return 0;
}
