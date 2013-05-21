#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 400 + 9;
const int M = N * N;
const int INF = 1000000000;
/*struct edge {
    int v, f, next;
} e[M];
int p[N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void _insert(int x, int y, int f) {
    e[eid].v = y;
    e[eid].f = f;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert(int x, int y, int f) {
    _insert(x, y, f); _insert(y, x, 0);
}*/
int cap[N][N];
int q[N], n, m, source, sink, d1[N], d2[N], dist[N], pre[N];
int g[N][N];
bool bfs() {
    memset(dist, -1, sizeof(dist));
    memset(pre, 0, sizeof(pre));
    int l = 0, r = 1;
    q[l] = source;
    dist[source] = 0;
    for (; l<r; ++l) {
        for (int i = 1; i <= n; ++i)
            if (dist[i] == -1 && cap[q[l]][i]) {
                q[r++] = i;
                pre[i] = q[l];
                dist[i] = dist[q[l]] + 1;
            }
    }
    return (dist[sink] != -1);
}
/*int dfs(int v, int flow) {
    int tmp, ans = 0;
    if (v == sink) return flow;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (e[i].f && dist[v] + 1 == dist[e[i].v]) {
            tmp = dfs(e[i].v, min(flow-ans, e[i].f));
            e[i].f -= tmp;
            e[i^1].f += tmp;
            ans += tmp;
            if (ans == flow) break;
        }
    return ans;
}
void gao(int v) {
    if (v == sink) {
        printf("\n");
        return ;
    }
    for (int i = p[v]; i != -1; i = e[i].next)
        if (e[i^1].f && d1[v] + g[v][e[i].v] == d1[e[i].v]) {
            printf(" %d", e[i].v);
            --e[i^1].f;
            ++e[i].f;
            gao(e[i].v);
            return ;
        }
}*/
void go(int v) {
    if (v == sink) {
        printf("%d\n", v);
        return ;
    }
    for (int i = 1; i <= n; ++i)
        if (i!=v && cap[v][i]==0 && d1[v]+g[v][i]==d1[i]) {
            printf("%d ", v);
            cap[v][i] = 1;
            go(i);
            return ;
        }
}
void maxflow(int st, int ed) {
    source = st; sink = ed;
    vector<int> a, b;
    if (!bfs()) {
        puts("No solution");
        return ;
    }
    for (int i = sink; i != source; i = pre[i]) {
        --cap[pre[i]][i];
        ++cap[i][pre[i]];
    }
    if (!bfs()) {
        puts("No solution");
        return ;
    }
    for (int i = sink; i != source; i = pre[i]) {
        --cap[pre[i]][i];
        ++cap[i][pre[i]];
    }
    go(1);
    go(1);
}

bool use[N];
void dijkstra(int v, int dist[]) {
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    dist[v] = 0;
    memset(use, 0, sizeof(use));
    for (int i = 1; i <= n; ++i) {
        int mt = -1, mx = INF;
        for (int i = 1; i <= n; ++i)
            if (!use[i] && dist[i] < mx) {
                mx = dist[i];
                mt = i;
            }
        if (mt < 1) break;
        use[mt] = 1;
        for (int i = 1; i <= n; ++i)
            if (!use[i] && mx + g[mt][i] < dist[i]) {
                dist[i] = mx + g[mt][i];
            }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    //init();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j) g[i][j] = INF;
            else g[i][j] = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        g[x][y] = min(g[x][y], d);
        g[y][x] = min(g[y][x], d);
    }
    dijkstra(1, d1);
    for (int i = 1; i <= n; ++i)
        for (int j = n; j >= 1; --j)
            if (i != j && g[i][j] < INF && d1[i] + g[i][j] == d1[j])
                cap[i][j] = 1;
    maxflow(1, n);
    return 0;
}
