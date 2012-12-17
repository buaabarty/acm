#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MAXN 32
using namespace std;
string temp;
int n, m, dat[MAXN][MAXN];
char c;
int main()
{
    while (cin >> temp)
    {
        if (temp == "ENDOFINPUT") break;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            scanf("\n");
            for (int j = 1; j <= m; ++j)
            {
                scanf("%c", &c);
                dat[i % n][j % m] = c - '0';
            }
        }
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
                printf("%d", (dat[i][j] + dat[(i+1)%n][j] + dat[i][(j+1)%m] + dat[(i+1)%n][(j+1)%m]) / 4);
            printf("\n");
        }
        cin >> temp;
    }
    return 0;
}
