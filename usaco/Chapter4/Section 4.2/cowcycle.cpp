/*
ID:ybojan2
LANG:C++
TASK:cowcycle
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 128
#define eps 1e-10
using namespace std;
int f, r, f1, f2, r1, r2;
int nf[MAXN], nr[MAXN];
int ansf[MAXN], ansr[MAXN];
double ans;
bool fsame(double x, double y)
{
    return fabs(x - y) < eps;
}
double s[MAXN * MAXN];
double res()
{
    int l = 0;
    for (int i = 1; i <= f; ++i)
        for (int j = 1; j <= r; ++j)
        {
            double x = (double) nf[i] / (double) nr[j];
            s[++l] = x;
        }
    sort(s + 1, s + l + 1);
    for (int i = 1; i < l; ++i)
        s[i] = s[i + 1] - s[i];
    l--;
    double ave = 0.0;
    for (int i = 1; i <= l; ++i)
        ave = ave + s[i];
    ave = ave / (double) l;
    double sum = 0.0;
    for (int i = 1; i <= l; ++i)
        sum = sum + (s[i] - ave) * (s[i] - ave);
    return sum / (double)l;
}
void dfs2(int deep, int last)
{
    if (deep == r + 1)
    {
        if (nr[r] * nf[f] < 3 * nr[1] * nf[1]) return;
        double temp = res();
        if (temp < ans)
        {
            ans = temp;
            memcpy(ansf, nf, sizeof(nf));
            memcpy(ansr, nr, sizeof(nr));
        }
        return;
    }
    for (int i = last + 1; i <= r2; ++i)
    {
        nr[deep] = i;
        dfs2(deep + 1, i);
        nr[deep] = 0;
    }
}
void dfs1(int deep, int last)
{
    if (deep == f + 1)
    {
        dfs2(1, r1 - 1);
        return;
    }
    for (int i = last + 1; i <= f2; ++i)
    {
        //if ((deep == 1) && (i > f1 + 1)) break;
        nf[deep] = i;
        dfs1(deep + 1, i);
        nf[deep] = 0;
    }
}
int main()
{
//    freopen("cowcycle.in", "r", stdin);
//    freopen("cowcycle.out", "w", stdout);
    scanf("%d%d", &f, &r);
    scanf("%d%d%d%d", &f1, &f2, &r1, &r2);
    ans = 1e100;
    dfs1(1, f1 - 1);
    for (int i = 1; i < f; ++i)
        printf("%d ", ansf[i]);
    printf("%d\n", ansf[f]);
    for (int i = 1; i < r; ++i)
        printf("%d ", ansr[i]);
    printf("%d\n", ansr[r]);
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
