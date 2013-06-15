// =====================================================================================
//
//       Filename:  d.cc
//
//    Description:  SG function
//
//        Version:  1.0
//        Created:  2013Äê06ÔÂ14ÈÕ
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Boyang Yang (barty), maiL@barty.ws
//        Company:  http://barty.ws
//
// =====================================================================================
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int S[] = {1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};
int getSG(int x){
    return S[x - 1];
}
bool use[100000];
bool gao(int n) {
    memset(use, 0, sizeof(use));
    int one = 1, ret = 0, tot = 0;
    for (int i = 2; i * i <= n; ++i) if (!use[i]) {
        int cnt = 0;
        LL j = i;
        while(j <= n){
            ++cnt;
            if (j < 100000) use[j] = 1;
            j *= i;
        }
        tot += cnt;
        ret ^= getSG(cnt);
    }
    ret ^= ((n - tot) & 1);
    return (bool)(ret > 0);
}
int main(){
    int n;
    while (scanf("%d", &n) == 1) {
        puts(gao(n) ? "Vasya" : "Petya");
    }

}
