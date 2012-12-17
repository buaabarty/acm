#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 512
#define MAXM 65536
using namespace std;
typedef struct edge{
    int v, next;
}EDGE;
EDGE e[MAXM];
int p[MAXN], eid, n, m;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
bool use[MAXN];
int link[MAXN];
bool dfs(int v)
{
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        int a = e[i].v;
        if (!use[a])
        {
            use[a] = true;
            if (link[a] == -1 || dfs(link[a]))
            {
                link[a] = v;
                return true;
            }
        }
    }
    return false;
}

bool solve()
{
    memset(link, -1, sizeof(link));
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(use, false, sizeof(use));
        if (!dfs(i)) return false;
    }
    return true;
}

int main()
{
    int t, k, x;
    scanf("%d", &t);
    while (t--)
    {
        memset(p, -1, sizeof(p));
        eid = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &k);
            while (k--)
            {
                scanf("%d", &x);
                insert(i, x);
            }
        }
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
