#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1024
#define MAXM 32768
using namespace std;
int k, m, s[MAXN], h, hcnt;
bool f[MAXM];
int main()
{
    while (scanf("%d", &k), k)
    {
        memset(f, false, sizeof(f));
        f[0] = 0;
        for (int i = 1; i <= k; ++i) scanf("%d", &s[i]);
        for (int i = 1; i < MAXM; ++i)
            for (int j = 1; j <= k; ++j)
                if (i >= s[j]) f[i] |= (!f[i - s[j]]);
        for (int i = 0; i < 100; ++i) printf("%d:%d ", i, f[i]);
        printf("\n");
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d", &hcnt);
            int res = 0;
            for (int i = 1; i <= hcnt; ++i)
            {
                scanf("%d", &h);
                res ^= f[h];
                printf(" A%d ", f[h]);
            }
            if (res) printf("L");
            else printf("W");
        }
        printf("\n");
    }
    return 0;
}
