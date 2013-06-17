// =====================================================================================
// 
//       Filename:  chaornot.cc
// 
//    Description:  gao
// 
//        Version:  1.0
//        Created:  2013年06月15日 21时50分10秒
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

int m, num[100000 + 9];

bool isp(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

int main (int argc, char *argv[]) {
    while (scanf("%d", &m) == 1) {
        for (int i = 1; i <= m; ++i) scanf("%d", &num[i]);
    }
    return 0;
}
