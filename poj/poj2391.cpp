#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#define MAXF 256
using namespace std;
typedef struct
{
    int v, next, val;
}edge;
const int MAXN = 1024;
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
int f, path, a[MAXF], b[MAXF], sum = 0;
long long map[MAXN][MAXN];
bool init()
{
    long long d;
    int x, y;
    sum = 0;
    if (scanf("%d%d", &f, &path) == EOF) return false;
    for (int i = 1; i <= f; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
        sum += a[i];
    }
    for (int i = 1; i <= f; ++i)
        for (int j = 1; j <= f; ++j)
            if (i == j) map[i][j] = 0LL;
            else map[i][j] = 1000000000000LL;
    for (int i = 1; i <= path; ++i)
    {
        scanf("%d%d%lld", &x, &y, &d);
        map[x][y] = min(map[x][y], d);
        map[y][x] = min(map[y][x], d);
    }
    for (int k = 1; k <= f; ++k)
        for (int i = 1; i <= f; ++i)
            for (int j = 1; j <= f; ++j)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
    /*for (int i = 1; i <= f; ++i, printf("\n"))
        for (int j = 1; j <= f; ++j)
            printf("%15lld", map[i][j]);*/
    return true;
}

bool okay(long long limit)
{
    memset(p, -1, sizeof(p));
    eid = 0;
    source = f * 2 + 1, sink = f * 2 + 2;
    for (int i = 1; i <= f; ++i)
        for (int j = 1; j <= f; ++j)
            if (map[i][j] <= limit) insert1(i, j + f, INT_MAX);
    for (int i = 1; i <= f; ++i)
    {
        insert1(source, i, a[i]);
        insert1(i + f, sink, b[i]);
    }
    n = f * 2 + 2;
    return (sap(source, sink) == sum);
}

int main()
{
    while (init())
    {
        long long l = 0LL, r = 1000000000000LL - 1LL, mid;
        while (l < r)
        {
            if (l + 1LL == r)
            {
                if (!okay(l)) l = r;
                break;
            }
            mid = (l + r) / 2LL;
            if (okay(mid)) r = mid;
            else l = mid + 1LL;
        }
        if (!okay(l)) printf("-1\n");
        else printf("%lld\n", l);
    }
    return 0;
}
