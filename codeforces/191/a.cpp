#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[20];
int dp[2][26][26], n;
int main()
{
    //freopen("data.txt", "w", stdout);
    memset(dp, 0x80, sizeof(dp));
    for (int i = 0; i < 26; ++i) dp[0][i][i] = 0;
    int now = 0;
    scanf("%d", &n);
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        now = 1 - now;
        memset(dp[now], 0x80, sizeof(dp[now]));
        scanf("%s", str);
        int len = strlen(str);
        int sx = str[0] - 'a';
        int sy = str[len - 1] - 'a';
        for (int x = 0; x < 26; ++x)
            dp[now][x][sy] = max(dp[now][x][sy], dp[1 - now][x][sx] + len);
        for (int x = 0; x < 26; ++x)
            for (int y = 0; y < 26; ++y)
                dp[now][x][y] = max(dp[now][x][y], dp[1 - now][x][y]);
        /*for (int x = 0; x < 26; ++x)
        {
            for (int y = 0; y < 26; ++y)
                printf("%d\t", dp[i][x][y]);
            puts("");
        }*/
        for (int x = 0; x < 26; ++x)
            res = max(res, dp[now][x][x]);
        //printf("%d\n", res);
    }
    printf("%d\n", res);
    return 0;
}
