#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1000000
using namespace std;
long long n, t, q, nid = 0, num[MAXN];
struct node{
    long long l, r, lch, rch;
    long long s, cover, first;
}a[MAXN];
long long buildtree(long long left, long long right)
{
    if (left > right) return -1;
    long long now = ++nid;
    a[now].l = left, a[now].r = right, a[now].first = (left == right) * num[left], a[now].cover = 0, a[now].s = 0;
    if (left == right) return now;
    long long mid = (left + right) >> 1;
    a[now].lch = buildtree(left, mid);
    a[now].rch = buildtree(mid + 1, right);
    a[now].first = a[a[now].lch].first + a[a[now].rch].first;
    return now;
}
void insert(long long id, long long left, long long right, long long d)
{
    a[id].s += (right - left + 1) * d;
    if ((left == a[id].l) && (right == a[id].r)){
        a[id].cover += d;
    }
    else{
        long long mid = (a[id].l + a[id].r) >> 1;//left~mid, mid+1~right
        if (right <= mid) insert(a[id].lch, left, right, d);
        else if (left > mid) insert(a[id].rch, left, right, d);
        else {
            insert(a[id].lch, left, mid, d);
            insert(a[id].rch, mid + 1, right, d);
        }
    }
}
long long calc(long long id, long long left, long long right)
{
    long long sum = 0;
    if ((left == a[id].l) && (right == a[id].r)) sum = a[id].first + a[id].s;
    else {
        sum += a[id].cover * (right - left + 1);
        long long mid = ((a[id].l + a[id].r) >> 1);//left~mid, mid+1~right
        if (right <= mid) sum += calc(a[id].lch, left, right);
        else if (left > mid) sum += calc(a[id].rch, left, right);
        else{
            sum += calc(a[id].lch, left, mid) + calc(a[id].rch, mid + 1, right);
        }
    }
    return sum;
}
int main()
{
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &num[i]);
    buildtree(1, n);
    char opr;
    long long a, b, c;
    for (int i = 1; i <= q; ++i)
    {
        scanf("\n%c", &opr);
        if (opr == 'Q'){
            scanf("%lld%lld", &a, &b);
            if (a > b) swap(a, b);
            printf("%lld\n", calc(1, a, b));
        }
        else{
            scanf("%lld%lld%lld", &a, &b, &c);
            if (a > b) swap(a, b);
            insert(1, a, b, c);
        }
    }
    return 0;
}
