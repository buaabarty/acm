#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 128
using namespace std;
int n, m, res = 0, d[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
bool vst[MAXN][MAXN];
bool init()
{
    memset(vst, false, sizeof(vst));
    char x;
    cin >> n >> m;
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
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> x;
            vst[i][j] = (x == '*');
        }
    res = 0;
    return true;
}
bool fill(int x, int y)
{
    vst[x][y] = true;
    for (int k = 0; k < 8; ++k)
    {
        int dx = x + d[k][0], dy = y + d[k][1];
        if (!vst[dx][dy]) fill(dx, dy);
    }
}
int main()
{
    while (init())
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (!vst[i][j])
                {
                    ++res;
                    fill(i, j);
                }
        cout << res << endl;
    }
    return 0;
}
