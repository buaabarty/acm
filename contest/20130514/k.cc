#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
int T, f[109], c[109], n;
int gao(int l) {
    if (l == 0) return inf;
    vector<int> ch[109];
    int st[109];
    vector<int> last;
    last.clear();
    memset(st, 0, sizeof(st));
    for (int i = 1; i <= n; ++i)
        ch[i].clear();
    for (int i = 1; i <= n; ++i)
        ch[f[i]].push_back(c[i]);
    for (int i = 1; i <= n; ++i)
        sort(ch[i].begin(), ch[i].end());
    int tot = 0, cnt = 0;
    for (int i = 2; i <= n; ++i)
        if (ch[i].size() > l - 1) {
            for (int j = 0; j <= ch[i].size() - l; ++j)
                tot += ch[i][j];
            st[i] = ch[i].size() - l + 1;
            cnt += ch[i].size() - l + 1;
        }
    if (cnt + ch[1].size() > l) return inf;
    bool got = false;
    for (int i = 2; i <= n; ++i)
        if (ch[i].size() < l - 1) {
            got = true;
            break;
        }
    if (!got) {
        //cout << "HEY" << endl;
        int delta = inf, loc = -1;
        for (int i = 2; i <= n; ++i)
            if (ch[i].size() >= l - 1) {
                if (ch[i][ch[i].size()-l+1] < delta) {
                    delta = min(delta, ch[i][ch[i].size()-l+1]);
                    loc = i;
                }
            }
        if (loc == -1) return inf;
        st[loc] = ch[loc].size()-l+2;
        tot += delta;
        ++cnt;
    }
    for (int i = 2; i <= n; ++i)
        for (int j = st[i]; j < ch[i].size(); ++j)
            last.push_back(ch[i][j]);
    //last.push_back(0);
    int todo = l - cnt - ch[1].size();
    //cout << todo << " " << last.size() << endl;
    if (todo > last.size()) return inf;
    sort(last.begin(), last.end());
    for (int i = 0; i < todo; ++i)
        tot += last[i];
    return tot;
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
        for (int i = 2; i <= n; ++i)
            scanf("%d", &c[i]);
        int ans = inf;
        for (int i = st; i < n; ++i) {
            //cout << i << " " << gao(i) << endl;
            ans = min(ans, gao(i));
        }
        printf("%d\n", ans);
    }
    return 0;
}
