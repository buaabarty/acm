#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;
const int N = 100000 + 9;
const int MOD = 1000000007;
const int inf = 1000000009;
void checkMin(int &x, int y) {
    if (y < x) x = y;
}
int k[N][26],l,ok, dp[N], f[N];
char s[N];
int gao_dp(int x) {
    if (x == -1) return 0;
    else if (~dp[x]) return dp[x];
    int ret = inf;
    for (int i = 0; i < 26; ++i) {
        checkMin(ret, 1 + gao_dp(k[x][i]));
    }
    dp[x] = ret;
    return ret;
}
int gao_f(int x) {   
    if (x == -1) return 1;
    if (f[x] != -1) return f[x];
    int ret = 0;
    for (int i = 0, o = gao_dp(x); i < 26; ++i) {
        if (o == 1 + gao_dp(k[x][i])) {
            ret += gao_f(k[x][i]);
            ret %= MOD;
        }
    }
    f[x] = ret;
    return ret;
}   
int main(){
    int T;
    int last[26];
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%s", s + 1);
        l = 1 + strlen(s + 1);
        for (int i = 1; i < l; ++i)
            s[i] -= 'a';
        memset(k, -1, sizeof(k));
        memset(last, -1, sizeof(last));
        memset(dp, -1, sizeof(dp));
        memset(f, -1, sizeof(f));
        for (int i = l - 1; i >= 0; --i) {
            for (int j = 0; j < 26; j++)
                k[i][j] = last[j];
            last[s[i]] = i;
        }
        printf("Case #%d:\n%d %d\n", ca, gao_dp(0), gao_f(0));
    }
    return 0;
}
