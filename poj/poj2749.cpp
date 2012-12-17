#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define M 10000000
#define N 1024
using namespace std;
struct edge{
    int v, next;
}e[M];
int eid, p[N];
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
int n, m;
int dfn[N], low[N], stack[N], belong[N];
int bcnt, dindex = 0, top = 0;
bool instack[N];
void tarjan(int v)
{
    instack[v] = true;
    stack[++top] = v;
    dfn[v] = low[v] = ++dindex;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        if (!dfn[e[i].v])
        {
            tarjan(e[i].v);
            low[v] = min(low[v], low[e[i].v]);
        }
        else if (instack[e[i].v])
        {
            low[v] = min(low[v], dfn[e[i].v]);
        }
    }
    int temp;
    if (dfn[v] == low[v])
    {
        bcnt++;
        do{
            temp = stack[top--];
            instack[temp] = false;
            belong[temp] = bcnt;
        }while (temp != v);
    }
}
void solve()
{
    memset(dfn, 0, sizeof(dfn));
    top = bcnt = dindex = 0;
    for (int i = 1; i <= 2 * n; ++i)
        if (!dfn[i]) tarjan(i);
}
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("");
    }
}
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int dist(int x1, int y1, int x2, int y2)
{
    return iabs(x1 - x2) + iabs(y1 - y2);
}
int x[N], y[N], sx1, sy1, sx2, sy2, a, b;
int ai[N], aj[N], bi[N], bj[N];
bool okay(int limit)
{
    mapinit();
    for (int i = 1; i <= a; ++i)
    {
        insert(ai[i], aj[i] + n);
        insert(ai[i] + n, aj[i]);
        insert(aj[i], ai[i] + n);
        insert(aj[i] + n, ai[i]);
    }
    for (int i = 1; i <= b; ++i)
    {
        insert(bi[i], bj[i]);
        insert(bi[i] + n, bj[i] + n);
        insert(bj[i], bi[i]);
        insert(bj[i] + n, bi[i] + n);
    }
    for (int i = 1; i <= n; ++i)
        if ((dist(x[i], y[i], sx1, sy1) > limit) && (dist(x[i], y[i], sx2, sy2) > limit)) return false;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) if (i != j)
        {
            if (dist(x[i], y[i], sx1, sy1) + dist(x[j], y[j], sx2, sy2) + dist(sx1, sy1, sx2, sy2) > limit)
            {
                insert(i, j);
                insert(j + n, i + n);
            }
            if (dist(x[i], y[i], sx1, sy1) + dist(x[j], y[j], sx1, sy1) > limit)
            {
                insert(i, j + n);
                insert(j, i + n);
            }
            if (dist(x[i], y[i], sx2, sy2) + dist(x[j], y[j], sx2, sy2) > limit)
            {
                insert(i + n, j);
                insert(j + n, i);
            }
        }
    solve();
    for (int i = 1; i <= n; ++i)
        if (belong[i] == belong[i + n]) return false;
    return true;
}
int main()
{
    while (~scanf("%d%d%d", &n, &a, &b))
    {
        scanf("%d%d%d%d", &sx1, &sy1, &sx2, &sy2);
        for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
        for (int i = 1; i <= a; ++i) scanf("%d%d", &ai[i], &aj[i]);
        for (int i = 1; i <= b; ++i) scanf("%d%d", &bi[i], &bj[i]);
        int left = 0, right = 100000000, mid;
        while (left < right)
        {
            if (left + 1 == right)
            {
                if (!okay(left)) left = right;
                break;
            }
            mid = (left + right) / 2;
            if (okay(mid)) right = mid;
            else left = mid + 1;
        }
        if (okay(left)) printf("%d\n", left);
        else puts("-1");
    }
    return 0;
}
