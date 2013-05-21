#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define PII pair<LL, LL>

const int maxn = 3000009;

int color[maxn];
vector<int> e[maxn];

void dfs(int v) {
    int cnt = 0, l = e[v].size();
    for (int i = 0; i < l; ++i)
        if (color[v] == color[e[v][i]]) ++cnt;
    if (cnt >= 2) {
        color[v] ^= 1;
        for (int i = 0; i < l; ++i)
            if (color[v] == color[e[v][i]]) dfs(e[v][i]);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].pb(y); e[y].pb(x);
    }
    for (int i = 1; i <= n; ++i)
        dfs(i);
    for (int i = 1; i <= n; ++i)
        printf("%d", color[i]);
    puts("");
    return 0;
}
