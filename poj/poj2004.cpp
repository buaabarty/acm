#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10010
#define M 1000000
#define L 32
using namespace std;
int p[M][26], cnt, dd[M], f[N], last[N], res[N], resl;
char str[N][L];
struct node
{
    char s[L];
    int pos;
    node (char *_s, int _pos)
    {
        strcpy(s, _s);
        //puts(s);
        pos = _pos;
        int templ = strlen(s);
        for (int i = 0; i < templ; ++i)
            for (int j = i + 1; j < templ; ++j)
                if (s[i] > s[j]) swap(s[i], s[j]);
        //puts(s);
    }
    node(){}
}d[N];
bool cmp(node a, node b)
{
    return (int)strlen(a.s) < (int)strlen(b.s);
}
void Trie_Init()
{
    memset(p, 0, sizeof(p));
    memset(dd, 0, sizeof(dd));
    memset(f, 0, sizeof(f));
    cnt = 0;
}
void insert(char *s, int idx)
{
    int i = 0, j = 0;
    for (; s[j]; ++j)
    {
        if (!p[i][s[j] - 'a']) p[i][s[j] - 'a'] = ++cnt;
        i = p[i][s[j] - 'a'];
    }
    dd[i] = idx;
}
int find(char *s)
{
    int i = 0, j = 0;
    for (; s[j]; ++j)
        if (!p[i][s[j] - 'a']) return 0;
        else i = p[i][s[j] - 'a'];
    return dd[i];
}
int n = 0;
int main()
{
    while (~scanf("%s", str[n + 1])) ++n;
    for (int i = 1; i <= n; ++i)
        d[i] = node(str[i], i);
    sort(d + 1, d + n + 1, cmp);
    Trie_Init();
    //for (int i = 1; i <= n; ++i) puts(d[i].s);
    for (int i = 1; i <= n; ++i)
    {
        char temp[L];
        int len = strlen(d[i].s);
        for (int j = 0; j < len; ++j)
        {
            int l = 0;
            for (int k = 0; k < len; ++k)
                if (j != k) temp[l++] = d[i].s[k];
            temp[l] = '\0';
            //printf("%s ", temp);
            int x = find(temp);
            if ((x > 0) && (f[x] > f[i]))
            {
                f[i] = f[x];
                last[i] = x;
            }
        }
        if (!f[i]) last[i] = i;
        f[i]++;
        insert(d[i].s, i);
        //puts(d[i].s);
    }
    int maxl = 0, maxt;
    for (int i = 1; i <= n; ++i)
        if (f[i] > maxl)
        {
            maxl = f[i];
            maxt = i;
        }
    resl = 0;
    memset(res, 0, sizeof(res));
    res[++resl] = maxt;
    if (maxl > 1)
    {
        do
        {
            maxt = last[maxt];
            res[++resl] = maxt;
        }while (last[maxt] != maxt);
    }
    for (int i = resl; i >= 1; --i)
        puts(str[d[res[i]].pos]);
    return 0;
}
