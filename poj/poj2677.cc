#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define sqr(x) ((x)*(x))
using namespace std;

template <typename T> T checkmin(T &a, const T &b) { if (b < a) a = b; }

const double inf = 1e16;

struct func {
    int n;
    double f[51][51], px[51], py[51], dist[51][51], ans;
    void dfs(int x, int y, double l) {
        f[x][y] = l;
        if (x == n) {
            checkmin(ans, l + dist[y][n]);
            return ;
        }
        if (l + dist[x][x + 1] < f[x + 1][y]) dfs(x + 1, y, l + dist[x][x + 1]);
        if (l + dist[y][x + 1] < f[x + 1][x]) dfs(x + 1, x, l + dist[y][x + 1]);
    }
    bool gao() {
        if (scanf("%d", &n) != 1) return false;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf", &px[i], &py[i]);
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = sqrt(sqr(px[i] - px[j]) + sqr(py[i] - py[j]));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                f[i][j] = inf;
        ans = inf;
        dfs(1, 1, 0);
        printf("%.2f\n", ans);
        return true;
    }
};

int main() {
    for (func a; a.gao(); );
    return 0;
}
