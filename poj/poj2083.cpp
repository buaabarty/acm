#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 10
#define MAXM 3000
using namespace std;
char dat[MAXM][MAXM];
int p3[MAXN] = {1, 3, 9, 27, 81, 243, 729, 2187};
void fill(int x, int y, int size)
{
    if (size == 0)
    {
        dat[x][y] = 'X';
        return;
    }
    fill(x, y, size - 1);
    fill(x, y + p3[size - 1] * 2, size - 1);
    fill(x + p3[size - 1], y + p3[size - 1], size - 1);
    fill(x + p3[size - 1] * 2, y, size - 1);
    fill(x + p3[size - 1] * 2, y + p3[size - 1] * 2, size - 1);
}
int main()
{
    //freopen("output.txt","w", stdout);
    int n;
    //bool flag = false;
    while (scanf("%d", &n), (n > 0))
    {
        //if (flag) printf("\n");
        n--;
        memset(dat, 0, sizeof(dat));
        fill(0, 0, n);
        for (int i = 0; i < p3[n]; ++i)
            for (int j = p3[n] - 1; j >= 0; --j)
                if (dat[i][j])
                {
                    for (int k = j - 1; k >= 0; --k)
                        if (!dat[i][k]) dat[i][k] = ' ';
                    break;
                }
        for (int i = 0; i < p3[n]; ++i)
            puts(dat[i]);
        puts("-");
        //flag = true;
        //printf("\n");
    }
    return 0;
}
