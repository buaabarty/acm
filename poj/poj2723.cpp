#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXM 10000000
#define MAXN 4096
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
int eid, p[MAXN];
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y)
{
    insert(x, y); insert(y, x);
}
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
int n, m, x, y;
int dfn[MAXN], low[MAXN], stack[MAXN], belong[MAXN];
int bcnt, dindex = 0, top = 0;
bool instack[MAXN];
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
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i);
}
bool inside(int a, int x, int y)
{
    return ((a >= x) && (a <= y)) || ((a >= y) && (a <= x));
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
int opp[MAXN], mx[MAXN], my[MAXN];
bool okay(int count)
{
    mapinit();
    for (int i = 1; i <= count; ++i)
    {
        insert(mx[i], opp[my[i]]);
        insert(my[i], opp[mx[i]]);
    }
    solve();
    for (int i = 1; i <= n; ++i)
        if (belong[i] == belong[opp[i]]) return false;
    return true;
}
int main()
{
    while (scanf("%d%d", &n, &m), (n + m))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &x, &y);
            x++, y++;
            opp[x] = y, opp[y] = x;
        }
        n *= 2;
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &mx[i], &my[i]);
            mx[i]++, my[i]++;
        }
        int left = 0, right = m;
        while (left < right)
        {
            if (left + 1 == right)
            {
                if (okay(right)) left = right;
                break;
            }
            if (okay((left + right + 1) / 2)) left = (left + right + 1) / 2;
            else right = (left + right + 1) / 2 - 1;
        }
        printf("%d\n", left);
    }
    return 0;
}
