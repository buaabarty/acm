#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define pl p<<1
#define pr p<<1|1
using namespace std;

struct node {
    int x, y1, y2, id;
    bool operator < (const node &a) const {
        return x < a.x;
    }
};

const int maxn = 100009;

namespace segment_tree {
    int d[maxn*4], f[maxn*4], n;
    bool use[maxn];
    void init(int _n) {
        n = _n;
        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(f));
    }
    void push(int p) {
        if (f[p]) { f[pl] = f[pr] = f[p]; f[p] = 0; }
    }
    void pop(int p) {
        if (f[pl] == f[pr]) {
            f[p] = f[pl];
            f[pl] = f[pr] = 0;
        } else f[p] = 0;
    }
    void insert(int a, int b, int c, int p = 1, int l = 1, int r = n) {
        push(p);
        if (a == l && b == r) {
            f[p] = c;
            return ;
        }
        int mid = (l + r) >> 1;
        if (b <= mid) insert(a, b, c, pl, l, mid);
        else if (a > mid) insert(a, b, c, pr, mid+1, r);
        else {
            insert(a, mid, c, pl, l, mid);
            insert(mid+1, b, c, pr, mid+1, r);
        }
        pop(p);
    }
    int query(int x, int p = 1, int l = 1, int r = n) {
        if (f[p] || l == r) return f[p];
        int mid = (l + r) >> 1;
        if (x <= mid) return query(x, pl, l, mid);
        else return query(x, pr, mid+1, r);
    }
    void squery(int st, int ed, vector<int> &ans) {
        memset(use, 0, sizeof(use));
        use[0] = 1;
        for (int i = st; i <= ed; ++i) {
            int x = query(i);
            if (!use[x]) {
                ans.push_back(x);
                use[x] = 1;
            }
        }
    }
}

vector<int> adj[maxn];

void print(vector<int> d) {
    for (int i = 0; i < d.size(); ++i)
        printf("%d ", d[i]);
    puts("");
}

int main() {
    int T, n;
    node d[8847];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d", &d[i].y1, &d[i].y2, &d[i].x), d[i].id = i, d[i].y1 = d[i].y1 * 2 + 1, d[i].y2 = d[i].y2 * 2 + 1;
        sort(d + 1, d + n + 1);
        segment_tree::init(16001);
        d[n + 1].x = -1;
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 1; i <= n; ++i) {
            segment_tree::squery(d[i].y1, d[i].y2, adj[d[i].id]);
            segment_tree::insert(d[i].y1, d[i].y2, d[i].id);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int s = adj[i].size();
            for (int x = 0; x < s; ++x)
                for (int y = 0; y < s; ++y) {
                    int dy = adj[i][y];
                    for (int k = 0, ys = adj[dy].size(); k < ys; ++k)
                        if (adj[dy][k] == adj[i][x]) ++ans;
                }
        }
        printf("%d\n", ans);
    }
    return 0;
}
