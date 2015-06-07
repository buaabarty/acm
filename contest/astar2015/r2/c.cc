#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
#include <queue>
using namespace std;

struct edge{
    int t;
    string s;
    bool operator < (const edge& e) const {
        return s > e.s;
    }
};

vector<edge> e[60];
bool r[60];
int n, m, a, b;
bool c[60][60];

void dfs(int x) {
    if (r[x]++) return;
    for (int i = 0; i < n; ++i) {
        if (c[x][i]) {
            dfs(i);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d%d%d", &n, &m, &a, &b);
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int x, y;
            char str[10];
            scanf("%d%d%s", &x, &y, str);
            edge A = {y, string(str)};
            e[x].push_back(A);
            c[y][x] = 1;
        }
        dfs(b);
        edge i = {a, ""};
        priority_queue<edge> pq;
        pq.push(i);
        set<string> s[60];
        while (!pq.empty()) {
            edge c = pq.top();
            if (c.t == b || c.s.size() > 6 * n) {
                break;
            }
            pq.pop();
            if (!s[c.t].insert(c.s).second) {
                continue;
            }
            for (int i = 0; i < e[c.t].size(); ++i) {
                edge N = {e[c.t][i].t, c.s + e[c.t][i].s};
                if (r[N.t]) {
                    pq.push(N);
                }
            }
        }
        printf("Case #%d:\n", ca);
        if (pq.empty() || pq.top().s.size() > 6 * n) {
            cout << "Tough way!" << endl;
        } else {
            cout << pq.top().s << endl;
        }
    }
    return 0;
}
