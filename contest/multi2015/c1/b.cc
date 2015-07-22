#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100000;
const int L = 20;
struct ST
{
    int dat, loc;
    ST(int x, int y)
    {
        dat = x, loc = y;
    }
    ST(){}
};
struct STable {
    ST st[N][L];
    int n, num1[N], p2[L];
    void Format_ST()
    {
        memset(st, 0, sizeof(st));
        p2[0] = 1;
        for (int i = 1; i < L; ++i) p2[i] = p2[i - 1] * 2;
        for (int i = 1; i <= n; ++i) st[i][0] = ST(num[i], i);
        for (int j = 1, p = 1; j < L; ++j, p *= 2)
            for (int i = 1; i <= n - p * 2 + 1; ++i)
                if (st[i][j - 1].dat > st[i + p][j - 1].dat) st[i][j] = st[i][j - 1];
                else st[i][j] = st[i + p][j - 1];
    }
    ST RMQ(int s, int t)
    {
        int l = (int)(log((double)(t - s + 1)) / log(2.0) + 1e-6);
        if (st[s][l].dat > st[t - p2[l] + 1][l].dat) return st[s][l];
        else return st[t - p2[l] + 1][l];
    }
}a, b;
