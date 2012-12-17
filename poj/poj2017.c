#include <stdio.h>
int main()
{
    int n, last, sum, x, y;
    while (scanf("%d",&n))
    {
        if (n == -1) break;
        last = sum = 0;
        while (n--)
        {
            scanf("%d%d", &x, &y);
            sum += x * (y - last);
            last = y;
        }
        printf("%d miles\n", sum);
    }
}
