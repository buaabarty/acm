#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const LL M = 1000000 + 9;
const LL N = 1000000 + 9;
struct edge {
    LL v, d, next;
} e[M];
LL p[N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(LL x, LL y, LL d) {
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(LL x, LL y, LL d) {
    insert(x, y, d);
    insert(y, x, d);
}
LL d[N], h[N], len, l[N], r[N], fa[N];
LL st[N][20], lg2[N];
bool vst[N];
void dfs(LL v, LL deep) {
    d[++len] = v;
    h[len] = deep;
    vst[v] = 1;
    l[v] = len;
    r[v] = len;
    for (LL i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v]) {
            fa[e[i].v] = e[i].d;
            dfs(e[i].v, deep + 1);
            d[++len] = v;
            h[len] = deep;
            r[v] = len;
        }
}
LL rmqinit() {
    for (LL i = 1; i < N; ++i)
        lg2[i] = (LL)(log2(i)+1e-10);
    for (LL i = 1; i <= len; ++i)
        st[i][0] = i;
    for (LL j = 1, t = 1; j < 20; ++j)
        for (LL i = 1; i+t*2-1<=len; ++i)
            if (h[st[i][j-1]]<h[st[i+t][j-1]]) st[i][j] = st[i][j-1];
            else st[i][j] = st[i+t][j-1];
}
LL lca(LL x, LL y) {
    LL left = l[x], right = r[x];
    left = min(left, l[y]);
    right = max(right, r[y]);
    LL len = lg2[right-left+1], t;
    if (h[st[left][len]] < h[st[right-(1<<len)+1][len]])
        return d[st[left][len]];
    else return d[st[right-(1<<len)+1][len]];
}


#define pl p<<1
#define pr p<<1|1

LL dat[N*4], tag[N*4], pdat[N*4];
pair<LL, LL> ans[N*4];

void go(LL v, LL l) {
    vst[v] = 1;
    pdat[v] = l;
    for (LL i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v]) go(e[i].v, l + e[i].d);
}

pair<LL, LL> getmax(pair<LL, LL> a, pair<LL, LL> b) {
    if (a.second > b.second) return a;
    else return b;
}

void build(LL p, LL l, LL r) {
    if (l == r) {
        ans[p] = make_pair(l, dat[l]);
        tag[p] = 0;
        return ;
    }
    LL mid = (l + r) >> 1;
    build(pl, l, mid);
    build(pr, mid+1, r);
    ans[p] = getmax(ans[pl], ans[pr]);
    tag[p] = 0;
}

void add(pair<LL, LL> &a, LL delta) {
    a.second += delta;
}

void push(LL p) {
    if (tag[p]) {
        tag[pl] += tag[p];
        tag[pr] += tag[p];
        add(ans[pl], tag[p]);
        add(ans[pr], tag[p]);
        tag[p] = 0;
    }
}

void pop(LL p) {
    ans[p] = getmax(ans[pl], ans[pr]);
}

void update(LL p, LL l, LL r, LL a, LL b, LL c) {
    if (l==a && r==b) {
        tag[p] += c;
        add(ans[p], c);
        return ;
    }
    push(p);
    LL mid = (l + r) >> 1;
    if (b <= mid) update(pl, l, mid, a, b, c);
    else if (a > mid) update(pr, mid+1, r, a, b, c);
    else {
        update(pl, l, mid, a, mid, c);
        update(pr, mid+1, r, mid+1, b, c);
    }
    pop(p);
}

pair<LL, LL> query(LL p, LL l, LL r, LL a, LL b) {
    if (l==a && r==b) return ans[p];
    push(p);
    LL mid = (l+r)>>1;
    pair<LL, LL> ans;
    if (b <= mid) ans = query(pl, l, mid, a, b);
    else if (a > mid) ans = query(pr, mid+1, r, a, b);
    else ans = getmax(query(pl, l, mid, a, mid), query(pr, mid+1, r, mid+1, b));
    pop(p);
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    LL T, n;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        init();
        for (LL i = 1; i < n; ++i) {
            LL x, y, d;
            scanf("%lld%lld%lld", &x, &y, &d);
            insert2(x, y, d);
        }
        len = 0;
        memset(vst, 0, sizeof(vst));
        dfs(1, 0);
        rmqinit();
        memset(vst, 0, sizeof(vst));
        go(1, 0);
        for (LL i = 1; i <= len; ++i)
            dat[i] = pdat[d[i]];
        build(1, 1, len);
        LL q, now = 1;
        scanf("%lld", &q);
        while (q--) {
            LL k, u, v, w;
            scanf("%lld", &k);
            if (k == 1) {
                scanf("%lld", &v);
                pair<LL, LL> a = query(1, 1, len, l[now], l[now]);
                pair<LL, LL> b = query(1, 1, len, l[v], l[v]);
                pair<LL, LL> c = query(1, 1, len, l[lca(now, v)], l[lca(now, v)]);
                printf("%lld\n", a.second+b.second-c.second*2);
                now = v;
            } else if (k == 2) {
                LL ans = query(1, 1, len, l[now], r[now]).second - query(1, 1, len, l[now], l[now]).second;
                //now = d[query(1, 1, len, l[now], r[now]).first];
                printf("%lld\n", ans);
            } else {
                scanf("%lld%lld%lld", &u, &v, &w);
                if (h[l[u]] < h[l[v]]) {
                    update(1, 1, len, l[v], r[v], w-fa[v]);
                    fa[v] = w;
                } else {
                    update(1, 1, len, l[u], r[u], w-fa[u]);
                    fa[u] = w;
                }
            }
        }
    }
    return 0;
}
