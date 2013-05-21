#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[3000010], n, *s;
int main() {
    scanf("%d", &n);
    s = a;
    for(int i = 0; i < n; ++i)
        s[i] = i+1;
    for (int i = 2; i <= n; ++i, ++s)
        for (int j = (n-1)/i*i; j >= 0; j -= i) {
            int x = j+i;
            if (x >= n) x = n;
            s[x] = s[j];
        }
    for (int i = 0; i < n; ++i)
        printf("%d%c", s[i], " \n"[i==n-1]);
    return 0;
}
