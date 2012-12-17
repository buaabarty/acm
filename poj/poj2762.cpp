#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 1024
#define MAXM 32768
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
int p[MAXN], eid, n, m;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
int dfn[MAXN], low[MAXN], stack[MAXN], belong[MAXN];
int bcnt, dindex = 0, top = 0, rd[MAXN];
bool instack[MAXN];
bool map[MAXN][MAXN], use[MAXN];
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


int main()
{
    int t, x, y;
    scanf("%d", &t);
    while (t--)
    {
        memset(p, -1, sizeof(p));
        eid = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &x, &y);
            insert(x, y);
        }
        solve();
        memset(map, false, sizeof(map));
        memset(rd, 0, sizeof(rd));
        for (int i = 1; i <= n; ++i)
            for (int j = p[i]; j != -1; j = e[j].next)
                if (belong[e[j].v] != belong[i])
                {
                    map[belong[i]][belong[e[j].v]] = true;
                    ++rd[belong[e[j].v]];
                }
        bool flag = true;
        memset(use, false, sizeof(use));
        n = bcnt;
        for (int i = 1; i <= n; ++i)
        {
            int cnt = 0, t;
            for (int j = 1; j <= n; ++j)
                if ((!rd[j]) && (!use[j])){
                    cnt++;
                    t = j;
                }
            if (cnt != 1){
                flag = false;
                break;
            }
            use[t] = true;
            for (int j = 1; j <= n; ++j)
                if (map[t][j]){
                    rd[j]--;
                    map[t][j] = false;
                }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
}
