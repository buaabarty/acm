#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 256
#define MAXM 65536
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
bool use[MAXN];
int match[MAXN], p[MAXN], eid, n, m, s;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
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
int x, y;
bool map[MAXN][MAXN];
bool init()
{
    memset(map, true, sizeof(map));
    scanf("%d%d%d", &n, &m, &s);
    if (n + m + s == 0) return false;
    memset(p, -1, sizeof(p));
    eid = 0;
    for (int i = 1; i <= s; ++i)
    {
        scanf("%d%d", &x, &y);
        map[x][y] = false;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (map[i][j]) insert(i, j);
    return true;
}

int main()
{
    int ca = 0;
    while (init())
    {
        printf("Case %d: %d\n",++ca, n + m - calc());
    }
}
