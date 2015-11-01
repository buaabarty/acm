#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL f[16] = {0, 1, 2, 2, 3, 3, 4, 3, 5, 4, 5, 4, 6, 5, 6, 4};
pair<LL, LL> get_dp(LL n) {
    LL l = 0, x = n;
    while (x) {
        l++;
        x >>= 1;
    }
    return make_pair<LL, LL>(l, n - (1<<(l-1)) + 1);
}
LL gao(LL x) {
    if (x <= 15) return f[x];
    pair<LL, LL> dt = get_dp(x);
    LL l = dt.first, d = dt.second;
    if (d & 1) {
        if (d <= (1LL << (l - 2))) {
            return (l - 1) * 2 - 1;
        } else {
            return (l - 1) * 2;
        }
    } else {
        return gao(x / 2) + 1;
    }
}
int main() {
    LL x;
    while (cin >> x) {
        cout << gao(x) << endl;
    }
    return 0;
}
