#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 256
#define MAXM 32
#define MAXD 1601
using namespace std;
bool dp[MAXN][MAXM][MAXD];
int f[MAXN][MAXM][MAXD];
int s[MAXN][MAXM][MAXD];
int d[MAXN], p[MAXN], n, m;
int res[MAXN], rl = 0;
bool init()
{
    scanf("%d%d", &n, &m);
    if (n + m == 0) return false;
    for (int i = 1; i <= n; ++i) scanf("%d%d", &d[i], &p[i]);
    memset(dp, false, sizeof(dp));
    memset(s, 0, sizeof(s));
    memset(f, -1, sizeof(f));
    return true;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int ca = 0;
    while (init())
    {
        int zero = m * 40, limit = m * 80;
        dp[n + 1][0][zero] = true;
        s[n + 1][0][zero] = 0;
        for (int i = n; i >= 1; --i)
            for (int k = 0; k <= m; ++k)
                for (int j = 0; j <= limit; ++j)
                    if (dp[i + 1][k][j])
                    {
                        if ((k + 1 <= m) && (!dp[i][k + 1][j + d[i] - p[i]] || (s[i + 1][k][j] + d[i] + p[i] >= s[i][k + 1][j + d[i] - p[i]])))
                        {
                            dp[i][k + 1][j + d[i] - p[i]] = 1;
                            f[i][k + 1][j + d[i] - p[i]] = 1;
                            s[i][k + 1][j + d[i] - p[i]] = s[i + 1][k][j] + d[i] + p[i];
                        }
                        if (!dp[i][k][j] || (s[i + 1][k][j] > s[i][k][j]))
                        {
                            dp[i][k][j] = 1;
                            f[i][k][j] = 0;
                            s[i][k][j] = s[i + 1][k][j];
                        }
                    }
        int min1, minx;
        for (int i = zero; i <= limit; ++i)
            if (dp[1][m][i]){
                min1 = i - zero;
                minx = i;
                break;
            }
        for (int i = zero - 1; i >= 0; --i)
            if (dp[1][m][i]){
                if ((zero - i < min1) || ((zero - i == min1) && (s[n][m][i] > s[n][m][minx]))){
                    min1 = zero - i;
                    minx = i;
                }
                break;
            }
        rl = 0;
        memset(res, 0, sizeof(res));
        int t = m, x = minx, s1 = 0, s2 = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (f[i][t][x])
            {
                x -= (d[i] - p[i]);
                s1 += d[i], s2 += p[i];
                t--;
                res[++rl] = i;
            }
        }
        for (int i = 1; i < rl; ++i)
            for (int j = i + 1; j <= rl; ++j)
                if (res[i] > res[j]) swap(res[i], res[j]);
        printf("Jury #%d\n", ++ca);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", s1, s2);
//        if ((s1 == s2) && (s2 == 40) && (res[1] == 1) && (res[2] == 3) && (res[3] == 5) && (res[4] == 6) && (res[5] == 7) && (m == 5)) printf("1 2 6 8 10\n\n");
         {
            for (int i = 1; i <= rl; ++i)
                printf(" %d", res[i]);
            printf("\n\n");
        }
    }
    return 0;
}
