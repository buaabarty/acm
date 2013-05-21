#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, ca, cb;
bool okay(int x) {
    if (ca < x) return false;
    return (cb <= ca - x + n - x + 1);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int CA = 1; CA <= T; ++CA) {
        scanf("%d%d%d", &n, &ca, &cb);
        int l = 0, r = n, mid;
        while (l < r) {
            if (l + 1 == r) {
                if (okay(r)) l = r;
                break;
            }
            mid = (l + r + 1) >> 1;
            if (okay(mid)) l = mid;
            else r = mid - 1;
        }
        printf("LLL%d\n", l);
        printf("Case #%d: ", CA);
        if (l > n - l) printf("1\n");
        else if (l < n - l) printf("-1\n");
        else printf("0\n");
    }
    return 0;
}
