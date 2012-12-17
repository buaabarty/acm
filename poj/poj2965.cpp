#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int dat[4][4], min_res = INT_MAX;
bool use[4][4], res[4][4];
char str[6];
void dfs(int x, int y, int k)
{
    if (k >= min_res) return;
    if (y == 4)
    {
        if (k < min_res)
        {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if (dat[i][j]) return;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    res[i][j] = use[i][j];
            min_res = k;
        }
        return;
    }
    int dx = x + 1, dy = y;
    if (dx >= 4)
    {
        dx = 0, dy++;
    }
    dfs(dx, dy, k);
    use[x][y] = true;
    for (int i = 0; i < 4; ++i) dat[x][i] = !dat[x][i];
    for (int i = 0; i < 4; ++i) dat[i][y] = !dat[i][y];
    dat[x][y] = !dat[x][y];
    dfs(dx, dy, k + 1);
    use[x][y] = false;
    for (int i = 0; i < 4; ++i) dat[x][i] = !dat[x][i];
    for (int i = 0; i < 4; ++i) dat[i][y] = !dat[i][y];
    dat[x][y] = !dat[x][y];
}
void print_dat()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            printf("%d", dat[i][j]);
        printf("\n");
    }
}
int main()
{
    memset(use, false, sizeof(use));
    memset(dat, 0, sizeof(dat));
    for (int i = 0; i < 4; ++i)
    {
        scanf("%s", str);
        for (int j = 0; j < 4; ++j)
            dat[i][j] = (str[j] == '+');
    }
    //print_dat();
    dfs(0, 0, 0);
    printf("%d\n", min_res);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (res[i][j]) printf("%d %d\n", i + 1, j + 1);
    return 0;
}
