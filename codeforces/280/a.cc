#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    double w, h, a;
    cin >> w >> h >> a;

    if (a >= 90) a = 180 - a;
    a = a / 180.0 * acos(-1);
    cout << a << endl;
    cout << 2 * atan(w / h) << endl;
    if (a < 2 * atan(w / h)) {
        //if (w > h) swap(w, h);
        double l = (1+cos(a)-sin(a)*sin(a)/(1+cos(a)));
        cout << sin(a) << " " << cos(a) << endl;
        double r = (h-w*sin(a)/(1+cos(a)));
        cout << l << " " << r << endl;
        double y = fabs((h-w*sin(a)/(1+cos(a))) / (1+cos(a)- sin(a)*sin(a)/(1+cos(a))));
        double x = fabs((w-y*sin(a))/(1+cos(a)));
        cout << x << " " << y << endl;
        cout << x+x*cos(a)+y*sin(a) << endl;
        cout << x*sin(a)+y+y*cos(a) << endl;
        printf("%.10f\n", w*h - x*x*cos(a)*sin(a) - y*y*cos(a)*sin(a));
    } else {
        printf("%.10f\n", min(w, h) * min(w, h) * cos(a));
    }

    return 0;
}
