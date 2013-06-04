// =====================================================================================
// 
//       Filename:  c.cc
// 
//    Description:  topsort
// 
//        Version:  1.0
//        Created:  2013年06月02日 01时04分10秒
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

const int N = 2000 + 9;

bool small[N][N];
int n, rd[N], a[N], b[N];
bool vst[N];
int q[N], l, r, ans[N];

int main (int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &b[i]);
        memset(rd, 0, sizeof(rd));
        memset(vst, 0, sizeof(vst));
        memset(small, 0, sizeof(small));
        for (int i = 1; i <= n; ++i) {
            int last = 0;
            for (int j = 1; j < i; ++j)
                if (a[j] + 1 > a[i]) small[i][j] = 1;
                else if (a[j] + 1 == a[i]) last = j;
            if (last)  small[last][i] = 1;
        }
        for (int i = n; i >= 1; --i) {
            int last = 0;
            for (int j = n; j > i; --j)
                if (b[j] + 1 > b[i]) small[i][j] = 1;
                else if (b[j] + 1 == b[i]) last = j;
            if (last) small[last][i] = 1;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (small[i][j]) ++rd[j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (!rd[j] && !vst[j]) {
                    for (int k = 1; k <= n; ++k)
                        if (!vst[k] && small[j][k]) {
                            --rd[k];
                        }
                    vst[j] = 1;
                    ans[j] = i;
                    break;
                }
        printf("Case #%d: ", ca);
        for (int i = 1; i <= n; ++i)
            printf("%d%c", ans[i], " \n"[i==n]);
    }
    return 0;
}
