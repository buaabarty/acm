#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int main()
{
    LL n, x, y;
    while (scanf("%I64d%I64d%I64d", &n, &x, &y) != EOF)
    {
        if (y < n)
        {
            puts("-1");
            continue;
        }
        LL t = n - 1 + (y - n + 1) * (y - n + 1);
        if (t < x)
        {
            puts("-1");
            continue;
        }
        for (int i = 1; i < n; ++i)
            printf("1 ");
        printf("%d\n", y - n + 1);
    }
}
