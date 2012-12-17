#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 100000000
using namespace std;
int res[MAXN], len = 0, n;
bool f[MAXN];
int main()
{
    for (int i = 1; i < 100000000; ++i)
    {
            //printf("%d\n", len);
        int temp = i;
        while (!(temp % 2)) temp /= 2;
        while (!(temp % 3)) temp /= 3;
        while (!(temp % 5)) temp /= 5;
        if (temp == 1) {res[++len] = i; printf("%d:%d\n", len, res[len]);}
        if (len > 1500) break; //{printf("%d\n", &i);break;}
    }
    while (scanf("%d", &n), n)
    {
        printf("%d\n", res[n]);
    }
    return 0;
}
