#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string str[4][4];
int sum(string s, char x, int c)
{
    int ss = 0;
    for (int i = 0, l = s.length(); i < l; ++i)
        if (c) ss += (s[i] == x);
        else ss += (s[i] != x);
    return ss;
}
int main()
{
    int __;
    scanf("%d", &__);
    while (__--)
    {
        for (int i = 1; i <= 3; ++i)
            for (int j = 1; j <= 3; ++j)
                cin >> str[i][j];
        bool flag = false;
        for (int x = 0; x <= 1; ++x)
        {
            if (flag) break;
            for (char c = 'A'; c <= 'Z'; ++c)
            {
                flag = true;
                for (int i = 1; i <= 3; ++i)
                {
                    int s1 = sum(str[i][1], c, x), s2 = sum(str[i][2], c, x);
                    if (((str[i][3] == "up") && (s1 <= s2)) || ((str[i][3] == "down") && (s1 >= s2)) || ((str[i][3] == "even") && (s1 != s2)))
                    {
                            flag = false; break;
                    }
                }
                if (flag){
                    printf("%c is the counterfeit coin and it is %s.\n", c, (x)? "heavy":"light");
                    break;
                }
            }
        }
    }
    return 0;
}
