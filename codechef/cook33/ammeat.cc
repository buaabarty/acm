#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long m, p[20];
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> p[i];
        sort(p + 1, p + n + 1);
        int res = -1;
        for (int i = n; i >= 1; --i) {
            m -= p[i];
            if (m <= 0) {
                res = n - i + 1;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
