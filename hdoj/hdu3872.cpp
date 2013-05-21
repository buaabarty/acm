#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define N 100010
#define LL long long
using namespace std;
LL n, num[N], color[N], last[N], hash[N], a[N], f[N];
int main()
{
    freopen("in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%I64d", &n);
        for (LL i = 1; i <= n; ++i) scanf("%I64d", &color[i]);
        for (LL i = 1; i <= n; ++i) scanf("%I64d", &num[i]);
        memset(hash, -1, sizeof(hash));
        for (LL i = 1; i <= n; ++i)
        {
            if (hash[color[i]] > 0) last[i] = hash[color[i]];
            else last[i] = 0;
            hash[color[i]] = i;
        }
        //for (int i = 1; i <= n; ++i) printf("%I64d ", last[i]);
        //puts("");
        for (LL i = 1; i <= n; ++i) a[i] = i;
        num[0] = INT_MAX;
        a[0] = -1;
        for (LL i = 1; i <= n; ++i)
            while (num[a[i] - 1] <= num[i]) a[i] = a[a[i] - 1];
        //for (int i = 1; i <= n; ++i) printf("%I64d ", a[i]);
        //puts("");
        for (LL i = 1; i <= n; ++i) f[i] = INT_MAX / 2;
        f[0] = 0;
        bool has = false;
        for (LL i = 1; i <= n; ++i)
        {
            LL j = a[i] - 1, x = num[i];
            while (j > last[i])
            {
                //printf("%I64d,%I64d    ", j, x);
                f[i] = min(f[i], f[j] + x);
                x = num[j];
                j = a[j] - 1;
            }
            if (j == a[i] - 1) has = true;
            //puts("");
            f[i] = min(f[i], x + f[last[i]]);
        }
        //if (has) printf("OMG\n");
        //for (int i = 1; i <= n; ++i) printf("%I64d ", f[i]);
        //puts("");
        printf("%I64d\n", f[n]);
    }
    return 0;
}
