#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL N = 10000 + 9;
LL T, n, m, k;
LL a[N];
int main() {
    cin >> T;
    for (LL ca = 1; ca <= T; ++ca) {
        cin >> n >> m >> k;
        for (LL i = 0; i < n; ++i) {
            scanf("%I64d", &a[i]);
        }
        sort(a, a + n);
        LL j = 0, lastj = -1;
        do {
            while (j < n && a[j] <= m) ++j;
            if (j == n || lastj >= j - 1 || k == 0) break;
            --j;
            m = a[j] + k;
            if (--k < 0) k = 0;
            lastj = j;
        } while (true);
        cout << "Case #" << ca << ":\n" << ((j == n) ? "why am I so diao?" : "madan!") << endl;
    }
    return 0;
}
