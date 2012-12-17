#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
class data
{
public:
    char c;
    int o;
    bool operator < (const data a) const
    {
        if (c != a.c) return c > a.c;
        return o < a.o;
    }
}d[100010];
int n;
char str[100010];
int main()
{
    scanf("%s", str);
    n = strlen(str);
    for (int i = 1; i <= n; ++i)
    {
        d[i].o = i;
        d[i].c = str[i - 1];
    }
    sort(d + 1, d + n + 1);
    int now = 0;
    for (int i = 1; i <= n; ++i)
        if (d[i].o > now)
        {
            printf("%c", d[i].c);
            now = d[i].o;
        }
    printf("\n");
    return 0;
}
