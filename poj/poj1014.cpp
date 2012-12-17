#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 130000
using namespace std;
bool f[MAXN];
int cnt[10], sum;
int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int ca = 0;
    while (true)
    {
        sum = 0;
        for (int i = 1; i <= 6; ++i)
        {
            scanf("%d", &cnt[i]);
            sum += cnt[i] * i;
        }
        if (!sum) break;
        printf("Collection #%d:\n", ++ca);
        if (sum % 2){
            printf("Can't be divided.\n\n");
            continue;
        }
        memset(f, false, sizeof(f));
        f[0] = true;
        for (int i = 1; i <= 6; ++i)
        {
            if (!cnt[i]) continue;
            int j = 1;
            for (; j <= cnt[i]; j *= 2)
            {
                for (int k = sum; k >= j * i; --k)
                {
                    f[k] |= f[k - j * i];
                    if (f[sum >> 1]) break;
                }
                cnt[i] -= j;
                if (f[sum >> 1]) break;
            }
            j = cnt[i];
            for (int k = sum; k >= j * i; --k)
            {
                f[k] |= f[k - j * i];
                if (f[sum >> 1]) break;
            }
            if (f[sum >> 1]) break;
        }
        if (f[sum >> 1]) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
