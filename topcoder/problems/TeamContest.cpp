// BEGIN CUT HERE

// END CUT HERE
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
class TeamContest {
public:
    int worstRank(vector <int> strength) {
        int dat = max(max(strength[0], strength[1]), strength[2]) +
                  min(min(strength[0], strength[1]), strength[2]);
        int n = strength.size() / 3;
        vector<int> a;
        a.clear();
        for (int i = 3; i < n*3; ++i)
            a.push_back(strength[i]);
        sort(a.begin(), a.end());
        bool use[100];
        memset(use, 0, sizeof(use));
        int ans = 0;
        for (int i = a.size()-1; i >= 0; --i) {
            int cnt = 0;
            for (int j = 0; j < i; ++j)
                if (!use[j] && a[j] + a[i] > dat) ++cnt;
            if (cnt < 2) break;
            ++ans;
            cnt = 0;
            for (int j = 0; j < i; ++j)
                if (!use[j] && a[j]+a[i]>dat) {
                    ++cnt;
                    use[j] = 1;
                    if (cnt == 2) break;
                }
        }
        return ans + 1;
    }
};
