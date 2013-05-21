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
const int MAXN = 2048;
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
    e[eid].v = to;
    e[eid].val = val;
    e[eid].next = p[from];
    p[from] = eid++;
    swap(from, to);
    e[eid].v = to;
    e[eid].val = 0;
    e[eid].next = p[from];
    p[from] = eid++;
}
inline void insert2(int from, int to, int val)
{
    e[eid].v = to;
    e[eid].val = val;
    e[eid].next = p[from];
    p[from] = eid++;
    swap(from, to);
    e[eid].v = to;
    e[eid].val = val;
    e[eid].next = p[from];
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
int s, t;
int vst[MAXN], pre[MAXN], c[MAXN];
bool init()
{
    sapinit();
    int a, b, x;
    if (scanf("%d%d", &a, &b) == EOF) return false;
    s = a + b + 1, t = a + b + 2;
    for (int i = 1; i <= a; ++i)
    {
        scanf("%d", &c[i]);
        insert1(s, i, c[i]);
    }
    memset(vst, 0, sizeof(vst));
    for (int i = 1; i <= b; ++i)
    {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j)
        {
            scanf("%d", &x);
            if (vst[x] == 0)
            {
                insert1(x, i + a, INT_MAX);
                pre[x] = i;
            }
            else
            {
                insert1(pre[x] + a, i + a, INT_MAX);
                pre[x] = i;
            }
            vst[x] = 1;
        }
        scanf("%d", &x);
        insert1(i + a, t, x);
    }
    n = t;
}

int main()
{
    while (init())
    {
        cout << sap(s, t) << endl;
    }
    return 0;
}
