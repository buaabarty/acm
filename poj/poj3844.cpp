#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cnt[1000000], d, n;
int main()
{
    int T, s, x, res; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &d, &n);
        memset(cnt, 0, sizeof(cnt)); s = res = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &x);
            s = (s + x) % d;
            res += cnt[s];
            if (!s) res++;
            cnt[s]++;
        }
        printf("%d\n", res);
    }
    return 0;
}
