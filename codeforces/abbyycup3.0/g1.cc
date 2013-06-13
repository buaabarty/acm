// =====================================================================================
// 
//       Filename:  g1.cc
// 
//    Description:  implement
// 
//        Version:  1.0
//        Created:  2013年06月12日 21时40分32秒
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

set<string> hash;

const int N = 2000 + 10;

void getnext(char *str, int next[]) {
    next[0] = -1;
    for (int i = 1, j = -1; str[i]; ++i) {
        while (~j && str[i] != str[j+1]) j = next[j];
        if (str[i] == str[j+1]) ++j;
        next[i] = j;
    }
}

char dat[20][N];
int n, next[N], l[20], r[20];

int count(char *str, int len, char *dest) {
    int ret = 0;
    for (int i = 0, j = -1; dest[i]; ++i) {
        while (~j && str[j+1] != dest[i]) j = next[j];
        if (str[j+1] == dest[i]) ++j;
        if (j == len - 1) {
            j = next[j];
            ++ret;
        }
    }
    return ret;
}
int count(char *str, int len, int x) {
    return count(str, len, dat[x]);
}

int gao(char *str) {
    getnext(str, next);
    int len = strlen(str), ret = 0;
    string now = "";
    for (int i = 1; i <= len; ++i) {
        now = now + str[i-1];
        bool flag = true;
        for (int j = 1; j <= n; ++j) {
            int ret = count(str, i, j);
            if (ret < l[j] || ret > r[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (hash.find(now) == hash.end()) {
                ++ret;
                hash.insert(now);
            }
        }
    }
    return ret;
}
char str[N];

int main (int argc, char *argv[]) {
    while (scanf("%s", str) == 1) {
        hash.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%s%d%d", dat[i], &l[i], &r[i]);
        int len = strlen(str), ret = 0;
        for (int i = 0; i < len; ++i) {
            ret += gao(str+i);
        }
        printf("%d\n", ret);
    }
    return 0;
}
