#include <iostream>
#include <cstdio>
#include <cstring>
#define N 2048
using namespace std;
struct edge{
    int v, next;
}e[N];
int p[N], eid, n, f[N][2], root;
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
bool isroot[N];
void dfs(int v)
{
    bool isleaf = true;
    int s1 = 0, s2 = 0;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        isleaf = false;
        dfs(e[i].v);
        s1 += min(f[e[i].v][0], f[e[i].v][1]);
        s2 += f[e[i].v][1];
    }
    if (isleaf)
    {
        f[v][0] = 0;
        f[v][1] = 1;
    }
    else
    {
        f[v][0] = s2;
        f[v][1] = s1 + 1;
    }
}
int main()
{
    while (~scanf("%d", &n))
    {
        mapinit();
        memset(isroot, true, sizeof(isroot));
        for (int i = 1; i <= n; ++i)
        {
            int st, k, x;
            scanf("%d:(%d)", &st, &k);
            while (k--)
            {
                scanf("%d", &x);
                insert(st + 1, x + 1);
                isroot[x + 1] = false;
            }
        }
        for (int i = 1; i <= n; ++i)
            if (isroot[i])
            {
                root = i;
                break;
            }
        memset(f, 0x7f, sizeof(f));
        dfs(root);
        printf("%d\n", min(f[root][0], f[root][1]));
    }
    return 0;
}
