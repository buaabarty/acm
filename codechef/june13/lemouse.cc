// =====================================================================================
// 
//       Filename:  lemouse.cc
// 
//    Description:  dynamic programming
// 
//        Version:  1.0
//        Created:  2013年06月13日 17时13分52秒
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Boyang Yang (barty), maiL@barty.ws
//        Company:  http://barty.ws
// 
// =====================================================================================


#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;
template <typename T> void checkMin(T &a, const T &b) { if (b < a) a = b; }
template <typename T> void checkMax(T &a, const T &b) { if (b > a) a = b; }

const int N = 100 + 9;

int dat[N][N], n, m, dp[2][N][N];
int step[5][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};

int main (int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%1d", &dat[i][j]);
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0][1] = dp[1][1][0] = dat[1][1];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                checkMin(dp[0][i][j], dp[1][i][j-1] + dat[i+1][j] + dat[i][j + 1]);
                checkMin(dp[0][i][j], dp[0][i][j-1] + dat[i-1][j] + dat[i+1][j] + dat[i][j+1]);
                checkMin(dp[1][i][j], dp[0][i-1][j] + dat[i+1][j] + dat[i][j+1]);
                checkMin(dp[1][i][j], dp[1][i-1][j] + dat[i][j-1] + dat[i][j+1] + dat[i+1][j]);
            }
        printf("%d\n", min(dp[0][n][m], dp[1][n][m]));
    }
    return 0;
}
