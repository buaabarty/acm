#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1024
using namespace std;
int n, num[N][N];
int main()
{
    while (scanf("%d", &n), n)
    {
        bool flag = true;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &num[i][j]);
                if ((i > 1) && (j > 1))
                {
                    if (!(num[i - 1][j] + num[i][j - 1] == num[i - 1][j - 1] + num[i][j])) flag = false;
                }
            }
        if (flag) puts("homogeneous");
        else puts("not homogeneous");
    }
    return 0;
}
