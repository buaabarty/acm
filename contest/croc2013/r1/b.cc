#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m;
struct edge {
    int v, next;
} e[1000010];
int p[100010], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y) {
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y) {
    insert(x, y);
    insert(y, x);
}
int d[100010];
bool ischain() {
    for (int i = 1; i <= n; ++i)
        if (d[i] > 2) return false;
    return true;
}
bool isstar() {
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (d[i] > 1) ++cnt;
    return (cnt == 1);
}
bool isring() {
    for (int i = 1; i <= n; ++i)
        if (d[i] != 2) return false;
    return true;
}
int main() {
    memset(d, 0, sizeof(d));
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        insert2(x, y);
        d[x]++; d[y]++;
    }
    if (m == n - 1) {
        if (ischain()) puts("bus topology");
        else if (isstar()) puts("star topology");
        else puts("unknown topology");
    } else if (m == n && isring()) puts("ring topology");
    else puts("unknown topology");
    return 0;
}
