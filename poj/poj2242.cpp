#include <iostream>
#include <cstdio>
#include <cmath>
#define PI acos(-1)
using namespace std;
double sqr(double x)
{
    return x * x;
}
int main()
{
    double ax, ay, bx, by, cx, cy, a, b, c, s, p, d;
    while (~scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy))
    {
        a = sqrt(sqr(ax - bx) + sqr(ay - by));
        b = sqrt(sqr(bx - cx) + sqr(by - cy));
        c = sqrt(sqr(cx - ax) + sqr(cy - ay));
        p = (a + b + c) / 2.0;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        d = a * b * c / s;
        printf("%.2f\n", d * PI / 2.0);
    }
    return 0;
}
