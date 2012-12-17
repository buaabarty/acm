#include <iostream>
#include <cstdio>
#include <cstring>
#define N 256
using namespace std;
int num[N][N], res[N][N], n, d[N][N], cnt[N][N];
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int dist(int ax, int ay, int bx, int by)
{
    return iabs(ax - bx) + iabs(ay - by);
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &num[i][j]);
        memset(d, 0x7f, sizeof(d));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (num[i][j] != 0)
                    for (int x = 1; x <= n; ++x)
                        for (int y = 1; y <= n; ++y)
                            if (num[x][y] == 0)
                            {
                                int temp = dist(i, j, x, y);
                                if (temp < d[x][y])
                                {
                                    d[x][y] = temp;
                                    res[x][y] = num[i][j];
                                    cnt[x][y] = 1;
                                }
                                else if (temp == d[x][y])
                                {
                                    cnt[x][y]++;
                                }
                            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (num[i][j] != 0) printf("%d", num[i][j]);
                else if (cnt[i][j] == 1) printf("%d", res[i][j]);
                else printf("0");
                if (j < n) printf(" ");
                else printf("\n");
            }
    }
    return 0;
}
