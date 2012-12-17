#include <iostream>
#include <cstdio>
#include <cstring>
#define pl p<<1
#define pr p<<1|1
#define mid ((l+r)>>1)
#define maxn 131072
using namespace std;
int XOR[maxn*4], cover[maxn*4];
int main() {
    memset(cover, -1, sizeof(cover));
    memset(XOR, 0, sizeof(XOR));
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
