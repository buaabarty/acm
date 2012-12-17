#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int x, y;
int dfs(int n)
{
    if (n == 1) return 0;
    else if (n & 1) return dfs(3 * n + 1) + 1;
    else return dfs(n >> 1) + 1;
}
int main()
{
    while (~scanf("%d%d", &x, &y))
    {
        printf("%d %d ", x, y);
        if (x > y) swap(x, y);
        int res = 0;
        for (int i = x; i <= y; ++i)
            res = max(res, dfs(i));
        printf("%d\n", res + 1);
    }
    return 0;
}
