#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>

#include <algorithm>
#include <map>

#define pb push_back

using namespace std;

typedef long long LL;

struct edge {
    int v, len, pow;
} e[20010];
int p[10010], eid;

void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y, int len, int pow) {
    e[eid].v = y;
    e[eid].len = len;
    e[eid].pow = pow;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y, int len, int pow) {
    insert(x, y, len, pow);
    insert(y, x, len, pow);
}
int n;
int dist[10010];
bool vst[10010];

void godeep(int v, int l) {
    vst[v] = 1;
    dist[v] = l;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v]) {
            godeep(e[i].v, e[i].len + l);
        }
}

int main() {
    while (scafn("%d", &n) == 1) {
        for (int i = 1; i <= n; ++i) e[i].clear();
        mapinit();
        for (int i = 1; i < n; ++i) {
            int x, y, len, pow;
            scanf("%d%d%d%d", &x, &y, &len, &pow);
            insert2(x, y, len, pow);
        }
        memset(vst, 0, sizeof(vst));
        godeep(1, 0);
        int st = 1;
        for (int i = 1; )
    }
    return 0;
}
