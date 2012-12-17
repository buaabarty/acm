/*
ID:ybojan2
LANG:C++
TASK:telecow
*/
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
const int MAXM = 32768;
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
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("(%d,%d) ", e[j].v, e[j].val);
        printf("\n");
    }
}
int main()
{
    freopen("telecow.in", "r", stdin);
    freopen("telecow.out", "w", stdout);
    sapinit();
    int a, m, c1, c2, x[MAXM], y[MAXM], res;
    scanf("%d%d%d%d",&a, &m, &c1, &c2);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
        insert1(x[i] + a, y[i], INT_MAX);
        insert1(y[i] + a, x[i], INT_MAX);
    }
    for (int i = 1; i <= a; ++i)
        insert1(i, i + a, 1);
    //print_map();
    n = a * 2;
    res = sap(c1 + a, c2);
    printf("%d\n", res);
    bool use[MAXN], flag = 0;
    memset(use, true, sizeof(use));
    for (int i = 1; i <= a; ++i)
    {
        use[i] = false;
        sapinit();
        for (int j = 1; j <= a; ++j)
            if (use[j]) insert1(j, j + a, 1);
        for (int j = 1; j <= m; ++j)
        {
            insert1(x[j] + a, y[j], INT_MAX);
            insert1(y[j] + a, x[j], INT_MAX);
        }
        //print_map();
        if (sap(c1 + a, c2) == res - 1)
        {
            if (flag) printf(" ");
            printf("%d", i);
            flag = 1;
            res--;
        }
        else use[i] = true;
    }
    printf("\n");
    return 0;
}
