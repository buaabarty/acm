#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1024
using namespace std;
int c[MAXN][MAXN], n;
int lowbit(int x)
{
    return (x & (x ^ (x - 1)));
}
int getsum(int x, int y)
{
    int s = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            s += c[i][j];
    return s;
}
void insert(int x, int y)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= n; j += lowbit(j))
            ++c[i][j];
}
int main()
{
    int t, m, x1, y1, x2, y2;
    scanf("%d", &t);
    while (t--)
    {
        memset(c, 0, sizeof(c));
        scanf("%d%d", &n, &m);
        char ch;
        while (m--)
        {
            scanf("%c", &ch);
            while ((ch != 'C') && (ch != 'Q')) scanf("%c", &ch);
            if (ch == 'C')
            {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                insert(x1, y1);
                insert(x2 + 1, y1);
                insert(x1, y2 + 1);
                insert(x2 + 1, y2 + 1);
            }
            else
            {
                scanf("%d%d", &x1, &y1);
                printf("%d\n", getsum(x1, y1) & 1);
            }
        }
        if (t > 0) printf("\n");
    }
    return 0;
}
