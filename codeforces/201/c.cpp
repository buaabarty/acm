#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
void update(LL &x, LL y) {
    if (y > x) x = y;
}
LL f[100010][3], n, a[100010], res;
int main() {
    scanf("%I64d", &n);
    for (LL i = 2; i <= n; ++i) scanf("%I64d", &a[i]);
    memset(f, 0, sizeof(f));
    for (LL i = 2; i <= n; ++i)
        for (LL j = 0; j < 3; ++j){
            LL now = a[i];
            if ((now + j) & 1LL) now--;
            if (!now) continue;
            for (LL k = 0; k <= j; ++k)
                update(f[i][j], f[i - 1][k] + now);
            update(res, f[i][j]);
        }
    printf("%I64d\n", res);
    return 0;
}
