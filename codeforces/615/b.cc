#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
struct edge {
    LL v, next;
} e[400000];
LL p[100000], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(LL x, LL y) {
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(LL x, LL y) {
    insert(x, y);
    insert(y, x);
}
LL f[100000], d[100000];
int main() {
    LL n, m, x, y;
    scanf("%I64d%I64d", &n, &m);
    init();
    memset(d, 0, sizeof(d));
    for (LL i = 0; i < m; ++i) {
        scanf("%I64d%I64d", &x, &y);
        x--; y--;
        insert2(x, y);
        d[x]++; d[y]++;
    }
    memset(f, 0, sizeof(f));
    LL ans = 0;
    for (LL i = 0; i < n; ++i) {
        for (LL j = p[i]; j != -1; j = e[j].next) {
            if (e[j].v < i) {
                f[i] = max(f[i], f[e[j].v] + 1);
            }
        }
        f[i] = max(1LL, f[i]);
        ans = max(ans, f[i] * d[i]);
    }
    printf("%I64d\n", ans);
    return 0;
}
