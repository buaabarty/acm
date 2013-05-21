#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pl p<<1
#define pr p<<1|1
#define root 1
using namespace std;
const int maxn = 100010;
struct sgtree {
    int f[maxn*4];
    int n;
    void build(int p, int l, int r) {
        f[p] = 1;
        if (l >= r) return ;
        int mid = (l + r) >> 1;
        build(pl, l, mid); build(pr, mid+1, r);
    }
    void init(int _n) {
        n = _n;
        build(root, 1, n);
    }
    void pop(int p) {
        int fa = p>>1;
        if (f[fa<<1] == f[fa<<1|1]) f[fa] = f[fa<<1];
        else f[fa] = 0;
    }
    void push(int p) {
        f[pl] = f[pr] = f[p]; f[p] = 0;
    }
    void insert(int p, int l, int r, int a, int b, int c) {
        if (f[p]) push(p);
        if (l==a && r==b) {
            f[p] = c; pop(p); return;
        }
        int mid = (l + r) >> 1;
        if (b <= mid) insert(pl, l, mid, a, b, c);
        else if (a > mid) insert(pr, mid+1, r, a, b, c);
        else {
            insert(pl, l, mid, a, mid, c);
            insert(pr, mid+1, r, mid+1, b, c);
            if (f[pl] == f[pr]) f[p] = f[pl];
        }
        pop(p);
    }
    void insert(int a, int b, int c) {
        insert(root, 1, n, a, b, c);
    }
    int getcolor(int p, int l, int r, int x) {
        if (f[p] || l==r) return f[p];
        int mid = (l+r)>>1;
        if (x <= mid) return getcolor(pl, l, mid, x);
        else return getcolor(pr, mid+1, r, x);
    }
    int getcolor(int x) {
        return getcolor(root, 1, n, x);
    }
}sg;
struct myhash {
    int tsize, table[maxn];
    void init_table() {
        sort(table, table+tsize);
        tsize = unique(table, table+tsize)-table;
    }
    int get_index(int key) {
        return lower_bound(table, table+tsize, key)-table+1;
    }
    void init() {
        tsize = 0;
        memset(table, 0, sizeof(table));
    }
    void insert(int x) {
        table[tsize++] = x;
    }
}h;
int main() {
    int T;
    int x[10010], y[10010];
    int cnt[10010];
    scanf("%d", &T);
    while (T--) {
        int n;
        h.init();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
            for (int j = -1; j <= 1; ++j)
                h.insert(x[i]+j), h.insert(y[i]+j);
        }
        h.init_table();
        for (int i = 1; i <= n; ++i)
            x[i] = h.get_index(x[i]), y[i] = h.get_index(y[i]);
        sg.init(h.tsize);
        sg.insert(1, h.tsize, maxn);
        for (int i = 1; i <= n; ++i)
            sg.insert(x[i], y[i], i);
        memset(cnt, 0, sizeof(cnt));
        int tot = 0;
        for (int i = 1; i <= h.tsize; ++i) {
            int ans = sg.getcolor(i);
            if (ans <= n && ans) {
                if (!cnt[ans]) ++tot;
                cnt[ans]++;
            }
        }
        printf("%d\n", tot);
    }
    return 0;
}
