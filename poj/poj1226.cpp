#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define N 100000
using namespace std;
int p[N][60], cnt, id[N], d[N], n, res;
int app[256], hc;
int ord(char c)
{
    if (app[c]) return app[c];
    else
    {
        app[c] = ++hc;
        return app[c];
    }
}
void init_trie()
{
    memset(p, 0, sizeof(p));
    memset(d, 0, sizeof(d));
    memset(id, 0, sizeof(id));
    cnt = res = 0;
}
void insert(char s[], int st, int x)
{
    for (int i = st, j = 0; s[i]; ++i)
    {
        if (!p[j][ord(s[i])]) p[j][ord(s[i])] = ++cnt;
        j = p[j][ord(s[i])];
        if (id[j] != x){ id[j] = x; d[j]++; }
        if (d[j] == n) res = max(res, i - st + 1);
    }
}

void mstrrev(char s[])
{
    int l = strlen(s);
    for (int i = 0; i < l / 2; ++i)
        swap(s[i], s[l - 1 - i]);
}

int main()
{
    hc = 0;
    memset(app, 0, sizeof(app));
    int T;
    char str[128];
    scanf("%d", &T);
    while (T--)
    {
        init_trie();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", str);
            for (int j = 0; str[j]; ++j) insert(str, j, i);
            mstrrev(str);
            for (int j = 0; str[j]; ++j) insert(str, j, i);
        }
        printf("%d\n", res);
    }
    return 0;
}
