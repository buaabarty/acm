// =====================================================================================
// 
//       Filename:  delish.cc
// 
//    Description:  dynamic programming
// 
//        Version:  1.0
//        Created:  2013年06月12日 18时04分18秒
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

typedef long long LL;

const LL N = 10000 + 9;
LL num[N], n, Fmax[N], Fmin[N], Tmax[N], Tmin[N];

LL iabs(LL x) {
    return (x > 0) ? x : -x;
}

int main (int argc, char *argv[]) {
    LL T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (LL i = 1; i <= n; ++i) cin >> num[i];
        LL now = 0;
        for (LL i = 1; i <= n; ++i) {
            now += num[i];
            Fmax[i] = now;
            checkMax(now, 0LL);
        }
        now = 0;
        for (LL i = 1; i <= n; ++i) {
            now += num[i];
            Fmin[i] = now;
            checkMin(now, 0LL);
        }
        now = 0;
        for (LL i = n; i >= 1; --i) {
            now += num[i];
            Tmax[i] = now;
            checkMax(now, 0LL);
        }
        now = 0;
        for (LL i = n; i >= 1; --i) {
            now += num[i];
            Tmin[i] = now;
            checkMin(now, 0LL);
        }
        LL ans = 0;
        for (LL i = 1; i < n; ++i)
            checkMax(ans, max(iabs(Fmax[i]-Tmin[i+1]), iabs(Fmin[i]-Tmax[i+1])));
        cout << ans << endl;
    }
    return 0;
}
