#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, k, x;
int f[10010][110];
int modk(int a)
{
    return ((a % k) + k) % k;
}
int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &x);
            for (int j = 0; j < k; ++j)
                if (f[i - 1][j])
                {
                    f[i][modk(j + x)] = 1;
                    f[i][modk(j - x)] = 1;
                }
        }
        if (f[n][0]) puts("Divisible");
        else puts("Not divisible");
    }
    return 0;
}
