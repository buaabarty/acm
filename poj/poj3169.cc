#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge {
    int v, d, next;
} e[100000];
int eid, p[1010];
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
int n, ml, md;
int main() {

    return 0;
}
