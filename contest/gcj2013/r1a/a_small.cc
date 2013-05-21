#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL T;
bool okay(LL r, LL t, LL k) {
    LL a = 2LL*r+2LL*k-1LL;
    if (a > t / k) return false;
    a = a * k;
    return (bool)(a <= t);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%lld", &T);
    for (int ca = 1; ca <= T; ++ca) {
        LL R, T;
        scanf("%lld%lld", &R, &T);
        LL l = 1, r = 1000000000000000000LL, mid;
        while (l < r) {
            if (l + 1LL == r) {
                if (okay(R, T, r)) l = r;
                break;
            }
            mid = (l + r + 1LL) >> 1LL;
            if (okay(R, T, mid)) l = mid;
            else r = mid - 1LL;
        }
        printf("Case #%d: %lld\n", ca, l);
    }
    return 0;
}
