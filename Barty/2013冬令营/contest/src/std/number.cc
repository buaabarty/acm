#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
LL c[2010][1010];
const LL module1 = 1000000007;
const LL module2 = 1000000006;
void init() {
    c[0][0] = 1;
    for (LL i = 1; i <= 2000; ++i) {
        c[i][0] = 1;
        for (LL j = 1; j <= i; ++j) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % module2;
        }
    }
}
LL pow(LL x, LL y) {
    LL s = 1;
    while (y) {
        if (y & 1) s = (s * x) % module1;
        x = (x * x) % module1;
        y >>= 1;
    }
    return s;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    LL n, m;
    init();
    scanf("%I64d%I64d", &n, &m);
    if (n == 1) {
        printf("%I64d\n", m);
        return 0;
    }
    LL ans = 1;
    for (LL i = 2; i <= m; ++i) {
        LL t = (c[m-i+n-2][n-2] * n) % module2;
        ans = (ans * pow(i, t)) % module1;
    }
    printf("%I64d\n", ans);
    return 0;
}
