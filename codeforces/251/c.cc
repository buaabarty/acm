#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
const LL lcm = 360360;
const LL inf = 1000000000;
LL f[lcm+100], k;
void checkmin(LL &x, LL y) {
    if (y < x) x = y;
}
LL go(LL l, LL r) {
    if (r < l) swap(l, r);
    for (LL i = 0; i < lcm; ++i) f[i] = inf;
    f[r] = 0;
    for (LL i = r; i >= l; --i) {
        checkmin(f[i-1], f[i]+1);
        for (LL j = 2; j <= k; ++j)
            if (i-(i%j)>=l) checkmin(f[i-(i%j)], f[i]+1);
    }
    return f[l];
}
int main() {
    LL a, b, tot = 0;
    scanf("%I64d%I64d%I64d", &a, &b, &k);
    if (a/lcm == b/lcm) {
        printf("%I64d\n", go(a%lcm, b%lcm));
    } else {
        printf("%I64d\n", go(a%lcm, 0) + go(lcm-1, b%lcm) + 1 + (go(lcm-1, 0)+1)*(a/lcm-b/lcm-1));
    }
    return 0;
}
