#include <iostream>
#include <cstdio>
#include <cmath>
#define pi acos(-1)
using namespace std;
int main()
{
    int t;
    double x, y;
    cin >> t;
    for (int ca = 1; ca <= t; ++ca)
    {
        cin >> x >> y;
        double r = sqrt(x * x + y * y);
        double s = pi * r * r / 2.0;
        printf("Property %d: This property will begin eroding in year %d.\n", ca, (int)(s / 50.0) + 1);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
