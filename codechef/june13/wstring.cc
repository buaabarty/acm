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

const int N = 100000 + 9;

int dat[N], len, cnt[26], a[N][26], b[N][26];
char str[N];

int gao() {
    int t = 0;
    for (int i = 0; i < 26; ++i) checkMax(t, cnt[i]);
    memset(cnt, 0, sizeof(cnt));
    return t;
}

int query(int l, int r) {
    int ret = 0;
    for (int i = 0; i < 26; ++i) checkMax(ret, a[r][i] - a[l-1][i]);
    return ret;
}

int sharpsequence[N], sharpcnt;

int main (int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        memset(cnt, 0, sizeof(cnt));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        len = strlen(str);
        sharpcnt = 0;
        for (int i = 0; str[i]; ++i) {
            if (str[i] == '#') {
                dat[i + 1] = -1;
                sharpsequence[++sharpcnt] = i + 1;
            }
            else dat[i + 1] = str[i] - 'a';
        }
        for (int i = 1; i <= len; ++i) 
            for (int j = 0; j < 26; ++j)
                a[i][j] = a[i-1][j] + (dat[i] == j);
        int ans = 0;
        for (int i = 1; i + 2 <= sharpcnt; ++i) {
            int t1 = query(1, sharpsequence[i]);
            int t2 = query(sharpsequence[i], sharpsequence[i+1]);
            int t3 = query(sharpsequence[i+1], sharpsequence[i+2]);
            int t4 = query(sharpsequence[i+2], len);
            if (t1 && t2 && t3 && t4) checkMax(ans, t1 + t2 + t3 + t4 + 3);
        }
        printf("%d\n", ans);
    }
    return 0;
}
