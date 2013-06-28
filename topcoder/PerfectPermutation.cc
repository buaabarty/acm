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
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

class PerfectPermutation {
public:
    bool vst[100];
    int reorder(vector <int> P) {
        memset(vst, 0, sizeof(vst));
        int cnt = 0, n = P.size();
        for (int i = 0; i < n; ++i)
            if (!vst[i]) {
                int x = i, now = 0;
                do {
                    vst[x] = 1;
                    ++now;
                    x = P[x];
                } while (x != i);
                ++cnt;
            }
        if (cnt > 1) return cnt;
        else return 0;
    }

};

