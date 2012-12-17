#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXW 1024
using namespace std;
int w, l, dp[MAXW];
string base, words[MAXW];
int main()
{
    cin >> w >> l >> base;
    for (int i = 1; i <= w; ++i) cin >> words[i];
    memset(dp, 0x7f, sizeof(dp));
    dp[l] = 0;
    for (int i = l - 1; i >= 0; --i)
    {
        dp[i] = min(dp[i], dp[i + 1] + 1);
        for (int j = 1; j <= w; ++j)
        {
            int k = i, s = 0, len = words[j].length(), del = 0;
            while ((s < len) && (k < l))
            {
                while ((k < l) && (words[j][s] != base[k]))
                {
                    ++k;
                    ++del;
                }
                if (k >= l) break;
                ++s, ++k;
            }
            if (s == len)
            {
                dp[i] = min(dp[i], dp[k] + del);
            }
        }
    }
    printf("%d\n", dp[0]);
    return 0;
}
