#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 32768
using namespace std;
int n, dat[MAXN], num[MAXN], x;
bool use[MAXN];
int next(int x)
{
    x++;
    while (use[x]) x++;
    return x;
}
int main()
{

    while (scanf("%d", &n) != EOF)
    {
        memset(num, 0, sizeof(num));
        memset(use, false, sizeof(use));
        for (int i = 2; i <= n; ++i) scanf("%d", &dat[i]);
        dat[1] = 0;
        for (int i = n; i >= 1; --i)
        {
            int x = 1;
            while (use[x]) x++;
            for (int j = 1; j <= dat[i]; ++j)
                x = next(x);
            num[i] = x;
            use[x] = true;
        }
        for (int i = 1; i <= n; ++i) printf("%d\n", num[i]);

    }
    return 0;
}
