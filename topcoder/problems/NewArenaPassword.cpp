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
class NewArenaPassword {
public:
    int fa[100];
    int father(int v) {
        if (fa[v] != v) fa[v] = father(fa[v]);
        return fa[v];
    }
    int cnt[100];
    void gao(int x, int y) {
        int fx = father(x), fy = father(y);
        if (fx != fy) fa[fx] = fy;
    }
    int minChange(string oldPassword, int K) {
        int n = oldPassword.length();
        for (int i = 1; i <= n; ++i) fa[i] = i;
        for (int i = 1; i <= K; ++i)
            gao(i, n - K + i);
        for (int i = 1; i <= n; ++i)
            fa[i] = father(i);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int tot = 0, mx = 0;
            memset(cnt, 0, sizeof(cnt));
            for (int j = 0; j < n; ++j)
                if (fa[j+1] == i) {
                    cnt[oldPassword[j]-'a']++;
                    ++tot;
                }
            for (int j = 0; j < 26; ++j)
                mx = max(mx, cnt[j]);
            ans += (tot - mx);
        }
        return ans;
    }

};
