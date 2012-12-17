#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#define N 1024
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
int a[N], b[N], x, y, cnt, ta, tb;
int main()
{
    cnt = 0;
    mapinit();
    while (scanf("%d%d", &x, &y), (x + y >= 0))
    {
        if ((x == 0) && (y == 0))
        {
            for (int i = 1; i <= cnt; ++i)
                for (int j = 1; j <= cnt; ++j) if (i != j)
                    if ((a[i] <= a[j]) && (b[i] <= b[j])) insert(i, j);
            n = cnt;
            printf("%d\n", n - calc());
            mapinit();
            cnt = 0;
        }
        else
        {
            a[++cnt] = x;
            b[cnt] = y;
        }
    }
    return 0;
}
