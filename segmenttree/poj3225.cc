#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pl p<<1
#define pr p<<1|1
#define root 1
#define clr(x) memset(x, 0, sizeof(x))
using namespace std;
const int maxn = 1000010;
struct sgtree {
    int a0[maxn*4], a1[maxn*4], bx[maxn*4];
    int n;
    void init(int _n) {
        n = _n;
        clr(a0); clr(a1); clr(bx);
    }
    inline void popchange(int x, int y, int &z) {
        if (x && y) z = 1;
    }
    inline void maintain(int p) {
        if (bx[p]) {
            if (a0[p]) { a0[p] = 0; a1[p] = 1; bx[p] = 0; }
            else if (a1[p]) { a1[p] = 0; a0[p] = 1; bx[p] = 0; }
        }
    }
    void pop(int p) {
        maintain(p);
        int fa = p>>1, l, r;
        l = fa<<1, r = fa<<1|1;
        popchange(a0[l], a0[r], a0[fa]);
        popchange(a1[l], a1[r], a1[fa]);
        popchange(bx[l], bx[r], bx[fa]);
        maintain(fa);
    }

    inline void pushchange(int &x, int &y, int &z) {
        if (z) x = y = z; z = 0;
    }
    void push(int p) {
        maintain(p);
        int l = p<<1, r = p<<1|1;
        pushchange(a0[l], a0[r], a0[p]);
        pushchange(a1[l], a1[r], a1[p]);
        pushchange(bx[l], bx[r], bx[p]);
        maintain(l);
        maintain(r);
    }
    void insert(int p, int l, int r, int a, int b, int c) {
        //printf("%d %d %d %d\n", l, r, a, b);
        push(p);
        if (l==a && r==b) {
            if (c == 0) {
                a0[p] = 1;
                a1[p] = 0;
                bx[p] = 0;
            } else if (c == 1) {
                a1[p] = 1;
                a0[p] = 0;
                bx[p] = 0;
            } else {
                bx[p] = !bx[p];
            }
            pop(p); return;
        }
        int mid = (l + r) >> 1;
        if (b <= mid) insert(pl, l, mid, a, b, c);
        else if (a > mid) insert(pr, mid+1, r, a, b, c);
        else {
            insert(pl, l, mid, a, mid, c);
            insert(pr, mid+1, r, mid+1, b, c);
        }
        pop(p);
    }
    void insert(int a, int b, int c) {
        insert(root, 1, n, a, b, c);
    }
    int getcolor(int p, int l, int r, int x) {
        if (a0[p] || a1[p] || l==r) {
            if (a1[p]) return 1;
            else return 0;
        }
        int mid = (l+r)>>1, ans;
        if (x <= mid) ans = getcolor(pl, l, mid, x);
        else ans = getcolor(pr, mid+1, r, x);
        if (bx[p]) ans = !ans;
        return ans;
    }
    int getcolor(int x) {
        return getcolor(root, 1, n, x);
    }
}sg;

int main() {
    char str[10], op1, op2;
    int x, y;
    sg.init(maxn);
    while (scanf("%s", str) == 1) {
        scanf(" %c%d,%d%c", &op1, &x, &y, &op2);
        x++; y++;
        if (op1 == '[') x = x * 2 - 1; else x = x * 2;
        if (op2 == ']') y = y * 2 - 1; else y = y * 2 - 2;
        if (str[0] == 'U') {
            if (x <= y) sg.insert(x, y, 1);
        }
        else if (str[0] == 'I') {
            if (1 <= x - 1) sg.insert(1, x - 1, 0);
            if (y + 1 <= maxn) sg.insert(y + 1, maxn, 0);
        }
        else if (str[0] == 'D') {
            if (x <= y) sg.insert(x, y, 0);
        }
        else if (str[0] == 'C') {
            if (1 <= x - 1) sg.insert(1, x - 1, 0);
            if (y + 1 <= maxn) sg.insert(y + 1, maxn, 0);
            if (x <= y) sg.insert(x, y, 2);
        }
        else {
            if (x <= y) sg.insert(x, y, 2);
        }
    }
    for (int i = 1; i <= 30; ++i)
        printf("%d ", sg.getcolor(i));
    puts("");
    bool inq = false, first = true;
    for (int i = 1; i <= maxn; ++i)
        if (sg.getcolor(i)) {
            if (!inq) {
                if (!first) printf(" ");
                if ((i & 1)) printf("[");
                else printf("(");
                printf("%d,", (i-1)/2);
                first = false;
                inq = true;
            }
        } else if (inq) {
            int x = i - 1;
            printf("%d", x/2);
            if (x & 1) printf("]");
            else printf(")");
            inq = false;
        }
    if (inq) {
        int x = maxn;
        printf("%d", (x-1)/2);
        if (x & 1) printf(")");
        else printf("]");
    }
    if (first) printf("empty set");
    puts("");
    return 0;
}
