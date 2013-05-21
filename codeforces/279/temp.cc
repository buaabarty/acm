#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    double x = 16.25885103191273;
    for (int i = 2; i <= 100000; ++i)
        if (fabs((int)(x*i+1e-4)-x*i)<1e-4) {
            cout << i << endl;
            break;
        }
    return 0;
}
