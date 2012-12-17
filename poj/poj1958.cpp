#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int f[32], h[32];
    h[0] = 0;
    h[1] = 1;
    for (int i = 2; i <= 12; ++i)
        h[i] = 2 * h[i - 1] + 1;
    f[1] = 1;
    for (int i = 2; i <= 12; ++i)
    {
        f[i] = 1000000000;
        for (int k = 0; k < i; ++k)
            f[i] = min(2 * f[k] + h[i - k], f[i]);
    }
    for (int i = 1; i <= 12; ++i)
        printf("%d\n", f[i]);
    return 0;
}
