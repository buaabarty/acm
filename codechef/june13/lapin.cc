// =====================================================================================
// 
//       Filename:  lapin.cc
// 
//    Description:  implement
// 
//        Version:  1.0
//        Created:  2013年06月12日 01时11分39秒
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

int cnt[26];

int main (int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
       char str[1000 + 9];
       scanf("%s", str);
       memset(cnt, 0, sizeof(cnt));
       int len = strlen(str), mid;
       mid = len / 2;
       for (int i = 0; i < mid; ++i) cnt[str[i] - 'a']++;
       for (int i = len - mid; i < len; ++i) cnt[str[i]-'a']--;
       bool flag = true;
       for (int i = 0; i < 26; ++i)
           if (cnt[i]) {
               flag = false;
               break;
           }
       puts((flag)?"YES":"NO");
    }
    return 0;
}
