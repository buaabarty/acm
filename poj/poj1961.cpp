#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000010
using namespace std;
int next[N], n;
char s[N];
void getnext()
{
    next[0] = -1;
    for (int j = 0, k = -1; j < n;)
        if ((k == -1) || (s[j] == s[k])) next[++j] = ++k;
        else k = next[k];
}
int main()
{
    int ca = 0;
    while (scanf("%d", &n), n)
    {
        scanf("%s", s);
        getnext();
        printf("Test case #%d\n", ++ca);
        for (int i = 2; i <= n; ++i)
            if ((i % (i - next[i])) == 0)
            {
                int x = i / (i - next[i]);
                if (x > 1) printf("%d %d\n", i, x);
            }
        puts("");
    }
    return 0;
}
