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
class TheDevice {
public:
    int minimumAdditional(vector <string> plates) {
        int cnt1[100], cnt0[100];
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt0, 0, sizeof(cnt0));
        int m = plates[0].length(), n = plates.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (plates[i][j] == '0') cnt0[j]++;
                else cnt1[j]++;
        int res = 0;
        for (int i = 0; i < m; ++i) {
            int now = 0;
            if (cnt0[i] < 1) now += 1 - cnt0[i];
            if (cnt1[i] < 2) now += 2 - cnt1[i];
            res = max(res, now);
        }
        return res;
    }

};
