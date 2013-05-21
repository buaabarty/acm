#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define pl p<<1
#define pr p<<1|1
#define mid ((l+r)>>1)
#define maxn 50010
#define maxt 32780
using namespace std;
struct node {
    int d;
    node *next[128];
};
node* newnode() {
    int i;
    node* p = (node*) malloc(sizeof(node));
    p->d = 0;
    for (i = 0; i < 128; ++i)
        p->next[i] = 0;
    return p;
}
void insert(node *root, char s[], int x) {
    int n = strlen(s);
    int i;
    node *p;
    p = root;
    for (i = 0; i < n; ++i) {
        if (p -> next[s[i]] == NULL)
            p -> next[s[i]] = newnode();
        p = p -> next[s[i]];
    }
    p -> d = x;
}
int search(node *root, char s[]) {
    int len = strlen(s);
    int i;
    node *p;
    p = root;
    for (i = 0; i < len; ++i) {
        if (p -> next[s[i]] != NULL)
            p = p->next[s[i]];
        else return 0;
    }
    return p->d;
}
/*int next[800000][26], d[800000], cnt, tot;
void formatTrie() {
    memset(next, 0, sizeof(next));
    memset(d, 0, sizeof(d));
    cnt = 0; tot = 0;
}
int insert(char *str) {
    int j = 0;
    for (int i = 0; str[i]; ++i) {
        if (!next[j][str[i] - 'A']) next[j][str[i] - 'A'] = ++cnt;
        j = next[j][str[i] - 'A'];
    }
    if (!d[j]) d[j] = ++tot;
    return d[j];
}
*/
char temp[1000];
char* format(char *str) {
    memset(temp, 0, sizeof(temp));
    int l = 0;
    for (int i = 1; str[i] != ']'; ++i)
        temp[l++] = str[i];
    temp[l] = '\0';
    return temp;
}
char str[100];
int x;
int cost[maxn];
int k, limit;
int mmax[maxt*4], delay[maxt*4];
void update(int p, int l, int r, int a, int b, int delta) {
    //printf("%d %d %d %d %d %d:%d,%d\n", p, l, r, a, b, delta, mmax[p], delay[p]);
    if (delay[p]) {
        delay[pl] += delay[p];
        delay[pr] += delay[p];
        mmax[pl] += delay[p];
        mmax[pr] += delay[p];
        delay[p] = 0;
    }
    if (l == a && r == b) {
        delay[p] += delta;
        mmax[p] += delta;
        return ;
    }
    if (b <= mid) update(pl, l, mid, a, b, delta);
    else if (a > mid) update(pr, mid+1, r, a, b, delta);
    else {
        update(pl, l, mid, a, mid, delta);
        update(pr, mid+1, r, mid+1, b, delta);
    }
    mmax[p] = max(mmax[pl], mmax[pr]);
}
int getmax(int p, int l, int r, int lim) {
//    printf("%d %d:%d\n", l, r, mmax[p]);
    if (mmax[p] <= lim) return 0;
    if (delay[p]) {
        delay[pl] += delay[p];
        delay[pr] += delay[p];
        mmax[pl] += delay[p];
        mmax[pr] += delay[p];
        delay[p] = 0;
    }
    if (l == r) {
        if (mmax[p] > lim) return l;
        else return 0;
    }
    int tmp = getmax(pl, l, mid, lim);
    if (!tmp) tmp = getmax(pr, mid+1, r, lim);
    mmax[p] = max(mmax[pl], mmax[pr]);
    return tmp;
}
int finddat(int p, int l, int r, int d) {
    if (delay[p]) {
        delay[pl] += delay[p];
        delay[pr] += delay[p];
        mmax[pl] += delay[p];
        mmax[pr] += delay[p];
        delay[p] = 0;
    }
    if (l == d && r == d) return mmax[p];
    if (d <= mid) return finddat(pl, l, mid, d);
    else return finddat(pr, mid+1, r, d);
}
int n;
int main() {
    scanf("%d", &n);
    //formatTrie();
    node *root = newnode();
    for (int i = 1; i <= n; ++i) {
        scanf("%s%d", str, &x);
        insert(root, format(str), i);
        cost[i] = x;
    }
    while (~scanf("%d%d", &k, &limit)) {
        memset(mmax, 0, sizeof(mmax));
        memset(delay, 0, sizeof(delay));
        for (int i = 1; i <= k; ++i) {
            int a, b;
            scanf("%s%d%d", str, &a, &b);
            a++; b++;
            x = search(root, format(str));
            update(1, 1, maxt, a, b, cost[x]);
        }
        if (mmax[1] <= limit) printf("The maximum power needed is %d Watts.\n", mmax[1]);
        else {
            x = getmax(1, 1, maxt, limit);
            int res = finddat(1, 1, maxt, x);
            printf("The power will be out at time %d because the power is %d Watts and overloaded.\n", x - 1, res);
        }
    }
    return 0;
}
