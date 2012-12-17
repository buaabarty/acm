#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define N 510
#define LL long long
using namespace std;
struct matrix
{
    LL n, m;
    LL* num[N];
    matrix(){}
    matrix(LL x, LL y)
    {
        n = x, m = y;
        for (LL i = 1; i <= n; ++i)
            num[i] = new LL[m + 1];
        for (LL i = 1; i <= n; ++i)
            for (LL j = 1; j <= m; ++j)
                num[i][j] = 0;
    }
    matrix operator *(matrix a)
    {
        matrix temp(n, a.m);
        for (LL i = 1; i <= n; ++i)
            for (LL j = 1; j <= a.m; ++j)
                for (LL k = 1; k <= m; ++k)
                {
                    temp.num[i][j] += num[i][k] * a.num[k][j];
                }
        return temp;
    }
    void read()
    {
        for (LL i = 1; i <= n; ++i)
            for (LL j = 1; j <= m; ++j)
                scanf("%lld", &num[i][j]);
    }
    void print()
    {
        for (LL i = 1; i <= n; ++i)
        {
            for (LL j = 1; j <= m; ++j)
                printf("%5d", num[i][j]);
            puts("");
        }
        puts("");
    }
    bool equal(matrix a)
    {
        if (n != a.n) return false;
        if (m != a.m) return false;
        for (LL i = 1; i <= n; ++i)
            for (LL j = 1; j <= m; ++j)
                if (num[i][j] != a.num[i][j]) return false;
        return true;
    }
};
int main()
{
    LL n;
    while (~scanf("%lld", &n))
    {
        matrix a(n, n), b(n, n), c(n, n), rdh(1, n), rdl(n, 1);
        a.read();
        b.read();
        c.read();
        for (LL i = 1; i <= n; ++i)
        {
            rdh.num[1][i] = rand() % n;
            rdl.num[i][1] = rand() % n;
        }
        bool flag1 = (((rdh * a) * b).equal(rdh * c));
        bool flag2 = ((a * (b * rdl)).equal(c * rdl));
        if (flag1 && flag2) puts("YES");
        else puts("NO");;
    }
    return 0;
}
