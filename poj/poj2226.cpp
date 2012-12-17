#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 2500
#define MAXM 32768
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
int p[MAXN], eid, n;
bool use[MAXN];
int match[MAXN];
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
int co[MAXN][MAXN];
int main()
{
    int r, c, last = 0, cnt = 0, lcnt, a[64][64], b[64][64], dat[64][64];
    memset(p, -1, sizeof(p));
    eid = 0;
    char x;
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; ++i)
    {
        scanf("%c", &x);
        last = 0;
        for (int j = 1; j <= c; ++j)
        {
           scanf("%c", &x);
           dat[i][j] = x;
           if (x == '*')
           {
               if (!last) ++cnt;
               a[i][j] = cnt;
               last = 1;
           }
           else last = 0;
        }
    }
    lcnt = cnt;
    cnt = 0;
    for (int i = 1; i <= c; ++i)
    {
        last = 0;
        for (int j = 1; j <= r; ++j)
        {
           if (dat[j][i] == '*')
           {
               if (!last) ++cnt;
               b[j][i] = cnt;
               last = 1;
           }
           else last = 0;
        }
    }
    n = max(cnt, lcnt);
    memset(co, false, sizeof(co));
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            co[a[i][j]][b[i][j]] = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (co[i][j]) insert(i, j);
    printf("%d\n", calc());
    return 0;
}
