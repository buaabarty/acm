#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 16
#define MAXM 4096
using namespace std;
char dat[MAXM][MAXM];
int p2[MAXN] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
void fill(int x, int y, int size)
{
    if (size == 1)
    {
        dat[x][y + 1] = '/';
        dat[x][y + 2] = '\\';
        dat[x + 1][y] = '/';
        dat[x + 1][y + 1] = '_';
        dat[x + 1][y + 2] = '_';
        dat[x + 1][y + 3] = '\\';
        return;
    }
    fill(x, y + p2[size - 1], size - 1);
    fill(x + p2[size - 1], y, size - 1);
    fill(x + p2[size - 1], y + p2[size], size - 1);
}
int main()
{
    //freopen("output.txt","w", stdout);
    int n;
    //bool flag = false;
    while (scanf("%d", &n), n)
    {
        //if (flag) printf("\n");
        memset(dat, 0, sizeof(dat));
        for (int i = 0; i < p2[n]; ++i)
            for (int j = 0; j < p2[n] + i; ++j)
                dat[i][j] = ' ';
        fill(0, 0, n);
        for (int i = 0; i <= p2[n]; ++i)
            puts(dat[i]);
        //flag = true;
        //printf("\n");
    }
    return 0;
}
