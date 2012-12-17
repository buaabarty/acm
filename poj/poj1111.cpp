#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 32
using namespace std;
int dat[MAXN][MAXN];
bool f[MAXN][MAXN];
int n, m;
bool inside(int x, int y)
{
    return (x >= 1) && (y >= 1) && (x <= n) && (y <= m);
}
void dfs(int x, int y)
{
    f[x][y] = true;
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            if (i || j){
                int dx = x + i, dy = y + j;
                if (!f[dx][dy] && dat[dx][dy] && inside(dx, dy)) dfs(dx, dy);
            }
}
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int getit(int x, int y)
{
    int s = 4;
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            if ((i || j) && (iabs(i) != iabs(j))){
                int dx = x + i, dy = y + j;
                if (inside(dx, dy) && dat[dx][dy]) s--;
            }
    return s;
}
int x, y;
bool init()
{
    memset(dat, 0, sizeof(dat));
    scanf("%d%d%d%d", &n, &m, &x, &y);
    if (!(n + m + x + y)) return false;
    for (int i = 1; i <= n; ++i)
    {
        scanf("\n");
        char c;
        for (int j = 1; j <= m; ++j)
        {
            scanf("%c", &c);
            if (c == 'X') dat[i][j] = 1;
            else dat[i][j] = 0;
        }
    }
    return true;
}
int main()
{
    while (init())
    {
        memset(f, false, sizeof(f));
        dfs(x, y);
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (f[i][j])
                    res += getit(i, j);
        printf("%d\n", res);
    }
    return 0;
}
