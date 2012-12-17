#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1200
using namespace std;
int c[N][N], n;
int lowbit(int x)
{
    return x & (x ^ (x - 1));
}
bool insert(int x, int y, int delta)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= n; j += lowbit(j))
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

int main()
{
    int q, x, y, a, l, b, r, t;
    while (~scanf("%d", &q), (q != 3))
    {
        if (q == 0)
        {
            scanf("%d", &n);
            memset(c, 0, sizeof(c));
        }
        else if (q == 1)
        {
            scanf("%d%d%d", &x, &y, &a);
            insert(++x, ++y, a);
        }
        else if (q == 2)
        {
            scanf("%d%d%d%d", &l, &b, &r, &t);
            printf("%d\n", getsum(++l, ++b, ++r, ++t));
        }
    }
    return 0;
}
