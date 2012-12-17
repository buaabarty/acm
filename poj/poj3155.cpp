#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define N 1024
#define M 100000
#define eps 1e-9
#define inf 1e9
using namespace std;
int n, m, s, t, l;
int deg[N], p[N], cur[N], pre[N], dist[N], eid, cnt[N];
double low[N];
struct Edge {
    int u, v;
    double cap, flow;
    int next;
}e[M];
void mapinit() {
    eid = 0;
    memset(p, -1, sizeof(p));
}
void add(int u, int v, double cap, double flow) {
    e[eid].u = u;
    e[eid].v = v;
    e[eid].cap = cap;
    e[eid].flow = flow;
    e[eid].next = p[u];
    p[u] = eid++;
}
void insert(int u, int v, double cap) {
    add(u, v, cap, 0), add(v, u, 0, 0);
}
double isap(int s, int t, int n) {
    int u, v, now;
    double flow = 0;
    memset(dist, 0, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    memset(low, 0, sizeof(low));
    for(u = 1; u <= n; u++) cur[u] = p[u];
    u = s;
    while(dist[s] < n) {
        for(now = cur[u]; now != -1; now = e[now].next)
            if(e[now].cap - e[now].flow && dist[u] == dist[v = e[now].v] + 1) break;
        if(now != -1) {
            cur[u] = pre[v] = now;
            low[v] = min(low[u], e[now].cap - e[now].flow);
            u = v;
            if(u == t) {
                for(; u != s; u = e[pre[u]].u) {
                    e[pre[u]].flow += low[t];
                    e[pre[u]^1].flow -= low[t];
                }
                flow += low[t], low[s] = inf;
            }
        } else {
            if(--cnt[dist[u]] == 0) break;
            dist[u] = n, cur[u] = p[u];
            for(now = cur[u]; now != -1; now = e[now].next)
                if(e[now].cap - e[now].flow && dist[u] > dist[v = e[now].v] + 1)
                    dist[u] = dist[v = e[now].v] + 1;
            cnt[dist[u]]++;
            if(u != s) u = e[pre[u]].u;
        }
    }
    return flow;
}
int map[M][2], source, sink;
bool okay(double limit)
{
    mapinit();
    source = n + 1, sink = n + 2;
    double sum = 0;
    for (int i = 1; i <= m; ++i)
    {
        insert(map[i][0], map[i][1], 1);
        insert(map[i][1], map[i][0], 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        insert(source, i, m);
        insert(i, sink, m * 1.0 + 2 * limit - deg[i] * 1.0);
    }
    return (m * n * 1.0 - isap(source, sink, sink)) / 2.0 > eps;
}
bool vst[N];
void dfs(int v)
{
    vst[v] = true;
    for (int i = p[v]; i != -1; i = e[i].next)
        if ((e[i].flow < e[i].cap) && !vst[e[i].v]) dfs(e[i].v);
}
void print(double left)
{
    memset(vst, false, sizeof(vst));
    okay(left);
    dfs(source);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += vst[i];
    printf("%d\n", cnt);
    for (int i = 1; i <= n; ++i)
        if (vst[i]) printf("%d\n", i);
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        if (m == 0)
        {
            printf("1\n1\n");
            continue;
        }
        memset(deg, 0, sizeof(deg));
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &map[i][0], &map[i][1]);
            deg[map[i][0]]++;
            deg[map[i][1]]++;
        }
        double left = 0, right = m;
        double step = n;
        step = 1 / (step * step);
        while (right - left >= step)
        {
            double mid = (left + right) / 2.0;
            if (okay(mid)) left = mid;
            else right = mid;
        }
        print(left);
    }
    return 0;
}
