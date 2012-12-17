#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[10001];
void format()
{
    memset(f, 0, sizeof(f));
    int t = 0;
    for (int i = 1; 1; ++i)
        for (int j = 1; j <= i; ++j)
        {
            f[++t] = f[t - 1] + i;
            if (t == 10001) return;
        }
}
int main()
{
    format();
    int x;
    while (scanf("%d", &x),x) printf("%d %d\n", x, f[x]);
    return 0;
}
