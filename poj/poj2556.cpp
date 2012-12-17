#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string str;
int x, y, now, step[4][2] = {{10, 0}, {0, -10}, {-10, 0}, {0, 10}};
int main()
{
    while (cin >> str)
    {
        x = 310, y = 420;
        printf("300 420 moveto\n");
        printf("310 420 lineto\n");
        now = 0;
        for (int i = 0, l = str.length(); i < l; ++i)
        {
            if (str[i] == 'A') now = (now + 1) % 4;
            else now = (now + 3) % 4;
            x += step[now][0], y += step[now][1];
            printf("%d %d lineto\n", x, y);
        }
        printf("stroke\nshowpage\n");
    }
    return 0;
}
