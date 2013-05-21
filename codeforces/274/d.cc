#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

struct edge {
    int v, next;
} e[1000010];
int p[1000010], eid;
int rd[1000010];
void init() {
    memset(p, -1, sizeof(p));
    memset(rd, 0, sizeof(rd));
    eid = 0;
}
void insert(int x, int y) {
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
    rd[y]++;
}

int tot;

struct data {
    int id, value;
    bool operator < (const data &a) const {
        return value < a.value;
    }
} d[100010];

int clr[100010];
int q[1000010], l, r;

int ans[1000010], n, m;

int main() {
    scanf("%d%d", &n, &m);
    init();
    tot = m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            d[j].id = j, scanf("%d", &d[j].value);
        sort(d + 1, d + m + 1);
        int last = 1, cnt = 0;
        d[0].value = -1;
        for (int j = 1; j <= m; ++j) {
            if (d[j].value != d[j - 1].value) ++cnt;
            clr[d[j].id] = cnt;
        }
        for (int j = 1; j <= m; ++j) if (clr[j]) {
            if (clr[j] > 1) insert(tot+clr[j]-1, j);
            if (clr[j] < cnt) insert(j, tot+clr[j]);
        }
        if (cnt) tot += cnt-1;
    }
    l = 1; r = 0;
    for (int i = 1; i <= tot; ++i)
        if (!rd[i]) q[++r] = i;
    int kk = 0;
    while (l <= r) {
        int now = q[l++];
        if (now <= m) {
            ++kk;
            ans[kk] = now;
        }
        for (int i = p[now]; i != -1; i = e[i].next) {
            --rd[e[i].v];
            if (!rd[e[i].v]) q[++r] = e[i].v;
        }
    }
    bool flag = true;
    for (int i = 1; i <= m; ++i)
        if (rd[i]) flag = false;
    if (!flag) {
        printf("-1");;
        return 0;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}
