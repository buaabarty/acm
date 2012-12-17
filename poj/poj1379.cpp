#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define EPS 1e-4
#define N 1024
using namespace std;
struct Point
{
    double x, y;
    Point(double _x, double _y)
    {
        x = _x, y = _y;
    }
    Point(){}
    double toPoint(Point a)
    {
        return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
    }
}p[N];
int n;
double cost(Point v)
{
    double res = 1e20;
    for (int i = 1; i <= n; ++i)
        res = min(res, v.toPoint(p[i]));
    return res;
}

double delta, nows, temps;
Point a, b;
double step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool change;
int main()
{
    int T;
    double X, Y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf%lf%d", &X, &Y, &n);
        for (int i = 1; i <= n; ++i)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        a = Point(X / 2, Y / 2), delta = sqrt(X * X + Y * Y);
        nows = cost(a);
        while (delta > EPS)
        {
            do
            {
                change = false;
                Point ta = a;
                double ts = nows;
                for (int k = 0; k < 4; ++k)
                {
                    b = Point(a.x + step[k][0] * delta, a.y + step[k][1] * delta);
                    if ((b.x < 0) || (b.x > X) || (b.y < 0) || (b.y > Y)) continue;
                    temps = cost(b);
                    if (temps > ts)
                    {
                        ta = b;
                        ts = temps;
                        change = true;
                        //break;
                    }
                }
                a = ta;
                nows = ts;
            }while (change);
            delta *= 0.9;
        }
        printf("The safest point is (%.1f, %.1f).\n", (round(a.x * 10.0) / 10.0), (round(a.y * 10.0) / 10.0));
    }
    return 0;
}
