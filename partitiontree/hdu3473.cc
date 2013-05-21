#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int maxn = 100000 + 9;
const int maxdeep = 18;

namespace Parition_Tree {
    int od[maxn], a[maxn], val[maxdeep][maxn], n, ld[maxdeep][maxn];
    LL suml, cntl, lsum[maxdeep][maxn], sum[maxn];
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
                lsum[d][i] = lsum[d][i-1] + (LL)a[od[val[d][i]]];
            } else {
                val[d+1][mid+i-l+1-p] = val[d][i];
                ld[d][i] = p;
                lsum[d][i] = lsum[d][i-1];
            }
        build(l, mid, d+1);
        build(mid+1, r, d+1);
    }
    int query(int s, int e, int k, int l = 1, int r = n, int d = 0) {
        if (l == r) return a[od[l]];
        int ss = (s==l ? 0 : ld[d][s-1]), ee = ld[d][e], mid = (l+r)>>1;
        if (ee - ss >= k) return query(l+ss, l+ee-1, k, l, mid, d+1);
        else {
            cntl += ee - ss;
            suml += lsum[d][e] - lsum[d][s-1];
            return query(mid+1+(s-l-ss), mid+1+(e-l-ee), k-(ee-ss), mid+1, r, d+1);
        }
    }
    LL query(int x, int y) {
        suml = cntl = 0;
        int mid = (y-x)/2+1;
        int midx = query(x, y, mid);
        int cntr = y-x+1-cntl;
        LL sumr = sum[y]-sum[x-1]-suml;
        return sumr-suml-(LL)midx*(cntr-cntl);
    }
    void init(int _n) {
        n = _n;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]) , od[i] = i;

        sort(od + 1, od + n + 1, cmp);
        for (int i = 0; i < maxdeep; ++i) lsum[i][0] = 0;
        for (int i = 1; i <= n; ++i)
            val[0][od[i]] = i;
        sum[0] = 0;
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + (LL)a[i];
        build(1, n, 0);
    }
}
int main() {
    int n, m, T;
    while (scanf("%d", &T) == 1) {
        for (int ca = 1; ca <= T; ++ca) {
            printf("Case #%d:\n", ca);
            scanf("%d", &n);
            Parition_Tree::init(n);
            scanf("%d", &m);
            for (int i = 1; i <= m; ++i) {
                int x, y;
                scanf("%d%d", &x, &y);
                printf("%I64d\n", Parition_Tree::query(x+1, y+1));
            }
            puts("");
        }
    }
    return 0;
}
