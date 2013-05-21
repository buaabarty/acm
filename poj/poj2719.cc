#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL len(LL x) {
    LL s = 0;
    while (x) {
        ++s; x /= 10;
    }
    return s;
}
LL f[20], pw10[20];
LL count(LL x, LL len) {
    if (len == 1) return (bool)(x >= 5);
    LL l = pw10[len-1], d;
    d = x / l;
    if (d < 4) return count(x-d*l, len-1) + d*f[len-1];
    else return l + (d-1)*f[len-1] + count(x-d*l, len-1);
}
int main() {
    pw10[0] = 1;
    for (LL i = 1; i <= 15; ++i) pw10[i] = pw10[i-1] * 10;
    f[1] = 9;
    for (LL i = 2; i <= 15; ++i)
        f[i] = f[i-1] * 9;
    for (LL i = 1; i <= 15; ++i)
        f[i] = pw10[i] - f[i];
    LL n;
    while (cin >> n, n) {
        cout << n << ": " << n - count(n, len(n)) << endl;
    }
    return 0;
}
