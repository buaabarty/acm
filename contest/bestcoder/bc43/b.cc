#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100000 + 9;
typedef long long LL;
LL a[N], n, p;
int main() {
    while (scanf("%lld%lld", &n, &p) == 2) {
        for (LL i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            a[i] %= p;
        }
        sort(a, a + n);
        LL tot = 0;
        for (LL i = n - 1, l = 0; i > l; --i) {
            while (l < i && a[l] + a[i] < p) ++l;
            --l;
            tot = max(tot, (a[l] + a[i]) % p);
        }
        cout << tot << endl;
    }
    return 0;
}
