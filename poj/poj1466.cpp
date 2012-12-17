#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 512
#define MAXM 262144
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
int eid, p[MAXN];
void einit()
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
int n;
bool init()
{
    einit();
    int k, x;
    if (scanf("%d", &n) == EOF) return false;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d: (%d)", &k, &k);
        for (int j = 1; j <= k; ++j)
        {
            scanf("%d", &x);
            insert(i, x + 1);
        }
    }
    return true;
}
bool use[MAXN];
int link[MAXN];
bool dfs(int v)
{
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        int u = e[i].v;
        if (!use[u])
        {
            use[u] = true;
            if (link[u] == -1 || dfs(link[u]))
            {
                link[u] = v;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int cnt = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= n; ++i)
    {
        memset(use, false, sizeof(use));
        if (dfs(i)) cnt++;
    }
    return cnt;
}
int main()
{
    while (init())
    {
        cout << n - hungary() / 2 << endl;
    }
    return 0;
}
