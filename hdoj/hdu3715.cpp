#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define E 10000000
#define M 10010
#define N 512
using namespace std;
struct edge{
    int v, next;
}e[E];
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
    for (int i = 1; i <= n * 2; ++i)
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
int a[M], b[M], c[M];
bool okay(int d)
{
    mapinit();
    for (int i = 1; i <= d; ++i)
        if (c[i] == 0)
        {
            insert(a[i], b[i] + n);
            insert(b[i], a[i] + n);
        }
        else if (c[i] == 1)
        {
            insert(a[i], b[i]);
            insert(a[i] + n, b[i] + n);
            insert(b[i], a[i]);
            insert(b[i] + n, a[i] + n);
        }
        else
        {
            insert(a[i] + n, b[i]);
            insert(b[i] + n, a[i]);
        }
    solve();
    for (int i = 1; i <= n; ++i)
        if (belong[i] == belong[i + n]) return false;
    return true;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            a[i]++, b[i]++;
        }
        int mid, left = 0, right = m;
        while (left < right)
        {
            if (left + 1 == right)
            {
                if (okay(right)) left = right;
                break;
            }
            mid = (left + right + 1) / 2;
            if (okay(mid)) left = mid;
            else right = mid - 1;
        }
        printf("%d\n", left);
    }
    return 0;
}
