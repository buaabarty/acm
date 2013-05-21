#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge {
    int v, next;
    double d;
} e[4010];
int p[101], eid;
int mapinit() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y, double d) {
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y, double d) {
    insert(x, y, d);
    insert(y, x, d);
}
double inf = 1e20;
double f[101][1<<12];
int n, m, nm, nt, ns, nr;
int loc[101];
int fm, ft, fs, fr;
int count(int x) {
    int tot = 0;
    while (x) {
        if (x&1) ++tot;
        x >>= 1;
    }
    return tot;
}
int countv(int x) {
    return count(x&fs) + count(x&fr);
}
template <typename T> void checkmin(T &a, T b) {
    if (b < a) a = b;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &m);
        mapinit();
        for (int i = 1; i <= m; ++i) {
            int x, y;
            double d;
            scanf("%d%d%lf", &x, &y, &d);
            insert2(x, y, d);
        }
        int now = 1;
        scanf("%d", &nm);
        for (int i = 1; i <= nm; ++i) {
            int x; scanf("%d", &x);
            fm |= now;
            loc[x] = now;
            now <<= 1;
        }
        scanf("%d", &nt);
        for (int i = 1; i <= nt; ++i) {
            int x; scanf("%d", &x);
            ft |= now;
            loc[x] = now;
            now <<= 1;
        }
        scanf("%d", &ns);
        for (int i = 1; i <= ns; ++i) {
            int x; scanf("%d", &x);
            fs |= now;
            loc[x] = now;
            now <<= 1;
        }
        scanf("%d", &nr);
        for (int i = 1; i <= nr; ++i) {
            int x; scanf("%d", &x);
            fr |= now;
            loc[x] = now;
            now <<= 1;
        }
        int s;
        scanf("%d", &s);
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < 1<<now; ++j)
                f[i][j] = inf;
        if (loc[s]&fr) f[s][loc[s]] = 3;
        else f[s][loc[s]] = 0;
        for (int i = 0; i < 1<<now; ++i)
            for (int j = 1; j <= n; ++j)
                if (f[j][i] < inf) {
                    cout << j << " " << i << " " << f[j][i] << endl;
                    double nowv = countv(i) * 5 + 30;
                    cout << "go" << endl;
                    for (int k = p[j]; k != -1; k = e[k].next) {
                        cout << nowv << endl;
                        int v = e[k].v;
                        double delta = 0;
                        if ((loc[v]&fr) && !(i&loc[v])) delta = 3;
                        checkmin(f[v][i|loc[v]], f[j][i] + e[k].d / nowv + delta);
                    }
                }
        double ans = 1e20;
        for (int i = 0; i < 1<<now; ++i)
            for (int j = 1; j <= n; ++j)
                if ((i&fm)==fm && (i&ft)==ft)
                    checkmin(ans, f[j][i]);
        printf("Case #%d: %.5f\n", ca, ans);
    }
    return 0;
}
