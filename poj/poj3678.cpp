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
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
int x[MAXN], y[MAXN];
int n, m;
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
    for (int i = 0; i < n; ++i)
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
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        mapinit();
        for (int i = 1; i <= m; ++i)
        {
            int x, y, z;
            char str[10];
            scanf("%d%d%d%s", &x, &y, &z, str);
            if (str[0] == 'A')
            {
                if (z == 1)
                {
                    insert(x * 2, x * 2 + 1);
                    insert(y * 2, y * 2 + 1);
                }
                else
                {
                    insert(x * 2 + 1, y * 2);
                    insert(y * 2 + 1, x * 2);
                }
            }
            else if (str[0] == 'O')
            {
                if (z == 1)
                {
                    insert(x * 2, y * 2 + 1);
                    insert(y * 2, x * 2 + 1);
                }
                else
                {
                    insert(x * 2 + 1, x * 2);
                    insert(y * 2 + 1, y * 2);
                }
            }
            else
            {
                if (z == 1)
                {
                    insert(x * 2, y * 2 + 1);
                    insert(x * 2 + 1, y * 2);
                    insert(y * 2, x * 2 + 1);
                    insert(y * 2 + 1, x * 2);
                }
                else
                {
                    insert(x * 2, y * 2);
                    insert(x * 2 + 1, y * 2 + 1);
                    insert(y * 2, x * 2);
                    insert(y * 2 + 1, x * 2 + 1);
                }
            }
        }
        n *= 2;
        solve();
        bool flag = true;
        for (int i = 0; i < n / 2; ++i)
            if (belong[i * 2] == belong[i * 2 + 1])
            {
                flag = false;
                break;
            }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
