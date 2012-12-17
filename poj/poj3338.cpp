#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 32
using namespace std;
int w, h, n, x1, y1, x2, y2;
int map[MAXN][MAXN];
bool init()
{
    scanf("%d%d", &w, &h);
    if (w + h == 0) return false;
    scanf("%d", &n);
    memset(map, 0, sizeof(map));
    for (int i = 1; i <= w; ++i)
    {
        map[1][i] = map[1][i] | 4;
        map[h][i] = map[h][i] | 8;
    }
    for (int i = 1; i <= h; ++i)
    {
        map[i][1] = map[i][1] | 1;
        map[i][w] = map[i][w] | 2;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        x1++, y1++;
        for (int i = x1; i <= x2; ++i)
        {
            map[i][y1] = map[i][y1] | 1;
            map[i][y1 - 1] = map[i][y1 - 1] | 2;
            map[i][y2] = map[i][y2] | 2;
            map[i][y2 + 1] = map[i][y2 + 1] | 1;
        }
        for (int i = y1; i <= y2; ++i)
        {
            map[x1][i] = map[x1][i] | 4;
            map[x1 - 1][i] = map[x1 - 1][i] | 8;
            map[x2][i] = map[x2][i] | 8;
            map[x2 + 1][i] = map[x2 + 1][i] | 4;
        }
    }
    return true;
}
int f[MAXN][MAXN], res, step[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
void dfs(int x, int y, int color)
{
    f[x][y] = color;
    for (int k = 0; k < 4; ++k)
        if (((map[x][y] & (1 << k)) == 0) && (f[x + step[k][0]][y + step[k][1]] == 0)) dfs(x + step[k][0], y + step[k][1], color);
}
int main()
{

    while (init())
    {
        res = 0;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                if (f[i][j] == 0) dfs(i, j, ++res);
        printf("%d\n", res);
    }
    return 0;
}
