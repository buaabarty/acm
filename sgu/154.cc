// =====================================================================================
// 
//       Filename:  154.cc
// 
//    Description:  二分，5进制
// 
//        Version:  1.0
//        Created:  2013年05月25日 19时39分54秒
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

LL gao(LL x) {
    LL s = 0;
    while (x) {
        s += x / 5;
        x /= 5;
    }
    return s;
}

int main (int argc, char *argv[]) {
    LL q;
    while (scanf("%lld", &q) == 1) {
        LL l = 1, r = 100000000000000000LL, mid;
        while (l < r) {
            if (l + 1 == r) {
                if (gao(l) < q) l = r;
                break;
            }
            mid = (l + r) >> 1;
            if (gao(mid) >= q) r = mid;
            else l = mid + 1;
        }
        if (gao(l) == q) printf("%lld\n", l);
        else puts("No solution");
    }
    return 0;
}
