#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
priority_queue<double> pq;
int n;
double d[101];
int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            double x;
            scanf("%lf", &x);
            pq.push(x);
        }
        for (int i = 1; i < n; ++i) {
            double x = pq.top();
            pq.pop();
            double y = pq.top();
            pq.pop();
            double ans = 2 * sqrt(x * y);
            pq.push(ans);
        }
        printf("%.3f\n", pq.top());
        pq.pop();
    }
    return 0;
}
