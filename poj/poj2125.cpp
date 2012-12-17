#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
using namespace std;
typedef struct
{
    int v, next, val;
}edge;
const int MAXN = 256;
const int MAXM = 150000;
edge e[MAXM];
int p[MAXN], eid, n, m, h[MAXN], gap[MAXN], source, sink;
int x, y, cnt;
bool map[MAXN][MAXN], vst[MAXN];
inline void sapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
inline void insert(int from, int to, int val, int f = 0)
{
    e[eid].v = to;
    e[eid].val = val;
    e[eid].next = p[from];
    p[from] = eid++;
    swap(from, to);
    e[eid].v = to;
    e[eid].val = f * val;
    e[eid].next = p[from];
    p[from] = eid++;
}
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
                e[j ^ 1].val += d;
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
bool init()
{
    sapinit();
    memset(map, false, sizeof(map));
    if (scanf("%d%d", &n, &m) == EOF) return false;
    source = 2 * n + 1, sink = 2 * n + 2;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        insert(source, i, x);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        insert(i + n, sink, x);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        map[x][y] = true;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = n; j >= 1; --j)
            if (map[i][j]) insert(j, i + n, INT_MAX);
    n = n * 2 + 2;
    return true;
}
void dfs(int v)
{
    vst[v] = true;
    for (int i = p[v];i != -1; i = e[i].next)
        if ((!vst[e[i].v]) && (e[i].val)) dfs(e[i].v);
}
int main()
{
    while (init())
    {
        cnt = 0;
        printf("%d\n", sap(source, sink));
        memset(vst, false, sizeof(vst));
        dfs(source);
        n = n / 2 - 1;
        for (int i = 1; i <= n; ++i)
        {
            if (vst[i + n]) cnt++;
            if (!vst[i]) cnt++;
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= n; ++i)
        {
            if (vst[i + n]) printf("%d -\n", i);
            if (!vst[i]) printf("%d +\n", i);
        }
    }
    return 0;
}
