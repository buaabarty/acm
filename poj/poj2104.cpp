#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 1000010
#define DEBUG
using namespace std;
int dat[MAXN];
int n, q, x, y, k;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &dat[i]);
    for (int i = 1; i <= q; ++i)
    {
        scanf("%d%d%d", &x, &y, &k);
        nth_element(dat + x - 1, dat + k + x - 2, dat + y - 1);
#ifdef DEBUG
        printf("%d\n", dat[x + k - 2]);
#endif
    }
    return 0;
}
