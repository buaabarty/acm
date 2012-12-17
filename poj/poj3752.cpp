#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1024
using namespace std;
int dat[N][N], step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main()
{
    int n, m;
    while  (~scanf("%d%d", &n, &m))
    {
        memset(dat, -1, sizeof(dat));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dat[i][j] = 0;
        int x = 1, y = 1, dir = 0, now = 2;
        dat[1][1] = 1;
        for (int i = 1; i < n * m; ++i)
        {
            //printf("%d %d\n", x, y);
            int dx = x + step[dir][0];
            int dy = y + step[dir][1];
            if (dat[dx][dy] != 0)
            {
                dir = (dir + 1) % 4;
                dx = x + step[dir][0];
                dy = y + step[dir][1];
            }
            x = dx, y = dy;
            dat[x][y] = now++;
            if (now > 26) now = 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                printf("   %c", dat[i][j] + 'A' - 1);
            puts("");
        }
    }
    return 0;
}
