#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n, x, y;
    while (~scanf("%d", &n))
    {
        x = n / 4;
        if (n % 4) x++;
        y = (2 * n) / 7;
        if (x <= y)
        {
            int d = y;
            x = 2 * n - 7 * d;
            y = 4 * d - n;
            for (int i = 1; i <= x; ++i)
                putchar('4');
            for (int i = 1; i <= y; ++i)
                putchar('7');
            puts("");
        }
        else puts("-1");
    }
    return 0;
}
