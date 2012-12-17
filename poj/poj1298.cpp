#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1000010];
int main()
{
    while (gets(str))
    {
        if (strcmp(str, "ENDOFINPUT") == 0) break;
        gets(str);
        for (int i = 0; str[i]; ++i)
            if (str[i] >= 'A' && str[i] <= 'Z') putchar('A' + (str[i] - 'A' + 'V' - 'A') % 26);
            else putchar(str[i]);
        puts("");
        gets(str);
    }
    return 0;
}

