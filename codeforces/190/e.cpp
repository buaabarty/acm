#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge
{
    int v, next;
}e[1000010];
int p[400040], eid;
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
void insert2(int x, int y)
{
    insert(x, y);
    insert(y, x);
}
int main()
{
    return 0;
}
