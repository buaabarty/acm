#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int M = 1000000;
const int N = 2000;
const int inf = 1000000000;
struct edge {
    int v, d, next;
} e[M];
int p[N], eid;
int n, m;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y, int d) {
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}

int dist[N];
int vst[N];
bool inq[N];
bool spfa(int v) {
    memset(inq, 0, sizeof(inq));
    memset(vst, 0, sizeof(vst));
    for (int i = 0; i <= n; ++i) dist[i] = -inf;
    dist[v] = 0;
    queue<int> q;
    q.push(v);
    inq[v] = 1;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = p[now]; i != -1; i = e[i].next)
            if (dist[now] + e[i].d > dist[e[i].v]) {
                dist[e[i].v] = dist[now] + e[i].d;
                if (!inq[e[i].v]) {
                    inq[e[i].v] = 1;
                    q.push(e[i].v);
                    vst[e[i].v]++;
                    if (vst[e[i].v] >= n) return false;
                }
            }
        inq[now] = 0;
    }
    return true;
}


int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        init();
        for (int i = 1; i <= n; ++i)
            insert(0, i, 0);
        bool flag = true;
        for (int i = 1; i <= m; ++i) {
            char str[4];
            scanf("%s", str);
            if (str[0] == 'P') {
                int x, y, z;
                scanf("%d%d%d", &x, &y, &z);
                if (x == y && z) flag = false;
                insert(y, x, z);
                insert(x, y, -z);
            } else {
                int x, y;
                scanf("%d%d", &x, &y);
                if (x == y) flag = false;
                insert(y, x, 1);
            }
        }
        if (flag && spfa(0)) puts("Reliable");
        else puts("Unreliable");
    }
    return 0;
}
