#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
LL n, k, a[400010];
class data
{
public:
    LL d, ori;
    bool operator < (const data a) const
    {
        return d < a.d;
    }
}dat[400010];
LL cnt[400010];
int main()
{
    scanf("%I64d%I64d", &n, &k);
    for (LL i = 0; i < n; ++i)
        scanf("%I64d", &dat[i].d);
    for (LL i = 0; i < n; ++i) dat[i].ori = i;
    sort(dat, dat + n);
    LL now = 0;
    for (LL i = 0; i < n; ++i)
    {
        if ((i == 0) || (dat[i].d != dat[i - 1].d)) ++now;
        a[dat[i].ori] = now;
    }
    memset(cnt, 0, sizeof(cnt));
    LL left = 0, right = 0;
    for (right = 0; right < n; ++right)
    {
        cnt[a[right]]++;
        if (cnt[a[right]] >= k) break;
    }
    if (right == n)
    {
        printf("0\n");
        return 0;
    }
    LL sum = n - right;
    for (left = 1; left < n; ++left)
    {
        cnt[a[left - 1]]--;
        if (cnt[a[left - 1]] == k - 1)
        {
            for (++right; right < n; ++right)
            {
                cnt[a[right]]++;
                if (cnt[a[right]] >= k) break;
            }
            if (right == n) break;
        }
        sum += n - right;
    }
    printf("%I64d\n", sum);

    return 0;
}
