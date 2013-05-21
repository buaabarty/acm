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
const int inf = 1000000000;
class DancingFoxes {
public:

    int g[51][51];
    int minimalDays(vector <string> friendship) {
        int n = friendship.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (friendship[i][j] == 'Y') g[i][j] = 1;
                else if (i == j) g[i][j] = 0;
                else g[i][j] = inf;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        if (g[0][1] < inf) return g[0][1]-1;
        else return -1;
    }

};
