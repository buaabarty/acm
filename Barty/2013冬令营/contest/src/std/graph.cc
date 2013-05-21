#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct unionset {
    int fa[510], n;
    unionset(int _n) {
        n = _n;
        for (int i = 1; i <= n; ++i) fa[i] = i;
    }
    unionset(){}
    int getfather(int x) {
        if (fa[x] != x) fa[x] = getfather(fa[x]);
        return fa[x];
    }
    void combine(int x, int y) {
        int fx = getfather(x);
        int fy = getfather(y);
        if (fx != fy) fa[fx] = fy;
    }
};
struct edge {
    int x, y, d;
    void init() {
        scanf("%d%d%d", &x, &y, &d);
    }
    bool operator <(const edge &e) const {
        return d < e.d;
    }
};
class func {
    int gcd(int x, int y) {
        return (!x) ? y : gcd(y%x, x);
    }
    bool small(int x1, int y1, int x2, int y2) {
        return (x1 * y2 < x2 * y1);
    }
    public: void gao() {
        edge e[5010];
        int n, m, s, t, resx, resy;
        unionset u;
        bool flag = false;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) e[i].init();
        scanf("%d%d", &s, &t);
        sort(e+1, e+m+1);
        resx = e[m].d;
        resy = e[1].d;
        for (int i = 1; i <= m; ++i) {
            int j = i;
            u = unionset(n);
            while (j<=m && u.getfather(s)!=u.getfather(t)) {
                u.combine(e[j].x, e[j].y);
                ++j;
            }
            if (u.getfather(s) != u.getfather(t)) break;
            flag = true;
            if (small(e[--j].d, e[i].d, resx, resy)) {
                resx = e[j].d;
                resy = e[i].d;
            }
        }
        if (flag) {
            printf("%.2f\n", (double)resx / (double)resy);
        } else printf("No Answer\n");
    }
};
int main() {
    //freopen("graph.in", "r", stdin);
    //freopen("graph.out", "w", stdout);
    func a;
    a.gao();
    return 0;
}
