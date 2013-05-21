#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int M = 30000 * 3 + 9;
const int N = 200 + 9;

struct edge {
    int v, next;
} e[M];
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

int clr[N];

bool dfs(int x, int c) {
    clr[x] = c;
    for (int i = p[x]; i != -1; i = e[i].next)
        if (!clr[e[i].v]) {
            if (!dfs(e[i].v, -c)) return false;
        } else {
            if (clr[e[i].v] != -c) return false;
        }
    return true;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        init();
        for (int i = 1; i <= m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            insert2(x, y);
        }
        memset(clr, 0, sizeof(clr));
        bool okay = true;
        for (int i = 1; i <= n; ++i)
            if (!clr[i] && !dfs(i, 1)) {
                okay = false; break;
            }
        if (!okay) {
            puts("no");
        } else {
            puts("yes");
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
                if (clr[i] == 1) ++cnt;
            printf("%d\n", cnt);
            for (int i = 1; i <= n; ++i)
                if (clr[i] == 1)  {
                    --cnt;
                    printf("%d%c", i, " \n"[cnt==0]);
                }
        }
    }
    return 0;
}
