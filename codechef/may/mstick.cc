#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 100000 + 9;

int st1[maxn][20], st2[maxn][20];
int n, dat[maxn];
int mlog2[maxn], p2[20];

void init() {
    p2[0] = 1;
    for (int i = 1; i < 20; ++i) p2[i] = p2[i-1]<<1;
    for (int i = 1; i < maxn; ++i)
        mlog2[i] = (int)(log2(i)+1e-6);
    for (int i = 1; i <= n; ++i)
        st1[i][0] = st2[i][0] = dat[i];
    for (int j = 1, t = 1; j < 20; ++j, t *= 2)
        for (int i = 1; i+t*2-1<=n; ++i) {
            st1[i][j] = max(st1[i][j-1], st1[i+t][j-1]);
            st2[i][j] = min(st2[i][j-1], st2[i+t][j-1]);
        }
}
int qmax(int x, int y) {
    int l = mlog2[y-x+1];
    return max(st1[x][l], st1[y-p2[l]+1][l]);
}
int qmin(int x, int y) {
    int l = mlog2[y-x+1];
    return min(st2[x][l], st2[y-p2[l]+1][l]);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &dat[i]);
    int q;
    init();
    scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y); ++x; ++y;
        int t = qmin(x, y);
        int a = 0, b = 0, c = 0;
        if (x > 1) a = qmax(1, x-1)*2;
        if (y < n) b = qmax(y+1, n)*2;
        c = qmax(x, y)-t;
        int ans = max(max(a, b), c) + t*2;
        if (ans&1) printf("%d.5\n", ans/2);
        else printf("%d.0\n", ans/2);
    }
    return 0;
}
