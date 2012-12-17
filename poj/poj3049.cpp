#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, num[20];
char s[20], res[20];
bool use[20];
bool yuanyin(char x)
{
    return (x == 'a') || (x == 'e') || (x == 'i') || (x == 'o') || (x == 'u');
}
void dfs(int d, int last, bool got)
{
    if (d == n)
    {
        if (!got) return;
        res[d] = '\0';
        puts(res);
        return;
    }
    for (int i = last + 1; i < m; ++i)
        if (!use[i])
        {
            res[d] = s[i];
            use[i] = true;
            dfs(d + 1, i, got || (yuanyin(s[i])));
            use[i] = false;
        }
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < m; ++i) scanf("%c%c", &s[i], &s[i]);
        s[m] = '\0';
        sort(s, s + m);
        //puts(s);
        memset(use, false, sizeof(use));
        dfs(0, -1, false);
    }
    return 0;
}
