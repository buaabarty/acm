#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef struct
{
    int v, next, val;
}edge;
const int N = 2048;
const int MAXM = 10000000;
edge e[MAXM];
int p[N], eid;
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
int h[N], gap[N];
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
bool map[N][N];
int x[N], y[N], a[N], b[N], sum;
double dist(int a, int b)
{
    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}
double d;
bool okay(int ss)
{
    sapinit();
    source = 2 * n + 1, sink = ss;
    for (int i = 1; i <= n; ++i)
    {
        insert1(source, i, a[i]);
        insert1(i, i + n, b[i]);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) if (i != j)
            if (map[i][j]) insert1(i + n, j, INT_MAX);
    int tempn = n;
    n = source;
    int res = sap(source, sink);
    n = tempn;
    //printf("%d %d\n", res, sum);
    return (res == sum);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        sum = 0;
        scanf("%d%lf", &n, &d);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d%d", &x[i], &y[i], &a[i], &b[i]);
            sum += a[i];
        }
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (dist(i, j) <= d) map[i][j] = map[j][i] = 1;
        bool first = true;
        for (int i = 1; i <= n; ++i)
            if (okay(i))
            {
                if (!first) printf(" ");
                first = false;
                printf("%d", i - 1);
            }
        if (!first) puts("");
        else puts("-1");

    }
    return 0;
}
