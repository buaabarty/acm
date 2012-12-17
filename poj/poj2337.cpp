#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define MAXN 32
#define MAXM 1024
#define MAXL 32
#define MAXS 4096
using namespace std;
struct edge{
    int k, v, next;
    bool use;
}e[MAXM];
int p[MAXN], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y, int k)
{
    e[eid].v = y;
    e[eid].k = k;
    e[eid].next = p[x];
    e[eid].use = false;
    p[x] = eid++;
}
int n, m, rd[MAXN], cd[MAXN];
string dat[MAXM];
char str[MAXL];
int s[MAXS], top, top2, res[MAXS], rl, s2[MAXS];
int fa[MAXN];
int father(int v)
{
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
bool init()
{
    memset(rd, 0, sizeof(rd));
    memset(cd, 0, sizeof(cd));
    mapinit();
    n = 26;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s", str);
        dat[i] = string(str);
    }
    sort(dat + 1, dat + m + 1);
    for (int i = m; i >= 1; --i)
    {
        int x = dat[i][0] - 'a' + 1, y = dat[i][dat[i].length() - 1] - 'a' + 1;
        insert(x, y, i);
        cd[x]++, rd[y]++;
        int fx = father(x), fy = father(y);
        if (fx != fy) fa[fx] = fy;
    }
    memset(s, 0, sizeof(s));
    memset(s2, 0, sizeof(s2));
    memset(res, 0, sizeof(res));
    rl = top = top2 = 0;
}
void dfs(int x, int lastp)
{
    s[++top] = x;
    if (lastp != -1) s2[top] = lastp;
    int temp = top;
    for (int i = p[x]; i != -1; i = e[i].next)
    if (!e[i].use)
        {
            e[i].use = true;
            dfs(e[i].v, e[i].k);
            break;
        }
}
void Fleury(int x)
{
    int b;
    top = 0;
    s[++top] = x;
    while (top)
    {
        b = 0;
        for (int i = p[s[top]]; i != -1; i = e[i].next)
            if (!e[i].use){
                b = 1; break;
            }
        if (!b) res[++rl] = s2[top--];
        else dfs(s[top--], -1);
    }
    while (top2) res[++rl] = s2[top--];
}
int judge()
{
    bool flag = true;
    int k = 0;
    for (int i = 1; i <= n; ++i)
        if (rd[i] || cd[i]){
            k = i; break;
        }
    for (int i = 1; i <= n; ++i)
        if ((rd[i] || cd[i]) && (father(i) != father(k))) flag = false;
    if (!flag) return 0;
    int cnt = 0, f1 = 0, f2 = 0;
    for (int i = n; i >= 1; --i)
        if (rd[i] != cd[i])
        {
            cnt++;
            if (rd[i] == cd[i] + 1) f1 = i;
            if (rd[i] == cd[i] - 1) f2 = i;
        }
    if (cnt == 0){
        for (int i = 1; i <= n; ++i)
            if (rd[i] || cd[i]) return i;
        return 1;
    }
    else if ((cnt == 2) && f1 && f2) return f2;
    else return 0;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        init();
        int s = judge();
        if (!s) printf("***\n");
        else
        {
            Fleury(s);
            bool first = true;
            for (int i = rl - 1; i >= 1; --i)
            {
                if (!first) cout << ".";
                first = false;
                cout << dat[res[i]];
            }
            cout << endl;
        }
    }
    return 0;
}
