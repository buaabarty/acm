#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[500010][3], n;
struct edge
{
    int v, next;
}e[1000010];
int p[500010], eid;
vector<int> ch[500010];
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
bool vst[500010];
//f[v][0]:v不占用且不被覆盖；f[v][1]:v不占用且被覆盖；f[v][2]:v被占用
void dfs(int v)
{
    int cnt = ch[v].size();
    if (cnt == 0)
    {
        f[v][0] = 1;
        f[v][1] = 0;
        f[v][2] = 1;
        return ;
    }
    int sum = 1,
    f[v][0] = f[v][1] = 1;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        int u = e[i].v;
        dfs(u);
        f[v][0] = (f[v][0] * f[u])
    }
}
void maketree(int v)
{
    vst[v] = 1;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v])
        {
            ch[v].push_back(e[i].v);
            maketree(e[i].v);
        }
}
int main()
{
    scanf("%d", &n);
    mapinit();
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        insert2(x, y);
    }
    memset(vst, 0, sizeof(vst));
    maketree(1);
    return 0;
}
