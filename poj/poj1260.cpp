#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[N][9][9];
int dat[9][9], n;
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                scanf("%d", &dat[i][j]);
        memset(dp, 0x3f, sizeof(dp));
        for (int x1 = 0; x1 < 9; ++x1)
            for (int y1 = 0; y1 < 9; ++y1)
                for (int x2 = 0; x2 < 9; ++x2)
                    for (int y2 = 0; y2 < 9; ++y2)
                        dp[0][x1][y1][x2][y2] = getans(x1, y1, x2, y2);
        for (int i = 1; i < n; ++i)
            for (int x1 = 0; x1 < 9; ++x1)
                for (int y1 = 0; y1 < 9; ++y1)
                    for (int x2 = 0; x2 < 9; ++x2)
                        for (int y2 = 0; y2 < 9; ++y2)
                        {
                            for (int t = x1 + 1; t <= x2; ++t)
                            {
                                update(dp[i][x1][y1][x2][y2], dp[i - 1][x1][y1][t - 1][y2] + dp[0][t][y1][x2][y2]);
                                update(dp[i][x1][y1][x2][y2], dp[0][x1][y1][t - 1][y2] + dp[i - 1][t][y1][x2][y2]);
                            }
                            for (int t = y1 + 1; t <= y2; ++t)
                            {
                                update(dp[i][x1][y1][x2][y2], dp[i - 1][x1][y1][x2][t - 1] + dp[0][x1][t][x2][y2]);
                                update(dp[i][x1][y1][x2][y2], dp[0][x1][y1][x2][t - 1] + dp[i - 1][x1][t][x2][y2]);
                            }
                        }
    }
    return 0;
}
