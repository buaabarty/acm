#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int h, m;
bool okay(int x, int y)
{
    return ((x % 10) == (y / 10)) && ((x / 10) == (y % 10));
}
int main()
{
    while (~scanf("%d:%d", &h, &m))
    {
        while (true)
        {
            m++;
            if (m == 60)
            {
                h++, m = 0;
            }
            if (h == 24) h = 0;
            if (okay(h, m))
            {
                printf("%02d:%02d\n", h, m);
                break;
            }
        }
    }
    return 0;
}
