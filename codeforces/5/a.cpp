#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[65536];
int cnt = 0, res = 0;
int find(char c, char s[])
{
    for (int i = 0; s[i]; ++i)
        if (s[i] == c) return i;
    return -1;
}
int main()
{
    while (gets(str) != NULL)
    {
        if (str[0] == '+') cnt++;
        else if (str[0] == '-') cnt--;
        else
        {
            int len = strlen(str), p = find(':', str);
            res += (len - p - 1) * cnt;
        }
    }
    printf("%d\n", res);
    return 0;
}
