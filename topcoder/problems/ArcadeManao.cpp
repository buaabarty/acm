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
class ArcadeManao {
public:
    bool vst[51][51];
    int n, m, dx, dy;
    bool g[51][51];
    void go(int x, int y, int l) {
        vst[x][y] = 1;
        for (int dx = x - l; dx <= x + l; ++dx)
            if (dx>=1 && dx<=n && !vst[dx][y] && g[dx][y]) go(dx, y, l);
        if (y>1 && !vst[x][y-1] && g[x][y-1]) go(x, y-1, l);
        if (y<m && !vst[x][y+1] && g[x][y+1]) go(x, y+1, l);
    }
    bool okay(int l) {
        memset(vst, 0, sizeof(vst));
        go(n, 1, l);
        return vst[dx][dy];
    }
    int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
        n = level.size();
        m = level[0].length();
        dx = coinRow;
        dy = coinColumn;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                g[i+1][j+1] = (level[i][j] == 'X');
        int l = 0, r = n, mid;
        while (l < r) {
            if (l + 1 == r) {
                if (!okay(l)) l = r;
                break;
            }
            mid = (l + r) >> 1;
            if (okay(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
