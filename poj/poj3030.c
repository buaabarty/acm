#include <stdio.h>
int main()
{
    int r, e, c, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &r, &e, &c);
        if (r < (e - c)) puts("advertise");
        else if (r == (e - c)) puts("does not matter");
        else puts("do not advertise");
    }
    return 0;
}
