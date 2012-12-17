#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 16
using namespace std;
struct node{
    int d, l;
}dat[MAXN];
int n, t;
bool map[MAXN][MAXN];
int cmp(const node &a, const node &b)
{
    if (a.d > b.d) return 1;
    else return 0;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &dat[i].d);
            dat[i].l = i;
        }
        bool flag = true;
        memset(map, false, sizeof(map));
        for (int i = 1; i <= n; ++i)
        {
            sort(dat + i, dat + n + 1, cmp);
            for (int j = i + 1; j <= n; ++j)
                if (dat[j].d > 0 && dat[i].d > 0 && !map[dat[i].l][dat[j].l])
                {
                    map[dat[i].l][dat[j].l] = true;
                    map[dat[j].l][dat[i].l] = true;
                    dat[j].d--;
                    dat[i].d--;
                }
            if (dat[i].d)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            printf("YES\n");
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                    printf("%d ", map[i][j]);
                printf("\n");
            }
        }
        else printf("NO\n");
        printf("\n");
    }
    return 0;
}
