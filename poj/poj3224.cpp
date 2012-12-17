#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n, s, smax = -1, smaxt, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        s = 0;
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &x);
            s += (x == 3);
        }
        if (s > smax)
        {
            smax = s;
            smaxt = i;
        }
    }
    printf("%d\n", smaxt);
    return 0;
}
