#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
using namespace std;
typedef struct
{
    int v, next, val, s;
    bool full;
}edge;
const int MAXN = 512;
const int MAXM = 10000000;
edge e[MAXM];
int p[MAXN], eid;
inline void sapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
inline void insert1(int from, int to, int val)
{
    e[eid].s = from;
    e[eid].v = to;
    e[eid].val = val;
    e[eid].next = p[from];
    e[eid].full = false;
    p[from] = eid++;
    swap(from, to);
    e[eid].s = from;
    e[eid].v = to;
    e[eid].val = 0;
    e[eid].next = p[from];
    e[eid].full = false;
    p[from] = eid++;
}
inline void insert2(int from, int to, int val)
{
    e[eid].s = from;
    e[eid].v = to;
    e[eid].val = val;
    e[eid].next = p[from];
    e[eid].full = false;
    p[from] = eid++;
    swap(from, to);
    e[eid].s = from;
    e[eid].v = to;
    e[eid].val = val;
    e[eid].next = p[from];
    e[eid].full = false;
    p[from] = eid++;
}
int n, m;
int h[MAXN], gap[MAXN];
int source, sink;
inline int dfs(int pos, int cost)
{
    if (pos == sink)
    {
        return cost;
    }
    int j, minh = n - 1, lv = cost, d;
    for (j = p[pos]; j != -1; j = e[j].next)
    {
        int v = e[j].v, val = e[j].val;
        if (val > 0)
        {
            if (h[v] + 1 == h[pos])
            {
                if (lv < e[j].val) d = lv;
                else d = e[j].val;
                d = dfs(v, d);
                e[j].val -= d;
                if (!e[j].val) e[j].full = true;
                e[j ^ 1].val += d;
                e[j ^ 1].full = false;
                lv -= d;
                if (h[source] >= n) return cost - lv;
                if (lv == 0) break;
            }
            if (h[v] < minh) minh = h[v];
        }
    }
    if (lv == cost)
    {
        --gap[h[pos]];
        if (gap[h[pos]] == 0) h[source] = n;
        h[pos] = minh + 1;
        ++gap[h[pos]];
    }
    return cost - lv;
}
int sap(int st, int ed)
{
    source = st;
    sink = ed;
    int ret = 0;
    memset(gap, 0, sizeof(gap));
    memset(h, 0, sizeof(h));
    gap[st] = n;
    while (h[st] < n)
    {
        ret += dfs(st, INT_MAX);
    }
    return ret;
}
int x, y, d;
bool vst[2][MAXN];
bool g[MAXN][MAXN];
void color_dfs(int k, int s)
{
    vst[k][s] = true;
    for (int t = 1; t <= n; ++t)
        if (g[s][t] && (!vst[k][t])){
            color_dfs(k, t);
        }
}
int main()
{
    sapinit();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &x, &y, &d);
        insert1(x + 1, y + 1, d);
    }
    sap(1, n);
    memset(vst, false, sizeof(vst));
    memset(g, false, sizeof(g));
    for (int i = 0; i < eid; i += 2)
        if (e[i].val) g[e[i].s][e[i].v] = true;
    color_dfs(0, 1);
    memset(g, false, sizeof(g));
    for (int i = 0; i < eid; i += 2)
        if (e[i].val) g[e[i].v][e[i].s] = true;
    color_dfs(1, n);
    int cnt = 0;
    for (int i = 0; i < eid; i += 2)
        if (e[i].full){
            if (vst[0][e[i].s] && vst[1][e[i].v]) ++cnt;
        }
    printf("%d\n", cnt);
    return 0;
}
