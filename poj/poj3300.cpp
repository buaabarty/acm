#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 1024
using namespace std;
int f, r, cnt;
double num[N], a[N], b[N];
int main()
{
    while (scanf("%d", &f), f)
    {
        scanf("%d", &r);
        for (int i = 1; i <= f; ++i) scanf("%lf", &a[i]);
        for (int i = 1; i <= r; ++i) scanf("%lf", &b[i]);
        cnt = 0;
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= f; ++i)
            for (int j = 1; j <= r; ++j)
                num[cnt++] = a[i] / b[j];
        sort(num, num + cnt);
        double res = 0;
        for (int i = 1; i < cnt; ++i) res = max(res, num[i] / num[i - 1]);
        printf("%.2lf\n", (round(res * 100.0) / 100.0));
    }
    return 0;
}
