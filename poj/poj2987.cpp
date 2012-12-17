#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#define LL long long
using namespace std;
typedef struct
{
    LL v, next, val;
}edge;
const LL MAXN = 5010;
const LL MAXM = 200000;
edge e[MAXM];
LL p[MAXN], eid;
inline void sapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
inline void insert1(LL from, LL to, LL val)
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
inline void insert2(LL from, LL to, LL val)
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
LL n, m;
LL h[MAXN], gap[MAXN];
LL source, sink;
inline LL dfs(LL pos, LL cost)
{
    if (pos == sink)
    {
        return cost;
    }
    LL j, minh = n - 1, lv = cost, d;
    for (j = p[pos]; j != -1; j = e[j].next)
    {
        LL v = e[j].v, val = e[j].val;
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
LL sap(LL st, LL ed)
{
    source = st;
    sink = ed;
    LL ret = 0;
    memset(gap, 0, sizeof(gap));
    memset(h, 0, sizeof(h));
    gap[st] = n;
    while (h[st] < n)
    {
        ret += dfs(st, INT_MAX);
    }
    return ret;
}

bool vst[MAXN];
void dfs(LL v)
{
    vst[v] = true;
    for (LL i = p[v]; i != -1; i = e[i].next)
        if ((e[i].val > 0) && !vst[e[i].v]) dfs(e[i].v);
}

int main()
{
    while (~scanf("%lld%lld", &n, &m))
    {
        sapinit();
        source = n + 1, sink = n + 2;
        LL sum = 0;
        for (LL i = 1; i <= n; ++i)
        {
            LL x;
            scanf("%lld", &x);
            if (x > 0) { insert1(source, i, x); sum += x; }
            else insert1(i, sink, -x);
        }
        for (LL i = 1; i <= m; ++i)
        {
            LL x, y;
            scanf("%lld%lld", &x, &y);
            insert1(x, y, INT_MAX);
        }
        n = sink;
        LL res = sap(source, sink), cnt = 0;
        memset(vst, false, sizeof(vst));
        dfs(source);
        for (LL i = 1; i < source; ++i)
            if (vst[i]) cnt++;
        printf("%lld %lld\n", cnt, sum - res);
    }
    return 0;
}
