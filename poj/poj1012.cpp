#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool use[300];
int res[14] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};
int next(int x, int n)
{
    return (x % n) + 1;
}
int find_next(int x, int n)
{
    x = next(x, n);
    while (use[x])
    {
        x = next(x, n);
    }
    return x;
}
bool okay(int n, int m)
{
    int x = 0, last = n * 2;
    memset(use, false, sizeof(use));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= ((m - 1) % last) + 1; ++j)
            x = find_next(x, 2 * n);
        use[x] = true;
        last--;
        if (x <= n) return false;
    }
    return true;
}
void solve()
{
    for (int i = 1; i <= 13; ++i)
        for (int j = i; ; ++j)
        {
            if (okay(i, j))
            {
                if (res[i] == j) printf("OKAY%d\n", i);
                break;
            }
        }
    printf("\n");
}
int main()
{
    f
    return 0;
}
