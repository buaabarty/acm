/*
ID:ybojan2
LANG:C++
TASK:race3
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXM 256
#define MAXN 64
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
int p[MAXN], eid, n;
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void read_map()
{
    memset(p, -1, sizeof(p));
    eid = n = 0;
    int x;
    while (scanf("%d", &x))
    {
        if (x == -1) break;
        ++n;
        while (x != -2)
        {

            insert(n, x + 1);
            scanf("%d", &x);
        }
    }
}
bool vst[MAXN], sav[MAXN];
void dfs(int v, int inv)
{
    vst[v] = true;
    for (int i = p[v]; i != -1; i = e[i].next)
        if ((!vst[e[i].v]) && (e[i].v != inv)) dfs(e[i].v, inv);
}
bool okay1(int k)
{
    memset(vst, false, sizeof(vst));
    dfs(1, k);
    return !vst[n];
}
bool okay2(int k)
{
    memset(vst, false, sizeof(vst));
    dfs(1, k);
    memcpy(sav, vst, sizeof(vst));
    memset(vst, false, sizeof(vst));
    dfs(k, -1);
    for (int i = 1; i <= n; ++i)
        if (vst[i] && sav[i]) return false;
    return true;
}
int main()
{
    int al, bl, resa[MAXN], resb[MAXN];
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);
    read_map();
    al = bl = 0;
    for (int i = 2; i < n; ++i)
        if (okay1(i))
        {
            resa[++al] = i - 1;
            if (okay2(i)) resb[++bl] = i - 1;
        }
    printf("%d", al);
    for (int i = 1; i <= al; ++i)
        printf(" %d", resa[i]);
    printf("\n");
    printf("%d", bl);
    for (int i = 1; i <= bl; ++i)
        printf(" %d", resb[i]);
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
