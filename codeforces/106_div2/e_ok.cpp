#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
#define N 101
struct POINT
{
    double x, y, z;
    POINT(double _x, double _y, double _z)
    { x = _x, y = _y, z = _z; }
    POINT(){}
}ar[N];
int n;
POINT getpoint()
{
    POINT t = POINT(0, 0, 0);
    for (int i = 0; i < n; i++)
    {
        t.x += ar[i].x; t.y += ar[i].y; t.z += ar[i].z;
    }
    t.x /= n; t.y /= n; t.z /= n;
    return t;
}

double getdistance(POINT p,POINT t)
{
    return (t.x - p.x) * (t.x - p.x) + (t.y - p.y) * (t.y - p.y) + (t.z - p.z) * (t.z - p.z);
}

int cal(POINT p)
{
    int id;
    double dis = -1, len;
    for (int i = 0;i < n; i++){
        len = getdistance(p, ar[i]);
        if(dis < len){
            dis = len;
            id = i;
        }
    }
    return id;
}

POINT MinBall()//×îÐ¡¸²¸ÇÇò
{
    POINT p = POINT(0, 0, 0);
    for (int i = 0; i < n; i++)
    {
        p.x += ar[i].x; p.y += ar[i].y; p.z += ar[i].z;
    }
    p.x /= n; p.y /= n; p.z /= n;
    int id;
    double delta = 0.5;
    while(delta > eps)
    {
        for(int i = 0; i < 200; i++)
        {
            id = cal(p);
            p.x += (ar[id].x - p.x) * delta;
            p.y += (ar[id].y - p.y) * delta;
            p.z += (ar[id].z - p.z) * delta;
        }
        delta /= 2;
    }
    return p;
}

int main()
{
    while(~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
            scanf("%lf%lf%lf", &ar[i].x, &ar[i].y, &ar[i].z);
        POINT p = MinBall();
        printf("%.10lf %.10lf %.10lf\n", p.x, p.y, p.z);
    }
    return 0;
}
