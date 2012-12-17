#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define N 256
using namespace std;
struct node
{
    int x, y;
    node(int _x, int _y){ x = _x, y = _y; }
    node(){}
    bool notsame(node a)
    {
        return (x != a.x) || (y != a.y);
    }
}res[N][N];
int dat[N][N], state[N][N], d[N][N], n, step[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
queue<node> q;
int main()
{
    while (~scanf("%d", &n))
    {
        queue<node> q;
        memset(state, -1, sizeof(state));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &dat[i][j]);
                if (dat[i][j]) { res[i][j] = node(i, j); q.push(node(i, j)); state[i][j] = -1; d[i][j] = 0; }
                else { state[i][j] = 0; d[i][j] = n * n * 2; }
            }
        while (!q.empty())
        {
            node now = q.front(); q.pop();
            //printf("%d %d:%d\n", now.x, now.y, dat[now.x][now.y]);
            for (int k = 0; k < 4; ++k)
            {
                int dx = now.x + step[k][0];
                int dy = now.y + step[k][1];
                if (state[dx][dy] >= 0)
                {
                    if (d[now.x][now.y] + 1 < d[dx][dy])
                    {
                        d[dx][dy] = d[now.x][now.y] + 1;
                        q.push(node(dx, dy));
                        res[dx][dy] = res[now.x][now.y];
                        state[dx][dy] = 1;
                    }
                    else if (d[now.x][now.y] + 1 == d[dx][dy])
                    {
                        if (res[now.x][now.y].notsame(res[dx][dy])) state[dx][dy]++;
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (state[i][j] >= 2) printf("0");
                else printf("%d", dat[res[i][j].x][res[i][j].y]);
                if (j < n) printf(" ");
                else printf("\n");
            }
    }
    return 0;
}
