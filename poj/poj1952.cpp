#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX_N 5010

using namespace std;

long long cnt[MAX_N];
long long res = 0;
int n, num[MAX_N], dp[MAX_N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            if (dp[j] > dp[i] && num[j] > num[i]) dp[i] = dp[j];
        dp[i]++;
    }
    int rmax = 0;
/*    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    cout << endl;*/
    for (int i = 1; i <= n; i++)
    {
        rmax = max(rmax, dp[i]);
        if (dp[i] == 1) cnt[i] = 1;
        else for (int j = i - 1; j >= 1; j--)
            if (dp[j] == dp[i] - 1 && num[j] > num[i])
            {
                bool okay = true;
                for (int k = j + 1; k < i; k++)
                    if (num[k] == num[j] && dp[k] == dp[j])
                    {
                        okay = false;
                        break;
                    }
                if (okay) cnt[i] += cnt[j];
            }
    }
    /*for (int i = 1; i <= n; i++)
        cout << cnt[i] << " ";
    cout << endl;*/

    for (int i = 1; i <= n; i++)
        if (dp[i] == rmax)
        {
            bool okay = true;
            for (int j = i + 1; j <= n; j++)
                if (dp[j] == rmax && num[j] == num[i])
                {
                    okay = false;
                    break;
                }
            if (okay) res += cnt[i];
        }
    cout << rmax << " " << res << endl;
    return 0;
}
