#include <iostream>
#include <cstdio>
#include <cstring>
#define N 10010
#define L 256
using namespace std;
int n, res;
char str[N][L];
int main()
{
    res = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%s", str[i]);
    res = strlen(str[1]);
    for (int i = 2, j; i <= n; ++i)
    {
        for (j = 0; j < min(strlen(str[i - 1]), strlen(str[i])); ++j)
            if (str[i][j] != str[i - 1][j]) break;
        res += strlen(str[i]) - j + 1;
    }
    printf("%d\n", res);
    return 0;
}
