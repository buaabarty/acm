#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 9;
const int maxdeep = 20;

namespace Parition_Tree {
    int od[maxn], a[maxn], val[maxdeep][maxn], n, ld[maxdeep][maxn];
    bool cmp(const int &x, const int &y) {
        return a[x] < a[y];
    }
    void build(int l, int r, int d) {
        if (l == r) return;
        int mid = (l + r) >> 1, p = 0;
        for (int i = l; i <= r; ++i)
            if (val[d][i] <= mid) {
                val[d+1][l+p] = val[d][i];
                ld[d][i] = ++p;
            } else {
                val[d+1][mid+i-l+1-p] = val[d][i];
                ld[d][i] = p;
            }
        build(l, mid, d+1);
        build(mid+1, r, d+1);
    }
    int query(int s, int e, int k, int l = 1, int r = n, int d = 0) {
        if (l == r) return a[od[l]];
        int ss = (s==l ? 0 : ld[d][s-1]), ee = ld[d][e], mid = (l+r)>>1;
        if (ee - ss >= k) return query(l+ss, l+ee-1, k, l, mid, d+1);
        else return query(mid+1+(s-l-ss), mid+1+(e-l-ee), k-(ee-ss), mid+1, r, d+1);
    }
    void init(int _n) {
        n = _n;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]), od[i] = i;
        sort(od + 1, od + n + 1, cmp);
        for (int i = 1; i <= n; ++i)
            val[0][od[i]] = i;
        build(1, n, 0);
    }
}
int main() {
    int n, m;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        Parition_Tree::init(n);
        for (int i = 1; i <= m; ++i) {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            printf("%d\n", Parition_Tree::query(x, y, k));
        }
    }
    return 0;
}
