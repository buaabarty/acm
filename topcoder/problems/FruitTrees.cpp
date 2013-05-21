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
#include <cstring>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
    if (a == 0) return b;
    else return gcd(b%a, a);
}
template <typename T> void checkmin(T &a, T b) {
    if (b < a) a = b;
}
template <typename T> void checkmax(T &a, T b) {
    if (b > a) a = b;
}
int iabs(int x) {
    if (x > 0) return x;
    else return -x;
}
int gao(int x, int y) {
    return min(y-x%y, x%y);
}
class FruitTrees {
public:
    int maxDist(int apple, int kiwi, int grape) {
        int res = 0;
        int x = gcd(apple, kiwi);
        int y = gcd(apple, grape);
        int z = gcd(kiwi, grape);
        if (x==1 || y==1 || z==1) return 0;
        else {
            for (int i = 1; i < kiwi; ++i) {
                for (int j = 1; j < grape; ++j) {
                    if (i==j) continue;
                    int now = 1000000000;
                    checkmin(now, gao(i, x));
                    checkmin(now, gao(j, y));
                    checkmin(now, gao(abs(i-j), z));
                    checkmax(res, now);
                }
            }
        }
        return res;
    }

};


// Powered by FileEdit
// Powered by CodeProcessor
