#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 16
using namespace std;
double dp[N][8][8][8][8];
double dat[8][8], ave;
int n;
void update(double &x, double y)
{
    if (y < x) x = y;
}
double getans(int x1, int ya, int x2, int y2)
{
    double sum = 0;
    for (int i = x1; i <= x2; ++i)
        for (int j = ya; j <= y2; ++j)
            sum += dat[i][j];
    return (sum - ave) * (sum - ave);
}
int main()
{
    while (~scanf("%d", &n))
    {
        ave = 0;
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
            {

                scanf("%lf", &dat[i][j]);
                //printf("HELLO%d,%d,%lf\n", i, j, dat[i][j]);
                ave += dat[i][j];
            }
        //puts("DONE");
        for (int i = 0; i < n; ++i)
            for (int x1 = 0; x1 < 8; ++x1)
                for (int ya = 0; ya < 8; ++ya)
                    for (int x2 = 0; x2 < 8; ++x2)
                        for (int y2 = 0; y2 < 8; ++y2)
                            dp[i][x1][ya][x2][y2] = 1e20;
        ave /= (double)n;
        for (int x1 = 0; x1 < 8; ++x1)
            for (int ya = 0; ya < 8; ++ya)
                for (int x2 = 0; x2 < 8; ++x2)
                    for (int y2 = 0; y2 < 9; ++y2)
                        dp[0][x1][ya][x2][y2] = getans(x1, ya, x2, y2);
        for (int i = 1; i < n; ++i)
            for (int k = 0; k < i; ++k)
                for (int x1 = 0; x1 < 8; ++x1)
                    for (int ya = 0; ya < 8; ++ya)
                        for (int x2 = 0; x2 < 8; ++x2)
                            for (int y2 = 0; y2 < 8; ++y2)
                            {
                                for (int t = x1 + 1; t <= x2; ++t)
                                {
                                    update(dp[i][x1][ya][x2][y2], dp[k][x1][ya][t - 1][y2] + dp[i - k - 1][t][ya][x2][y2]);
                                    update(dp[i][x1][ya][x2][y2], dp[i - k - 1][x1][ya][t - 1][y2] + dp[k][t][ya][x2][y2]);
                                }
                                for (int t = ya + 1; t <= y2; ++t)
                                {
                                    update(dp[i][x1][ya][x2][y2], dp[k][x1][ya][x2][t - 1] + dp[i - k - 1][x1][t][x2][y2]);
                                    update(dp[i][x1][ya][x2][y2], dp[i - k - 1][x1][ya][x2][t - 1] + dp[k][x1][t][x2][y2]);
                                }
                            }
        printf("%.3f\n", sqrt(dp[n - 1][0][0][7][7] / (double)n));
    }
    return 0;
}
