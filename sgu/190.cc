// =====================================================================================
// 
//       Filename:  190.cc
// 
//    Description:  二分图匹配
// 
//        Version:  1.0
//        Created:  2013年05月24日 16时06分14秒
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Boyang Yang (barty), maiL@barty.ws
//        Company:  http://barty.ws
// 
// =====================================================================================


#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;
template <typename T> void checkMin(T &a, const T &b) { if (b < a) a = b; }
template <typename T> void checkMax(T &a, const T &b) { if (b > a) a = b; }

const int Bsize = 40 + 9;
const int N = 1600 + 9;
const int M = 100000 + 9;

bool dat[Bsize][Bsize];
int n;
int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


struct edge {
    int v, next;
} e[M];
int p[N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y) {
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
bool vst[N];
int pre[N];
bool hungary(int v) {
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v]) {
            vst[e[i].v] = 1;
            if (!pre[e[i].v] || hungary(pre[e[i].v])) {
                pre[e[i].v] = v;
                return true;
            }
        }
    return false;
}
int maxpair() {
    memset(pre, 0, sizeof(pre));
    int ret = 0;
    for (int i = 1; i <= n; ++i) 
        if (!pre[i]) {
            memset(vst, 0, sizeof(vst));
            ret += hungary(i);
        }
    return ret;
}

int main (int argc, char *argv[]) {
    int p;
    while (scanf("%d%d", &n, &p) == 2) {
        init();
        int nn = n;
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dat[i][j] = 1;
        for (int i = 1; i <= p; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            dat[x][y] = 0;
        }
        p = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (!dat[i][j]) ++p;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dat[i][j] && ((i+j)&1))
                    for (int k = 0; k < 4; ++k) {
                        int dx = i + step[k][0], dy = j + step[k][1];
                        if (dat[dx][dy]) insert((i-1)*n+j, (dx-1)*n+dy);
                    }
        n = n * n;
        int ans = maxpair();
        if (ans * 2 + p == n) {
            n = nn;
            puts("Yes");
            int cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    if (!((i+j)&1) && pre[(i-1)*n+j]) {
                        int x = (pre[(i-1)*n+j]-1)/n+1;
                        int y = pre[(i-1)*n+j]%n;
          //              cout << i << " " << j << " " << x << " " << y << endl;
                        if (0 == y) y = n;
                        if (i != x) ++cnt1; else ++cnt2;
                    }
            printf("%d\n", cnt1);
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    if (!((i+j)&1) && pre[(i-1)*n+j]) {
                        int x = (pre[(i-1)*n+j]-1)/n+1;
                        int y = pre[(i-1)*n+j]%n;
                        if (0 == y) y = n;
                        if (i != x) printf("%d %d\n", min(i, x), j);
                    }
            printf("%d\n", cnt2);
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    if (!((i+j)&1) && pre[(i-1)*n+j]) {
                        int x = (pre[(i-1)*n+j]-1)/n+1;
                        int y = pre[(i-1)*n+j]%n;
                        if (0 == y) y = n;
                        if (i == x) printf("%d %d\n", i, min(j, y));
                    }
        } else {
            puts("No");
        }
    }
    return 0;
}
