#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double s, x, y, z, a, b, c;
    scanf("%lf%lf%lf%lf", &s, &a, &b, &c);
    if (fabs(a + b + c) < 1e-6)
    {
        printf("0 0 %.10lf\n", s);
        return 0;
    }
    x = s * a / (a + b + c);
    y = s * b / (a + b + c);
    z = s * c / (a + b + c);
    printf("%.10lf %.10lf %.10lf\n", x, y, z);
    return 0;
}
