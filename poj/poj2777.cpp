#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1000000
using namespace std;
int n, t, q, nid = 0;
struct node{
    int c, l, r, lch, rch, cover;
}a[MAXN];
int buildtree(int left, int right)
{
    if (left > right) return -1;
    int now = ++nid;
    a[now].l = left, a[now].r = right, a[now].c = 1;
    if (left == right) return now;
    int mid = (left + right) >> 1;
    a[now].lch = buildtree(left, mid);
    a[now].rch = buildtree(mid + 1, right);
    return now;
}
void color(int id, int left, int right, int c)
{
    if ((left == a[id].l) && (right == a[id].r)){
        a[id].c = c;
        a[id].cover = 1;
        return;
    }
    if (a[id].cover){
        a[a[id].lch].c = a[a[id].rch].c = a[id].c;
        a[id].cover = 0;
        a[a[id].lch].cover = a[a[id].rch].cover = 1;
    }
    int mid = (a[id].l + a[id].r) >> 1;//left~mid, mid+1~right
    if (left > mid) color(a[id].rch, left, right, c);
    else if (right <= mid) color(a[id].lch, left, right, c);
    else{
        color(a[id].lch, left, mid, c);
        color(a[id].rch, mid + 1, right, c);
    }
    a[id].c = a[a[id].lch].c | a[a[id].rch].c;
}
int calc(int id, int left, int right)
{
    if (((left == a[id].l) && (right == a[id].r)) || a[id].cover) return a[id].c;
    int sum = 0, mid = ((a[id].l + a[id].r) >> 1);//left~mid, mid+1~right
    if (left > mid) return calc(a[id].rch, left, right);
    else if (right <= mid) return calc(a[id].lch, left, right);
    else return calc(a[id].lch, left, mid) | calc(a[id].rch, mid + 1, right);
}
int num(int x)
{
    int s = 0;
    while (x > 0)
    {
        s += (x & 1);
        x >>= 1;
    }
    return s;
}
int main()
{
    scanf("%d%d%d", &n, &t, &q);
    buildtree(1, n);
    char opr;
    int a, b, c;
    for (int i = 1; i <= q; ++i)
    {
        scanf("\n%c", &opr);
        if (opr == 'C'){
            scanf("%d%d%d", &a, &b, &c);
            if (a > b) swap(a, b);
            color(1, a, b, (1 << (c - 1)));
        }
        else{
            scanf("%d%d", &a, &b);
            if (a > b) swap(a, b);
            printf("%d\n", num(calc(1, a, b)));
        }
    }
    return 0;
}
