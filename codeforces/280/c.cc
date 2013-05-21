#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> e[100010];
int d[100010];
int n;
bool vst[100010];
void dfs(int v, int l) {
    vst[v] = 1;
    d[v] = l;
    for (int i = 0; i < e[v].size(); ++i)
        if (!vst[e[v][i]]) {
            dfs(e[v][i], l + 1);
        }
}
int main() {
    int x, y;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 1);
    double ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += 1 / (double)d[i];
    printf("%.10f\n", ans);
    return 0;
}
