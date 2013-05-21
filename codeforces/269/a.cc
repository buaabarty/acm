#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

struct data {
    LL k, a;
    bool operator < (const data &x) const {
        return k < x.k;
    }
}d[100010];
LL n;

LL div(LL x) {
    LL s = x / 4;
    if (x % 4) ++s;
    return s;
}

LL gao(LL dk, LL a) {
    while (dk && a > 1) {
        a = div(a);
        --dk;
    }
    return a;
}

int main() {
    scanf("%I64d", &n);
    LL maxk = 0;
    for (LL i = 1; i <= n; ++i) {
        scanf("%I64d%I64d", &d[i].k, &d[i].a);
        maxk = max(maxk, d[i].k);
    }
    LL maxs = 0;
    for (LL i = 1; i <= n; ++i)
        maxs = max(maxs, gao(maxk - d[i].k, d[i].a));
    if (maxs == 1) ++maxs;
    while (maxs > 1) {
        maxs = div(maxs);
        ++maxk;
    }
    printf("%I64d\n", maxk);
    return 0;
}
