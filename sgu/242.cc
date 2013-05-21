#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Dinic {
    const static int maxn = 100000 + 5;
    const static int maxe = maxn * 2 + 5;
    const static int inf = 2000000000;

    struct node {
        int b, c;
        node *next, *anti;
    } *ge[maxn], pool[maxe], *pooltop;
    int dist[maxn];
    int n;

    void init(int n) {
        pooltop = pool; this->n = n;
        for (int i = 0; i < n; ++i) ge[i] = 0;
    }

    node *_insert(int a, int b, int c) {
        node *p = pooltop++; p->b = b; p->c = c; p->next = ge[a]; ge[a] = p;
        return p;
    }

    void insert2(int a, int b, int c) {
        node *p = _insert(a, b, c), *q = _insert(b, a, c);
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

    LL flow(int s, int t) {
        static int pre[maxn];
        static node *cur[maxn], *path[maxn];

        LL tot = 0;
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
} g;

int main() {
    return 0;
}
