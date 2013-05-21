#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[1000];
int main()
{
    f[1] = 0;
    f[2] = 1;
    f[3] = 1;
    for (int i = 4; i < 100; ++i)
    {
        f[i] |= !f[i - 1];
        f[i] |= !f[i - 2];
        for (int j = 1; j < i - 1; ++j)
            f[i] |= !(f[j] ^ f[i - j - 1]);
        for (int j = 1; j < i - 2; ++j)
            f[i] |= !(f[j] ^ f[i - j - 2]);
    }
    for (int i = 1; i < 100; ++i)
        printf("%d %d\n", i, f[i]);
    return 0;
}
