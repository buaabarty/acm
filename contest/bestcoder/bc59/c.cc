#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct data {
    int a, b, c;
    bool operator < (const data& d) const {
        return b * d.c > d.b * c;
    }
} d[1001];
int T, n, t, dp[1001][3001];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &t);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &d[i].a, &d[i].b, &d[i].c);
        }
        sort(d + 1, d + n + 1);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= t; ++j) {
                if (j < d[i].c) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - d[i].c] + max(0, d[i].a - d[i].b * j));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= t; ++i) {
             ans = max(ans, dp[n][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
