#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
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
double d[101][1<<16];
bool inq[101][1<<16];
struct data {
    int x, y;
    data(int _x, int _y) {
        x = _x, y = _y;
    }
    data() {
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &m);
        mapinit();
        memset(loc, 0, sizeof(loc));
        for (int i = 1; i <= m; ++i) {
            int x, y;
            double d;
            scanf("%d%d%lf", &x, &y, &d);
            insert2(x, y, d);
        }
        int now = 1;
        scanf("%d", &nm);
        fm = 0;
        for (int i = 1; i <= nm; ++i) {
            int x; scanf("%d", &x);
            fm |= now;
            loc[x] = now;
            now <<= 1;
        }
        scanf("%d", &nt);
        ft = 0;
        for (int i = 1; i <= nt; ++i) {
            int x; scanf("%d", &x);
            ft |= now;
            loc[x] = now;
            now <<= 1;
        }
        scanf("%d", &ns);
        fs = 0;
        for (int i = 1; i <= ns; ++i) {
            int x; scanf("%d", &x);
            fs |= now;
            loc[x] = now;
            now <<= 1;
        }
        scanf("%d", &nr);
        fr = 0;
        for (int i = 1; i <= nr; ++i) {
            int x; scanf("%d", &x);
            fr |= now;
            loc[x] = now;
            now <<= 1;
        }
        int s;
        scanf("%d", &s);
        if (nm + nt == 0) {
            printf("Case #%d: 0.00000\n", ca);
            continue;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < 1<<now; ++j)
                f[i][j] = inf;
        memset(inq, 0, sizeof(inq));
        if (loc[s]&fr) {
            f[s][loc[s]] = 3;
        } else {
            f[s][loc[s]] = 0;
        }
        queue<data> q;
        q.push(data(s, loc[s]));
        inq[s][loc[s]] = 1;
        if (loc[s] && !(loc[s]&fr)) {
            f[s][0] = 0;
            inq[s][0] = 1;
            q.push(data(s, 0));
        }
        while (!q.empty()) {
            data now = q.front();
            inq[now.x][now.y] = 0;
            //cout << now.x << " " << now.y << " " << f[now.x][now.y] << endl;
            q.pop();
            if ((now.y&fm)==fm) continue;
            double nowv = countv(now.y) * 5 + 30;
            for (int i = p[now.x]; i != -1; i = e[i].next) {
                int v = e[i].v;
                double delta = 0;
                if ((loc[v]&fr) && !(now.y&loc[v])) delta = 3;
                if (f[v][now.y|loc[v]] > f[now.x][now.y] + e[i].d / nowv + delta) {
                    f[v][now.y|loc[v]] = f[now.x][now.y] + e[i].d / nowv + delta;
                    if (!inq[v][now.y|loc[v]]) {
                        inq[v][now.y|loc[v]] = 1;
                        q.push(data(v, now.y|loc[v]));
                    }
                }
                if (!(loc[v]&fr) && !(now.y&loc[v])) {
                    if (f[v][now.y] > f[now.x][now.y] + e[i].d / nowv + delta) {
                        f[v][now.y] = f[now.x][now.y] + e[i].d / nowv + delta;
                        if (!inq[v][now.y]) {
                            inq[v][now.y] = 1;
                            q.push(data(v, now.y));
                        }
                    }
                }
            }
        }
        /*
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
                }*/
        double ans = 1e20;
        for (int i = 0; i < 1<<now; ++i)
            for (int j = 1; j <= n; ++j)
                if ((i&fm)==fm && (i&ft)==ft)
                    checkmin(ans, f[j][i]);
        printf("Case #%d: %.5f\n", ca, ans);
    }
    return 0;
}
