#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL f(LL a, LL xa, LL b, LL xb, LL c, LL xc) {
    return xc*c+xc*c*(c-1)+xb*b+xb*b*(b+c+c-1)+xa*a+xa*a*(a+b+c+b+c-1);
}

int main() {
    LL T, a, b, c;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c;
        cout << f(c, 50, b, 100, a, 300) << " " << f(a, 300, b, 100, c, 50) << endl;
    }
    return 0;
}
