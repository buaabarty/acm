#include <iostream>
#include <cstdio>
#include <cstring>
#define pl p<<1
#define pr p<<1|1
using namespace std;
int a[100010], b[100010];
int z[400010];
int n, m;
void update(int p, int l, int r, int x, int y, int c) {
    //printf("%d %d %d %d %d %d\n", p, l, r, x, y, c);
    if (x==l && y==r) {
        z[p] = c;
        return;
    }
    int mid = (l + r) >> 1;
    if (z[p]) {
        z[pl] = z[p];
        z[pr] = z[p] + mid + 1 - l;
        z[p] = 0;
    }
    if (y <= mid) update(pl, l, mid, x, y, c);
    else if (x > mid) update(pr, mid+1, r, x, y, c);
    else {
        update(pl, l, mid, x, mid, c);
        update(pr, mid+1, r, mid+1, y, c + mid + 1 - x);
    }
    if (z[pl] && z[pr] && z[pr]==z[pl]+mid+1-l) {
        z[p] = z[pl];
        z[pl] = 0;
        z[pr] = 0;
    }
    //printf("%d %d %d %d %d %d:\t%d\n", p, l, r, x, y, c, z[p]);
}
int query(int p, int l, int r, int x) {
    //printf("%d %d %d %d:\t%d\n", p, l, r, x, z[p]);
    if (z[p]) return a[z[p]+x-l];
    else if (l == r && l == x) return b[l];
    int mid = (l + r) >> 1, ans;
    if (z[p]) {
        //puts("PUSH");
        z[pl] = z[p];
        z[pr] = z[p] + mid + 1 - l;
        z[p] = 0;
    }
    if (x <= mid) ans = query(pl, l, mid, x);
    else ans = query(pr, mid+1, r, x);
    if (z[pl] && z[pr] && z[pr]==z[pl]+mid+1-l) {
        //puts("POP");
        z[p] = z[pl];
        z[pl] = 0;
        z[pr] = 0;
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    memset(z, 0, sizeof(z));
    for (int i = 1; i <= m; ++i) {
        int t, x, y, k;
        scanf("%d%d", &t, &x);
        if (t == 1) {
            scanf("%d%d", &y, &k);
            update(1, 1, n, y, y + k - 1, x);
        } else printf("%d\n", query(1, 1, n, x));
    }
    return 0;
}
