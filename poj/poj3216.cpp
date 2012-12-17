#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#define N 256
#define M 1048576
using namespace std;
struct edge
{
    int v, next;
}e[M];
int n, p[N], eid;
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
bool use[N];
int match[N];
bool hungary(int v)
{
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        int u = e[i].v;
        if (!use[u])
        {
            use[u] = true;
            int temp = match[u];
            match[u] = v;
            if (temp == 0 || hungary(temp)) return true;
            match[u] = temp;
        }
    }
    return false;
}
int calc()
{
    memset(match, 0, sizeof(match));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(use, false, sizeof(use));
        if (hungary(i)) cnt++;
    }
    return cnt;
}
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d: ", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("%d  ", e[j].v);
        puts("");
    }
}
int a[N], b[N], c[N], m, map[N][N];
int main()
{
    while (scanf("%d%d", &n, &m), (n + m))
    {
        mapinit();
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &map[i][j]);
                if (map[i][j] == -1) map[i][j] = INT_MAX / 2;
            }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
        for (int i = 1; i <= m; ++i)
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j) if (i != j)
                if (b[i] + c[i] + map[a[i]][a[j]] <= b[j]) insert(i, j);
        n = m;
        printf("%d\n", m - calc());
    }
    return 0;
}
