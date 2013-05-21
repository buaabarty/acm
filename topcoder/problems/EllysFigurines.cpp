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
class EllysFigurines {
public:
    int check(int x, int r, int n) {
        int f[20];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i-1];
            if ((1<<(i-1))&x) f[i]++;
            for (int k = 1; k <= min(i, r); ++k)
                f[i] = min(f[i], f[i-k] + 1);
        }
        return f[n];
    }
    int getMoves(vector <string> board, int R, int C) {
        int n = board.size(), m = board[0].length();
        int ans = 1000000000;
        for (int i = 0; i < (1<<n); ++i) {
            int tot = check(i, R, n);
            int bt = 0;
            for (int x = 0; x < n; ++x)
                for (int y = 0; y < m; ++y)
                    if (!((1<<x)&i) && board[x][y] == 'X')
                        bt |= (1<<y);
            ans = min(ans, tot +  check(bt, C, m));
        }
        return ans;
    }
};
