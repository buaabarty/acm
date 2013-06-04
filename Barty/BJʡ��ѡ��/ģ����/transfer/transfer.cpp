#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MAXZ 128
#define MAXM 3240000
#define MAXN 32768
using namespace std;
struct line{
    int x1, y1, x2, y2;
};
struct edge{
    int v, next;
}e[MAXM], ne[MAXM];
int d[MAXN] ,nd[MAXN], p[MAXN], np[MAXN], eid, neid, n, m, root;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void ninsert(int x, int y)
{
    ne[neid].v = y;
    ne[neid].next = np[x];
    np[x] = neid++;
}
int ord(int x, int y)
{
    return (x - 1) * m + y;
}
int dfn[MAXN], low[MAXN], stack[MAXM], belong[MAXN];
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
    for (int j = 1; j <= n; ++j)
    {
        if (!dfn[j]) tarjan(j);
    }
}
bool filled[MAXN][MAXN];
void make_new_map()
{
    neid = 0;
    memset(np, -1, sizeof(np));
    memset(nd, 0, sizeof(nd));
    memset(ne, 0, sizeof(ne));
    memset(filled, false, sizeof(filled));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = p[i]; j != -1; j = e[j].next)
            if ((belong[i] != belong[e[j].v]) && !filled[belong[i]][belong[e[j].v]])
            {
                ninsert(belong[i], belong[e[j].v]);
                filled[belong[i]][belong[e[j].v]] = true;
            }
    }
    for (int i = 1; i <= n; ++i)
        nd[belong[i]] += d[i];
    n = bcnt;
    root = belong[1];
}
int maxl = 0, longest[MAXN];
bool vst[MAXN];
void dfs(int v, int l)
{
    if ((l <= longest[v]) && (vst[v])) return;
    vst[v] = true;
    longest[v] = l;
    if (np[v] == -1)
    {
        maxl = max(maxl, l);
        return;
    }
    for (int i = np[v]; i != -1; i = ne[i].next)
        dfs(ne[i].v, l + nd[ne[i].v]);
}
int maxr[MAXN];
int find_longest()
{
    maxl = 0;
    memset(longest, 0, sizeof(longest));
    dfs(root, nd[root]);
    return maxl;
}
int main()
{
    freopen("transfer.in", "r", stdin);
    freopen("transfer.out", "w", stdout);
    int dat[MAXZ][MAXZ], lc = 0;
    line l[MAXN];
    string str;
    memset(e, 0, sizeof(e));
    eid = lc = 0;
    memset(p, -1, sizeof(p));
    memset(l, 0, sizeof(l));
    memset(d, 0, sizeof(d));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        cin >> str;
        for (int j = 0; j < m; ++j)
            if (str[j] == '*')
            {
                l[++lc].x1 = i;
                l[lc].y1 = j + 1;
                dat[i][j + 1] = 10;
            }
            else if (str[j] == '#') dat[i][j + 1] = -1;
            else
            {
                dat[i][j + 1] = str[j] - '0';
                d[ord(i, j + 1)] = str[j] - '0';
            }
    }
    for (int i = 1; i <= lc; ++i)
    {
        scanf("%d%d", &l[i].x2, &l[i].y2);
        l[i].x2++; l[i].y2++;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (dat[i][j] >= 0)
            {
                if ((dat[i][j + 1] >= 0) && (j < m)) insert(ord(i, j), ord(i, j + 1));
                if ((dat[i + 1][j] >= 0) && (i < n)) insert(ord(i, j), ord(i + 1, j));
            }
    for (int i = 1; i <= lc; ++i)
        insert(ord(l[i].x1, l[i].y1), ord(l[i].x2, l[i].y2));
    n = n * m;
    solve();
    make_new_map();
    printf("%d\n", find_longest());
    return 0;
}
