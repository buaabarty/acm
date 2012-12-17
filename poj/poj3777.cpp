#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
LL x1, y1, z1, y2, z2, q, p;
struct matrix
{
    LL dat[2][2];
    int n, m;
    matrix(int a, int b)
    {
        memset(dat, 0, sizeof(dat));
        n = a, m = b;
    }
    matrix operator * (matrix a)
    {
        matrix temp(n, a.m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < a.m; ++j)
                for (int k = 0; k < m; ++k)
                    temp.dat[i][j] = (temp.dat[i][j] + dat[i][k] * a.dat[k][j]) % p;
        return temp;
    }
    void print()
    {
        printf("Matrix:\n");
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                printf("%4I64d", dat[i][j]);
            printf("\n");
        }
    }
};
LL iabs(LL x)
{
    return (x > 0) ? x : -x;
}
LL modp(LL x, LL y)
{
    return ((x % y) + y) % y;
}
int main()
{
    while (cin >> x1 >> y1 >> z1)
    {
        if ((x1 == -1) && (y1 == -1) && (z1 == -1)) break;
        cin >> y2 >> z2 >> p;
        LL q = 1, x = x1;
        while (y1)
        {
            if (y1 & 1LL) q = (q * x) % p;
            x = (x * x) % p;
            y1 >>= 1;
        }
        if (x1 == 0) q = 0;
        q = (((q + z1) % p) + p) % p;
        matrix a(2, 2), res(1, 2), o(2, 2);
        a.dat[0][0] = modp(q - 1, p);
        a.dat[0][1] = modp(q, p);
        a.dat[1][0] = 1;
        a.dat[1][1] = 0;
        o = a;
        res.dat[0][0] = 1;
        res.dat[0][1] = 0;
        while (z2 > 0)
        {
            if (z2 & 1) res = a * res;
            a = a * a;
            z2 >>= 1;
        }
        a = o;
        for (int i = 0; i < y2; ++i)
        {
            res = a * res;
            a = a * a;
        }
        cout << res.dat[0][0] << endl;
    }
    return 0;
}
