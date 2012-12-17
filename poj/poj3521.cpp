#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define EPS 0.00000001
#define N 256

using namespace std;

struct Point
{
    int x,y;
    bool operator == (const Point &a) const
    {
        return (x == a.x) && (y == a.y);
    }
}s,t;
struct Road
{
    Point a;
    Point b;
    int dir;//0断，1正向，-1反向，2双向
    bool mark;//是不是边
    int l,r;
    double len;
}r[N];
int n;

int cross(int x1,int y1,int x2,int y2)
{
    return x1*y2-x2*y1;
}
int ab_cross_ac(Point a,Point b,Point c) //ab与ac的叉积
{
    return cross(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int ab_dot_ac(Point a,Point b,Point c)
{
    return (b.x - a.x)*(c.x - a.x) + (b.y - a.y)*(c.y - a.y);
}
bool seg_cross(Point a,Point b,Point c,Point d)
{
   return (ab_cross_ac(a,c,d)*ab_cross_ac(b,c,d) <= 0 && ab_cross_ac(c,a,b)*ab_cross_ac(d,a,b) <= 0);
}

double dis(Point a,Point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (b.y - a.y)*(b.y - a.y));
}
void chg(int i ,int j)
{
    if(r[i].a == r[j].a)
    {
        r[i].l++;
        r[j].l++;
    }else if (r[i].b == r[j].a)
    {
        r[i].r++;
        r[j].l++;
    }else if (r[i].a == r[j].b)
    {
        r[i].l++;
        r[j].r++;
    }else if (r[i].b == r[j].b)
    {
        r[i].r++;
        r[j].r++;
    }else
    {
        if (!seg_cross(r[i].a,r[i].b,r[j].a,r[j].b))
            return ;
        if (ab_cross_ac(r[i].a,r[j].a,r[i].b) == 0)
        {
            r[j].l++;
        }else if (ab_cross_ac(r[i].a,r[j].b,r[i].b) == 0)
        {
            r[j].r++;
        }else if (ab_cross_ac(r[j].a,r[j].b,r[i].a) == 0)
        {
            r[i].l++;
        }else if (ab_cross_ac(r[j].a,r[j].b,r[i].b) == 0)
        {
            r[i].r++;
        }
    }
}

void chd(int i ,int j)
{
    if (!seg_cross(r[i].a,r[i].b,r[j].a,r[j].b))
            return ;
        if (ab_cross_ac(r[i].a,r[j].a,r[i].b) == 0)
        {
            int temp = ab_dot_ac(r[j].a,r[i].a,r[j].b);
            if (temp == 0)
                r[i].dir = 0;
            else if (temp > 0)
            {
                if (r[i].dir > 0)
                    r[i].dir = 1;
                else r[i].dir = 0;
            }else
            {
                if (r[i].dir == 1)
                    r[i].dir = 0;
                else r[i].dir = -1;
            }
        }else if (ab_cross_ac(r[i].a,r[j].b,r[i].b) == 0)
        {
            int temp = ab_dot_ac(r[j].b,r[i].a,r[j].a);
            if (temp == 0)
                r[i].dir = 0;
            else if (temp > 0)
            {
                if (r[i].dir > 0)
                    r[i].dir = 1;
                else r[i].dir = 0;
            }else
            {
                if (r[i].dir == 1)
                    r[i].dir = 0;
                else r[i].dir = -1;
            }
        }
}

Point d[N];
int cnt = 0;
struct edge
{
    int v, next;
    double d;
}e[N * N];
int p[N], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y, double d)
{
    e[eid].v = y;
    e[eid].d = d;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(int x, int y, double d)
{
    insert(x, y, d);
    insert(y, x, d);
}
double dist[N];
bool use[N];
int last[N];
void dijkstra(int v)
{
    for (int i = 1; i <= n; ++i)
        dist[i] = 1e20;
    dist[v] = 0;
    last[v] = 0;
    memset(use, false, sizeof(use));
    for (int i = 1; i <= n; ++i)
    {
        int x = -1;
        double y = 1e20;
        for (int j = 1; j <= n; ++j)
            if (!use[j] && (dist[j] < y))
            {
                y = dist[j];
                x = j;
            }
        if (x == -1) return;
        use[x] = true;
        for (int j = p[x]; j != -1; j = e[j].next)
            if (!use[e[j].v] && (e[j].d + y < dist[e[j].v]))
            {
                dist[e[j].v] = e[j].d + y;
                last[e[j].v] = x;
            }
    }
}
int gethash(Point a)
{
    for (int i = 1; i <= cnt; ++i)
        if (d[i] == a) return i;
    d[++cnt] = a;
    return cnt;
}
void print_map()
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d:", i);
        for (int j = p[i]; j != -1; j = e[j].next)
            printf("(%d,%.2f)   ", e[j].v, e[j].d);
        printf("\n");
    }
}
int main()
{
    while(scanf("%d",&n) && n != 0)
    {
        scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d%d",&r[i].a.x,&r[i].a.y,&r[i].b.x,&r[i].b.y);
            r[i].dir = 2;
            r[i].l = r[i].r = 0;
            r[i].mark = false;
            r[i].len = dis(r[i].a,r[i].b);
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                chg(i,j);
        for (int i = 1; i <= n; ++i)
            if(r[i].l && r[i].r)
            {
                r[i].mark = true;
            }
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (r[i].mark && !r[j].mark)
                    chd(i,j);
                else if (!r[i].mark && r[j].mark)
                    chd(j,i);
                cnt = 0;
        mapinit();
        for (int i = 1; i <= n; ++i)
        {
            if (r[i].dir == 0) continue;
            int x = gethash(r[i].a);
            int y = gethash(r[i].b);
            if (r[i].dir == 1) insert(x, y, r[i].len);
            else if (r[i].dir == -1) insert(y, x, r[i].len);
            else insert2(x, y, r[i].len);
        }

        int st = gethash(s);
        int ed = gethash(t);
        n = cnt;
        print_map();
        printf("SBSBSSBSBSB%d %d\n", st, ed);
        dijkstra(st);
        if (dist[ed] > 1e10) printf("-1\n");
        else printf("%.2f\n", d[ed]);
    }
    return 0;
}
