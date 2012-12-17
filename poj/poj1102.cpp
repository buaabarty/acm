#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define eps 1e-6
#define S 128
using namespace std;
bool dat[10][7] = {{1, 0, 1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 1, 0, 1},
                   {1, 1, 1, 0, 1, 1, 0},
                   {1, 1, 1, 0, 1, 0, 1},
                   {0, 1, 0, 1, 1, 0, 1},
                   {1, 1, 1, 1, 0, 0, 1},
                   {1, 1, 1, 1, 0, 1, 1},
                   {1, 0, 0, 0, 1, 0, 1},
                   {1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 0, 1}};
char res[S * 3][S * 10];
char str[S * 10];
int s, n;
void print(int x, int y, int d)
{
    if (dat[d][0]) for (int i = y + 1; i <= y + s; ++i) res[x][i] = '-';
    if (dat[d][1]) for (int i = y + 1; i <= y + s; ++i) res[x + s + 1][i] = '-';
    if (dat[d][2]) for (int i = y + 1; i <= y + s; ++i) res[x + 2 * s + 2][i] = '-';
    if (dat[d][3]) for (int i = x + 1; i <= x + s; ++i) res[i][y] = '|';
    if (dat[d][4]) for (int i = x + 1; i <= x + s; ++i) res[i][y + s + 1] = '|';
    if (dat[d][5]) for (int i = x + 1; i <= x + s; ++i) res[i + s + 1][y] = '|';
    if (dat[d][6]) for (int i = x + 1; i <= x + s; ++i) res[i + s + 1][y + s + 1] = '|';
}
int main()
{
//    freopen("output.txt", "w", stdout);
    while (scanf("%d%s", &s, str), s)
    {
        memset(res, 0, sizeof(res));
        int len = strlen(str);
        for (int i = 0; i < len; ++i)
            print(0, i * (s + 3), str[i] - '0');
        for (int i = 0; i <= (s + 1) * 2; ++i)
        {
            int last = len * (s + 3) - 1;
            while (!res[i][last - 1]) last--;
            for (int j = 0; j <= min(last, len * (s + 3) - 2); ++j)
                if (res[i][j]) putchar(res[i][j]);
                else putchar(' ');
            puts("");
        }
        puts("");
    }

    return 0;
}
