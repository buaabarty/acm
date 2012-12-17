#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string str;
int main()
{
    while (cin >> str)
    {
        int s = 0;
        for (int i = 0; i < str.length(); ++i)
            s += ((str[i] == '4') || (str[i] == '7'));
        if (!s)
        {
            puts("NO");
            continue;
        }
        bool flag = true;
        while (s)
        {
            int x = s % 10;
            if ((x != 4) && (x != 7))
            {
                flag = false;
                break;
            }
            s /= 10;
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
