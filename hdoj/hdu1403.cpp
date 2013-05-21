#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 200010
using namespace std;
int r[MAXN];
int wa[MAXN], wb[MAXN], wv[MAXN], tmp[MAXN];
int sa[MAXN]; //index range 1~n value range 0~n-1
int cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = wa, *y = wb, *ws = tmp;
    for (i = 0; i < m; ++i)
        ws[i] = 0;
    for (i = 0; i < n; ++i)
        ws[x[i] = r[i]]++;
    for (i = 1; i < m; ++i)
        ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; --i)
        sa[--ws[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
        for (p = 0, i = n - j; i < n; ++i)
            y[p++] = i;
        for (i = 0; i < n; ++i)
            if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; ++i)
            wv[i] = x[y[i]];
        for (i = 0; i < m; ++i)
            ws[i] = 0;
        for (i = 0; i < n; ++i)
            ws[wv[i]]++;
        for (i = 1; i < m; ++i)
            ws[i] += ws[i - 1];
        for (i = n - 1; i >= 0; --i)
            sa[--ws[wv[i]]] = y[i];
        for (swap(x, y), p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}
int rank[MAXN]; //index range 0~n-1 value range 1~n
int height[MAXN]; //index from 1   (height[1] = 0)
void calHeight(int *r, int *sa, int n) {
    int i, j, k = 0;
    for (i = 1; i <= n; ++i)
        rank[sa[i]] = i;
    for (i = 0; i < n; height[rank[i++]] = k)
        for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; ++k);
    return;
}
char a[MAXN], b[MAXN];

int main()
{
    while (~scanf("%s%s", a, b))
    {
        int n = strlen(a), m, k = 0;
        strcat(a, "$");
        strcat(a, b);
        m = strlen(a);
        for (int i = 0; i < m; ++i)
        {
            r[i] = a[i];
            k = max(k, r[i]);
        }
        da(r, sa, m + 1, k + 1);
        calHeight(r, sa, m);
        //for (int i = 0; i < m; ++i)
        //    printf("%d %d\n", sa[i], height[i]);
        int res = 0;
        for (int i = 1; i < m; ++i)
            if ((sa[i] < n) && (sa[i - 1] >= n) || (sa[i] >= n) && (sa[i - 1] < n))
                res = max(res, height[i]);
        printf("%d\n", res);
    }
    return 0;
}
