#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int n, m, d[N];
int map[N][N];
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                map[i][j] = INT_MAX / 3;
    }
    return 0;
}
