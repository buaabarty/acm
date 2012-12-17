#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 32768
using namespace std;
int myabs(int x)
{
    return (x > 0) ? x : -x;
}
int a[MAXN], b[MAXN], rest[MAXN], resd[MAXN], w, n, s, resl;
bool inside(int x, int y)
{
    return (x >= 0) && (y >= 0) && (y < w) && (x * w + y < s);
}
int dd(int t)
{
    int ss = 0;
    for (int i = 1; i <= n; ++i)
    {
        if ((t >= ss) && (t < ss + b[i])) return a[i];
        ss += b[i];
    }
}
int code(int x, int y)
{
    int maxd = 0;
    for (int dx = x - 1; dx <= x + 1; ++dx)
        for (int dy = y - 1; dy <= y + 1; ++dy)
            if (inside(dx, dy)){
                maxd = max(myabs(dd(dx * w + dy) - dd(x * w + y)), maxd);
            }
        return maxd;
}
void sort(int l, int r)
{
    int i = l, j = r;
    int mid = rest[(i + j) / 2];
    do{
        while (rest[i] < mid) ++i;
        while (rest[j] > mid) --j;
        if (i <= j){
            swap(rest[i], rest[j]);
            swap(resd[i], resd[j]);
            ++i, --j;
        }
    }while (i <= j);
    if (l < j) sort(l, j);
    if (i < r) sort(i, r);
}
int main()
{
    int x, y, t, now, nowx, nowy;
    while (scanf("%d", &w))
    {
        if (!w) break;
        n = 0;
        s = 0;
        while(scanf("%d%d", &x, &y))
        {
            if (x + y == 0) break;
            a[++n] = x;
            b[n] = y;
            s += b[n];
        }
        printf("%d\n", w);
        now = resl = 0;
        for (int i = 1; i <= n + 1; ++i)
        {
            nowx = now / w;
            nowy = now % w;
            for (int dx = nowx - 1; dx <= nowx + 1; ++dx)
                for (int dy = nowy - 1; dy <= nowy + 1; ++dy)
                    if (inside(dx, dy)){
                        t = dx * w + dy;
                        rest[++resl] = t;
                        resd[resl] = code(dx, dy);
                    }
            now += b[i];
        }
        sort(1, resl);
        int last = 0;
        for (int i = 2; i <= resl; ++i)
            if (resd[i] != resd[i - 1])
            {
                printf("%d %d\n", resd[i - 1], rest[i] - last);
                last = rest[i];
            }
        printf("%d %d\n0 0\n", resd[resl], s - last);
    }
    printf("0\n");
    return 0;
}
