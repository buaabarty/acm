#include <iostream>
#include <cstdio>
#include <cstring>
#define N 2000
#define M 10000
using namespace std;
struct edge
{
    int v, next;
}e[M];
int p[N], eid, n, m;
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
            printf("%d ", e[j].v);
        puts("");
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    mapinit();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (i > 0) insert(i * m + j + 1, (i - 1) * m + j + 1);
            if (i < n - 1) insert(i * m + j + 1, (i + 1) * m + j + 1);
            if (j > 0) insert(i * m + j + 1, i * m + (j - 1) + 1);
            if (j < m - 1) insert(i * m + j + 1, i * m + (j + 1) + 1);
            insert(i * m + j + 1, i * m + j + 1);
        }
    n = n * m;
    print_map();
    printf("%d\n", n - calc());
    return 0;
}
