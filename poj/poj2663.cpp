#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 8
using namespace std;
int s;
int okay(int x, int y)
{
    if ((x | y) != 7) return 0;
    return ((x & y) == 0) || ((x & y) == 3) || ((x & y) == 6);
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
        for (int i = 0; i < 8; ++i)
            num[i][i] = 1;
        n = m = 8;
    }
    void format_cal()
    {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                num[i][j] = okay(i, j);
        n = m = 8;
    }
    Matrix operator *(Matrix a)
    {
        Matrix temp(8, 8);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < a.m; ++j)
                for (int k = 0; k < m; ++k)
                    temp.num[i][j] = (temp.num[i][j] + num[i][k] * a.num[k][j]);
        return temp;
    }
};
int main()
{
    Matrix temp(8, 8), res(8, 8);
    while (cin >> s)
    {
        if (s < 0) break;
        s++;
        res.format_one();
        temp.format_cal();
        while (s > 0)
        {
            if (s % 2) res = res * temp;
            temp = temp * temp;
            s /= 2;
        }
        printf("%d\n", res.num[0][7]);
    }
    return 0;
}
