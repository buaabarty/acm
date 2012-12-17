#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 210
using namespace std;
class Matrix{
public:
    long long dat[MAXN][MAXN];
    int n, m;
    Matrix(int x, int y){
        n = x, m = y;
        memset(dat, 0, sizeof(dat));
    }
    void format1(){
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i) dat[i][i] = 1;
    }
    void formatg(int k){
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i)
            dat[i][i] = 1;
        dat[n][k] = 1;
    }
    void formats(int x, int y){
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i)
            if (i == x) dat[y][i] = 1;
            else if (i == y) dat[x][i] = 1;
            else dat[i][i] = 1;
    }
    void formate(int k){
        memset(dat, 0, sizeof(dat));
        for (int i = 1; i <= n; ++i)
            if (i != k) dat[i][i] = 1;
    }
    Matrix operator *(Matrix a)
    {
        Matrix temp = Matrix(n, a.m);
        for (int i = 1; i <= n; ++i)
            for (int k = 1; k <= m; ++k)
                if (dat[i][k])
                    for (int j = 1; j <= a.m; ++j)
                        temp.dat[i][j] += dat[i][k] * a.dat[k][j];
        return temp;
    }
};
int n, m, k;
char c;
int x, y;
int main()
{
    while (scanf("%d%d%d", &n, &m, &k) && (n + m + k))
    {
        Matrix a = Matrix(n + 1, n + 1);
        Matrix temp = Matrix(n + 1, n + 1);
        a.format1();
        for (int i = 1; i <= k; ++i)
        {
            //a.print();
            scanf("\n%c", &c);
            if (c == 'g'){
                scanf("%d", &x);
                temp.formatg(x);
            //    temp.print();
                a = a * temp;
            }
            else if (c == 's'){
                scanf("%d%d", &x, &y);
                temp.formats(x, y);
            //    temp.print();
                a = a * temp;
            }
            else{
                scanf("%d", &x);
                temp.formate(x);
            //    temp.print();
                a = a * temp;
            }
        }
        //a.print();
        Matrix res = Matrix(1, n + 1);
        res.dat[1][n + 1] = 1;
        while (m > 0)
        {
            if (m & 1) res = res * a;
            a = a * a;
            m >>= 1;
        }
        for (int i = 1; i < n; ++i)
            printf("%lld ", res.dat[1][i]);
        printf("%lld\n", res.dat[1][n]);
    }
    return 0;
}
