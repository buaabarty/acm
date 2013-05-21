#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000000 + 9;
const int M = 2000000 + 9;
const int inf = 1000000000;
struct edge {
    int v, d, next;
} e[M];
int p1[N], p2[N], eid;
void insert(int p[], int x, int y, int d) {
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y, int d) {
    insert(p1, x, y, d);
    insert(p2, y, x, d);
}

bool vst1[N], vst2[N], g[N];

int dist[N];

int n, m, s, t, q;
int rd[N], cd[N];





void init() {
    memset(p1, -1, sizeof(p1));
    memset(p2, -1, sizeof(p2));
    eid = 0;
    memset(vst1, 0, sizeof(vst1));
    memset(vst2, 0, sizeof(vst2));
    memset(rd, 0, sizeof(rd));
    memset(cd, 0, sizeof(cd));
}

void go(int v, bool vst[], int p[]) {
    vst[v] = 1;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v]) go(e[i].v, vst, p);
}

void count(int p[], int cnt[]) {
    for (int i = 1; i <= n; ++i) if (g[i])
        for (int j = p[i]; j != -1; j = e[j].next)
            if (g[e[j].v]) ++cnt[i];
}
int Q[N];
void topo(int p[]) {
    bool vst[N];
    memset(vst, 0, sizeof(vst));
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i) dist[i] = inf;
    for (int i = 1; i <= n; ++i)
        if (g[i] && !rd[i]) {
            Q[r++] = i;
            dist[i] = 0;
        }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", rd[i], " \n"[i==n]);
    while (l-r) {
        int now = Q[l++];
        for (int i = p[now]; i != -1; i = e[i].next)
            if (g[e[i].v] && !vst[e[i].v]) {
                --rd[e[i].v];
                dist[e[i].v] = min(dist[e[i].v], dist[now] + e[i].d);
                if (!rd[e[i].v]) {
                    Q[r++] = e[i].v;
                    vst[e[i].v] = 1;
                }
            }
    }
}

int T;
int main() {
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d%d%d%d%d", &n, &m, &s, &t, &q);
        ++s; ++t;
        for (int i = 1; i <= m; ++i) {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            ++x, ++y;
            insert2(x, y, d);
        }
        go(s, vst1, p1);
        go(t, vst2, p2);

        for (int i = 1; i <= n; ++i)
            g[i] = vst1[i] && vst2[i];

        for (int i = 1; i <= n; ++i)
            printf("%d%c", g[i], " \n"[i==n]);

        count(p2, rd);
        count(p1, cd);

        topo(p1);

        for (int i = 1; i <= n; ++i)

    }
    return 0;
}
