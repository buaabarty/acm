#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int w, x, y, a, b, nowh, maxw;
int main()
{
    while (scanf("%d", &w), w)
    {
        x = y = nowh = maxw = 0;
        while (scanf("%d%d", &a, &b), (a + b > 0))
        {
            if (x + a <= w)
            {
                x += a;
                nowh = max(nowh, b);
            }
            else
            {
                x = a;
                y += nowh;
                nowh = b;
            }
            maxw = max(maxw, x);
        }
        y += nowh;
        printf("%d x %d\n", maxw, y);
    }
    return 0;
}
