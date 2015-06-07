#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100000 + 9;
int a[N], n, T;
bool okay(int limit) {
    int st = a[0] - limit;
    for (int i = 1; i < n; ++i) {
        if (a[i] + limit <= st) {
            return false;
        }
        st = max(a[i] - limit, st);
    }
    return true;
}
int main() {
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int left = 0, right = 1000000, mid;
        while (left < right) {
            if (left + 1 == right) {
                if (!okay(left)) left = right;
                break;
            }
            mid = (left + right) >> 1;
            if (okay(mid)) right = mid;
            else left = mid + 1;
        }
        printf("Case #%d:\n%d\n", ca, left);
    }
    return 0;
}
