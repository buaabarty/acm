#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1010][32768];
char line[32768];
int main()
{
    int cnt = 0, mlen = 0;
    while (gets(line) != NULL)
    {
        strcpy(str[++cnt], line);
        mlen = max(mlen, (int)strlen(str[cnt]));
    }
    for (int i = 1; i <= mlen + 2; ++i)
        printf("*");
    puts("");
    int now = 1;
    for (int i = 1; i <= cnt; ++i)
    {
        printf("*");
        int len = strlen(str[i]);
        int left = (mlen - len) / 2;
        int right = (mlen - len) / 2;
        if ((mlen - len) & 1)
        {
            if (now & 1) right++;
            else left++;
            now = 1 - now;
        }
        for (int j = 1; j <= left; ++j)
            printf(" ");
        printf("%s", str[i]);
        for (int j = 1; j <= right; ++j)
            printf(" ");
        printf("*\n");
    }
    for (int i = 1; i <= mlen + 2; ++i)
        printf("*");
    puts("");
    return 0;
}
