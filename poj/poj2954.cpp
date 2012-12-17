#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int gcd(int x, int y)
{
    return (x) ? gcd(y % x, x) : y;
}
int count(int x1, int y1, int x2, int y2)
{
    int a = max(x1, x2) - min(x1, x2);
    int b = max(y1, y2) - min(y1, y2);
    return gcd(a, b) + 1;
}
int x1, y1, x2, y2, x3, y3;
int main()
{
    while (~scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3))
    {
        if ((x1 == 0) && (x2 == 0) && (x3 == 0) && (y1 == 0) && (y2 == 0) && (y3 == 0)) break;
        int s = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        if (s < 0) s = -s; s += 2;
        s -= count(x1, y1, x2, y2) + count(x2, y2, x3, y3) + count(x1, y1, x3, y3) - 3;
        s /= 2;
        printf("%d\n", s);
    }
    return 0;
}
