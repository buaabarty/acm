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
const int MAXN = 512;
const int MAXM = 65536;
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
int a, c1, c2, res, x, y;
bool map[MAXN][MAXN];
int main()
{
    sapinit();
    scanf("%d%d%d",&a, &c1, &c2);
    memset(map, false, sizeof(map));
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= a; ++j)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j]){
                insert1(i + a, j, INT_MAX);
            }
        }
    for (int i = 1; i <= a; ++i)
        insert1(i, i + a, 1);
    n = a * 2;
    res = sap(c1 + a, c2);
    if (res == INT_MAX)
    {
        printf("NO ANSWER!\n");
        return 0;
    }
    printf("%d\n", res);
    bool use[MAXN], flag = 0;
    memset(use, true, sizeof(use));
    for (int i = 1; i <= a; ++i)
    {
        use[i] = false;
        sapinit();
        for (int j = 1; j <= a; ++j)
            if (use[j]) insert1(j, j + a, 1);
        for (int j1 = 1; j1 <= a; ++j1)
            for (int j2 = 1; j2 <= a; ++j2)
                if (map[j1][j2]){
                    insert1(j1 + a, j2, INT_MAX);
                }
        if (sap(c1 + a, c2) == res - 1)
        {
            if (flag) printf(" ");
            flag = 1;
            printf("%d", i);
            res--;
        }
        else use[i] = true;
    }
    printf("\n");
    return 0;
}
