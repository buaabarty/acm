#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

typedef long long LL;

LL f1[100010], f2[100010], d[100010];
LL n;

struct edge {
    LL v, next;
}e[200010];
LL p[100010], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(LL x, LL y) {
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(LL x, LL y) {
    insert(x, y);
    insert(y, x);
}

bool vst[100010];

void dfs(LL v) {
    vst[v] = 1;
    LL icnt = 0, dcnt = 0;
    for (LL i = p[v]; i != -1; i = e[i].next)
        if (!vst[e[i].v]) {
            dfs(e[i].v);
            icnt = max(icnt, f1[e[i].v]);
            dcnt = max(dcnt, f2[e[i].v]);
        }
    LL now = d[v] + icnt - dcnt;
    if (now < 0) icnt += -now;
    else dcnt += now;
    f1[v] = icnt;
    f2[v] = dcnt;
}

int main() {
    init();
    scanf("%I64d", &n);
    for (LL i = 1; i < n; ++i) {
        LL x, y;
        scanf("%I64d%I64d", &x, &y);
        insert2(x, y);
    }
    for (LL i = 1; i <= n; ++i) scanf("%I64d", &d[i]);
    memset(vst, 0, sizeof(vst));
    dfs(1);
    printf("%I64d\n", f1[1] + f2[1]);
    return 0;
}
