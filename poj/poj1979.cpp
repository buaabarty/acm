#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 128
using namespace std;
int n, m, res = 0, sx, sy, d[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
bool vst[MAXN][MAXN];
int dat[MAXN][MAXN];
bool init()
{
    memset(vst, false, sizeof(vst));
    char x;
    cin >> m >> n;
    if (n + m == 0) return false;
    for (int i = 0; i <= n + 1; ++i)
    {
        vst[i][0] = true;
        vst[i][m + 1] = true;
    }
    for (int i = 0; i <= m + 1; ++i)
    {
        vst[0][i] = true;
        vst[n + 1][i] = true;
    }
    memset(dat, 0, sizeof(dat));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> x;
            if (x == '.') dat[i][j] = 1;
            else if (x == '#')
            {
                dat[i][j] = 2;
                vst[i][j] = true;
            }
            else if (x == '@')
            {
                dat[i][j] = 3;
                sx = i;
                sy = j;
            }
        }
    res = 0;
    return true;
}
bool fill(int x, int y)
{
    vst[x][y] = true;
    for (int k = 0; k < 4; ++k)
    {
        int dx = x + d[k][0], dy = y + d[k][1];
        if (!vst[dx][dy]) fill(dx, dy);
    }
}
int main()
{
    while (init())
    {
        fill(sx, sy);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (dat[i][j] == 1 && vst[i][j]) res++;
        cout << res + 1 << endl;
    }
    return 0;
}
