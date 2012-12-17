#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define eps 1e-8
#define pi acos(-1)
using namespace std;
struct point{
    double x, y;
};
double C2_area(point p1, double r1, point p2, double r2)//计算两圆相交面积{可做模板}
{
    double ans = 0;
    double d = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    if (r1 < r2) swap(r1, r2);
    if (d >= r1 + r2) return 0;
    if (d <= r1 - r2) return pi * r2 * r2;
    double angle1 = acos((r1 * r1 + d * d - r2 * r2) / 2.0 / r1 / d);
    double angle2 = acos((r2 * r2 + d * d - r1 * r1) / 2.0 / r2 / d);
    ans -= d * r1 * sin(angle1);
    ans += angle1 * r1 * r1 + angle2 * r2*r2;
    return ans;
}

int main()
{
    point a, b;
    double ra, rb;
    while (scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &ra, &b.x, &b.y, &rb) != EOF)
    {
        printf("%.3f\n", C2_area(a, ra, b, rb));
    }
    return 0;
}
