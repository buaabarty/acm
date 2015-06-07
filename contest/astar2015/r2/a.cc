#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;
bool inside(int x, int y, int d) {
    return min(x, y) <= d && d <= max(x, y);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int n;
        int ax[100], ay[100], bx[100], by[100];
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &ax[i], &ay[i], &bx[i], &by[i]);
            if (ax[i] > bx[i]) swap(ax[i], bx[i]);
            if (ay[i] > by[i]) swap(ay[i], by[i]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) if (ax[i] == bx[i] && ay[i] != by[i])
            for (int j = 0; j < n; ++j) if (ax[j] == bx[j] && ay[j] != by[j] && ax[i] > ax[j])
                for (int u = 0; u < n; ++u) if (ax[u] != bx[u] && ay[u] == by[u]) 
                    for (int v = 0; v < n; ++v) if (ax[v] != bx[v] && ay[v] == by[v] && ay[u] > ay[v]) {
                        if (inside(ay[i], by[i], ay[u]) && inside(ay[j], by[j], ay[u])
                                && inside(ay[i], by[i], ay[v]) && inside(ay[j], by[j], ay[v])
                                && inside(ax[u], bx[u], ax[i]) && inside(ax[v], bx[v], ax[i])
                                && inside(ax[u], bx[u], ax[j]) && inside(ax[v], bx[v], ax[j])) {
                            ++res;
                        }
                    }
        printf("Case #%d:\n%d\n", ca, res);
    }
    return 0;
}
