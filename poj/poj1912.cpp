#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define EPS 0.00000001

using namespace std;

struct Point
{
    double x,y;
}v[100005];
Point p1,p2,s[100005];
int n,p;

double cross(struct Point a,struct Point b,struct Point c)
{
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}
int cmp(const struct Point &a,const struct Point &b)
{
    if(fabs(cross(v[1],a,b)) < EPS)
            return a.x < b.x;
    if(cross(v[1],a,b) > 0)
        return 1;
    else return 0;
}
void c_h()
{
    int ty = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(v[i].y < v[ty].y || (v[i].y == v[ty].y && v[i].x < v[ty].x))
            ty = i;
    }
    struct Point temp;
    temp = v[1];
    v[1] = v[ty];
    v[ty] = temp;
    v[n + 1] = v[1];
    p = 0;
    sort(v + 2, v + 1 + n, cmp);
    s[++p] = v[1];
    for(int i = 2; i <= n + 1; ++i)
    {
        while(p > 1 && cross(s[p - 1],s[p],v[i]) < 0)
            p--;
        s[++p] = v[i];
    }
}

double dot_pos(Point p,Point a,Point b)
{
    double A,B,C;
    A = b.y - a.y;B = a.x - b.x;
    C = b.x * a.y - a.x * b.y;
    return A*p.x + B*p.y + C;
}

bool line_cross_poy(Point p1,Point p2)
{
    if (p == 2)
        return  dot_pos(s[1],p1,p2)*dot_pos(s[2],p1,p2) >= 0;
    int det = p/3 + 1;
    double da,db,dc;
    int i,j,k;i = 1;j = det - 1;k = det + 1;
    if(j < 1)   j+=p;
    if(k > p)   k-=p;
    while(det >= 1)
    {
        da = dot_pos(s[i],p1,p2);
        db = dot_pos(s[j],p1,p2);
        dc = dot_pos(s[k],p1,p2);
        if (da*db < 0 || da*dc < 0 || dc*db < 0)
            return true;
        if (det == 1)   break;
        if (det % 2)    det++;
        det = det/2;
        if (fabs(da) < fabs(db))
        {
            if (fabs(da) < fabs(dc))
            {//a最近
                j = i - det;k = i + det;
                if(j < 1)   j+=p;
                if(k > p)   k-=p;
            }else
            {//c最近
                i = k - det;j = k + det;
                if(i < 1)   i+=p;
                if(j > p)   j-=p;
            }
        }else
        {
            if (fabs(db) < fabs(dc))
            {//b最近
                i = j - det;k = j + det;
                if(i < 1)   i+=p;
                if(k > p)   k-=p;
            }else
            {//c最近
                i = k - det;j = k + det;
                if(i < 1)   i+=p;
                if(j > p)   j-=p;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf",&v[i].x,&v[i].y);
    if (n >= 3)
    {c_h();p--;}
    while(scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y) != EOF)
    {
        if (p <= 1 || !line_cross_poy(p1,p2))
            printf("GOOD\n");
        else printf("BAD\n");
    }
    return 0;
}
