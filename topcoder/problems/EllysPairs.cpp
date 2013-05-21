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
class EllysPairs {
public:
    int getDifference(vector <int> knowledge) {
        int minx = 1000000000, maxx = 0, n = knowledge.size();
        sort(knowledge.begin(), knowledge.end());
        for (int i = 0; i < n / 2; ++i) {
            minx = min(minx, knowledge[i] + knowledge[n-i-1]);
            maxx = max(maxx, knowledge[i] + knowledge[n-i-1]);
        }
        return maxx - minx;
    }

};
