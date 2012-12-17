#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <ctime>
#define MAXN 500000
using namespace std;
long long res[MAXN], dat[MAXN];
set<long long, less<long long> > s;
set<long long>::iterator p;
int l, r, n, mid;
int getsum(long long x)
{
    l = 0, r = n + 1;
    while (l < r){
        if (l + 1 == r){
            if (x >= res[r]) l = r;
            break;
        }
        mid = (l + r + 1) / 2;
        if (x >= res[mid]) l = mid;
        else r = mid - 1;
    }
    return l;
}
void dfs(long long x, int deep)
{
    if (deep == n + 1) return;
    if (x > 1000000000000LL / dat[deep]) return;
    dfs(x, deep + 1);
    while (x <= 1000000000000LL / dat[deep])
    {
        x =  x * dat[deep];
        res[++r] = x;
        dfs(x, deep + 1);
    }
}
void make(long long x, int deep)
{
    dat[r++] = x;
    if (deep == 12) return;
    make(x * 10LL + 4LL, deep + 1);
    make(x * 10LL + 7LL, deep + 1);
}
int main()
{
    int t;
    long long x, y;
    r = 0;
    make(0, 0);
    n = r - 1;
    sort(dat + 1, dat + n + 1);
    r = 0;
    dfs(1, 1);
    n = r;
    sort(res + 1, res + n + 1);
    res[0] = 0;
    r = 0;
    for (int i = 1; i <= n; ++i)
        if (res[i] != res[i - 1]) res[++r] = res[i];
    n = r;
    res[n + 1] = 10000000000000LL;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld", &x, &y);
        printf("%d\n", getsum(y) - getsum(x - 1));
    }
    return 0;
}
