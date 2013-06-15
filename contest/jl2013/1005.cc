#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000000 * 2 + 9;
const int inf = 1000000000;
template <typename T> void checkMax(T &a, const T &b) {
    if (b > a) a = b;
}
template <typename T> void checkMin(T &min1, T &min2, const T &x) {
    if (x < min2) min2 = x;
    if (min2 < min1) swap(min1, min2);
}
struct edge {
    int v, next;
} e[N];
int p[N], eid;
int n;
bool vst[N];
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y) {
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y) {
    insert(x, y);
    insert(y, x);
}

int dp[2][N];

struct data {
    int id, deep;
    bool operator < (const data &a) const {
        return deep > a.deep;
    }
} d[N];

int q[N];

void build() {
    int l = 0, r = 1;
    q[0] = 1;
    d[1].id = 1;
    d[1].deep = 0;
    vst[1] = 1;
    while (l-r) {
        int now = q[l++];
        for (int i = p[now]; ~i; i = e[i].next)
            if (!vst[e[i].v]) {
                vst[e[i].v] = 1;
                q[r++] = e[i].v;
                d[e[i].v].deep = d[now].deep + 1;
                d[e[i].v].id = e[i].v;
            }
    }
}

void dfs(int v) {
    vst[v] = 1;
    int cnt = 0, tot = 0, md1 = inf, md2 = inf;
    for (int i = p[v]; ~i; i = e[i].next)
        if (!vst[e[i].v]) {
            dfs(e[i].v);
            ++cnt;
            tot += dp[1][e[i].v];
            checkMin(md1, md2, dp[0][e[i].v] - dp[1][e[i].v]);
        }
    if (cnt == 0) {
        dp[0][v] = dp[1][v] = 0;
    } else if (cnt == 1) {
        dp[0][v] = min(tot + md1, tot + 1);
        dp[1][v] = dp[0][v];
    } else {
        dp[0][v] = tot + cnt + min(md1 - 1, 0);
        dp[1][v] = tot + cnt + min(md1 + md2 - 2, 0);
        dp[1][v] = min(dp[0][v], dp[1][v]);
    }
}

void gao() {
    for (int i = 1; i <= n; ++i) {
        int x = d[i].id;
        int cnt = 0, tot = 0, md1 = inf, md2 = inf;
        for (int j = p[x]; ~j; j = e[j].next)
            if (vst[e[j].v]) {
                int y = e[j].v;
                ++cnt;
                tot += dp[1][y];
                checkMin(md1, md2, dp[0][y] - dp[1][y]);
            }
        if (cnt == 0) {
            dp[0][x] = dp[1][x] = 0;
        } else if (cnt == 1) {
            dp[0][x] = min(tot + md1, tot + 1);
            dp[1][x] = dp[0][x];
        } else {
            dp[0][x] = tot + cnt + min(md1 - 1, 0);
            dp[1][x] = tot + cnt + min(md1 + md2 - 2, 0);
            dp[1][x] = min(dp[0][x], dp[1][x]);
        }
        vst[x] = 1;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        for (int i = 1; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            insert2(x, y);
        }
        memset(vst, 0, sizeof(vst));
        build();
        sort(d + 1, d + n + 1);
        memset(vst, 0, sizeof(vst));
        gao();
        //dfs(1);
        printf("%d\n", 2 * dp[1][1] + 1);
    }
    return 0;
}
