#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int b, c, p;
    node *next, *anti;
};

struct Dinic {
    const static int maxn = 200000 + 5;
    const static int maxe = maxn * 10 + 5;
    const static int inf = 2000000000;

    node *ge[maxn], pool[maxe], *pooltop;
    int dist[maxn];
    int n;

    void init(int n) {
        pooltop = pool; this->n = n;
        for (int i = 0; i < n; ++i) ge[i] = 0;
    }

    node *_insert(int a, int b, int c, int pp) {
        node *p = pooltop++; p->b = b; p->c = c; p->next = ge[a]; ge[a] = p;
        p->p = pp;
        return p;
    }

    void insert2(int a, int b, int c, int pp) {
        node *p = _insert(a, b, c, pp), *q = _insert(b, a, 0, -pp);
        p->anti = q; q->anti = p;
    }

    bool bfs(int s, int t) {
        static int q[maxn], *qtop, *qbase;
        qbase = qtop = q;
        memset( dist, -1, sizeof(dist[0]) * (n+1) );
        dist[s] = 0; *qtop++ = s;
        for (; qbase != qtop; ++qbase) {
            for (node *p = ge[*qbase]; p; p = p->next) {
                if ( p->c && dist[p->b] == -1 ) {
                    dist[p->b] = dist[*qbase] + 1;
                    *qtop++ = p->b;
                    if (p->b == t) return 1;
                }
            }
        }
        return false;
    }

    int flow(int s, int t) {
        static int pre[maxn];
        static node *cur[maxn], *path[maxn];

        int tot = 0;
        while ( bfs(s, t) ) {
            memcpy(cur, ge,  sizeof(ge[0]) * (n+1) );
            for (int i = s; dist[s] != -1; ) {
                if ( i == t ) {
                    int flow = inf;
                    for (; i != s; i = pre[i])
                        flow = min(flow, path[i]->c);
                    tot += flow;
                    for (i = t; i != s; i = pre[i]) {
                        path[i]->c -= flow;
                        path[i]->anti->c += flow;
                    }
                }
                for (node *&p = cur[i]; p; p = p->next) {
                    int v = p->b;
                    if ( p->c && dist[v] == dist[i] + 1 ) {
                        pre[v] = i; path[v] = p; i = v; break;
                    }
                }
                if ( cur[i] == 0 ) {
                    dist[i] = -1;
                    i = pre[i];
                }
            }
        }
        return tot;
    }
}g;

struct edge {
    int x, y, d, clr;
}E[200010];

vector<int> e[200010];
int n, m;
int ff[200010];
queue<int> q;
int d[200010];


int main() {

    scanf("%d%d", &n, &m);
    g.init(n);
    memset(ff, 0, sizeof(ff));
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &E[i].x, &E[i].y, &E[i].d);
        e[E[i].x].push_back(E[i].y);
        e[E[i].y].push_back(E[i].x);
    }
    queue<int> q;
    q.push(1);
    memset(d, 0, sizeof(d));
    d[1] = 1;
    while (!q.empty()) {
        int h = q.front(); q.pop();
        for (int i = 0; i < e[h].size(); ++i)
            if (!d[e[h][i]]) {
                d[e[h][i]] = d[h] + 1;
                q.push(e[h][i]);
            }
    }
    d[n] = n + 1;
    for (int i = 1; i <= m; ++i) {
        if (d[E[i].x] <= d[E[i].y]) {
            ff[E[i].x] -= E[i].d;
            ff[E[i].y] += E[i].d;
            if (E[i].x != 1 && E[i].x != n && E[i].y != 1 && E[i].y != n) g.insert2(E[i].y, E[i].x, E[i].d, i);
            E[i].clr = 0;
        } else {
            ff[E[i].y] -= E[i].d;
            ff[E[i].x] += E[i].d;
            if (E[i].x != 1 && E[i].x != n && E[i].y != 1 && E[i].y != n) g.insert2(E[i].x, E[i].y, E[i].d, i);
            E[i].clr = 1;
        }
    }
    for (int i = 2; i < n; ++i)
        if (ff[i] > 0) g.insert2(1, i, ff[i] / 2, 0);
        else if (ff[i] < 0) g.insert2(i, n, -ff[i] / 2, 0);
    g.flow(1, n);
    for (int i = 1; i <= n; ++i) {
        for (node *p = g.ge[i]; p; p = p->next) {
            if (!(p->c) && (p->p>=1) && (p->p<=m)) {
                E[p->p].clr = !E[p->p].clr;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", E[i].clr);
    return 0;
}
