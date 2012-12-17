#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge {
    int v, d, next;
}e[M];
int p[N], eid;
void mapinit() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y, int d) {
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
int main() {
    int l, n, a[110], b[110]; scanf("%d%d", &l, &n);
    for (int i = 1; i <= n; ++i)
    return 0;
}
