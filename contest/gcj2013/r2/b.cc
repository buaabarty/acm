// =====================================================================================
// 
//       Filename:  b.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2013年06月02日 00时26分03秒
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

typedef long long LL;
template <typename T> void checkMin(T &a, const T &b) { if (b < a) a = b; }
template <typename T> void checkMax(T &a, const T &b) { if (b > a) a = b; }

const int N = 1000000 + 11;
LL n, p;
LL f1()
{
    LL l = 1 , r = (1LL<<n);
    while (l < r) {
        LL m = (l+r+1)/2, res = 0, b = (m-1) ;
        for (LL j = 1 ; j <= n ; j++){
            if (!b) res <<= 1;
            else {
                res = (res << 1) | 1;
                b--;
                b/=2;
            }
        }
        if (res+1<=p) l = m;
        else r = m-1;
    }
    return l-1;
}
LL f2(){
    LL l = 1 , r = (1LL<<n);
    while (l < r) {
        LL m = (l+r+1)/2, res = 0, b = (1LL<<n)-m;
        for (LL j = 1 ; j <= n ; j++){
            if (!b) res <<= 1, res +=1;
            else {
                res *= 2;
                b-=1, b/=2;
            }
        }
        if (res+1<=p) l = m;
        else r = m-1;
    }
    return l-1;
}


int main (int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%lld%lld", &n, &p);
        printf("Case #%d: %lld %lld\n", ca, f1(), f2());
    }
    return 0;
}
