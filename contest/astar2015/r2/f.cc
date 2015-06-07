#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;
const int N = 60;
const int M = 6000;
struct edge {
    int v, next;
} e[M];
int p[N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = -1;
}
void insert(int x, int y) {
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
int n, m, k;

int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d%d", &n, &m, &k);
        init();

    }
    return 0;
}
