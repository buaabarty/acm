#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;
int dp[6000][5][5][5][5];
int a[6000][4], b[6000][4];
int T, n;
void checkMin(int& x, int y) {
    if (y < x) x = y;
}
int iabs(int x) {
    if (x > 0) return x;
    return -x;
}
int dist(int i, int x, int y) {
    return iabs(a[i][x] - a[i+1][y]) + iabs(b[i][x] - b[i + 1][y]);
}
int main() {
    scanf("%d", &T);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < 4; ++i) b[0][i] = i + 1;
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 4; ++j)
                scanf("%d%d", &a[i][j], &b[i][j]);
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0][1][2][3] = 0;
        for (int i = 1; i <= n; ++i) {
            int x[4] = {0, 1, 2, 3};
            do {
                if (b[i][x[0]] > b[i][x[1]] || b[i][x[1]] > b[i][x[2]] || b[i][x[2]] > b[i][x[3]]) continue;
                int y[4] = {0, 1, 2, 3};
                do {
                    checkMin(dp[i][x[0]][x[1]][x[2]][x[3]], dp[i-1][y[0]][y[1]][y[2]][y[3]] + dist(i-1,y[0],x[0])
                            + dist(i-1,y[1],x[1]) + dist(i-1,y[2],x[2]) + dist(i-1,y[3],x[3]));
                } while (next_permutation(y, y + 4));
            } while (next_permutation(x, x + 4));
        }
        int res = 1000000000;
        int x[4] = {0, 1, 2, 3};
        do {
            checkMin(res, dp[n][x[0]][x[1]][x[2]][x[3]]);
        } while (next_permutation(x, x + 4));
        printf("Case #%d:\n%d\n", ca, res);
    }
    return 0;
}
