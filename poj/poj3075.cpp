#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1048576];
int main()
{
    while (gets(str))
    {
        if (strcmp(str, "end") == 0) break;
        int s1 = 0, s2 = 0, now = 0, cnt = 0;
        char last = ' ';
        for (int i = 0; str[i]; ++i)
        {
            if (str[i] == last) now++;
            else now = 1;
            if (now >= 3)
            {
                cnt++;
                now = 0;
            }
            if (str[i] == 'X') s1++;
            else if (str[i] == 'O') s2++;
            last = str[i];
            if (last == '.') last = ' ';
        }
        bool flag = true;
        if (!((s1 == s2 + 1) || (s1 == s2))) flag = false;
        if (cnt > 1) flag = false;
        if (flag) puts("valid");
        else puts("invalid");
    }
    return 0;
}
