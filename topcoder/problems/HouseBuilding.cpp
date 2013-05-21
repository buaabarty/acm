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
// END CUT HERE
class HouseBuilding {
public:
    int getMinimum(vector <string> area) {
        int ans = 1000000000, n = area.size(), m = area[0].length();
        for (int i = 0; i < 10; ++i) {
            int tot = 0;
            for (int x = 0; x < n; ++x)
                for (int y = 0; y < m; ++y)
                    if (area[x][y]-'0'<i) tot += i - area[x][y]+'0';
                    else if (area[x][y]-'0'>i+1) tot += area[x][y]-'0'-i-1;
            ans = min(ans, tot);
        }
        return ans;
    }

};
