#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#define MAXN 50010
#define MAXL 20
using namespace std;
int n, m, num[MAXN], a[MAXN], b[MAXN];
void get_ans()
{
    for (int i = 1; i <= n; ++i) { a[i] = i; b[i] = i; }
    num[0] = num[n + 1] = -INT_MAX;
    a[0] = b[n + 1] = -1;
    for (int i = 1; i <= n; ++i)
        while (num[a[i] - 1] >= num[i]) a[i] = a[a[i] - 1];
    for (int i = n; i >= 1; --i)
        while (num[b[i] + 1] >= num[i]) b[i] = b[b[i] + 1];
}
struct ST
{
    int dat, loc;
    ST(int x, int y)
    {
        dat = x, loc = y;
    }
    ST(){}
}st[MAXN][MAXL];
int p2[MAXL];
void Format_ST()
{
    memset(st, 0, sizeof(st));
    p2[0] = 1;
    for (int i = 1; i < MAXL; ++i) p2[i] = p2[i - 1] * 2;
    for (int i = 1; i <= n; ++i) st[i][0] = ST(num[i], i);
    for (int j = 1, p = 1; j < MAXL; ++j, p *= 2)
        for (int i = 1; i <= n - p * 2 + 1; ++i)
            if (st[i][j - 1].dat > st[i + p][j - 1].dat) st[i][j] = st[i][j - 1];
            else st[i][j] = st[i + p][j - 1];
}
ST RMQ(int s, int t)
{
    int l = (int)(log((double)(t - s + 1)) / log(2.0) + 1e-6);
    if (st[s][l].dat > st[t - p2[l] + 1][l].dat) return st[s][l];
    else return st[t - p2[l] + 1][l];
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
        get_ans();
        Format_ST();
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res = max(res, RMQ(i, b[i]).loc - i);
        if (res > 0) printf("%d\n", res);
        else printf("-1\n");
    }
    return 0;
}
