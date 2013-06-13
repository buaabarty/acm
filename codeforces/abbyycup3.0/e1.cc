// =====================================================================================
// 
//       Filename:  e1.cc
// 
//    Description:  implement
// 
//        Version:  1.0
//        Created:  2013年06月12日 21时04分50秒
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

const LL module = 1000000000;

const int N = 100 + 9;

int num[N], n, m;
LL f[N];

int main (int argc, char *argv[]) {
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 100; ++i) f[i] = (f[i-1] + f[i-2]) % module;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
        for (int i = 1; i <= m; ++i) {
            int t, a, b;
            scanf("%d%d%d", &t, &a, &b);
            if (t == 1) {
                num[a] = b;
            } else {
                LL ret = 0;
                for (LL j = 0; j <= b - a; ++j) {
                    ret = (ret + (LL)f[j] * (LL)num[a+j]) % module;
                }
                printf("%d\n", (int)ret);
            }
        }
    }

    return 0;
}
