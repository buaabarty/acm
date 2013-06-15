#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 100000 + 9;
const LL inf = 1000000000;

char a[N], c[N];
LL dat[N];
LL b, d, lena, lenc, n, m;

bool okay(LL x){
    return b >= (d*x)/m*n+dat[(d*x)%m];
}

bool legal() {
    lena = strlen(a);
    lenc = strlen(c);
    for (LL i = 0; i < lenc; ++i) {
        bool find = false;
        for (LL j = 0; j < lena; ++j)
            if (a[j] == c[i]) {
                find = true;
                break;
            }
        if (!find) {
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%I64d%I64d", &b, &d);
    scanf("%s%s", a, c);
    if (!legal()) {
        puts("0");
        return 0;
    }
    LL i = 0, j = 0, cnta = 1, cntc = 0;
    do {
        if (j == lenc) {
            dat[++cntc] = cnta;
            j = 0;
            if (cntc == N-1){
                n = cnta, m = cntc;
                break;
            }
        }
        if (i == lena){
            i = 0, ++cnta;
        }
        if (a[i] == c[j]) ++j;
        ++i;
    } while (1);
    LL l = 0, r = inf;
    while (l < r){
        if (l + 1 == r) {
            if (okay(r)) l = r;
            break;
        }
        LL mid = (l + r + 1) >> 1;
        if (okay(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%I64d\n", l);
    return 0;
}

