#include <iostream>
#include <cstdio>
#include <cstring>
#define N 20
#define LL long long
using namespace std;
LL MOD = 1000000007LL;
struct matrix
{
    LL n, m, num[N][N];
    matrix(){}
    matrix(LL x, LL y)
    {
        n = x, m = y;
        memset(num, 0, sizeof(num));
    }
    matrix operator *(matrix a)
    {
        matrix temp(n, a.m);
        for (LL i = 1; i <= n; ++i)
            for (LL j = 1; j <= a.m; ++j)
                for (LL k = 1; k <= m; ++k)
                {
                    temp.num[i][j] += num[i][k] * a.num[k][j];
                    temp.num[i][j] %= MOD;
                }
        return temp;
    }
};
int main()
{
    LL n;
    cin >> n;
    matrix a = matrix(2, 2), b = matrix(2, 1);
    matrix res;
    a.num[1][1] = 3;
    a.num[1][2] = 1;
    a.num[2][1] = 1;
    a.num[2][2] = 3;
    b.num[1][1] = 1;
    b.num[2][1] = 0;
    while (n)
    {
        if (n & 1)
        {
            b = a * b;
        }
        a = a * a;
        n >>= 1;
    }
    cout << b.num[1][1] << endl;
    return 0;
}
