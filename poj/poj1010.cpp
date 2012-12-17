#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#define MAXN 128
using namespace std;
int s[MAXN], sl = 0, c[MAXN], cl = 0;
int res1, res2, res3, res[MAXN], cnt, now[MAXN];
bool init()
{
    int x;
    memset(s, 0, sizeof(s));
    memset(c, 0, sizeof(c));
    sl = cl = 0;
    if (scanf("%d", &x) == EOF) return false;
    while (x)
    {
        s[++sl] = x;
        scanf("%d", &x);
    }
    sort(s + 1, s + sl + 1);
    scanf("%d", &x);
    while (x)
    {
        c[++cl] = x;
        scanf("%d", &x);
    }
    return true;
}
void dfs(int sum, int deep, int count, int last)
{
    if (sum == 0)
    {
        if ((count > res1) || ((count == res1) && (deep < res2))
            || ((count == res1) && (deep == res2) && (s[last] > res3)))
        {
            res1 = count;
            res2 = deep;
            res3 = s[last];
            for (int i = 1; i <= res2; ++i)
                res[i] = s[now[i]];
            cnt = 1;
        }
        else if ((count == res1) && (deep == res2) && (s[last] == res3)) cnt++;
        return;
    }
    if (deep == 4) return;
    for (int i = last; i <= sl; ++i)
    {
        if (i == 0) continue;
        if (sum < s[i]) break;
        now[deep + 1] = i;
        if (i == last) dfs(sum - s[i], deep + 1, count, i);
        else dfs(sum - s[i], deep + 1, count + 1, i);
        now[deep + 1] = 0;
    }
}
void solve(int sum)
{
    memset(res, 0, sizeof(res));
    res1 = 0;
    res2 = INT_MAX;
    res3 = 0;
    cnt = 0;
    dfs(sum, 0, 0, 0);
}
int main()
{
    while (init())
    {
        for (int ca = 1; ca <= cl; ++ca)
        {
            solve(c[ca]);
            if (cnt > 1) printf("%d (%d): tie\n", c[ca], res1);
            else if (cnt == 0) printf("%d ---- none\n", c[ca]);
            else
            {
                printf("%d (%d):", c[ca], res1);
                for (int ll = 1; ll <= res2; ++ll)
                    printf(" %d", res[ll]);
                printf("\n");
            }
        }
    }
    return 0;
}
