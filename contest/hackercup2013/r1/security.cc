#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXX = 100;
const int MAXY = 100;
struct Hungray {
        int nx, ny, mx[MAXX], my[MAXY];
        vector<int> e[MAXX];
        bool mark[MAXX];
        void init(int nx, int ny) {
                this->nx = nx;
                this->ny = ny;
                for (int i = 0; i < nx; ++i) {
                        e[i].clear();
                }
        }
        void add(int a, int b) {
                e[a].push_back(b);
        }
        bool augment(int i) {
                if (!mark[i]) {
                        mark[i] = true;
                        for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
                                if (my[*j] == -1 || augment(my[*j])) {
                                        mx[i] = *j;
                                        my[*j] = i;
                                        return true;
                                }
                        }
                }
                return false;
        }
        int gao() {
                int ret = 0;
                fill(mx, mx + nx, -1);
                fill(my, my + ny, -1);
                for (int i = 0; i < nx; ++i) {
                        fill(mark, mark + nx, false);
                        if (augment(i)) {
                                ++ret;
                        }
                }
                return ret;
        }
};
bool okay(char *k1, char *k2, int m) {
    int len = strlen(k1), l;
    l = len / m;
    Hungray h;
    h.init(m, m);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j) {
            bool flag = true;
            for (int s = 0; s < l; ++s)
                if (k1[i*l+s]!=k2[j*l+s] && k1[i*l+s]!='?' && k2[j*l+s]!='?') {
                    flag = false;
                    break;
                }
            if (flag) h.add(i, j);
        }
    return (h.gao() == m);
}
int main() {
    freopen("security.txt", "r", stdin);
    freopen("securityout.txt", "w", stdout);
    int T, m;
    char k1[127], k2[127];
    scanf("%d",  &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%s%s", &m, k1, k2);
        int len = strlen(k1);
        bool flag = true;
        for (int i = 0; k1[i]; ++i)
            if (k1[i] == '?') {
                bool find = false;
                for (char c = 'a'; c <= 'f'; ++c) {
                    k1[i] = c;
                    if (okay(k1, k2, m)) {
                        find = true;
                        break;
                    }
                }
                if (!find) {
                    flag = false;
                    break;
                }
            }
        flag = okay(k1, k2, m);
        if (!flag) printf("Case #%d: IMPOSSIBLE\n", ca);
        else printf("Case #%d: %s\n", ca, k1);
    }
    return 0;
}
