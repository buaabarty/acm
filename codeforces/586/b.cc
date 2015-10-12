#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int dp[52][2][2][2], n, a[2][50], b[50];
int main() {
    while (scanf("%d", &n) == 1) {
        for (int j = 0; j < 2; ++j)
            for (int i = 0; i < n - 1; ++i) {
                scanf("%d", &a[j][i]);
            }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0][0][0] = 0;
        dp[1][0][0][0] = a[1][n - 2] * 2;
        dp[1][1][1][0] = b[n - 1] * 2;
        dp[1][1][0][1] = a[1][n - 2] + b[n - 1];
        dp[1][0][1][1] = dp[1][1][0][1];
        for (int i = 2; i < n; ++i) {
            dp[i][0][0][0] = dp[i - 1][0][0][0] + a[1][n - i - 1] * 2;
            dp[i][0][0][1] = dp[i - 1][0][0][1] + a[1][n - i - 1] * 2;
            dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][0][0][1]);

            dp[i][1][1][0] = min(dp[i - 1][0][0][0] + b[n - i] * 2, dp[i - 1][1][1][0] + a[0][n - i] * 2);
            dp[i][1][1][1] = min(dp[i - 1][0][0][1] + b[n - i] * 2, dp[i - 1][1][1][1] + a[0][n - i] * 2);
            dp[i][1][1][1] = min(dp[i][1][1][1], dp[i - 1][0][1][1] + b[n - i] + a[0][n - i]);
            dp[i][1][1][0] = min(dp[i][1][1][0], dp[i][1][1][1]);

            dp[i][0][1][1] = min(min(dp[i - 1][0][0][0], dp[i - 1][0][0][1]) + b[n - i] + a[1][n - i - 1], dp[i - 1][0][1][1] + a[0][n - i] + a[1][n - i - 1]);
            dp[i][0][1][0] = min(dp[i][0][1][0], dp[i][0][1][1]);
        }
        int ans = 1000000000;
        ans = min(dp[n - 1][0][0][1] + b[0] * 2, dp[n - 1][1][1][1] + a[0][0] * 2);
        ans = min(ans, dp[n - 1][0][1][1] + b[0] + a[0][0]);
        printf("%d\n", ans);
    }
    return 0;
}
