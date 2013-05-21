#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL t[1010], c[1010];
LL n;
int main() {
    LL mt = 0;
    scanf("%I64d", &n);
    for (LL i = 1; i <= n; ++i) {
        scanf("%I64d%I64d", &t[i], &c[i]);
    }
    LL tot = c[1], mtot = c[1], now = t[1];
    for (LL i = 2; i <= n; ++i)
        if (now + tot > t[i]) {
            LL delta = t[i] - now;
            now += delta;
            tot -= delta;
            tot += c[i];
            mtot = max(mtot, tot);
        } else {
            now = t[i];
            tot = c[i];
            mtot = max(mtot, tot);
        }
    now += tot;
    printf("%I64d %I64d\n", now, mtot);
    return 0;
}
