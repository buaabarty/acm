#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MAXN 5010
using namespace std;
int n;
string str, rev;
int dp[2][MAXN];
string reverse(string s)
{
    string temp = s;
    int len = temp.length();
    for (int i = 0; i < len; ++i)
        swap(temp[i], temp[len - i - 1]);
    return temp;

}
int main()
{
    scanf("%d", &n);
    cin >> str;
    rev = str;
    for (int i = 0; i < n / 2; ++i)
        swap(rev[i], rev[n - i - 1]);
    memset(dp, 0, sizeof(dp));
    int k = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[k][j] = max(dp[k ^ 1][j], dp[k][j - 1]);
            if (str[i - 1] == rev[j - 1]) dp[k][j] = max(dp[k][j], dp[k ^ 1][j - 1] + 1);
        }
        k = k ^ 1;
        for (int j = 0; j <= n; ++j)
            dp[k][j] = 0;
    }
    printf("%d\n", n - dp[k ^ 1][n]);
    return 0;
}
