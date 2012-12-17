#include <iostream>
#include <cstdio>
#include <cstring>
#define N 2048
using namespace std;
int f[N];
bool app[N];
int main()
{
    int n;
    memset(f, 0, sizeof(f));
    f[0] = 0; f[1] = 1; f[2] = 1; f[3] = 1; f[4] = 2; f[5] = 2;
    for (int i = 6; i <= 2000; ++i)
    {
        memset(app, false, sizeof(app));
        for (int j = 3; j <= 5; ++j)
            app[f[i - j]] = 1;
        for (int j = 1; j <= i - 5; ++j)
            app[f[j] ^ f[i - 5 - j]] = 1;
        int j = 0;
        while (app[j]) j++;
        f[i] = j;
    }
    while (~scanf("%d", &n))
    {
        if (f[n]) printf("1\n");
        else printf("2\n");
    }
    return 0;
}
