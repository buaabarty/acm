#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string str;
int main()
{
    int ca = 0, top, res;
    while (cin >> str)
    {
        if (str[0] == '-') break;
        top = res = 0;
        printf("%d. ", ++ca);
        for (int i = 0, l = str.length(); i < l; ++i)
            if (str[i] == '{') top++;
            else if (top == 0)
            {
                top++, res++;
            }
            else top--;
        res += top / 2;
        printf("%d\n", res);
    }
    return 0;
}
