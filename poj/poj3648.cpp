#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#define M 10000000
#define N 4096
using namespace std;
struct edge{
    int v, next;
}e1[M], e2[M];
int eid1, p1[N], eid2, p2[N];
void insert1(int x, int y)
{
    e1[eid1].v = y;
    e1[eid1].next = p1[x];
    p1[x] = eid1++;
}
void insert2(int x, int y)
{
    e2[eid2].v = y;
    e2[eid2].next = p2[x];
    p2[x] = eid2++;
}
void mapinit1()
{
    memset(p1, -1, sizeof(p1));
    eid1 = 0;
}
void mapinit2()
{
    memset(p2, -1, sizeof(p2));
    eid2 = 0;
}
int x[N], y[N];
int n, m;
int dfn[N], low[N], stack[N], belong[N];
int bcnt, dindex = 0, top = 0;
bool instack[N];
void tarjan(int v)
{
    instack[v] = true;
    stack[++top] = v;
    dfn[v] = low[v] = ++dindex;
    for (int i = p1[v]; i != -1; i = e1[i].next)
    {
        if (!dfn[e1[i].v])
        {
            tarjan(e1[i].v);
            low[v] = min(low[v], low[e1[i].v]);
        }
        else if (instack[e1[i].v])
        {
            low[v] = min(low[v], dfn[e1[i].v]);
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
void print_map1()
{
    for (int i = 0; i < 2 * n; ++i)
    {
        printf("%d:", i);
        for (int j = p1[i]; j != -1; j = e1[j].next)
            printf("%d ", e1[j].v);
        puts("");
    }
}
void print_map2()
{
    for (int i = 0; i < bcnt; ++i)
    {
        printf("%d:", i);
        for (int j = p2[i]; j != -1; j = e2[j].next)
            printf("%d ", e2[j].v);
        puts("");
    }
}
int opp(int x)
{
    if (x < n) return x + n;
    else return x - n;
}
/*
1 ~ n:        ѡ1h~nh
n+1 ~ n*2:    ѡ1w~hw
*/
int rd[N], cf[N], res[N];
queue<int> q;
bool print()
{
    while (!q.empty()) q.pop();
    for (int i = 0; i < n; ++i)
        if (belong[i] == belong[i + n])
        {
            puts("bad luck");
            return false;
        }
    mapinit2();
    memset(rd, 0, sizeof(rd));
    for (int i = 0; i < 2 * n; ++i)
        for (int j = p1[i]; j != -1; j = e1[j].next)
            if (belong[i] != belong[e1[j].v])
            {
                rd[belong[i]]++;
                insert2(belong[e1[j].v], belong[i]);
            }
    //printf("%d\n", bcnt);
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; ++i)
    {
        cf[belong[i]] = belong[i + n];
        cf[belong[i + n]] = belong[i];
    }
    for (int i = 1; i <= bcnt; ++i)
        if (rd[i] == 0) q.push(i);
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        if (res[now] == 0)
        {
            res[now] = 1;
            res[cf[now]] = -1;
        }
        for (int i = p2[now]; i != -1; i = e2[i].next)
            if ((--rd[res[e2[i].v]]) == 0) q.push(e2[i].v);
    }
    bool first = true;
    for (int i = 1; i < n; ++i)
    {
        if (!first) putchar(' ');
        first = false;
        if (res[belong[i]] == 1) printf("%dh", i);
        else printf("%dw", i);
    }
    puts("");
    return true;
}
int main()
{
    while (scanf("%d%d", &n, &m), (n + m))
    {
        mapinit1();
        for (int i = 1; i <= m; ++i)
        {
            int x, y;
            char s1[10], s2[10];
            scanf("%d%s%d%s", &x, s1, &y, s2);
            if (s1[0] == 'w') x += n;
            if (s2[0] == 'w') y += n;
            insert1(opp(x), y);
            insert1(opp(y), x);
        }
        insert1(0, n);
        //print_map1();
        solve();
        print();
    }
    return 0;
}
