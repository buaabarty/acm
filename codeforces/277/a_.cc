#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int fa[110];
int father(int v) {
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
void gao(int x, int y) {
    int fx = father(x), fy = father(y);
    if (fx != fy) fa[fx] = fy;
}
bool app[110];
int dat[110];
int main() {
    int n, m;
    int st, ans = 0;
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i = 1; i <= m; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) {
        int k; scanf("%d", &k);
        if (k == 0) ++ans;
        for (int j = 1; j <= k; ++j) scanf("%d", &dat[j]);
        for (int j = 2; j <= k; ++j) gao
    }
    return 0;
}
