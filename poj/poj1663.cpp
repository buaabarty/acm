#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int x, y, n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &x, &y);
            if (x == y)
            {
                if (x % 2 == 0) printf("%d\n", x * 2);
                else printf("%d\n", x * 2 - 1);
            }
            else if (x == y + 2)
            {
                if (x % 2 == 0) printf("%d\n", 2 * (x - 1));
                else printf("%d\n", 2 * (x - 2) + 1);
            }
            else printf("No Number\n");
        }
    return 0;
}
