#include <iostream>
#include <cstdio>
#include <cstring>
#define N 2048
#define M 10000010
using namespace std;
struct edge
{
    int v, next;
}e[M];
int p[N], eid, n, m;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y)
{
    insert(x, y);
    insert(y, x);
}
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
    for (int i = 0; i < 2 * n; ++i)
        if (!dfn[i]) tarjan(i);
}
int loc(int a, int c)
{
    return a * 2 + c;
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        mapinit();
        for (int i = 1; i <= m; ++i)
        {
            int a1, a2, c1, c2;
            scanf("%d%d%d%d", &a1, &a2, &c1, &c2);
            insert(loc(a1, c1), loc(a2, 1 - c2));
            insert(loc(a2, c2), loc(a1, 1 - c1));
        }
        solve();
        bool flag = true;
        for (int i = 0; i < n; ++i)
            if (belong[i * 2] == belong[i * 2 + 1])
            {
                flag = false; break;
            }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
