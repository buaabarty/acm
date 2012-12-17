#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 210
using namespace std;
int x[MAXN], y[MAXN], d[MAXN], mm;
class Matrix{
public:
    int dat[MAXN][MAXN], n;
    Matrix(int x){
        n = x;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dat[i][j] = INT_MAX / 2;
    }
    void format1(){
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dat[i][j] = INT_MAX / 2;
        for (int i = 1; i <= n; ++i) dat[i][i] = 0;
    }
    void format(){
        for (int i = 1; i <= mm; ++i)
        {
            dat[x[i]][y[i]] = min(dat[x[i]][y[i]], d[i]);
            dat[y[i]][x[i]] = min(dat[y[i]][x[i]], d[i]);
        }
    }
    Matrix operator *(Matrix a)
    {
        Matrix temp = Matrix(n);
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    temp.dat[i][j] = min(temp.dat[i][j], dat[i][k] + a.dat[k][j]);
        return temp;
    }
};
int l, s, e, n;
bool app[1024];
int hash[1024];
void init()
{
    scanf("%d%d%d%d", &l, &mm, &s, &e);
    memset(app, false, sizeof(app));
    for (int i = 1; i <= mm; ++i)
    {
        scanf("%d%d%d", &d[i], &x[i], &y[i]);
        app[x[i]] = true;
        app[y[i]] = true;
    }
    app[s] = true;
    app[e] = true;
    int cnt = 0;
    for (int i = 1; i <= 1000; ++i)
        if (app[i]) hash[i] = ++cnt;
    for (int i = 1; i <= mm; ++i)
    {
        x[i] = hash[x[i]];
        y[i] = hash[y[i]];
    }
    s = hash[s];
    e = hash[e];
    n = cnt;
}

int main()
{
    init();
    Matrix a = Matrix(n);
    a.format();
    Matrix res = Matrix(n);
    res.format1();
    while (l > 0)
    {
        if (l & 1) res = res * a;
        a = a * a;
        l >>= 1;
    }
    printf("%d\n", res.dat[s][e]);
    return 0;
}
