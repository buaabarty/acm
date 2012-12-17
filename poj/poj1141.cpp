#include <iostream>
#include <cstdio>
#include <cstring>
#define N 128
using namespace std;
int f[N][N], t[N][N], n;
char str[N];
void go(int left, int right)
{
    if (left > right) return;
    if (left == right)
    {
        if ((str[left] == '(') || (str[left] == ')')) printf("()");
        else printf("[]");
        return;
    }
    if (t[left][right] >= 0)
    {
        go(left, t[left][right] - 1);
        go(t[left][right], right);
    }
    else
    {
        printf("%c", str[left]);
        go(left + 1, right - 1);
        printf("%c", str[right]);
    }
}
int main()
{
    while (gets(str) != NULL)
    {
        int n = strlen(str);
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i)
            f[i][i] = 1;
        for (int s = 1; s < n; ++s)
            for (int i = 0; i < n - s; ++i)
            {
                int j = i + s;
                f[i][j] = n * n;
                for (int k = i + 1; k <= j; ++k)
                    if (f[i][k - 1] + f[k][j] < f[i][j])
                    {
                        f[i][j] = f[i][k - 1] + f[k][j];
                        t[i][j] = k;
                    }
                if ((str[i] == '(') && (str[j] == ')') || (str[i] == '[') && (str[j] == ']'))
                {
                    if (f[i + 1][j - 1] < f[i][j])
                    {
                        f[i][j] = f[i + 1][j - 1];
                        t[i][j] = -1;
                    }
                }
            }
        go(0, n - 1);
        puts("");
    }
    return 0;
}
