#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXM 1024
#define MAXN 32
using namespace std;
struct edge{
    int v, next;
}e[MAXM];
int p[MAXN], eid, rd[MAXN];
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
string str;
int dat[5][5], n = 9;
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
    memset(rd, 0, sizeof(rd));
    memset(p, -1, sizeof(p));
    eid = 0;
    cin >> str;
    if (str == "ENDOFINPUT") return false;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            scanf("%d", &dat[i][j]);
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            for (int x = i; x <= i + 1; ++x)
                for (int y = j; y <= j + 1; ++y)
                    if (dat[x][y] != (i - 1) * 3 + j)
                    {
                        insert(dat[x][y], (i - 1) * 3 + j);
                        ++rd[(i - 1) * 3 + j];
                    }
    cin >> str;
    //print_map();
    return true;
}
bool vst[MAXN];
bool topsort()
{
    int cnt = 0;
    memset(vst, false, sizeof(vst));
    for (int t = 1; t <= n; ++t)
    {
        for (int i = 1; i <= n; ++i)
            if (!vst[i] && !rd[i]){
                vst[i] = true;
                for (int j = p[i]; j != -1; j = e[j].next)
                    --rd[e[j].v];
                ++cnt;
                break;
            }
    }
    return (cnt == n);
}
int main()
{
    while (init())
    {
        if (topsort()) printf("THESE WINDOWS ARE CLEAN\n");
        else printf("THESE WINDOWS ARE BROKEN\n");
    }

    return 0;
}
