#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10000000 + 9;
int n, m;
struct data {
    int v, x;
    bool operator < (const data &a) const {
        return x > a.x;
    }
    data(int _v, int _x) {
        x = _x; v = _v;
    }
    data() {}
};
vector<data> e[maxn];
int k1[maxn], d1[maxn], d2[maxn];
void dfs(int x) {
    //printf("%d   %d\n", x, e[x].);
    for (int i = 0, s = e[x].size(); i < s; ++i) {
        dfs(e[x][i].v);
        d1[x] += d1[e[x][i].v];
        d2[x] += d2[e[x][i].v];
        e[x][i].x = d2[e[x][i].v];
    }
    sort(e[x].begin(), e[x].end());
    d1[x] += k1[x];
    d2[x]++;
    //cout << x << " " << d1[x] << " " << d2[x] << endl;
}
int gao(int v) {
    int last = m - k1[v], s = e[v].size(), ans = 0;
    for (int i = 0; i < s; ++i) {
        if (last >= d1[e[v][i].v]) {
            last -= d1[e[v][i].v];
            ans += e[v][i].x;
        } else {
            ans += gao(e[v][i].v);
        }
    }
    //cout << v << " " << ans << endl;
    return ans;
}
int main() {
    freopen("example.in", "r", stdin);
    //freopen("example.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int k, x; scanf("%d%d", &k1[i], &k);
        while (k--) {
            scanf("%d", &x);
            e[i].push_back(data(x, 0));
        }
    }
    dfs(0);
    printf("%d\n", gao(0));
    return 0;
}
