#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int destx, desty, n, map[1024][1024], d[1024][1024];
int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
class point{
    public:
        int x, y;
        point(int a, int b)
        {
            x = a, y = b;
        }
};
bool inside(int x, int y)
{
    return (x >= 0) && (y >= 0) && (x <= 1002) && (y <= 1002);
}
int main()
{
    int x, y;
    memset(map, 0, sizeof(map));
    memset(d, 0x7f, sizeof(d));
    scanf("%d%d%d", &destx, &desty, &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &x, &y);
        map[x + 501][y + 501] = 1;
    }
    queue<point> q;
    q.push(point(501, 501));
    d[501][501] = 0;
    destx += 501, desty += 501;
    bool find = false;
    while (!q.empty())
    {
        point now = q.front();
        int nowx = now.x, nowy = now.y;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int kx = nowx + step[i][0], ky = nowy + step[i][1];
            if (inside(kx, ky) && (!map[kx][ky])){
                if (d[nowx][nowy] + 1 < d[kx][ky]){
                    d[kx][ky] = d[nowx][nowy] + 1;
                    q.push(point(kx, ky));
                    if ((kx == destx) && (ky == desty)) find = true;
                }
            }
        }
        if (find) break;
    }
    printf("%d\n", d[destx][desty]);
    return 0;
}
