#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, k;
int s[1100];
int fa[1100];
int father(int v) {
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
void gao(int x, int y) {
    int fx = father(x), fy = father(y);
    if (fx != fy) fa[fx] = fy;
}
bool app[1100];
bool d[1100];
int main() {
    scanf("%d%d", &n, &m);
    int tot1 = 0, tot2 = 0;
    for (int i = 1; i <= m; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        if (!k) ++tot1;
        for (int j = 1; j <= k; ++j) {
            scanf("%d", &s[j]);
            app[s[j]] = 1;
        }
        for (int j = 1; j < k; ++j)
            gao(s[j], s[j + 1]);
    }
    for (int i = 1; i <= m; ++i)  fa[i] = father(i);
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= m; ++i)
        if (app[i] && !d[fa[i]]) {
            d[fa[i]] = 1;
            ++tot2;
        }
    if (tot2 > 0) --tot2;
    printf("%d\n", tot1+tot2);
    return 0;
}
