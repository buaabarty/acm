#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef unsigned long long LL;

LL p[110], q[110], m0, m1, n, v, a0, b0, c0, a1, b1, c1;

const LL module = 1000000007;

LL mul(LL x, LL y, LL mod) {
    return (x*y)%mod;
}

LL add(LL x, LL y, LL mod) {
    return (x+y)%mod;
}

LL pow(LL x, LL y) {
    LL s = 1LL;
    while (y) {
        if (y&1LL) s = mul(s, x, module);
        y >>= 1LL;
        x = mul(x, x, module);
    }
    return s;
}

int main() {
    LL T;
    scanf("%llu", &T);
    while (T--) {
        scanf("%llu%llu%llu%llu%llu%llu%llu%llu%llu%llu%llu%llu%llu%llu", &v, &n, &p[0], &p[1], &a0, &b0, &c0, &m0, &q[0], &q[1], &a1, &b1, &c1, &m1);
        LL ans = 1;
        bool flag = true;
        for (LL i = 0; i < n; ++i) {
            if (i >= 2) {
                p[i] = (mul(mul(a0,a0,m0),p[i-1],m0)+add(mul(b0,p[i-2],m0),c0,m0))%m0;
                q[i] = (mul(mul(a1,a1,m1),q[i-1],m1)+add(mul(b1,q[i-2],m1),c1,m1))%m1;
            }
            if (p[i] == 0 && q[i] == 0) {
                flag = false;
            }
            ans = mul(ans, add(mul(p[i], m1, (module-1LL)), q[i], (module-1LL)),(module-1LL));
        }
        if (v%module==0) {
            if (!flag) puts("1");
            else puts("0");
            continue;
        }
        printf("%llu\n", pow(v%module, ans));
    }
    return 0;
}
