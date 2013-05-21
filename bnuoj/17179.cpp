#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int fac[1000010], k, n, v[1010], fcnt;
bool okay(int x)
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if ((v[i] % fac[x]) == 0) ++cnt;
    return (cnt >= k);
}
int main()
{
    //freopen("data.in", "r", stdin);
    while (~scanf("%d%d", &n, &k))
    {
//        memset(fac, 0, sizeof(fac));
        fcnt = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &v[i]);
        sort(v + 1, v + n + 1);
        fac[++fcnt] = 1;
        for (int i = 1; i <= n; ++i)
            if (v[i] != v[i - 1])
            {
                fac[++fcnt] = v[i];
                int lim = (int)(sqrt(v[i]) + 1);
                for (int j = 2; j <= lim; ++j)
                    if ((v[i] % j) == 0)
                    {
                        fac[++fcnt] = j;
                        fac[++fcnt] = v[i] / j;
                    }
            }
        sort(fac + 1, fac + fcnt + 1);
        fcnt = unique(fac + 1, fac + fcnt + 1) - (fac + 1);
        for (int i = fcnt; i >= 1; --i)
        {
            if (okay(i))
            {
                printf("%d\n", fac[i]);
                break;
            }
        }
    }
    return 0;
}
