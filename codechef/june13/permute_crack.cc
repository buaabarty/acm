// =====================================================================================
// 
//       Filename:  permute_crack.cc
// 
//    Description:  crack
// 
//        Version:  1.0
//        Created:  2013年06月15日 21时03分48秒
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

bool okay(int num[], int n, int m) {
    for (int i = 0; i < n - 1; ++i)
        if (num[i] + num[i + 1] > m) return false;
    return true;
}

int num[10];

int main (int argc, char *argv[]) {
    for (int i = 1; i <= 10; ++i) {
        printf("%d\n", i);
        for (int j = 2; j <= i * 2; ++j) {
            for (int k = 0; k < i; ++k) num[k] = k + 1;
            int cnt = 0;
            do {
                if (okay(num, i, j)) ++cnt;
            } while (next_permutation(num, num + i));
            printf("%d\t%d\t%d\n", i, j, cnt);
        }
    }
    return 0;
}
