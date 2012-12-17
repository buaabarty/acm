#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
LL f[11][2010], n, m, s[11][2010];
int main()
{
    memset(s, 0, sizeof(s));
    memset(f, 0, sizeof(f));
    LL T;
    scanf("%lld", &T);
    for (LL i = 1; i <= 2000; ++i)
    {
        f[1][i] = 1;
        s[1][i] = i;
    }
    for (LL i = 2; i <= 10; ++i)
        for (LL j = 1; j <= 2000; ++j)
        {
            f[i][j] += s[i - 1][j / 2];
            s[i][j] = s[i][j - 1] + f[i][j];
        }
    for (LL ca = 1; ca <= T; ++ca)
    {
        scanf("%lld%lld", &n, &m);
        printf("Case %lld: n = %lld, m = %lld, # lists = %lld\n", ca, n, m, s[n][m]);
    }
    return 0;
}
