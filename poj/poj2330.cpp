#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 64
#define MAXD 1024
using namespace std;
int n, m, w, h, t, x, y;
int a[MAXN][MAXN];
char res[MAXD][MAXD];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        w = 4 * m + 2 * n + 1;
        h = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &a[i][j]);
                h = max((n - i) * 2 + 3 + a[i][j] * 3, h);
            }
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                res[i][j] = '.';
        for (int i = n; i >= 1; --i)
            for (int j = 1; j <= m; ++j)
                for (int hh = 1; hh <= a[n - i + 1][j]; ++hh)
                {
                    x = h - ((i - 1) * 2 + (hh - 1) * 3);
                    y = (j - 1) * 4 + (i - 1) * 2 + 1;
                    res[x][y] = '+';
                    res[x-1][y] = '|';
                    res[x-2][y] = '|';
                    res[x-3][y] = '+';
                    res[x-3][y+1] = '-';
                    res[x-3][y+2] = '-';
                    res[x-3][y+3] = '-';
                    res[x-3][y+4] = '+';
                    res[x][y+1] = '-';
                    res[x][y+2] = '-';
                    res[x][y+3] = '-';
                    res[x][y+4] = '+';
                    res[x-1][y+4] = '|';
                    res[x-2][y+4] = '|';
                    res[x-1][y+5] = '/';
                    res[x-2][y+6] = '+';
                    res[x-3][y+6] = '|';
                    res[x-4][y+6] = '|';
                    res[x-5][y+6] = '+';
                    res[x-4][y+1] = '/';
                    res[x-4][y+5] = '/';
                    res[x-5][y+2] = '+';
                    res[x-5][y+3] = '-';
                    res[x-5][y+4] = '-';
                    res[x-5][y+5] = '-';
                    res[x-1][y+1] = ' ';
                    res[x-2][y+1] = ' ';
                    res[x-1][y+2] = ' ';
                    res[x-2][y+2] = ' ';
                    res[x-1][y+3] = ' ';
                    res[x-2][y+3] = ' ';
                    res[x-2][y+5] = ' ';
                    res[x-3][y+5] = ' ';
                    res[x-4][y+2] = ' ';
                    res[x-4][y+3] = ' ';
                    res[x-4][y+4] = ' ';
                }
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= w; ++j)
                printf("%c", res[i][j]);
            printf("\n");
        }
    }
    return 0;
}
