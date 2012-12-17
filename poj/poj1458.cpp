#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1024
using namespace std;
int dp[N][N];
int max(int a, int b, int c)
{
    return max(max(a, b), c);
}
int common(string a, string b)
{
    memset(dp, 0, sizeof(dp));
    int la = a.length();
    int lb = b.length();
    for (int i = 1; i <= la; ++i)
        for (int j = 1; j <= lb; ++j)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]));
    return dp[la][lb];
}
int main()
{
    string a, b;
    while (cin >> a >> b)
        cout << common(a, b) << endl;
    return 0;
}
