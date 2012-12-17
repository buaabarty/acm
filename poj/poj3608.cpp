#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define PI acos(-1)
#define EPS 1e-8

using namespace std;

struct NODE
{
    double x,y;
}a[20005],b[20005],s[20005];
int n,m;
int pa,pb,top;
double ans;
double cnt;

double cross(struct NODE i,struct NODE j,struct NODE k)
{
    return (j.x - i.x)*(k.y - i.y) - (k.x - i.x)*(j.y - i.y);
}

int cmp1(const struct NODE &aa,const struct NODE &bb)
{
    if(cross(a[1],aa,bb) < 0)
        return 1;
    else if(fabs(cross(a[1],aa,bb)) < EPS)
            return aa.x < bb.x;
    else return 0;
}
int cmp2(const struct NODE &aa,const struct NODE &bb)
{
    if(cross(b[1],aa,bb) < 0)
        return 1;
    else if(fabs(cross(b[1],aa,bb)) < EPS)
            return aa.x < bb.x;
    else return 0;
}

void c_h(struct NODE *v,int nu,int &p)
{
    s[++p] = v[1];
    s[++p] = v[2];
    for(int i = 3; i <= nu; ++i)
    {
        while(p > 1 && cross(s[p - 1],s[p],v[i]) > 0)
            p--;
        s[++p] = v[i];
    }
    struct NODE temp;
    for (int i = 2; i <= p; ++i)
    {
        v[i] = s[i];
    }
}

double dis(struct NODE i,struct NODE j)
{
    return sqrt((i.x - j.x)*(i.x - j.x) + (i.y - j.y)*(i.y - j.y));
}

double distoline(struct NODE i,struct NODE j,struct NODE k)
{
    struct NODE t;
    t = k;
	t.x += i.y - j.y;
	t.y += j.x - i.x;
	if (cross(k,i,t) * cross(k,j,t) > EPS)
		return dis(k,i) < dis(k,j) ? dis(k,i) : dis(k,j);
	return fabs(cross(k,i,j))/dis(i,j);
}

int ang(struct NODE &t1,struct NODE &t2,int i,int j,int ii, int jj)
{
//cout<<a[i].x<<" "<<a[i].y<<"   "<<a[ii].x<<" "<<a[ii].y<<endl;
//cout<<b[j].x<<" "<<b[j].y<<"   "<<b[jj].x<<" "<<b[jj].y<<endl;
    double ta1,ta2,an1 ,an2;
    ta1 = atan2(t1.y,t1.x);
    if(ta1 < 0)
        ta1 = 2*PI + ta1;
    an1 = atan2(a[ii].y - a[i].y ,a[ii].x - a[i].x);
    ta2 = atan2(t2.y,t2.x);
    if(ta2 < 0)
        ta2 = 2*PI + ta2;
    if(an1 < 0)
        an1 = 2*PI + an1;
    an2 = atan2(b[jj].y - b[j].y ,b[jj].x - b[j].x);
    if(an2 < 0)
        an2 = 2*PI + an2;
//cout<<an1<<"___"<<an2<<endl;
    an1 = fabs(ta1 - an1);
    an2 = fabs(ta2 - an2);
    if(an1 > PI)
        an1 = 2*PI - an1;
    if(an2 > PI)
        an2 = 2*PI - an2;
    if(fabs(an1 - an2) <= EPS)
    {
        t2.x = b[jj].x - b[j].x;
        t2.y = b[jj].y - b[j].y;
        t1.x = -t2.x;t1.y = -t2.y;
        cnt += an1;
        return 0;
    }
    else if(an2 - an1 > EPS)
    {
        t1.x = a[ii].x - a[i].x;
        t1.y = a[ii].y - a[i].y;
        t2.x = -t1.x;t2.y = -t1.y;
        cnt += an1;
        return -1;
    }else
    {
        t2.x = b[jj].x - b[j].x;
        t2.y = b[jj].y - b[j].y;
        t1.x = -t2.x;t1.y = -t2.y;
        cnt += an2;
        return 1;
    }
}

int main()
{
    while(scanf("%d%d",&n,&m) && (m + n))
    {
        cnt = 0.0;
        int l,r;
        l = 1; r = 1;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lf%lf",&a[i].x,&a[i].y);
            if(a[i].y > a[l].y)
                l = i;
        }
        for (int i = 1; i <= m; ++i)
        {
            scanf("%lf%lf",&b[i].x,&b[i].y);
            if(b[i].y < b[r].y)
                r = i;
        }
        ans = dis(a[l],b[r]);
        struct NODE temp;
        temp = a[l];
        a[l] = a[1];
        a[1] = temp;
        temp = b[r];
        b[r] = b[1];
        b[1] = temp;
        sort(a + 2, a + n + 1, cmp1);
        sort(b + 2, b + m + 1, cmp2);
        a[n + 1] = a[1];
        b[m + 1] = b[1];
        pa = 0;pb = 0;
        c_h(a,n,pa);
        c_h(b,m,pb);

        int i = 1,j = 1,f;
        struct NODE t1,t2;
        int ii,jj;
        t1.x = 1;t1.y = 0;
        t2.x = -1;t2.y = 0;
        do
        {
            ii = i + 1;
            jj = j + 1;
            if(ii > pa) ii = 1;
            if(jj > pb) jj = 1;
            f = ang(t1,t2,i,j,ii,jj);

            if(f < 0)
            {
                ans = min(ans,distoline(a[i],a[ii],b[j]));
                ans = min(ans,dis(a[ii],b[j]));
                i = ii;
            }else if(f > 0)
            {
                ans = min(ans,distoline(b[j],b[jj],a[i]));
                ans = min(ans,dis(b[jj],a[i]));
                j = jj;
            }else if(f == 0)
            {
                ans = min(ans,dis(a[ii],b[jj]));
                ans = min(ans,dis(a[ii],b[j]));
                ans = min(ans,dis(a[i],b[jj]));
                ans = min(ans,distoline(b[j],b[jj],a[i]));
                i = ii;j = jj;
            }
    //cout<<ans<<endl;
        }while(cnt <= max(m,n)*PI);
        printf("%.5f\n",ans);
    }

    return 0;
}
