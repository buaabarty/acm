#include <iostream>
#include <cstdio>
#include <cstring>
#define N 128
using namespace std;
int c[N][N], n, W, H;
int lowbit(int x)
{
    return x & (x ^ (x - 1));
}
bool insert(int x, int y, int delta = 1)
{
    for (int i = x; i <= W; i += lowbit(i))
        for (int j = y; j <= H; j += lowbit(j))
            c[i][j] += delta;
    return true;
}
int getsum(int x, int y)
{
    int s = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            s += c[i][j];
    return s;
}
int getsum(int x1, int y1, int x2, int y2)
{
    return getsum(x2, y2) - getsum(x1 - 1, y2) - getsum(x2, y1 - 1) + getsum(x1 - 1, y1 - 1);
}
int x, y, w, h;
int main()
{
    while (scanf("%d",  &n), n)
    {
        scanf("%d%d", &W, &H);
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &x, &y);
            insert(x, y);
        }
        scanf("%d%d", &w, &h);
        int res = 0;
        for (int i = 1; i + w - 1 <= W; ++i)
            for (int j = 1; j + h - 1 <= H; ++j)
                res = max(res, getsum(i, j, i + w - 1, j + h - 1));
        printf("%d\n", res);
    }
    return 0;
}
