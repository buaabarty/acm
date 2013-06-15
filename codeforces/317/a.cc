// =====================================================================================
// 
//       Filename:  a.cc
// 
//    Description:  implement
// 
//        Version:  1.0
//        Created:  2013年06月14日 23时33分14秒
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

LL x, y, m;

int main (int argc, char *argv[]) {
    while (cin >> x >> y >> m) {
        if (x > y) swap(x, y);
        if (x <= 0 && y <= 0) {
            if (max(x, y) >= m) printf("0\n");
            else printf("-1\n");
        } else {
            int cnt = 0;
            while (y < m) {
                ++cnt;
                x = x + y;
                if (x > y) swap(x, y);
            }
            printf("%d\n", cnt);

        }
    }
    return 0;
}
