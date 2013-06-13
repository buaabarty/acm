// =====================================================================================
// 
//       Filename:  predict.cc
// 
//    Description:  probability
// 
//        Version:  1.0
//        Created:  2013年06月12日 10时47分59秒
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

double func(double p, int i) {
    return p * ((2-2*p)*i-10000+i) + (1-p) * ((2-2*(1-p))*(10000-i)-i);
}

int main (int argc, char *argv[]) {
    int T;
    double p;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf", &p);
        double ans = -1e20;
        checkMax(ans, func(p, 0));
        checkMax(ans, func(p, 10000));
        printf("%.10f\n", 10000 + ans);
    }
    return 0;
}
