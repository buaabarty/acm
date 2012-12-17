#include <iostream>
#include <cstdio>
#define MAXL 1024
using namespace std;
int main()
{
    int n, dat[MAXL], l = 0, t = 2;
    scanf("%d", &n);
    if (n == 1){
        printf("1\n");
        return 0;
    }
    while (n >= 0)
    {
        dat[++l] = t;
        n -= t++;
    }
    n += --t;
    t = --l;
    while (n > 0)
    {
        dat[t]++;
        n--;
        t--;
        if (t == 0) t = l;
    }
    for (int i = 1; i < l; ++i) printf("%d ", dat[i]);
    printf("%d\n", dat[l]);
    return 0;
}
