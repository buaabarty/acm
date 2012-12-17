#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cctype>
#define MAXL 256
using namespace std;
char str[MAXL];
char change(char x)
{
    return (x - 'A' + 21) % 26 + 'A';
}
int main()
{
    while (gets(str))
    {
        if (strcmp(str, "ENDOFINPUT") == 0) break;
        gets(str);
        for (int i = 0, l = strlen(str); i < l; ++i)
            if (isalpha(str[i])) str[i] = change(str[i]);
        puts(str);
        gets(str);
    }
    return 0;
}
