#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1024
using namespace std;
int main()
{
    int t, n, num[MAXN], dat[MAXN];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &num[i]);
            dat[num[i] + i] = 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            int s = 1, r = 0;
            for (int j = num[i] + i - 1; (j >= 1) && s; --j)
                if (dat[j]) { s++; r++; }
                else s--;
            printf("%d", r + 1);
            if (i < n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
