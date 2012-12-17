#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 32768
#define MAXH 128
using namespace std;
struct point{
    int x, y;
}p[2][MAXN];
int w, h, n, d[2][MAXN];
int map[2][MAXH][MAXH];
void init()
{
    scanf("%d%d%d", &w, &h, &n);
    memset(map, 0, sizeof(map));
    for (int t = 0; t <= 1; ++t)
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &p[t][i].x, &p[t][i].y);
            map[t][++p[t][i].x][++p[t][i].y] = 1;
        }
}
int cal(int s, int x, int y)
{
    int sum = 1;
    for (int i = x - 1; map[s][i][y]; --i, ++sum);
    for (int i = x + 1; map[s][i][y]; ++i, ++sum);
    for (int i = y - 1; map[s][x][i]; --i, ++sum);
    for (int i = y + 1; map[s][x][i]; ++i, ++sum);
    return sum;
}
void deal(int s)
{
    for (int i = 1; i <= n; ++i)
        d[s][i] = cal(s, p[s][i].x, p[s][i].y);
}
int main()
{
    int __;
    scanf("%d", &__);
    while (__--)
    {
        init();
        for (int t = 0; t <= 1; ++t) deal(t);
        sort(d[0] + 1, d[0] + n + 1);
        sort(d[1] + 1, d[1] + n + 1);
        bool same = true;
        for (int i = 1; i <= n; ++i)
            if (d[0][i] != d[1][i])
            {
                same = false;
                break;
            }
        if (same) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
