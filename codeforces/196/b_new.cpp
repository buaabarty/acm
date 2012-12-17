#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int dat[1500][1500], vst[1500][1500], lx[1500][1500], ly[1500][1500], step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char str[1600];
bool f[2];
int n, m, sx, sy, res = 0;
bool dfs(int x, int y)
{
    int nx = ((x % n) + n) % n;
    int ny = ((y % m) + m) % m;
    if (!dat[nx][ny]) return false;
    if (!vst[nx][ny])
    {
        vst[nx][ny] = 1;
        lx[nx][ny] = x;
        ly[nx][ny] = y;
    }
    else if ((lx[nx][ny] != x) || (ly[nx][ny] != y)) return true;
    else return false;
    for (int i = 0; i < 4; ++i)
        if (dfs(x + step[i][0], y + step[i][1])) return true;
    return false;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", str);
        for (int j = 0; j < m; ++j)
        {
            dat[i][j] = (str[j] != '#');
            if (str[j] == 'S')
            {
                sx = i;
                sy = j;
            }
        }
    }
    if (dfs(sx, sy)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
