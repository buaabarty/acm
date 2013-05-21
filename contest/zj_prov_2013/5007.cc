#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int T, n;
int f[109], cost[109];

int okay(int l) {
    //cout << "L=" << l << endl;
    vector<int> d[109], s;
    s.clear();
    for (int i = 1; i <= n; ++i) d[i].clear();
    for (int i = 1; i <= n; ++i)
        d[f[i]].push_back(cost[i]);
    if (d[1].size() >= l) {
        for (int i = 2; i <= n; ++i)
            if (d[i].size() >= l) return -1;
            return 0;
    }
    for (int i = 1; i <= n; ++i)
        sort(d[i].begin(), d[i].end());
    /*for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < d[i].size(); ++j)
            printf("%d ", d[i][j]);
        if (d[i].size()) puts("");
    }*/

    int tot = 0, cnt = 0;
    for (int i = 2; i <= n; ++i) {
        //cout << i << "'s size: " << d[i].size() << endl;
        if (d[i].size() >= l) {
            cnt += d[i].size() - l + 1;
            for (int j = 0; j < d[i].size() - l + 1; ++j)
                tot += d[i][j];
            for (int j = d[i].size() - l + 1; j < d[i].size(); ++j)
                s.push_back(d[i][j]);
        } else {
            for (int j = 0; j < d[i].size(); ++j)
                s.push_back(d[i][j]);
        }
    }
    //cout << cnt << " " << tot << endl;
    if (l-d[1].size() < cnt) return -1;
    sort(s.begin(), s.end());
    int last = l-d[1].size()-cnt;
    for (int i = 0; i < last; ++i)
        tot += s[i];
    if (tot < 1000000000) return tot;
    else return -1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int st = 0;
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &f[i]);
            if (f[i] == 1) ++st;
        }
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &cost[i]);
        }
        int ans = 1000000000;
        cost[1] = 1000000000;
        for (int i = 2; i <= n; ++i) {
            f[1] = i;
            for (int k = st; k <= n; ++k) {
                int x = okay(k);
                if (x >= 0) {
                    ans = min(ans, x);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
