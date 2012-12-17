#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge
{
    int v, next;
}e[1000010], e_back[1000010];
int p[1010], eid, p_back[1010], eid_back;
bool map[1010][1010];
void mapinit()
{
    memset(p, -1, sizeof(p));
    memset(p_back, -1, sizeof(p_back));
    eid = 0;
    eid_back = 0;
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert_back(int x, int y)
{
    e_back[eid_back].v = y;
    e_back[eid_back].next = p_back[x];
    p_back[x] = eid_back++;
}
int n, m;
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        mapinit();
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= m; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            insert(x, y);
            insert_back(y, x);
            map[x][y] = 1;
        }

        for (int k = 1; k <= n; ++k)
            for (int i = p[k]; i != -1; i = e[i].next)
                for (int j = p_back[k]; j != -1; j = e_back[j].next)
                {
                    int x = e[i].v;
                    int y = e_back[j].v;
                    if (!map[y][x])
                    {
                        insert(y, x);
                        insert_back(x, y);
                        map[y][x] = 1;
                    }
                }
        int sum = (n * (n - 1)) >> 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                sum -= map[i][j];
        printf("%d\n", sum);

    }
    return 0;
}
