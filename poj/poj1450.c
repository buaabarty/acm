#include <stdio.h>
int t, x, y, ca;
main()
{
    scanf("%d", &t);
    for (ca = 1; ca <= t; ++ca)
    {
        scanf("%d%d", &x, &y);
        printf("Scenario #%d:\n", ca);
        printf("%d.", x * y);
        if ((x & 1) && (y & 1)) puts("41\n");
        else puts("00\n");
    }
}
