#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int n, x1, y1, z1, x2, y2, z2, x, y, z, d;
int main()
{
    while (~scanf("%d", &n), n)
    {
        x1 = y1 = z1 = -INT_MAX;
        x2 = y2 = z2 = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d%d", &x, &y, &z, &d);
            x1 = max(x1, x);
            y1 = max(y1, y);
            z1 = max(z1, z);
            x2 = min(x2, x + d);
            y2 = min(y2, y + d);
            z2 = min(z2, z + d);
        }
        if ((x1 >= x2) || (y1 >= y2) || (z1 >= z2)) printf("0\n");
        else printf("%d\n", (x2 - x1) * (y2 - y1) * (z2 - z1));
    }
    return 0;
}
