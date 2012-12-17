#include <iostream>
#include <cstdio>
#include <cstring>
#define N 128
#define M 65536
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
int color[N], n;
char str[N];
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d: ", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("%d ", e[j].v);
        puts("");
    }
}
bool dfs(int v, int limit)
{
    if (v == n + 1) return true;
    bool f[5];
    memset(f, 1, sizeof(f));
    for (int i = p[v]; i != -1; i = e[i].next)
        f[color[e[i].v]] = 0;
    for (int i = 1; i <= limit; ++i)
        if (f[i])
        {
            color[v] = i;
            if (dfs(v + 1, limit)) return true;
            color[v] = 0;
        }
    return false;
}
bool okay(int cnt)
{
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; ++i)
        if (!color[i])
        {
            if (!dfs(i, cnt)) return false;
        }
    return true;
}
int main()
{
    while (scanf("%d", &n), n)
    {
        mapinit();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", str);
            int st = str[0] - 'A' + 1;
            for (int j = 2; str[j]; ++j)
                insert(st, str[j] - 'A' + 1);
        }
        n = 26;
        for (int i = 1; i; ++i)
            if (okay(i))
            {
                if (i == 1) printf("%d channel needed.\n", i);
                else printf("%d channels needed.\n", i);
                break;
            }
    }
    return 0;
}
