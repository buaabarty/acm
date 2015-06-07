#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 300000 + 9;
struct edge {
    int v, next;
} e[N * 2];
int p[N], eid;
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
int stack[N], top = 0;
int travel[N * 3], l[N], r[N];
bool instack[N];
int pp[N], n, q, h[N * 3];
void checkMin(int &x, int y) {
    if (y < x) x = y;
}
void checkMax(int &x, int y) {
    if (y > x) x = y;
}
int lst[N][20], rst[N][20], len;
int hpos[N * 3][20];
void dfs() {
    top = 0;
    memset(stack, 0, sizeof(stack));
    stack[++top] = 1;
    memset(instack, 0, sizeof(instack));
    instack[1] = 1;
    for (int i = 1; i <= n; ++i) {
        pp[i] = p[i];
        l[i] = n * 4;
        r[i] = 0;
    }
    int cnt = 0, nowh = 1;
    while (top) {
        travel[++cnt] = stack[top];
        checkMin(l[stack[top]], cnt);
        checkMax(r[stack[top]], cnt);
        int &i = pp[stack[top]];
        h[cnt] = -nowh;
        while (i != -1 && instack[e[i].v]) {
            i = e[i].next;
        }
        if (i != -1) {
            ++nowh;
            stack[++top] = e[i].v;
            instack[e[i].v] = true;
            i = e[i].next;
        } else {
            --nowh;
            instack[stack[top--]] = false;
        }
    }
    len = cnt;
    //for (int i = 1; i <= n; ++i)
    //    cout << l[i] << " " << r[i] << endl;
    //for (int i = 1; i <= len; ++i)
    //    cout << travel[i] << " " << h[i ] << endl;
}
void build_st() {
    for (int i = 1; i <= n; ++i) {
        lst[i][0] = l[i];
        rst[i][0] = r[i];
    }
    for (int i = 1; i <= len; ++i) {
        hpos[i][0] = i;
    }
    for (int i = 1; i < 20; ++i)
        for (int j = 1; j + (1<<i) - 1 <= n; ++j) {
            lst[j][i] = min(lst[j][i-1], lst[j + (1<<(i-1))][i-1]);
            rst[j][i] = max(rst[j][i-1], rst[j + (1<<(i-1))][i-1]);
        }
    for (int i = 1; i < 20; ++i)
        for (int j = 1; j + (1<<i) - 1 <= len; ++j) {
            if (h[hpos[j][i-1]] > h[hpos[j + (1<<(i-1))][i-1]]) {
                hpos[j][i] = hpos[j][i - 1];
            } else {
                hpos[j][i] = hpos[j + (1<<(i-1))][i-1];
            }
        }
}
int get_minl(int L, int R) {
    //cout << "CALMIN" << L << " " << R << endl;
    int sz = int(1e-6 + log2(R - L + 1));
    //cout << min(lst[L][sz], lst[R - (1<<sz) + 1][sz]) << endl;
    return min(lst[L][sz], lst[R - (1<<sz) + 1][sz]);
}
int get_maxr(int L, int R) {
    //cout << "CALMAX" << L << " " << R << endl;
    int sz = int(1e-6 + log2(R - L + 1));
    //cout << max(rst[L][sz], rst[R - (1<<sz) + 1][sz]) << endl;
    return max(rst[L][sz], rst[R - (1<<sz) + 1][sz]);
}
int get_res(int L, int R) {
    int lm = get_minl(L, R), rm = get_maxr(L, R);
    int sz = int(1e-6 + log2(rm - lm + 1));
    //cout << "WTFG" << hpos[lm][sz] << " " << hpos[rm - (1<<sz) + 1][sz] << endl;
    //cout << "WTFG" << h[hpos[lm][sz]] << " " << h[hpos[rm - (1<<sz) + 1][sz]] << endl;
    if (h[hpos[lm][sz]] > h[hpos[rm - (1<<sz) + 1][sz]]) return travel[hpos[lm][sz]];
    else return travel[hpos[rm - (1<<sz) + 1][sz]];
}
int main() {
    while (scanf("%d", &n) == 1) {
        init();
        for (int i = 1; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            insert2(x, y);
        }
        dfs();
        build_st();
        scanf("%d", &q);
        while (q--) {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d\n", get_res(x, y));
        }
    }
    return 0;
}
