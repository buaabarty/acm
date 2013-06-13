#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 10000 + 9;
const int M = 1000000 + 9;
struct edge {
    int v, f, next;
} e[M];
int p[N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void _insert(int x, int y, int f) {
    e[eid].v = y;
    e[eid].f = f;
    e[eid].next = p[x];
    p[x] = eid++;
}
void
int main() {
    return 0;
}
