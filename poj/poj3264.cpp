#include <iostream>
#include <cstdio>
#define pl p<<1
#define pr p<<1|1
#define mid ((l+r)>>1)
#define maxn 50010
using namespace std;
int amax[maxn*4], amin[maxn*4];
int n, num[maxn], q;
void build(int p, int l, int r) {
    if (l == r) {
        amax[p] = num[l];
        amin[p] = num[l];
        return ;
    }
    build(pl, l, mid);
    build(pr, mid+1, r);
    amax[p] = max(amax[pl], amax[pr]);
    amin[p] = min(amin[pl], amin[pr]);
}
int getmax(int p, int l, int r, int a, int b) {
    //printf("%d %d %d %d %d:%d\n", p, l, r, a, b, amax[p]);
    if (l == a && r == b) return amax[p];
    if (b <= mid) return getmax(pl, l, mid, a, b);
    else if (a > mid) return getmax(pr, mid+1, r, a, b);
    else return max(getmax(pl, l, mid, a, mid), getmax(pr, mid+1, r, mid+1, b));
}
int getmin(int p, int l, int r, int a, int b) {
    //printf("%d %d %d %d %d:%d\n", p, l, r, a, b, amin[p]);
    if (l == a && r == b) return amin[p];
    if (b <= mid) return getmin(pl, l, mid, a, b);
    else if (a > mid) return getmin(pr, mid+1, r, a, b);
    else return min(getmin(pl, l, mid, a, mid), getmin(pr, mid+1, r, mid+1, b));
}
int main() {
    while (scanf("%d%d", &n, &q) == 2) {
        for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
        build(1, 1, n);
        for (int i = 1; i <= q; ++i) {
            int x, y; scanf("%d%d", &x, &y);

            //cout << getmax(1, 1, n, x, y) << endl;
            //cout << getmin(1, 1, n, x, y) << endl;
            printf("%d\n", getmax(1, 1, n, x, y) - getmin(1, 1, n, x, y));
        }
    }
    return 0;
}
