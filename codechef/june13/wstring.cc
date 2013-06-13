// =====================================================================================
// 
//       Filename:  wstring.cc
// 
//    Description:  implement
// 
//        Version:  1.0
//        Created:  2013年06月12日 20时38分19秒
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

const int N = 10000 + 9;

int dat[N], len, cnt[26];
char str[N];

int gao() {
    int t = 0;
    for (int i = 0; i < 26; ++i) checkMax(t, cnt[i]);
    memset(cnt, 0, sizeof(cnt));
    return t;
}

int main (int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        memset(cnt, 0, sizeof(cnt));
        len = 0;
        for (int i = 0; str[i]; ++i) {
            if (str[i] == '#') dat[++len] = gao();
            else ++cnt[str[i]-'a'];
        }
        dat[++len] = gao();
        int ans = 0;
        for (int i = 1; i + 3 <= len; ++i)
            if (dat[i] && dat[i+1] && dat[i+2] && dat[i+3])
                checkMax(ans, dat[i] + dat[i+1] + dat[i + 2] + dat[i + 3] + 3);
        printf("%d\n", ans);
    }
    return 0;
}
