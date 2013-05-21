#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int fax[10010][510], fay[10010][510];
int n, m;
int x[100010], y[100010];
int father(int f[], int a) {
    if (f[a] != a) f[a] = father(f, f[a]);
    return f[a];
}
void cb(int g[], int a, int b) {
    int fa = father(g, a);
    int fb = father(g, b);
    if (fa != fb) g[fa] = fb;
}
int df[510];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m + 1; ++i)
        for (int j = 1; j <= n; ++j)
            fax[i][j] = fay[i][j] = j;
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j)
            fax[i][j] = fax[i-1][j];
        cb(fax[i], x[i], y[i]);
        for (int j = 1; j <= n; ++j)
            fax[i][j] = father(fax[i], j);
    }
    for (int i = m; i >= 1; --i) {
        for (int j = 1; j <= n; ++j)
            fay[i][j] = fay[i+1][j];
        cb(fay[i], x[i], y[i]);
        for (int j = 1; j <= n; ++j)
            fay[i][j] = father(fay[i], j);
    }

    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        //for (int j = 1; j <= n; ++j)
        //    printf("%d%c", fax[l-1][j], " \n"[j==n]);
        //for (int j = 1; j <= n; ++j)
        //    printf("%d%c", fay[r+1][j], " \n"[j==n]);
        for (int j = 1; j <= n; ++j) df[j] = fax[l-1][j];
        for (int j = 1; j <= n; ++j) {
            if (df[j] != fay[r+1][j]) cb(df, j, fay[r+1][j]);
        }
        for (int j = 1; j <= n; ++j)
            df[j] = father(df, j);
        //for (int j = 1; j <= n; ++j)
        //    printf("%d%c", df[j], " \n"[j==n]);
        sort(df + 1, df + n + 1);
        int ans = unique(df + 1, df + n + 1) - df - 1;
        printf("%d\n", ans);
    }
    return 0;
}
