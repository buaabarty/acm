// =====================================================================================
// 
//       Filename:  d1.cc
// 
//    Description:  combinaration
// 
//        Version:  1.0
//        Created:  2013年06月13日 00时41分18秒
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

int c[11][11];
int p[11];
int n;

int main (int argc, char *argv[]) {
    p[0] = 1;
    for (int i = 1; i <= 10; ++i) p[i] = p[i-1] * i;
    c[0][0] = 1;
    for (int i = 1; i <= 10; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
    while (scanf("%d", &n) == 1) {
        int cnt2 = 0, cnt1 = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            if (x >= 2) ++cnt2;
            else if (x >= 1) ++cnt1;
        }
        while (cnt1 < 2) {
            --cnt2;
            ++cnt1;
        }
        int ans = 1;
        cout << cnt1 << " " << cnt2 << endl;
        cout << ans << endl;
        cnt1 = min(cnt1, 2);
        if (cnt2 <= 0) {
            printf("0\n");
            continue;
        }
        ans *= c[n][cnt1+cnt2] * p[cnt1+cnt2];
        cout << c[n][cnt1+cnt2] << " " << p[cnt1+cnt2] << endl;
        printf("%d\n", ans);
    }
    return 0;
}
