#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXM 512
#define MAXN 32
#define MAXL 1024
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
int eid, p[MAXN], rd[MAXN], n;
char chr[MAXN];
int dat[256];
bool app[256];
bool first_case = true;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("%d ", e[j].v);
        printf("\n");
    }
}
bool init()
{
    memset(p, -1, sizeof(p));
    memset(rd, 0, sizeof(rd));
    memset(app, false, sizeof(app));
    eid = 0;
    char str[MAXL];
    if (gets(str) == NULL) return false;
    int len = strlen(str);
    int i = 0, cnt = 0;
    memset(chr, 0, sizeof(chr));
    while (i < len)
    {
        while (!isalpha(str[i]) && (i < len)) ++i;
        if (i >= len) break;
        app[str[i++]] = true;
    }
    for (char i = 'a'; i <= 'z'; ++i)
        if (app[i]){
            dat[i] = ++cnt;
            chr[cnt] = i;
        }
    gets(str);
    len = strlen(str);
    i = 0;
    int x, y;
    while (i < len)
    {
        while (!isalpha(str[i]) && (i < len)) ++i;
        if (i >= len) break;
        x = dat[str[i++]];
        while (!isalpha(str[i]) && (i < len)) ++i;
        if (i >= len) break;
        y = dat[str[i++]];
        insert(x, y);
        ++rd[y];
    }
    n = cnt;
//    print_map();
    return true;
}
bool vst[MAXN];
int res[MAXN];
void dfs(int deep)
{
    if (deep == n){
        for (int i = 1; i <= n; ++i)
            printf("%c", chr[res[i]]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (!rd[i] && !vst[i]){
            for (int j = p[i]; j != -1; j = e[j].next)
                --rd[e[j].v];
            res[deep + 1] = i;
            vst[i] = true;
            dfs(deep + 1);
            vst[i] = false;
            for (int j = p[i]; j != -1; j = e[j].next)
                ++rd[e[j].v];
        }
}
void topsort()
{
    memset(vst, false, sizeof(vst));
    dfs(0);
}
int main()
{
    while (init())
    {
        if (!first_case) printf("\n");
        topsort();
        first_case = false;
    }
    return 0;
}
