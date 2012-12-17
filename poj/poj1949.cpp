#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n;
    int f[10010];
    while (~scanf("%d", &n))
    {
        memset(f, 0, sizeof(f));
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            int k, x, st = 0, p;
            scanf("%d%d", &p, &k);
            while (k--)
            {
                scanf("%d", &x);
                st = max(st, f[x]);
            }
            f[i] = st + p;
            res = max(res, f[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}
