#include <iostream>
#include <cstdio>
#include <cstring>
#define M 10000
#define N 2010
using namespace std;
struct edge
{
    int v, next;
}e[M];
int p[N], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert1(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
int n, x;
int dfs(int v)
{
    int now = 0;
    for (int i = p[v]; i != -1; i = e[i].next)
        now = max(now, dfs(e[i].v));
    return now + 1;
}
int main()
{
    mapinit();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        if (x > 0) insert1(x, i);
        else insert1(n + 1, i);
    }
    printf("%d\n", dfs(n + 1) - 1);
    return 0;
}
