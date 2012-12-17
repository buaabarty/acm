#include <iostream>
#include <cstdio>
#include <cstring>
#define N 16
using namespace std;
int n, num[N*N][N*N];
bool dat[N*N*3][9];
int main()
{
    scanf("%d", &n);
    {
        memset(dat, 0, sizeof(dat));
        bool flag = true;
        for (int i = 1; i <= n * n; ++i)
            for (int j = 1; j <= n * n; ++j)
            {
                scanf("%d", &num[i][j]);
                int x = (i - 1) / n + 1;
                int y = (j - 1) / n + 1;
                int t = 2 * n * n + (x - 1) * n + y;
//                printf("%d %d %d\n", t, i, j);
                if (num[i][j])
                {
                    if (!dat[t][num[i][j]]) dat[t][num[i][j]] = true;
                    else flag = false;
                    if (!dat[i][num[i][j]]) dat[i][num[i][j]] = true;
                    else flag = false;
                    if (!dat[j + n * n][num[i][j]]) dat[j + n * n][num[i][j]] = true;
                    else flag = false;
                }
            }
        if (flag) printf("CORRECT\n");
        else printf("INCORRECT\n");
    }
    return 0;
}
