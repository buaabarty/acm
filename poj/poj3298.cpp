#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int T, n, dat[30010];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &dat[i]);
        dat[0] = -2147483648;
        dat[n + 1] = -2147483648;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if ((dat[i] > dat[i - 1]) && (dat[i] > dat[i + 1])) ans += 2;
        if (dat[n] > dat[n - 1]) ans--;
        printf("%d\n", ans);
    }
    return 0;
}
