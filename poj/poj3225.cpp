#include <iostream>
#include <cstdio>
#include <cstring>
#define pl p<<1
#define pr p<<1|1
#define mid ((l+r)>>1)
#define maxn 131072
using namespace std;
int sum[maxn*4];
int state[maxn*4];
char str[3], op1, op2;
void push(int p, int l, int r) {
    if (state[p] == 1) {
        state[pl] = 1;
        state[pr] = 1;
        state[p] = 0;
    }
    else if (state[p] == 2) {
        state[pl] = 2;
        state[pr] = 2;
        state[p] = 0;
    }
    else if (state[p] == 3) {
        if (state[pl] == 1) state[pl] = 2;
        else if (state[pl] == 2) state[pl] = 1;
        else if (state[pl] == 3) state[pl] = 0;
        else state[pl] = 3;
        if (state[pr] == 1) state[pr] = 2;
        else if (state[pr] == 2) state[pr] = 1;
        else if (state[pr] == 3) state[pr] = 0;
        else state[pr] = 3;
        state[p] = 0;
    }
    if (state[pl] == 1) sum[pl] = 0;
    else if (state[pl] == 2) sum[pl] = (mid - l + 1);
    else if (state[pl] == 3) sum[pl] = (mid - l + 1) - sum[pl];
    if (state[pr] == 1) sum[pr] = 0;
    else if (state[pr] == 2) sum[pr] = (r - mid);
    else if (state[pr] == 3) sum[pr] = (r - mid) - sum[pr];
}
void insert(int p, int l, int r, int a, int b, int t) {
//    printf("%d %d %d %d %d %d:%d,%d\n", p, l, r, a, b, t, state[p], sum[p]);
    if (l == a && r == b) {
        if (t == 0) {
            state[p] = 1;
            sum[p] = 0;
        }
        else if (t == 1) {
            state[p] = 2;
            sum[p] = (r - l + 1);
        }
        else {
            if (state[p] == 1) {
                state[p] = 2;
                sum[p] = (r - l + 1);
            }
            else if (state[p] == 2) {
                sum[p] = 0;
                state[p] = 1;
            }
            else if (state[p] == 3) state[p] = 0;
            else {
                sum[p] = (r - l + 1) - sum[p];
                state[p] = 3;
            }
        }
        //printf("(%d,%d) %d\n", l, r, sum[p]);
        return ;
    }
    push(p, l, r);
    if (b <= mid) insert(pl, l, mid, a, b, t);
    else if (a > mid) insert(pr, mid+1, r, a, b, t);
    else {
        insert(pl, l, mid, a, mid, t);
        insert(pr, mid+1, r, mid+1, b, t);
    }
    sum[p] = sum[pl] + sum[pr];
    //printf("(%d,%d) %d\n", l, r, sum[p]);
}
int getsum(int p, int l, int r, int a, int b) {
    if (l == a && r == b) {
        /*if (state[p] == 1) sum[p] = 0;
        else if (state[p] == 2) sum[p] = (r - l + 1);
        else if (state[p] == 3) sum[p] = (r - l + 1) - sum[p];*/
        return sum[p];
    }
    push(p, l, r);
    int res = 0;
    if (b <= mid) res = getsum(pl, l, mid, a, b);
    else if (a > mid) res = getsum(pr, mid+1, r, a, b);
    else {
        res = getsum(pl, l, mid, a, mid) + getsum(pr, mid+1, r, mid+1, b);
    }
    sum[p] = sum[pl] + sum[pr];
    return res;
}
int main() {
    int x, y, ca = 5;
    memset(sum, 0, sizeof(sum));
    memset(state, 0, sizeof(state));
    while (cin >> str) {
        scanf(" %c%d,%d%c", &op1, &x, &y, &op2);
        x++; y++;
        if (op1 == '[') x = x * 2 - 1; else x = x * 2;
        if (op2 == ']') y = y * 2 - 1; else y = y * 2 - 2;
        //printf("%d %d\n", x, y);
        if (str[0] == 'U') {
            if (x <= y) insert(1, 1, maxn, x, y, 1);
        }
        else if (str[0] == 'I') {
            if (1 <= x - 1) insert(1, 1, maxn, 1, x - 1, 0);
            if (y + 1 <= maxn) insert(1, 1, maxn, y + 1, maxn, 0);
        }
        else if (str[0] == 'D') {
            if (x <= y) insert(1, 1, maxn, x, y, 0);
        }
        else if (str[0] == 'C') {
            if (1 <= x - 1) insert(1, 1, maxn, 1, x - 1, 0);
            if (y + 1 <= maxn) insert(1, 1, maxn, y + 1, maxn, 0);
            if (x <= y) insert(1, 1, maxn, x, y, 2);
        }
        else {
            if (x <= y) insert(1, 1, maxn, x, y, 2);
        }
        //printf("%d\n", sum[1]);
        //for(int i = 1; i <= maxn; ++i)
        //if (getsum(1, 1, maxn, i, i)) printf("%d ", i);
    }
    bool inq = false, first = true;
    for (int i = 1; i <= maxn; ++i)
        if (getsum(1, 1, maxn, i, i)) {
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
