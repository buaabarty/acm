#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T, len;
    char str[200];
    int dp[200][200];
    scanf("%d", &T);
    gets(str);
    for (int ca = 1; ca <= T; ++ca) {
        gets(str);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        len = strlen(str);
        for (int i = 1; i <= len; ++i)
            for (int j = 0; j <= i; ++j)
                if (str[i-1] == ')') {
                    dp[i][j] |= dp[i-1][j+1];
                    if (i>1 && str[i-2]==':') dp[i][j] |= dp[i-2][j];
                } else if (str[i-1] == '(') {
                    if (j) dp[i][j] |= dp[i-1][j-1];
                    if (i>1 && str[i-2]==':') dp[i][j] |= dp[i-2][j];
                } else dp[i][j] |= dp[i-1][j];
        printf("Case #%d: %s\n", ca, (dp[len][0])?"YES":"NO");
    }
    return 0;
}
