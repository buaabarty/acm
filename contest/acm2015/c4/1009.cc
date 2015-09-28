#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL T, n, m, a[33][33];
LL dp[33][33][1803];
bool f[33][33][1803];
void checkMin(LL &x, LL y) {
    if (y < x) {
        x = y;
    }
}
int main() {
    scanf("%lld", &T);
    for (LL ca = 1; ca <= T; ++ca) {
        scanf("%lld%lld", &n, &m);
        for (LL i = 1; i <= n; ++i) {
            for (LL j = 1; j <= m; ++j) {
                scanf("%lld", &a[i][j]);
            }
        }
        memset(f, 0, sizeof(f));
        memset(dp, 0x3f, sizeof(dp));
        f[1][1][a[1][1]] = 1;
        dp[1][1][a[1][1]] = a[1][1] * a[1][1];
        for (LL i = 1; i <= n; ++i) {
            for (LL j = 1; j <= m; ++j) {
                for (LL k = 0; k <= 30 * (i + j - 1); ++k) {
                    if (f[i][j][k]) {
                        if (i < n) {
                            checkMin(dp[i + 1][j][k + a[i + 1][j]], dp[i][j][k] + a[i + 1][j] * a[i + 1][j]);
                            f[i + 1][j][k + a[i + 1][j]] = 1;
                        }
                        if (j < m) {
                            checkMin(dp[i][j + 1][k + a[i][j + 1]], dp[i][j][k] + a[i][j + 1] * a[i][j + 1]);
                            f[i][j + 1][k + a[i][j + 1]] = 1;
                        }
                    }
                }
            }
        }
        LL ans = 10000000000000000LL;
        for (LL i = 0; i <= 30 * (n + m - 1); ++i) {
            if (f[n][m][i]) {
                checkMin(ans, (n + m - 1) * dp[n][m][i] - i * i);
            }
        }
        printf("Case #%lld: %lld\n", ca, ans);
    }
    return 0;
}

