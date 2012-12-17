#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#define N 2048
#define S 64
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
char str[S];
int dat[S][S], step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
    int T, m; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        mapinit();
        memset(dat, 0, sizeof(dat));
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", str);
            for (int j = 1; j <= m; ++j)
            {
                dat[i][j] = (str[j - 1] == '*');
                if (dat[i][j]) ++cnt;
            }
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (((i + j) & 1) && dat[i][j])
                    for (int k = 0; k < 4; ++k)
                    {
                        int dx = i + step[k][0];
                        int dy = j + step[k][1];
                        if (dat[dx][dy]) insert((i - 1) * m + j, (dx - 1) * m + dy);
                    }
        n = n * m;
        printf("%d\n", cnt - calc());
    }
    return 0;
}
