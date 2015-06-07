#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long LL;
class func {
    LL count1(LL x) {
        LL sum = 0;
        for (LL j = 1; j <= x; j <<= 1) {
            LL t = x / (j * 2);
            t *= j;
            LL z = x % (j * 2);
            if (z >= j) t += z - j + 1;
            sum += t;
        }
        return sum;
    }
    public : void gao() {
        LL n, k;
        scanf("%I64d%I64d", &n, &k);
        LL l = (LL)(sqrt(n) + 1e-6);
        if (2 * k + 1 >= l) printf("%I64d\n", count1(n));
        else printf("%I64d\n", count1(n) - count1(n - sqr(2 * k + 1)));
    }
};
int main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    func a;
    a.gao();
    return 0;
}
