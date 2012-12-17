#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool vst[100][100];
int n, dat[100][100];
bool usd[100];
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y)
{
    vst[x][y] = 1;
    for (int k = 0; k < 4; ++k)
    {
        int dx = x + step[k][0];
        int dy = y + step[k][1];
        if ((dx >= 1) && (dx <= n) && (dy >= 1) && (dy <= n))
        {
            if (!vst[dx][dy] && (dat[dx][dy] == dat[x][y]))
            {
                dfs(dx, dy);
            }
        }
    }
}
int main()
{
    while (scanf("%d", &n), n)
    {
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i < n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                int x, y;
                scanf("%d%d", &x, &y);
                dat[x][y] = i;
            }
        memset(vst, 0, sizeof(vst));
        memset(usd, 0, sizeof(usd));
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (!vst[i][j])
                {
                    ++cnt;
                    dfs(i, j);
                }
        if (cnt != n) printf("wrong\n");
        else printf("good\n");
    }
    return 0;
}
