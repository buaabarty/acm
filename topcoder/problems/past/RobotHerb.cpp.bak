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
class RobotHerb {
public:
    inline long long iabs(long long x) {
        return (x < 0) ? -x : x;
    }
    inline long long dist(long long x, long long y) {
        return iabs(x) + iabs(y);
    }
    long long getdist(int T, vector <int> a) {
        long long nx = 0, ny = 0, step[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        int n = a.size(), dir = 0;
        if (T == 0) return 0;
        for (int i = 1; i <= 4; ++i) {
            for (int j = 0; j < n; ++j) {
                nx += step[dir][0] * a[j];
                ny += step[dir][1] * a[j];
                dir = (dir + a[j]) % 4;
            }
            if (T == i) return dist(nx, ny);
        }
        long long ss = T / 4LL;
        nx *= ss; ny *= ss;
        for (int i = 1; i <= T % 4; ++i) {
            for (int j = 0; j < n; ++j) {
                nx += step[dir][0] * a[j];
                ny += step[dir][1] * a[j];
                dir = (dir + a[j]) % 4;
            }
        }
        return dist(nx, ny);
    }

};
