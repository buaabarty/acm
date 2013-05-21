#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
int main()
{
    int x, y, z, a, b, c;
    while (~scanf("%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c))
    {
        if (x > y) swap(x, y);
        if (x > z) swap(x, z);
        if (y > z) swap(y, z);
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        int step1 = 0, step2 = 0;
        while (!(x == y))
        {
            if (y - x >= z - y)
            {
                x = 2 * y - x;
                swap(x, y);
                swap(y, z);
            }
            else
            {
                z = 2 * y - z;
                swap(x, z);
                swap(y, z);
            }
            ++step1;
        }
        while (!(a == b))
        {
            if (b - a >= c - b)
            {
                a = 2 * b - a;
                swap(a, b);
                swap(b, c);
            }
            else
            {
                c = 2 * b - c;
                swap(a, c);
                swap(b, c);
            }
            ++step2;
        }
        printf("%d %d %d %d %d %d\n", x, y, z, a, b, c);
        if (x == a)
            printf("YES\n%d\n", iabs(step1 - step2));
        else
            printf("NO\n");
    }
    return 0;
}
