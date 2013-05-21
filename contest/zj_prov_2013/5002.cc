#include <iostream>
#include <cstdio>
#include <cstring>
#define count1 __builtin_popcount
using namespace std;

struct bitset {
    int a, b, c, d;
    bitset() {
        a = b = c = d = 0;
    }
    void init() {
        a = b = c = d = 0;
    }
    void insert(int k) {
        if (k < 25) a |= (1<<k);
        else if (k < 50) b |= (1<<(k-25));
        else if (k < 75) c |= (1<<(k-50));
        else d |= (1<<(k-75));
    }
    int count(const bitset &x) {
        return count1(a&x.a) + count1(b&x.b) + count1(c&x.c) + count1(d&x.d);
    }
} d[110];

int n, g[110][110], m, k;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; ++i) d[i].init();
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= m; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            g[x][y] = g[y][x] = 1;
            d[x].insert(y);
            d[y].insert(x);
        }
        bool find;
        int ans = 0;
        do {
            find = false;
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                    if (!g[i][j] && d[i].count(d[j]) >= k) {
                        d[i].insert(j);
                        d[j].insert(i);
                        g[i][j] = g[j][i] = 1;
                        ++ans;
                        find = true;
                    }
        } while (find);
        printf("%d\n", ans);
    }
    return 0;
}
