#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define INF 1000000000
#define N 500
using namespace std;
int dat[N][N], vst[N][N], lx[N][N], ly[N][N], step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char str[N+10];
int n, m, sx, sy, res = 0;
bool dfs(int x, int y)
{
    int nx = ((x % n) + n) % n;
    int ny = ((y % m) + m) % m;
    if (dat[nx][ny] < 0) return false;
    if (!vst[nx][ny])
    {
        vst[nx][ny] = 1;
        lx[nx][ny] = x;
        ly[nx][ny] = y;
        res = res + dat[nx][ny];
    }
    else if ((lx[nx][ny] != x) || (ly[nx][ny] != y)) return true;
    else return false;
    for (int i = 0; i < 4; ++i)
        if (dfs(x + step[i][0], y + step[i][1])) return true;
    return false;
}
int main()
{
    int q;
    //freopen("maze.in", "r", stdin);
    //freopen("maze.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", str);
        for (int j = 0; j < m; ++j)
        {
            if (str[j] == '#') dat[i][j] = -1;
            else dat[i][j] = str[j] - '0';
        }
    }
    scanf("%d", &q);
    while (q--)
    {
        memset(vst, 0, sizeof(vst));
        memset(lx, 0, sizeof(lx));
        memset(ly, 0, sizeof(ly));
        scanf("%d%d", &sx, &sy);
        sx %= n;
        sy %= m;
        res = 0;
        if (dfs(sx, sy)) printf("inf\n");
        else printf("%d\n", res);
    }
    return 0;
}
