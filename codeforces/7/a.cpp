#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[10];
int r[8], c[8], rc, cc;
int main()
{
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 8; ++i)
    {
        scanf("%s", str);
        for (int j = 0; j < 8; ++j)
            if (str[j] == 'B')
            {
                r[i]++;
                c[j]++;
            }
    }
    rc = 0, cc = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (r[i] == 8) rc++;
        if (c[i] == 8) cc++;
    }
    if ((rc == 8) || (cc == 8)) printf("8\n");
    else printf("%d\n", rc + cc);
    return 0;
}
