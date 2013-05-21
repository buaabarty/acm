#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 109;
int g[N][N], dist[N], a[N], x[N], y[N];
bool use[N];
int n;
int iabs(int x) {
    return (x > 0) ? x : -x;
}
int get_dist(int i, int j) {
    return iabs(x[i]-x[j])+iabs(y[i]-y[j]);
}

bool okay(int x) {
    memset(dist, -1, sizeof(dist));
    dist[1] = x;
    memset(use, 0, sizeof(use));
    for (int i = 1; i <= n; ++i) {
        int mt = -1, mx = -1;
        for (int j = 1; j <= n; ++j)
            if (dist[j] > mx && !use[j]) {
                mt = j; mx = dist[j];
            }
        if (mt < 0) break;
        use[mt] = 1;
        for (int j = 1; j <= n; ++j)
            if (!use[j] && g[mt][j] <= mx) {
                dist[j] = max(dist[j], mx - g[mt][j] + a[j]);
            }
    }
    return (dist[n] >= 0);
}

int main() {
    int d;
    while (scanf("%d%d", &n, &d) == 2) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                g[i][j] = 0;
        memset(a, 0, sizeof(a));
        for (int i = 2; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &x[i], &y[i]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                g[i][j] = get_dist(i, j) * d;
        int left = 0, right = 2147483647, mid;
        while (left < right) {
            if (left + 1 == right) {
                if (!okay(left)) left = right;
                break;
            }
            mid = (left + right) >> 1;
            if (okay(mid)) right = mid;
            else left = mid + 1;
        }
        printf("%d\n", left);
    }
    return 0;
}
