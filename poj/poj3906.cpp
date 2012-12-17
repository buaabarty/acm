#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 131072
#define MAXM 131072*2
using namespace std;

//数据结构
typedef struct{
    int s, v, next, opp;
    bool used;
}EDGE;
EDGE e[MAXM];//边表
int n, m, eid, res;//eid表示边表的容量, n-res为最终结果
int  p[MAXN];//边表的链接数组
bool resb[MAXN];//存某个点是否能在一个奇圈
int mem[MAXN];//判断二分图时标记节点的颜色
bool mark[MAXN];//标记在点双连通分量中的出现情况
int dfn[MAXN], low[MAXN], stack[MAXM];//tarjan算法的基本数据结构
int dindex = 0, top;//dindex表示tarjan算法中的标号，top表示栈容量

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
    int a = eid, b = eid + 1;
    e[eid].s = x;
    e[eid].v = y;
    e[eid].opp = b;
    e[eid].next = p[x];
    p[x] = eid++;
    e[eid].s = y;
    e[eid].v = x;
    e[eid].opp = a;
    e[eid].next = p[y];
    p[y] = eid++;
}
void printmap()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("(%d,%d) ", e[j].v, e[e[j].opp].v);
        printf("\n");
    }
}

//输入数据，取补图
bool init()
{
    memset(p, -1, sizeof(p));
    eid = 0;
    scanf("%d%d", &n, &m);
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        insert2(x, y);
    }
//    printmap();
    return true;
}

//判断图是否为二分图，只搜mark标记的节点
bool bigraph(int v, int now)
{
    mem[v] = now;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (mark[e[i].v])
        {
            int u = e[i].v;
            if (mem[u] == mem[v]) return false;
            if ((mem[u] == -1) && !bigraph(u, 1 - now)) return false;
        }
    return true;
}

//对找到的点双连通分量进行判断，如果不是二分图则分量中所有点都可以出现在奇圈中。
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
    memset(mem, -1, sizeof(mem));
    if (!bigraph(node, 0))
    {
        //如果不是二分图，则把所有点都标记
        for (int i = 1; i <= n; ++i)
            resb[i] |= mark[i];
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
        if (e[i].used) continue;
        e[i].used = true;
        e[e[i].opp].used = true;
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
    for (int i = 0; i < eid; ++i)
        e[i].used = false;
    memset(dfn, 0, sizeof(dfn));
    memset(stack, 0, sizeof(stack));
    memset(resb, false, sizeof(resb));
    top = 0;
    dindex = 0;
    for (int i = 1;i <= n; ++i)
        if (!dfn[i]) tarjan(i);
    res = 0;
    for (int i = 1; i <= n; ++i)
        if (resb[i]) ++res;//resb标记是否在奇圈中出现过
}

//主函数
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        init();
        solve();
        printf("%d\n", res);
    }
    return 0;
}
