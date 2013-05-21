#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int n, a, num[200];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &a, &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
        sort(num + 1, num + n + 1);
        int res = 0, ans = 100000000;
        int sta = a;
        for (int nn = 0; nn <= n; ++nn) {
            res = 0;
            a = sta;
            for (int i = 1; i <= nn; ++i)
                if (a > num[i]) {
                    a += num[i];
                } else {
                    int x = a, t = 0;
                    for (int j = 1; j <= nn - i; ++j) {
                        x += (x - 1);
                        if (x > num[i]) {
                            t = j; break;
                        }
                    }
                    if (t) {
                        res += t;
                        a = x + num[i];
                    } else {
                        res += nn - i + 1;
                        break;
                    }
                }
            //cout << nn << " " << res << endl;
            if (res+n-nn < ans) ans = res+n-nn;
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
