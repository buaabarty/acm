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

class TheSquareRootDilemma {
public:
    int cnt[100010];
    bool issqr(int x) {
        int r = (int)(sqrt(x)+1e-6);
        return (r*r == x);
    }
    int countPairs(int N, int M) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= 77777; ++i)
            cnt[i] = issqr(i) + cnt[i-1];
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            int x = i, st = 1;
            for (int j = 2; j*j <= x; ++j)
                if (x%j==0) {
                    int now = 0;
                    while (x%j==0) {
                        x /= j;
                        ++now;
                    }
                    if (now&1) st *= j;
                }
            if (x > 1) st *= x;
            res += cnt[M/st];
        }
        return res;
    }

};


// Powered by FileEdit
// Powered by CodeProcessor
