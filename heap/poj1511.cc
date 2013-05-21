#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define PII pair<LL, LL>
#define CLR(x) memset(x, 0, sizeof(x))
using namespace std;

typedef long long LL;

const LL maxn = 2000009;
const LL inf = 100000000000000000LL;
struct min_heap {
    LL size, d[maxn], p[maxn], v[maxn];
    min_heap() {
        CLR(d); CLR(p); CLR(v); size = 0;
    }
    void init() {
        CLR(d); CLR(p); CLR(v); size = 0;
    }
    void myswap(LL x, LL y) {
        swap(d[x], d[y]); swap(p[d[x]], p[d[y]]);
    }
    void pop(LL x) {
        for (LL y = x>>1; y; x = y, y >>= 1)
            if (v[d[x]] < v[d[y]]) myswap(x, y);
    }
    void push(LL x) {
        for (LL y = x<<1; y <= size; x = y, y <<= 1) {
            if (y + 1 <= size && v[d[y + 1]] < v[d[y]]) myswap(y + 1, y);
            if (v[d[y]] < v[d[x]]) myswap(x, y);
        }
    }
    void insert(LL loc, LL value) {
        d[++size] = loc; p[loc] = size;
        v[loc] = value; pop(size);
    }
    void change(LL loc, LL value) {
        if (!p[loc]) insert(loc, value);
        else { v[d[p[loc]]] = value; pop(p[loc]); push(p[loc]); }
    }
    PII pop() {
        PII ans; myswap(1, size);
        ans = make_pair(d[size], v[d[size]]);
        if (--size) push(1); return ans;
    }
};

struct Graph {
    struct edge {
        int v, d, next;
    } e[maxn];
    int p[maxn], eid;
    void init() {
        memset(p, -1, sizeof(p));
        eid = 0;
    }
    void insert(int x, int y, int d) {
        e[eid].v = y;
        e[eid].d = d;
        e[eid].next = p[x];
        p[x] = eid++;
    }
}g1, g2;

LL d1[maxn], d2[maxn];
min_heap h;

void dijkstra1(LL n) {
    for (LL i = 1; i <= n; ++i) d1[i] = inf;
    h.init();
    h.insert(1, 0);
    d1[1] = 0;
    for (LL i = 1; i <= n; ++i) {
        PII now = h.pop();
        LL x = now.first;
        LL v = now.second;
        //printf("AA%lld %lld\n", x, v);
        for (int j = g1.p[x]; j != -1; j = g1.e[j].next)
            if (d1[g1.e[j].v] > v + g1.e[j].d) {
                h.change(g1.e[j].v, g1.e[j].d + v);
                d1[g1.e[j].v] = v + g1.e[j].d;
            }
    }
}

void dijkstra2(LL n) {
    for (LL i = 1; i <= n; ++i) d2[i] = inf;
    h.init();
    h.insert(1, 0);
    d2[1] = 0;
    for (LL i = 1; i <= n; ++i) {
        PII now = h.pop();
        LL x = now.first;
        LL v = now.second;
        //printf("BB%lld %lld\n", x, v);
        for (int j = g2.p[x]; j != -1; j = g2.e[j].next)
            if (d2[g2.e[j].v] > v + g2.e[j].d) {
                h.change(g2.e[j].v, g2.e[j].d + v);
                d2[g2.e[j].v] = v + g2.e[j].d;
            }
    }
}


int main() {
    LL T;
    scanf("%lld", &T);
    while (T--) {
        LL n, m;
        scanf("%lld%lld", &n, &m);
        g1.init(); g2.init();
        for (LL i = 1; i <= m; ++i) {
            LL x, y, d;
            scanf("%lld%lld%lld", &x, &y, &d);
            g1.insert(x, y, d);
            g2.insert(y, x, d);
        }
        dijkstra1(n);
        dijkstra2(n);
        LL ans = 0;
        for (LL i = 1; i <= n; ++i)
            ans += d1[i] + d2[i];
        printf("%lld\n", ans);
    }
    return 0;
}
