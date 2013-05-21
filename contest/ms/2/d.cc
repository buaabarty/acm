#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
double l1, l2, l3, l4, l5;
int T;
int main() {
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%lf%lf%lf%lf%lf", &l1, &l2, &l3, &l4, &l5);
        if (l1 < l2) swap(l1, l2);
        double a = l1, b = l2, c = l5;
        double h = acos((c*c+a*a-b*b)/(2*a*c));
        double d = sqrt(cos(h)*2*(a-b)*c - c*c - (a-b)*(a-b));
        double p = (b+b+d)/2.0;
        double s = sqrt(p*(p-b)*(p-b)*(p-d));
        cout <<
    }
    return 0;
}
