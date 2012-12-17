#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[1100], cnt;
void dfs(int deep, int s, int f)
{
    if (deep == 9)
    {
        num[++cnt] = s;
        return;
    }
    if (!f) dfs(deep + 1, s * 10, f);
    dfs(deep + 1, s * 10 + 4, 1);
    dfs(deep + 1, s * 10 + 7, 1);
}
int next(int s, int d)
{
    int i = 1;
    for (; num[i] <= s; ++i);
    if (i + d <= cnt) return num[i + d];
    else return -1;
}
double getsum(int l, int r, int k)
{
    int i = next(l, 0), j = next(l, k - 1);
    if ((i < 0) || (j < 0)) return 0;
    if (j >= r)
    {
        if (j == r) return 1;
        else return 0;
    }
    double s = 0;
    while ((next(l, k) < r) && (next(l, k) > 0))
    {
        s += (next(l, 0) - l) * (next(l, k) - next(l, k - 1)) - 1;
        l = next(l, 1);
    }
    s += (next(l, 0) - l) * (r - next(l, k - 1));
    if (r == next(l, k)) s--;
    return s;
}
int main()
{
    int pl, pr, vl, vr, k;
    cnt = 0;
    dfs(0, 0, 0);
    while (~scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &k))
    {
        if ((pl > vl) || (pl == vl) && (pr > vr))
        {
            swap(pl, vl);
            swap(pr, vr);
        }
        double s1 = getsum(pl, vr, k);
        double s2 = getsum(pl, vl, k);
        double s3 = getsum(pr, vr, k);
        double s4 = getsum(pr, vl, k);
        printf("%f %f %f %f\n", s1, s2, s3, s4);
        double s = s1 - s2 - s3 + s4;
        double l = (vr - vl + 1) * (pr - pl + 1);
        printf("%.12f %.12f\n", s, l);

    }
    return 0;
}
