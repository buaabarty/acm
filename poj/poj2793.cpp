#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1024
#define MAXM 1024*1024
using namespace std;

//数据结构
typedef struct{
    int s, v, next;
}EDGE;
EDGE e[MAXM];//边表
int n, m, eid;//eid表示边表的容量, n-res为最终结果
int  p[MAXN];//边表的链接数组
int resn[MAXN];//存某个点是否能在一个奇圈
bool mark[MAXN];//标记在点双连通分量中的出现情况
int dfn[MAXN], low[MAXN], stack[MAXM];//tarjan算法的基本数据结构
int dindex = 0, top;//dindex表示tarjan算法中的标号，top表示栈容量
int rescnt = 1;
bool used[MAXN][MAXN];

//边表的基本操作
void insert(int x, int y)
{
    e[eid].s = x;
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y)
{
    insert(x, y);
    insert(y, x);
}
void printmap()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("%d ", e[j].v);
        printf("\n");
    }
}

//输入数据，取补图
bool init()
{
    memset(resn, 0, sizeof(resn));
    rescnt = 1;
    memset(p, -1, sizeof(p));
    eid = 0;
    if (scanf("%d%d", &n, &m) == EOF) return false;
    int k, dat[1024];
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j)
        {
            scanf("%d", &dat[j]);
            if (j > 1) insert2(dat[j - 1], dat[j]);
        }
    }
    return true;
}

void color_solve(int node)
{
    //堆栈中所有边出栈，并标记所有边的顶点
    memset(mark, false, sizeof(mark));
    int k;
    do{
        k = stack[top];
        mark[e[k].v] = true;
        mark[e[k].s] = true;
        top--;
    }while (e[k].s != node);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (mark[i])
        {
            printf("%d  ", i);
            ++cnt;
        }
    printf("\n");
    if (cnt > 2)
    {
        rescnt *= (cnt + 1);
        for (int i = 1; i <= n; ++i)
            resn[i] += mark[i];
    }
}

//Tarjan算法求点双连通分量
void tarjan(int v)
{
    dfn[v] = low[v] = ++dindex;
    int u;
    for (int i = p[v]; i != -1; i = e[i].next)
    {
        u = e[i].v;
        if (used[v][u]) continue;
        used[u][v] = true;
        used[v][u] = true;
        stack[++top] = i;
        if (!dfn[u])
        {
            tarjan(u);
            low[v] = min(low[v], low[u]);
            if (dfn[v] <= low[u])
            {
                //此时即找到双连通分量，其余部分可用作模板
                color_solve(v);
            }
        }
        else low[v] = min(low[v], dfn[u]);
    }
}

//Tarjan算法的外围部分，以及对最终结果的统计
void solve()
{
    printmap();
    memset(used, false, sizeof(used));
    memset(dfn, 0, sizeof(dfn));
    memset(stack, 0, sizeof(stack));
    top = 0;
    dindex = 0;
    for (int i = 1;i <= n; ++i)
        if (!dfn[i]) tarjan(i);
}

//主函数
int main()
{
    while (init())
    {
        solve();
        bool flag = true;
        for (int i = 1; i <= n; ++i)
            printf("%d\n", resn[i]);
        for (int i = 1; i <= n; ++i)
            if (resn[i] > 1)
            {
                flag = false;
                break;
            }
        if (flag) printf("%d\n", rescnt);
        else printf("0\n");
    }
    return 0;
}

