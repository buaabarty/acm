#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXM 32768
#define MAXN 1024
using namespace std;
struct edge{
    int x, y, d;
}e[MAXM];
bool operator < (const edge a, const edge b)
{
    return a.d < b.d;
}
int n, m, eid = 0;
void insert(int x, int y, int d)
{
    eid++;
    e[eid].x = x;
    e[eid].y = y;
    e[eid].d = d;
}
int fa[MAXN];
int father(int v)
{
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
bool res[MAXM];
int main()
{
    int x, y, d;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &x, &y, &d);
        insert(x, y, d);
    }
    for (int i = 1; i <= n; ++i) fa[i] = i;
    sort(e + 1, e + m + 1);
    int mx = 0;
    memset(res, false, sizeof(res));
    for (int i = 1; i <= m; ++i)
    {
        int fx = father(e[i].x), fy = father(e[i].y);
        if (fx != fy){
            fa[fx] = fy;
            mx = e[i].d;
            res[i] = true;
        }
    }
    printf("%d\n%d\n", mx, n - 1);
    for (int i = 1; i <= m; ++i)
        if (res[i]) printf("%d %d\n", e[i].x, e[i].y);
    printf("\n");
    return 0;
}
