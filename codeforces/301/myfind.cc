#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int MaxSum(int *a, int n) {
    int s = 0, res = a[0];
    for (int i = 0; i < n; ++i) {
        if (s < 0) s = 0;
        s = (s + a[i]);
        if (s > res) res = s;
    }
    return res;
}
int main() {
    int num[10], n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    printf("%d\n", MaxSum(num, n));
    return 0;
}
