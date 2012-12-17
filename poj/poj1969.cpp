#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n, x, y, dx, dy, dir = 0, speed[2][2] = {{-1, 1}, {1, -1}};
    while (~scanf("%d", &n))
    {
        x = 1, y = 1, dir = 0;
        for (int i = 1; i < n; ++i)
        {
            dx = x + speed[dir][0], dy = y + speed[dir][1];
            if ((!dx) || (!dy))
            {
                if (!dx) y++;
                else x++;
                dir = 1 - dir;
            }
            else x = dx, y = dy;
        }
        printf("TERM %d IS %d/%d\n", n, x, y);
    }
    return 0;
}
