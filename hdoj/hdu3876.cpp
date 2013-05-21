#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define EPS 1e-8
using namespace std;
double a, b, c, r1, r2;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf%lf%lf", &a, &b, &c);
        if (b * b - 4.0 * a * c < -EPS) printf("NO\n");
        else if (fabs(b * b - 4.0 * a * c) < EPS)
        {
            r1 =  -b / (2.0 * a);
            if (fabs(r1) < EPS) printf("0.00\n");
            else printf("%.2f\n", r1);
        }
        else
        {
            double delta = sqrt(b * b - 4.0 * a * c);
            r1 = (-b - delta) / (2.0 * a);
            r2 = (-b + delta) / (2.0 * a);
            if (r1 > r2) swap(r1, r2);
            if (fabs(r1) < EPS) printf("0.00 ");
            else printf("%.2f ", r1);
            if (fabs(r2) < EPS) printf("0.00\n");
            else printf("%.2f\n", r2);
        }
    }
    return 0;
}
