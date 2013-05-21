#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c[1010][1010], n;
const int module = 1000000007;
void init() {
    c[0][0] = 1;
    for (int i = 1; i <= 1000; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
            if (c[i][j] >= module) c[i][j] -= module;
        }
    }
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, x;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &x);
        int ans = 0;
        for (int i = n/2+1; i <= n; ++i) {
            ans += c[n][i];
            if (ans >= module) ans -= module;
        }
        printf("%d\n", ans);
    }
    return 0;
}
