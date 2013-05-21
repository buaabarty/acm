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

int map[MAXN][MAXN];
int x[MAXM], y[MAXM], d[MAXM], d1[MAXN], d2[MAXN], start, end;
bool use[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = INT_MAX / 2 * (i != j);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &x[i], &y[i], &d[i]);
            map[x[i]][y[i]] = min(map[x[i]][y[i]], d[i]);
        }
        scanf("%d%d", &start, &end);
        memset(d1, 0x7f, sizeof(d1));
        memset(d2, 0x7f, sizeof(d2));
        memset(use, false, sizeof(use));
        d1[start] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int a, b = INT_MAX;
            for (int j = 1; j <= n; ++j)
                if ((d1[j] < b) && !use[j])
                {
                    a = j, b = d1[j];
                }
            use[a] = true;
            for (int j = 1; j <= n; ++j)
                if (!use[j] && (b + map[a][j] < d1[j]))
                    d1[j] = b + map[a][j];
        }
        memset(use, false, sizeof(use));
        d2[end] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int a, b = INT_MAX;
            for (int j = 1; j <= n; ++j)
                if ((d2[j] < b) && !use[j])
                {
                    a = j, b = d2[j];
                }
            use[a] = true;
            for (int j = 1; j <= n; ++j)
                if (!use[j] && (b + map[j][a] < d2[j]))
                    d2[j] = b + map[j][a];
        }
        sapinit();
        for (int i = 1; i <= m; ++i)
            if ((x[i] != y[i]) && (d1[x[i]] + d2[y[i]] + d[i] == d1[end]))
            {
                insert1(x[i], y[i], 1);
            }
        printf("%d\n", sap(start, end));
    }
    return 0;
}
