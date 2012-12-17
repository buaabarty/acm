#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int x, y, r, num[32];
    scanf("%x,%d,%d", &r, &x, &y);
    for (int i = 0; i < 32; ++i)
    {
        num[i] = r & 1;
        r >>= 1;
    }
    num[x] = 0;
    num[y] = 1;
    num[y - 1] = 1;
    num[y - 2] = 0;
    int res = 0;
    for (int i = 31; i >= 0; --i)
        res = (res << 1) | num[i];
    printf("%x\n", res);
    return 0;
}
