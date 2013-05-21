#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define PII pair<LL, LL>

typedef long long LL;

LL mod;

LL pow2(LL x) {
    LL s = 1, p2 = 2;
    while (x) {
        if (x & 1) s = (s * p2) % mod;
        p2 = (p2 * p2) % mod;
        x >>= 1;
    }
    return s;
}

LL n, x, pn2[200009], cnt2[200009];

int main() {
    memset(pn2, 0, sizeof(pn2));
    memset(cnt2, 0, sizeof(cnt2));
    vector<PII> d;
    scanf("%I64d", &n);
    for (LL i = 1; i <= n; ++i) {
        scanf("%I64d", &x); d.pb(mp(x, i));
    }
    for (LL i = 1; i <= n; ++i) {
        scanf("%I64d", &x); d.pb(mp(x, i));
    }
    scanf("%I64d", &mod);
    sort(d.begin(), d.end());
    pn2[1] = 1;
    for (LL i = 2; i <= n * 2; ++i) {
        LL now = i, now2 = 0;
        while (now % 2 == 0) {
            now /= 2;
            ++now2;
        }
        pn2[i] = (pn2[i-1] * now) % mod;
        cnt2[i] = cnt2[i-1] + now2;
    }
    LL p2 = 0, up = 1;
    for (LL i = 0; i < n * 2; ++i) {
        LL j = i + 1;
        while (j < n * 2 && d[j].first == d[i].first) ++j;
        up = (up * pn2[j-i]) % mod;
        p2 += cnt2[j-i];
        i = j - 1;
    }
    d.resize(unique(d.begin(), d.end()) - d.begin());
    p2 -= (2LL * n - d.size());
    printf("%I64d\n", (up * pow2(p2)) % mod);
    return 0;
}
