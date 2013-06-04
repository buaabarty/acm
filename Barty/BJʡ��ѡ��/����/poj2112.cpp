#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#define MAXE 65536
#define MAXN 256
#define INF 1000000000
using namespace std;
struct edge{
    int v, val, next;
}e[MAXE];
int p[MAXN], eid;
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
void map_init()
{
    eid = 0;
    memset(p, -1, sizeof(p));
}
int k, c, max_edge;
int map[MAXN][MAXN];
void print_num_map()
{
    for (int i = 1; i <= n; ++i, printf("\n"))
        for (int j = 1; j <= n; ++j)
            printf("%d ", map[i][j]);
}
bool init()
{
    if (scanf("%d%d%d", &k, &c, &m) == EOF) return false;
    n = k + c;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &map[i][j]);
            if (!map[i][j]) map[i][j] = INF;
        }
    for (int t = 1; t <= n; ++t)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = min(map[i][j], map[i][t] + map[t][j]);
    max_edge = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= c; ++j)
            max_edge = max(max_edge, map[i][j + k]);
    return true;
}
bool okay(int limit)
{
    map_init();
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= c; ++j)
            if (map[i][j + k] <= limit) insert1(i, j + k, 1);
    int s = k + c + 1, t = k + c + 2;
    for (int i = 1; i <= k; ++i)
        insert1(s, i, m);
    for (int i = 1; i <= c; ++i)
        insert1(i + k, t, 1);
    n = k + c + 2;
    return (sap(s, t) == c);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    while (init())
    {
        int l = 1, r = max_edge, mid;
        while (l < r)
        {
            if (l + 1 == r){
                if (!okay(l)) l = r;
                break;
            }
            mid = (l + r) / 2;
            if (okay(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
