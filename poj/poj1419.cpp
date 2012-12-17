/*
输出最大团的点的个数以及一组解
ret[0~res - 1]为解的点集
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 128
using namespace std;
void clique(int n, int* u, int mat[][N], int size, int& max, int& bb, int* res, int* rr, int* c)
{
    int i, j, vn, v[N];
    if (n)
    {
        if (size + c[u[0]] <= max) return;
        for (i = 0; i < n + size - max && i < n; ++ i)
        {
            for (j = i + 1, vn = 0; j < n; ++ j)
                if (mat[u[i]][u[j]]) v[vn ++] = u[j];
            rr[size] = u[i];
            clique(vn, v, mat, size + 1, max, bb, res, rr, c);
            if (bb) return;
        }
    }
    else if (size > max)
    {
        max = size;
            for (i = 0; i < size; ++ i)
                res[i] = rr[i];
        bb = 1;
    }
}
int maxclique(int n, int mat[][N], int *ret)
{
    int max = 0, bb, c[N], i, j;
    int vn, v[N], rr[N];
    for (c[i = n - 1] = 0; i >= 0; -- i)
    {
        for (vn = 0, j = i + 1; j < n; ++ j)
            if (mat[i][j]) v[vn ++] = j;
        bb = 0;
        rr[0] = i;
        clique(vn, v, mat, 1, max, bb, ret, rr, c);
        c[i] = max;
    }
    return max;
}
int main()
{
    int n, m, T;
    int mat[N][N], ret[N], x, y;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = 1;
        while (m--)
        {
            scanf("%d%d", &x, &y);
            mat[x - 1][y - 1] = 0;
        }
        int res = maxclique(n, mat, ret);
        printf("%d\n", res);
        printf("%d", ret[0] + 1);
        for (int i = 1; i < res; ++i)
            printf(" %d", ret[i] + 1);
        printf("\n");
    }
    return 0;
}
