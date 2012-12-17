/*
ID:ybojan2
LANG:C++
TASK:milk6
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
using namespace std;
typedef struct
{
    int x, y, next, id;
    long long val;
}edge;
const int MAXN = 128;
const int MAXM = 10000;
edge e[MAXM];
int p[MAXN], eid;
inline void sapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
inline void insert1(int from, int to, long long val, int id)
{
    e[eid].x = from;
    e[eid].y = to;
    e[eid].val = val;
    e[eid].id = id;
    e[eid].next = p[from];
    p[from] = eid++;
    swap(from, to);
    e[eid].x = from;
    e[eid].y = to;
    e[eid].val = 0;
    e[eid].id = 0;
    e[eid].next = p[from];
    p[from] = eid++;
}
int n, m;
int h[MAXN], gap[MAXN];
int source, sink;
inline long long dfs(int pos, long long cost)
{
    if (pos == sink)
    {
        return cost;
    }
    int j, minh = n - 1;
    long long lv = cost, d;
    for (j = p[pos]; j != -1; j = e[j].next)
    {
        int v = e[j].y;
        long long val = e[j].val;
        if (val > 0LL)
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
long long sap(int st, int ed)
{
    source = st;
    sink = ed;
    long long ret = 0;
    memset(gap, 0, sizeof(gap));
    memset(h, 0, sizeof(h));
    gap[st] = n;
    while (h[st] < n)
    {
        ret += dfs(st, 100000000000000000LL);
    }
    return ret;
}
bool map[MAXN][MAXN];
bool vst[MAXN];
void fill(long long v)
{
    vst[v] = true;
    for (long long i = 1; i <= n; ++i)
        if (map[v][i] && !vst[i]) fill(i);
}
int res[MAXM], rl = 0;
long long dat[MAXN][MAXN];
int main()
{
    freopen("milk6.in", "r", stdin);
    freopen("milk6.out", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(dat, 0, sizeof(dat));
    sapinit();
    int x, y;
    long long d;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%lld", &x, &y, &d);
        insert1(x, y, 500000LL + (long long)i - 1LL + (long long)500000 * 1001 * d, i);
    }
    long long ans = sap(1, n);
    printf("%lld %lld\n", ans / (500000 * 1001), (ans % (500000LL * 1001LL)) / 500000LL);
    memset(map, false, sizeof(map));
    for (int i = 0; i < eid; i ++)
    {
        if (e[i].val) map[e[i].x][e[i].y] = true;
    }
    memset(vst, false, sizeof(vst));
    fill(1);
    for (int i = 0; i < eid; i += 2)
        if (vst[e[i].x] && !vst[e[i].y] && !e[i].val) res[++rl] = e[i].id;
    //for (int i = 1; i <= n; ++i) printf("%d ", vst[i]);printf("\n");
    for (long long i = 1; i <= rl; ++i) printf("%d\n", res[i]);
    return 0;
}
