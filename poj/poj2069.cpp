#include <cstdio>
#include <climits>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#define sqr(x) ((x)*(x))
using namespace std;
const int N = 110, nt = 1, L = 30;
const double inf = 1e100;
const double eps = 1e-10;
int n;
double delta, maxv, minv;
struct vpoint{
    double x, y, z, d;
    int id;
}vp[N], test[N];
double dis(vpoint a, vpoint b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z) + eps);
}
void calc(vpoint &p) {
    p.d = 0;
    for (int i = 0; i < n; ++i) {
        double t = dis(p, vp[i]);
        if (p.d < t) {
            p.d = t;
            p.id = i;
        }
    }
}
void updata(int id) {
    double d = test[id].d;
    test[id].x += (vp[test[id].id].x - test[id].x) / d * delta;
    test[id].y += (vp[test[id].id].y - test[id].y) / d * delta;
    test[id].z += (vp[test[id].id].z - test[id].z) / d * delta;
    calc(test[id]);
}
void solve() {
    maxv = -inf; minv = inf;
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf%lf", &vp[i].x, &vp[i].y, &vp[i].z);
        maxv = max(maxv, vp[i].x);
        maxv = max(maxv, vp[i].y);
        minv = min(minv, vp[i].x);
        minv = min(minv, vp[i].y);
    }
    for (int i = 0; i < nt; ++i) {
        test[i].x = minv + (rand() % (int(maxv - minv + 1) * 1000)) / 1000.0;
        test[i].y = minv + (rand() % (int(maxv - minv + 1) * 1000)) / 1000.0;
        test[i].z = minv + (rand() % (int(maxv - minv + 1) * 1000)) / 1000.0;
        calc(test[i]);
    }
    double r = 0.98;
    for (delta = 30000; delta > eps; delta *= r) {
        for (int i = 0; i < nt; ++i)
            for (int j = 0; j < L; ++j)
                updata(i);
    }
    double res = inf;
    int x = 0;
    for (int i = 0; i < nt; ++i)
        if (test[i].d < res)
        {
            res = test[i].d;
            x = i;
        }
    printf("%.10f\n", test[x].d);
}
int main() {
    while (scanf("%d", &n), n) {
        solve();
    }
    return 0;
}
