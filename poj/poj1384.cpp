#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int T, a, b, w, p, n, m, f[10010];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &a, &b);
        n = b - a;
        for (int i = 1; i <= n; ++i) f[i] = INT_MAX / 3;
        f[0] = 0;
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d", &p, &w);
            for (int i = w; i <= n; ++i)
                f[i] = min(f[i], f[i - w] + p);
        }
        if (f[n] == INT_MAX / 3) puts("This is impossible.");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", f[n]);
    }
    return 0;
}
