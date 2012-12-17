#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1024
#define K 100010
using namespace std;
int n, m, dat[N][N], sum[N][N], step[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dir[K], len[K], k, sx[26], sy[26];
bool f[26];
char str[N];
int getsum(int x1, int y1, int x2, int y2)
{
    if (x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    if ((x1 == x2) && (y1 > y2)) swap(y1, y2);
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int dd(char c)
{
    switch (c)
    {
        case 'N': return 0; break;
        case 'S': return 1; break;
        case 'W': return 2; break;
        case 'E': return 3; break;
    }
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(sum, 0, sizeof(sum));
        memset(f, false, sizeof(f));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", str);
            for (int j = 1; j <= m; ++j)
            {
                dat[i][j] = (str[j - 1] == '.');
                if ((str[j - 1] >= 'A') && (str[j - 1] <= 'Z'))
                {
                    dat[i][j] = 1;
                    sx[str[j - 1] - 'A'] = i;
                    sy[str[j - 1] - 'A'] = j;
                    f[str[j - 1] - 'A'] = true;
                }
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + dat[i][j];
            }
        }
        scanf("%d", &k);
        for (int i = 1; i <=k; ++i)
        {
            scanf("%s%d", str, &len[i]);
            dir[i] = dd(str[0]);
//            printf("%d\n", dir[i]);
        }
        bool find = false;
        for (int i = 0; i < 26; ++i)
            if (f[i])
            {
                bool flag = true;
                int nowx = sx[i], nowy = sy[i];
                for (int j = 1; j <= k; ++j)
                {
                    int dx = nowx + step[dir[j]][0] * len[j];
                    int dy = nowy + step[dir[j]][1] * len[j];
      //              printf("%d %d %d %d\n", nowx, nowy, dx, dy);
                    if ((dx < 1) || (dx > n) || (dy < 1) || (dy > m))
                    {
                        flag = false; break;
                    }
                    int s = getsum(nowx, nowy, dx, dy);
    //                printf("    %d\n", s);
                    if (s != (len[j] + 1))
                    {
                        flag = false; break;
                    }
                    nowx = dx, nowy = dy;
                }
  //              printf("IMG%d\n", flag);
                if (flag) { printf("%c", i + 'A'); find = true; }
            }
        if (find) puts("");
        else puts("no solution");
    }
    return 0;
}
