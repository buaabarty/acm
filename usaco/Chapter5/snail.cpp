/*
ID:ybojan2
LANG:C++
TASK:snail
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 128
using namespace std;
int n, b;
bool map[MAXN][MAXN], ooxx[MAXN][MAXN];
int d[MAXN][MAXN];
int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, dir;
void dfs(int x, int y, int deep, int dir)
{
    d[x][y] = max(d[x][y], deep);
    if (!map[x + step[dir][0]][y + step[dir][1]])
    {
        if (ooxx[x + step[dir][0]][y + step[dir][1]]) return;
        for (int k = 0; k < 4; ++k)
            if (map[x + step[k][0]][y + step[k][1]]){
                //if (deep + 1 > d[x + step[k][0]][y + step[k][1]])
                {
                    map[x + step[k][0]][y + step[k][1]] = false;
                    dfs(x + step[k][0], y + step[k][1], deep + 1, k);
                    map[x + step[k][0]][y + step[k][1]] = true;
                }
            }
    }
    else //if (deep + 1 > d[x + step[dir][0]][y + step[dir][1]])
    {
        map[x + step[dir][0]][y + step[dir][1]] = false;
        dfs(x + step[dir][0], y + step[dir][1], deep + 1, dir);
        map[x + step[dir][0]][y + step[dir][1]] = true;
    }
}
int main()
{
    freopen("snail.in", "r", stdin);
    freopen("snail.out", "w", stdout);
    char c;
    int x, y;
    scanf("%d%d", &n, &b);
    memset(map, false, sizeof(map));
    memset(ooxx, false, sizeof(ooxx));
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) ooxx[i][j] = map[i][j] = true;
    for (int i = 1; i <= b; ++i)
    {
        scanf("\n%c%d", &c, &y);
        x = c - 'A' + 1;
        ooxx[y][x] = map[y][x] = false;
    }
    map[1][1] = false;
    dfs(1, 1, 1, 1);
    dfs(1, 1, 1, 0);
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            res = max(res, d[i][j]);
    printf("%d\n", res);
    return 0;
}
