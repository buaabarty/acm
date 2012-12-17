#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, tsx, tsy, sx, sy;
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool dat[3010][3010];
char str[3010];
bool vst[3010][3010];
class point
{
public:
    int x, y;
    point(int _x, int _y)
    {
        x = _x, y = _y;
    }
    point(){}
}q[3000*3000+10];
int l, r;
int gethash(int x, int y)
{
    int a = (x - 1) / (n / 2);
    int b = (y - 1) / (m / 2);
    return a * 100 + b;
}
int main()
{
    scanf("%d%d", &n, &m);
    memset(dat, 0, sizeof(dat));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", str);
        for (int j = 1; j <= m; ++j)
        {
            dat[i][j] = (str[j - 1] != '#');
            if (str[j - 1] == 'S')
            {
                tsx = i;
                tsy = j;
            }
        }
    }

    for (int i = 1; i <= n * 2; ++i)
        for (int j = 1; j <= m * 2; ++j)
        {
            int ri = i;
            if (ri > n) ri -= n;
            int rj = j;
            if (rj > m) rj -= m;
            dat[i][j] = dat[ri][rj];
        }
    n *= 2;
    m *= 2;
        /*for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= m; ++j)
                    printf("%d", dat[i][j]);
                puts("");
            }*/
    bool flag = false;
    for (int ax = 0; ax <= 1; ++ax)
        for (int ay = 0; ay <= 1; ++ay)
        {
            sx = tsx + ax * (n / 2);
            sy = tsy + ay * (n / 2);

            memset(vst, 0, sizeof(vst));
            q[1] = point(sx, sy);
            vst[sx][sy] = gethash(sx, sy);
            l = 1, r = 1;
            while (l <= r)
            {
                point now = q[l++];
                //printf("%d %d\n", now.x, now.y);
                for (int i = 0; i < 4; ++i)
                {
                    int rx = now.x + step[i][0];
                    int ry = now.y + step[i][1];
                    int area = gethash(rx, ry);
                    int dx = (rx % (n / 2));
                    int dy = (ry % (m / 2));
                    if (dx == 0) dx = n / 2;
                    if (dy == 0) dy = m / 2;
                    if (!vst[dx][dy])
                    {
                        vst[dx][dy] = 1;
                        q[++r] = point(dx, dy);
                    }
                    else if (vst[dx][dy] != area)
                    {
                        printf("Yes\n");
                        return 0;
                    }
                }
            }
            /*puts("\n");
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= m; ++j)
                    printf("%d", vst[i][j]);
                puts("");
            }*/
        }
    printf("No\n");
    return 0;
}
