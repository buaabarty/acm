#include <stdio.h>
int b, c, a, t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d/%d/%d", &a, &b, &c);
        printf("%02d/%02d/%04d", b, c, a);
        scanf("-%d:%d:%d", &a, &b, &c);
        printf("-%02d:%02d:%02d", ((a + 11) % 12) + 1, b, c);
        if (a < 12) printf("am\n");
        else printf("pm\n");
    }
    return 0;
}
