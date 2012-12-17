#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, num[10][10], res;
int calc()
{
    int mm = -100000000, s[10];
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            s[j] += num[i][j];
    for (int i = 1; i <= n; ++i) mm = max(mm, s[i]);
    return mm;
}
void print()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%d\t", num[i][j]);
        puts("");
    }
}
void dfs(int deep)
{
    if (deep == n)
    {
        res = min(res, calc());
        return ;
    }
    for (int i = 0; i <= n; ++i)
    {
        dfs(deep + 1);
        num[deep][0] = num[deep][1];
        for (int j = 1; j <= n; ++j)
            num[deep][j] = num[deep][j + 1];
        num[deep][n] = num[deep][0];
    }
}
int main()
{
    while (~scanf("%d", &n), (n > 0))
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &num[i][j]);
        res = 1000000000;
        dfs(1);
        printf("%d\n", res);
    }
    return 0;
}
