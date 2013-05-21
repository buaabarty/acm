#include <iostream>
#include <cstring>
#include <cstdio>
#define N 64
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
    int n;
    int mat[N][N], ret[N];
    while(scanf("%d",&n), n)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &mat[i][j]);
        printf("%d\n", maxclique(n, mat, ret));
    }
    return 0;
}
