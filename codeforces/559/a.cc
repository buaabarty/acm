#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int a, b, c, d, e, f;
int cnt(int x) {
    return (x + 1) * x / 2 + (x - 1) * x / 2;
}
int main() {
    cin >> a >> b >> c >> d >> e >> f;
    int s = a + b + c;
    cout << cnt(s) - cnt(a) - cnt(c) - cnt(e) << endl;
    return 0;
}
