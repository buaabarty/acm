#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MAXL 32
#define MAXN 600010
using namespace std;
int p[MAXN][26], d[MAXN];
class Trie{
public:
    int size, cnt;
    Trie(){
        size = 1;
        cnt = 0;
        memset(p, 0, sizeof(p));
        memset(d, 0, sizeof(d));
    }
    int insert(char str[])
    {
        int j = 1;
        for (int i = 0; str[i] != '\0'; ++i)
            if (p[j][str[i] - 'a']) j = p[j][str[i] - 'a'];
            else{
                p[j][str[i] - 'a'] = ++size;
                j = size;
            }
        if (!d[j]) d[j] = ++cnt;
        return d[j];
    }
}T;
char s1[MAXL], s2[MAXL];
int cnt, fa[MAXN], ds[MAXN];
int myabs(int x)
{
    return (x > 0) ? x : -x;
}
int data(char s[])
{
    return T.insert(s);
}
int father(int v)
{
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
int main()
{
    T = Trie();
    memset(ds, 0, sizeof(ds));
    for (int i = 1; i <= 600000; ++i) fa[i] = i;
    while (scanf("%s%s", s1, s2) != EOF)
    {
        int x = data(s1), y = data(s2), fx, fy;
        //printf("%d %d\n", x, y);
        ds[x]++, ds[y]++;
        fx = father(x), fy = father(y);
        //printf("%d %d\n", fx, fy);
        if (fx != fy) fa[fx] = fy;
    }

    cnt = T.cnt;
    int s1 = 0, s2 = 0;
    bool flag = true;
    for (int i = 1; i <= cnt; ++i)
        if (father(i) != father(1))
        {
            flag = false;
            break;
        }
    if (!flag) printf("Impossible\n");
    else{
        for (int i = 1; i <= cnt; ++i)
            if (ds[i] % 2) s1++;
        if ((s1 == 0) || (s1 == 2)) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
