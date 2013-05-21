#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int temp[1000010];
void gao(int num[], int n, int k) {
    int now = 0;
    for (int i = 1; i <= n / k; ++i) {
        for (int j = (i-1)*k + 2; j <= (i-1)*k+k; ++j)
            temp[++now] = num[j];
        temp[++now] = num[(i-1)*k+1];
    }
    if (n/k*k<n) {
        for (int i = n/k*k+2; i <= n; ++i)
            temp[++now] = num[i];
        temp[++now] = num[n/k*k+1];
    }
    for (int i = 1; i <= n; ++i)
        num[i] = temp[i];
}
int num[1000010];
int main() {
    //freopen("ans.txt", "w", stdout);
    for (int n = 2; n <= 100; ++n) {
        for (int i = 1; i <= n; ++i)
            num[i] = i;
        for (int i = 2; i <= n; ++i)
            gao(num, n, i);
        printf("%d\t", n);
        for (int i = 1; i <= n; ++i)
            if (num[i] == 8) printf("%d\n", i);
        //for (int i = 1; i <= n; ++i)
        //    printf("%3d%c",  num[i], " \n"[i==n]);
    }
    return 0;
}
