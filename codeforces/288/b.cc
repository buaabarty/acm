#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long n, k, res = 1;
const long long mod = 1000000007LL;
int main() {
    cin >> n >> k;
    for (int i = 2; i <= k; ++i) {
        res = (res * k) % mod;
    }
    for (int i = k + 1; i <= n; ++i)
        res = (res * (n - k)) % mod;
    cout << res << endl;
    return 0;
}
