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

int dat[N][N], pre[N][N], n, m, dp[N][N];
int step[5][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};

int main (int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(dat, 0, sizeof(dat));
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%1d", &pre[i][j]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                for (int k = 0; k < 5; ++k) {
                    int dx = i + step[k][0];
                    int dy = j + step[k][1];
                    if (dx < 1 || dy < 1 || dx > n || dy > m) continue;
                    dat[i][j] += pre[dx][dy];
                }
        memset(dp, 0x3f, sizeof(dp));
        dp[1][1] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                checkMin(dp[i][j], min(dp[i-1][j]-pre[i-1][j]-pre[i][j], dp[i][j-1]-pre[i][j-1]-pre[i][j]) + dat[i][j]);
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
