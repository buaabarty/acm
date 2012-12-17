#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define PI acos(-1)
using namespace std;
double r(double x, double y)
{
    return x / (1 + (1 / sin(PI / y)));
}
int main()
{
    int t;
    double x, y;
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ++ca)
    {
        scanf("%lf%lf", &x, &y);
        if (ca > 1) printf("\n");
        printf("Scenario #%d:\n%.3f\n", ca, r(x, y));
    }
    return 0;
}
