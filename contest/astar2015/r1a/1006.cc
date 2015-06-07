#include <cstdio>
#include <cmath>
#include <algorithm>
 
#define P Point
using namespace std;
typedef double lf;
const int N = 50005;
const lf eps = 1e-8;
 
struct Point {
    lf x, y;
    P() {}
    P(lf _x, lf _y) : x(_x), y(_y) {}
     
    inline bool operator < (const P &X) const {
        return fabs(y - X.y) < eps ? x < X.x : y < X.y;
    }
    inline bool operator == (const P &X) const {
        return fabs(x - X.x) < eps && fabs(y - X.y) < eps;
    }
    inline bool operator != (const P &X) const {
        return !(*this == X);
    }
    inline P operator + (const P &X) const {
        return P(x + X.x, y + X.y);
    }
    inline P operator - (const P &X) const {
        return P(x - X.x, y - X.y);
    }
    inline P operator * (const lf &X) const {
        return P(x * X, y * X);
    }
    inline lf operator * (const P &X) const {
        return x * X.y - y * X.x;
    }
    inline lf operator / (const P &X) const {
        return x * X.x + y * X.y;
    }
    inline void read() {
        scanf("%lf%lf", &x, &y);
    }
}p[N], s[N], t[5];
 
int n, top;
lf ans = 1e60;
 
inline lf sqr(lf x) {
    return x * x;
}
 
inline lf dis(P a, P b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
 
inline bool cmp_p(P a, P b) {
    lf tmp = (a - p[1]) * (b - p[1]);
    return fabs(tmp) < eps ? dis(a, p[1]) - dis(b, p[1]) < eps : tmp > -eps;
}
 
void graham() {
    int i;
    for (i = 2; i <= n; ++i)
        if (p[i] < p[1]) swap(p[1], p[i]);
    sort(p + 2, p + n + 1, cmp_p);
    for (i = 2, s[top = 1] = p[1]; i <= n; ++i) {
        while (top > 1 && (s[top] - s[top - 1]) * (p[i] - s[top]) < eps) --top;
        s[++top] = p[i];
    }
    s[0] = s[top];
}
 
inline bool check_p(int i, int p) {
    return (s[i + 1] - s[i]) * (s[p + 1] - s[i]) - (s[i + 1] - s[i]) * (s[p] - s[i]) > -eps;
}
 
inline bool check_r(int i, int r) {
    return (s[i + 1] - s[i]) / (s[r + 1] - s[i]) - (s[i + 1] - s[i]) / (s[r] - s[i]) > -eps;
}
 
inline bool check_l(int i, int l) {
    return (s[i + 1] - s[i]) / (s[l + 1] - s[i]) - (s[i + 1] - s[i]) / (s[l] - s[i]) < eps;
}
 
void work() {
    int l, r, p, i;
    lf L, R, H, D, tmp;
    for (i = 0, l = r = p = 1; i < top; ++i) {
        D = dis(s[i], s[i + 1]);
        while (check_p(i, p)) (p += 1) %= top;
        while (check_r(i, r)) (r += 1) %= top;
        if (!i) l = r;
        while (check_l(i, l)) (l += 1) %= top;
        L = (s[i + 1] - s[i]) / (s[l] - s[i]) / D;
        R = (s[i + 1] - s[i]) / (s[r] - s[i]) / D;
        H = (s[i + 1] - s[i]) * (s[p] - s[i]) / D;
        if (H < 0) H = -H;
        tmp = (R - L) * H;
        if (tmp < ans) {
            ans = tmp;
            t[0] = s[i] + (s[i + 1] - s[i]) * (R / D);
            t[1] = t[0] + (s[r] - t[0]) * (H / dis(t[0], s[r]));
            t[2] = t[1] - (t[0] - s[i]) * ((R - L) / dis(s[i], t[0]));
            t[3] = t[2] - (t[1] - t[0]);
        }
    }
}
 
int main() {
    int i, st, T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        ans = 1e60;
        scanf("%d", &n);
        n *= 4;
        for (i = 1; i <= n; ++i)
            p[i].read();
        graham();
        work();
        for (i = 1, st = 0; i <= 3; ++i)
            if (t[i] < t[st]) st = i;
        printf("Case #%d:\n%d\n", ca, (int)(round(ans) + 1e-6));
    }
    return 0;
}
