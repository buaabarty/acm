#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1024
using namespace std;
int num[MAXN], n, res, dp[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &num[i]);
    memset(dp, 0, sizeof(dp));
    res = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
            if (num[j] < num[i]) dp[i] = max(dp[i], dp[j]);
        dp[i]++;
        res = max(res, dp[i]);
    }
    printf("%d\n", res);

    return 0;
}

