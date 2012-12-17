#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 128
using namespace std;
int dp[MAXN][MAXN];
int main()
{
    int t, l1, l2;
    scanf("%d", &t);
    string a, b;
    while (t--)
    {
        cin >> a >> b;
        l1 = a.length();
        l2 = b.length();
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= l1; ++i)
            for (int j = 1; j <= l2; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (a[i - 1] == b[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        if (dp[l1][l2] == l2) printf("YES\n");
        else{
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= l1; ++i)
                for (int j = 1; j <= l2; ++j)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    if (a[i - 1] == b[l2 - j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            if (dp[l1][l2] == l2) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
