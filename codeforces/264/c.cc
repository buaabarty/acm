#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

const LL inf = 100000000000000000;

struct data {
    LL v1, c1, v2, c2;
    void init() {
        v1 = -inf; v2 = -inf;
        c1 = -1; c2 = -1;
    }
    void update(LL v, LL c) {
        if (c1 == c) {
            v1 = max(v1, v);
        } else if (c2 == c) {
            v2 = max(v2, v);
            if (v2 > v1) {
                swap(v1, v2);
                swap(c1, c2);
            }
        } else {
            if (v > v2) {
                v2 = v; c2 = c;
            }
            if (v2 > v1) {
                swap(v1, v2);
                swap(c1, c2);
            }
        }
    }
}d;

LL n, q;
LL c[100010], v[100010];
LL f[100010], mm[100010];

LL gao(LL a, LL b) {
    LL res = 0;
    d.init();
    for (LL i = 1; i <= n; ++i) mm[i] = -inf;
    for (LL i = 1; i <= n; ++i) {
        f[i] = v[i] * b;
        if (d.c1 != -1) {
            if (d.c1 == c[i]) {
                f[i] = max(f[i], d.v1 + v[i] * a);
                if (d.c2 != -1) {
                    f[i] = max(f[i], d.v2 + v[i] * b);
                }
            } else {
                f[i] = max(f[i], d.v1 + v[i] * b);
                if (mm[c[i]] > -inf) f[i] = max(f[i], mm[c[i]] + v[i] * a);
            }
        }
        d.update(f[i], c[i]);
        res = max(res, f[i]);
        mm[c[i]] = max(mm[c[i]], f[i]);
    }
    return res;
}

int main() {
    scanf("%I64d%I64d", &n, &q);
    for (LL i = 1; i <= n; ++i) scanf("%I64d", &v[i]);
    for (LL i = 1; i <= n; ++i) scanf("%I64d", &c[i]);
    while (q--) {
        LL x, y; scanf("%I64d%I64d", &x, &y);
        printf("%I64d\n", gao(x, y));
    }
    return 0;
}
