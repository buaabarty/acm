#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100010
using namespace std;
struct edge
{
    int v, next;
}e[2000010];
int p[N], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
int top;
bool vst[N];
int n, m, dindex;
int dfn[N], low[N];
int main()
{
    return 0;
}
