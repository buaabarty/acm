#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int st, ed;
int num[20], len, c[35][35];
int dfs(int now, int s0, int s1)
{

}
int count(int x)
{
    if (x <= 0) return 1;
    len = 0;
    int s = x;
    while (s)
    {
        len++;
        num[len] = (s & 1);
        s >>= 1;
    }
    for (int i = 1; i < len - i + 1; ++i)
        swap(num[i], num[len - i + 1]);
    return dfs(1, 0, 0);
}
int main()
{
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= 33; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    while (~scanf("%d%d", &st, &ed))
    {
        printf("%d\n", count(ed) - count(st - 1));
    }
    return 0;
}
