#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL module = 1000000000 + 7;
LL pow(LL x, LL y) {
    if (y < 0) return 0;
    if (x == 0) return 0;
    if (y == 0) return 1;
    LL s = 1;
    while (y) {
        if (y&1) s = (s * x) % module;
        x = (x * x) % module;
        y >>= 1;
    }
    return s;
}
LL gao1(LL n) {
    if (n == 1LL) return 1LL;
    return pow(n, n-2);
}
LL gao2(LL n) {
    LL a = pow(n, n-2);
    LL b = pow(n-1, n);
    LL c = pow(4LL, n-1);
    a = (a * b) % module;
    a = (a * c) % module;
    return a;
}
LL gao3(LL n) {
    LL a = pow(n, n-2);
    LL b = pow(n-1, n*2);
    LL c = pow(3LL, n*3-2);
    a = (a * b) % module;
    a = (a * c) % module;
    return a;
}
int main() {
    LL n, k;
    while (scanf("%lld%lld", &n, &k) == 2) {
        if (k == 1) printf("%lld\n", gao1(n));
        else if (k == 2) printf("%lld\n", gao2(n));
        else printf("%lld\n", gao3(n));
    }
    return 0;
}
