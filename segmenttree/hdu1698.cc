#include <iostream>
#include <cstdio>
#include <cstring>
#define pl p<<1
#define pr p<<1|1
#define root 1
using namespace std;
const int maxn = 100010;
struct sgtree {
    int f[maxn*4], s[maxn*4];
    void build(int p, int l, int r) {
        f[p] = 1; s[p] = r - l + 1;
        if (l >= r) return ;
        int mid = (l + r) >> 1;
        build(pl, l, mid); build(pr, mid+1, r);
    }
    void init(int n) {
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
    int getsum(int p, int l, int r) {
        if (f[p] || l==r) return f[p] * (r-l+1);
        int mid = (l+r)>>1;
        return getsum(pl, l, mid) + getsum(pr, mid+1, r);
    }
}sg;
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int n, m, x, y, z;
        scanf("%d%d", &n, &m);
        sg.init(n);
        while (m--) {
            scanf("%d%d%d", &x, &y, &z);
            sg.insert(root, 1, n, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n", ca, sg.getsum(1, 1, n));
    }
    return 0;
}
