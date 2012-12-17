#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 200000
#define MAXM 20
#define MAXD 100000
using namespace std;
int num[MAXN], st[MAXN * 3], l[MAXN * 3];
int f[MAXN * 3][MAXM];
int n, q, m, p2[MAXM];
bool init()
{
    p2[0] = 1;
    for (int i = 1; i < 20; ++i) p2[i] = p2[i - 1] * 2;
    memset(st, 0, sizeof(st));
    memset(num, 0, sizeof(num));
    num[0] = 0x80;
    memset(l, 0, sizeof(l));
    scanf("%d", &n);
    if (n == 0) return false;
    scanf("%d", &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &num[i]);
        num[i] = num[i] + MAXD;
        if (num[i] != num[i - 1])
        {
            st[num[i]] = i;
//            printf("%d %d ", num[i], i);
        }
        l[num[i]]++;
    }
    n = MAXD * 2;
//    printf("\n");
//    for (int i = 1; i <= n; ++i)
//        printf("%d ", l[i]);
//    printf("\n");

    m = log(n) / log(2) + 1;
    for (int i = 1; i <= n; ++i)
        f[i][0] = l[i];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j + p2[i] - 1 <= n; ++j)
            f[j][i] = max(f[j][i - 1], f[j + p2[i - 1]][i - 1]);
    return true;
}
int rmq(int x, int y)
{
    int len = log(y - x + 1) / log(2);
    return max(f[x][len], f[y - p2[len] + 1][len]);
}
int ans(int x, int y)
{
    //printf("%d %d %d %d\n", num[x], num[y], st[num[x]], st[num[y]]);
    if (num[y] == num[x]) return y - x + 1;
    int s1 = l[num[x]] - x + st[num[x]];
    int s2 = y - st[num[y]] + 1;
    if (num[y] == num[x] + 1) return max(s1, s2);
    return max(rmq(num[x] + 1, num[y] - 1), max(s1, s2));
}
int cnt[MAXN * 3];
int crack(int x, int y)
{
    memset(cnt, 0, sizeof(cnt));
    int res = 0;
    for (int i = x; i <= y; ++i)
    {
        cnt[num[i]]++;
        res = max(res, cnt[num[i]]);
    }
    return res;
}
int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("ans.out", "w", stdout);
    while (init())
    {
        int x, y;
        for (int i = 1; i <= q; ++i)
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", ans(x, y));
//            printf("%d\n", crack(x, y));
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
