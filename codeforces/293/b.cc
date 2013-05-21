#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000007;

int dp[11][11][1<<10];
int n, m, k;
int dat[11][11];

bool check(int x, int y) {
    return (bool)(x&(1<<(y-1)));
}
int add(int x, int y) {
    return (x|(1<<(y-1)));
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    if (n+m-1 > k) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &dat[i][j]);
    if (dat[1][1]) dp[1][1][1<<(dat[1][1]-1)] = 1;
    else {
        for (int i = 1; i <= k; ++i)
            dp[1][1][1<<(i-1)] = 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) if (i+j>2) {
            cout << "AAA   " << i << " " << j << endl;
            if (i == 1) {
                if (dat[i][j]) {
                    for (int t = 0; t < (1<<k); ++t)
                        if (!check(t, dat[i][j])) {
                            int st = add(t, dat[i][j]);
                            dp[i][j][st] += dp[i][j-1][t];
                            if (dp[i][j][st] >= mod) dp[i][j][st] -= mod;
                        }
                } else {
                    for (int x = 1; x <= k; ++x)
                        for (int t = 0; t < (1<<k); ++t)
                            if (!check(t, x)) {
                                int st = add(t, x);
                                dp[i][j][st] += dp[i][j-1][t];
                                if (dp[i][j][st] >= mod) dp[i][j][st] -= mod;
                            }
                }
            } else if (j == 1) {
                if (dat[i][j]) {
                    for (int t = 0; t < (1<<k); ++t)
                        if (!check(t, dat[i][j])) {
                            int st = add(t, dat[i][j]);
                            dp[i][j][st] += dp[i-1][j][t];
                            if (dp[i][j][st] >= mod) dp[i][j][st] -= mod;
                        }
                } else {
                    for (int x = 1; x <= k; ++x)
                        for (int t = 0; t < (1<<k); ++t)
                            if (!check(t, x)) {
                                int st = add(t, x);
                                dp[i][j][st] += dp[i-1][j][t];
                                if (dp[i][j][st] >= mod) dp[i][j][st] -= mod;
                            }
                }
            } else {
                if (dat[i][j]) {
                    for (int t1 = 0; t1 < (1<<k); ++t1) if (!check(t1, dat[i][j]))
                        for (int t2 = 0; t2 < (1<<k); ++t2) if (!check(t2, dat[i][j])) {
                                int st = add(t1|t2, dat[i][j]);
                                dp[i][j][st] = (dp[i][j][st] + dp[i-1][j][t1] * dp[i][j-1][t2]) % mod;
                            }
                } else {
                    for (int x = 1; x <= k; ++x)
                        for (int t1 = 0; t1 < (1<<k); ++t1) if (!check(t1, x))
                            for (int t2 = 0; t2 < (1<<k); ++t2) if (!check(t2, x)) {
                                    int st = add(t1|t2, x);
                                    dp[i][j][st] = (dp[i][j][st] + dp[i-1][j][t1] * dp[i][j-1][t2]) % mod;
                                }
                }
            }
        }
    int tot = 0;
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= m; ++y) {
            for (int i = 0; i < (1<<k); ++i) {
                cout << i << " " << dp[x][y][i] << endl;
                //tot = (tot + dp[n][m][i]) % mod;
            }
            puts("\n");
        }
    //printf("%d\n", tot);
    return 0;
}
