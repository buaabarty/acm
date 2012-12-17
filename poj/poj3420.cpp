#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 16
using namespace std;
int mod, s;
int okay(int x, int y)
{
    if ((x | y) != 15) return 0;
    return ((x & y) == 0) || ((x & y) == 3) || ((x & y) == 6) || ((x & y) == 12) || ((x & y) == 15);
}
class Matrix{
public:
    int num[MAXN][MAXN], n, m;
    Matrix(int x, int y)
    {
        n = x, m = y;
        memset(num, 0, sizeof(num));
    }
    void format_one()
    {
        memset(num, 0, sizeof(num));
        for (int i = 0; i < 16; ++i)
            num[i][i] = 1;
        n = m = 16;
    }
    void format_cal()
    {
        for (int i = 0; i < 16; ++i)
            for (int j = 0; j < 16; ++j)
                num[i][j] = okay(i, j);
        n = m = 16;
    }
    Matrix operator *(Matrix a)
    {
        Matrix temp(16, 16);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < a.m; ++j)
                for (int k = 0; k < m; ++k)
                    temp.num[i][j] = (temp.num[i][j] + num[i][k] * a.num[k][j]) % mod;
        return temp;
    }
    void print()
    {
        for (int i = 0; i < n; ++i, printf("\n"))
            for (int j = 0; j < m; ++j)
                printf("%d ", num[i][j]);
    }
};
int main()
{
    Matrix temp(16, 16), res(16, 16);
    while (cin >> s >> mod)
    {
        if ((s++) + mod == 0) break;
        res.format_one();
        temp.format_cal();
        while (s > 0)
        {
            if (s % 2) res = res * temp;
            temp = temp * temp;
            s /= 2;
        }
        printf("%d\n", res.num[0][15]);
    }
    return 0;
}
