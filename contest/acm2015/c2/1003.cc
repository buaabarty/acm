#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge {
    int v, next;
} e[400000 + 3];
int p[20003], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y) {
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y) {
    insert(x, y);
    insert(y, x);
}
int T, n, m, d1[20003], d2[20003], a[20003][20], h[20003], d[20003], sd2[20003];
bool vst[20003];
void dfs(int fa, int v) {
    vst[v] = 1;
    a[v][0] = fa;
    h[v] = h[fa] + 1;
    for (int i = p[v]; i != -1; i = e[i].next) {
        if (!vst[e[i].v]) {
            dfs(v, e[i].v);
        }
    }
}
int getlca(int x, int y) {
    if (h[x] < h[y]) swap(x, y);
    for (int i = 9; i >= 0; --i) {
        if ((h[x] - h[y]) >= (1 << i)) {
            x = a[x][i];
        }
    }
    if (x == y) return x;
    for (int i = 9; i >= 0; --i) {
        if ((h[x] >= (1 << i)) && a[x][i] != a[y][i]) {
            x = a[x][i];
            y = a[y][i];
        }
    }
    return a[x][0];
}
int x[200009], y[200009];
void gao(int v) {
    vst[v] = 1;
    d1[v] = d[v];
    sd2[v] = d2[v];
    for (int i = p[v]; i != -1; i = e[i].next) {
        if (!vst[e[i].v]) {
            gao(e[i].v);
            d1[v] += d1[e[i].v];
            sd2[v] += sd2[e[i].v];
        }
    }
}
int main() {
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &m);
        init();
        memset(vst, 0, sizeof(vst));
        for (int i = 1; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            insert2(x, y);
        }
        dfs(1, 1);
        for (int i = 1; i < 20; ++i) {
            for (int j = 1; j <= n; ++j)
                a[j][i] = a[a[j][i-1]][i-1];
        }
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));
        memset(d, 0, sizeof(d));
        memset(sd2, 0, sizeof(sd2));
        for (int i = 1; i <= m - n + 1; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            d2[getlca(x, y)]++;
            d[x]++;
            d[y]++;
        }
        memset(vst, 0, sizeof(vst));
        gao(1);
        int ans = m + 1;
        for (int i = 2; i <= n; ++i) {
            ans = min(ans, d1[i] - sd2[i] * 2 + 1);
        }
        printf("Case #%d: %d\n", ca, ans);

    }
    return 0;
}
