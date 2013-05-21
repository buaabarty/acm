#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int x, int y) {
    return (x) ? gcd(y % x, x) : y;
}
bool isprime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}
int main() {
    for (int i = 1; i <= 1000; ++i)
    {
        printf("%d:\t", i);
        int sum = 0;
        for (int x = 1; x <= i; ++x)
            for (int y = 1; y <= i; ++y)
                if (isprime(gcd(x, y))) sum++;
        printf("%d\n", sum);
    }
    return 0;
}
