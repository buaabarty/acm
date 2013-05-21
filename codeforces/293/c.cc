#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;

LL num[100000], len;
LL n;

int main() {
    scanf("%I64d", &n);
    LL lim = (LL)(sqrt(n)+1e-10);
    for (LL i = 2; i <= lim; ++i)
        if (!(n % i)) num[++len] = i;
    num[++len] = n;
    lim = (LL)(pow(n, 1.0/3.0)+1e-10);
    LL cnt = 0;
    for (LL a = 1; a <= lim; ++a)
        for (LL x = 1; x < len; ++x) {
            //puts("");
            //printf("A=%I64d,", a);
            LL bc1 = num[x];
            //printf("BC1=%I64d,", bc1);
            LL t = n / bc1;
            LL bc2 = t-3*a*a-3*a*bc1;
            if (bc2%3) continue;
            bc2 /= 3;
            if (4*bc2>bc1*bc1) continue;
            //printf("BC2=%I64d,", bc2);
            LL B = -bc1;
            LL C = bc2;
            LL delta = B*B-4*C;
            if (delta < 0) continue;
            LL q = (LL)(pow(delta, 0.5)+1e-10);
            if (q*q!=delta) continue;
            LL up1 = -B+q;
            if (up1 <= 0) continue;
            if (up1&1) continue;
            LL up2 = -B-q;
            if (up2 <= 0) continue;
            if (up2&1) continue;
            printf("\nLALALA %I64d %I64d %I64d\n\n", a, up1/2, up2/2);
            if (up1 != up2) ++cnt;
            ++cnt;
        }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
