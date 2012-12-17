#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char d[10010][20], str[20];
int myabs(int x)
{
    return (x > 0) ? x : -x;
}
int f[20][20];
bool okay(char a[], char b[])
{
    int la = strlen(a), lb = strlen(b);
    if (myabs(la - lb) > 1) return false;
    if (la == lb){
        int s = 0;
        for (int i = 0; i < la; ++i)
            if (a[i] != b[i]){
                s++; if (s > 1) return false;
            }
    }
    else{
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= la; ++i)
            for (int j = 1; j <= lb; ++j)
            {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
                if (a[i - 1] == b[j - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        if (f[la][lb] != min(la, lb)) return false;
    }
    return true;
}
int main()
{
    int n = 0;
    while (scanf("%s", d[++n]))
    {
        if (d[n][0] == '#') break;
    }
    n--;
    while (scanf("%s", str))
    {
        if (str[0] == '#') break;
        bool find = false;
        for (int i = 1; i <= n; ++i)
            if (strcmp(str, d[i]) == 0){
                find = true;
                printf("%s is correct\n", str);
                break;
            }
        if (!find){
            printf("%s:", str);
            for (int i = 1; i <= n; ++i)
                if (okay(str, d[i])) printf(" %s", d[i]);
            printf("\n");
        }
    }
    return 0;
}
