#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 10010
#define MAXM 100010
using namespace std;
struct edge{
    int v, next;
    bool use;
}e[MAXM];
int p[MAXN], eid, n, m;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    e[eid].use = false;
    p[x] = eid++;
}
void dfs(int v)
{
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!e[i].use){
            e[i].use = true;
            dfs(e[i].v);
            printf("%d\n", e[i].v);
        }
}
int main()
{
    int x, y;
    scanf("%d%d", &n, &m);
    memset(p, -1, sizeof(p));
    eid = 0;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        insert(x, y);
        insert(y, x);
    }
    dfs(1);
    printf("1\n");
    return 0;
}
