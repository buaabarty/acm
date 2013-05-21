#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[11][11][11];
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        printf("Case #%d: ", ca);
        if (a <= n) {
            int cb = b / 2;
            if (n - cb < cb) puts("-1");
            else if (n - cb > cb) puts("1");
            else puts("0");
        } else {
            int cb = 0;
            while (b > (a - n + cb)) {
                b -= (a - n + cb + 1);
                ++cb;
            }
            if (n - cb < cb) puts("-1");
            else if (n - cb > cb) puts("1");
            else puts("0");
        }
    }
    return 0;
}
