#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;
typedef long long LL;
const int N = 200000 + 7;
LL a[N], v[N], R;
int lis[N];
LL calc(int x){
    return -R * x + a[x];
}
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int n;
        scanf("%d%lld", &n, &R);
        for (int i = 0 ; i < n ; ++i){
            scanf("%lld", &a[i]);
            a[i + n] = a[i];
            v[i] = calc(i);
            v[i + n] = calc(i + n);
        }
        int front = 0, end = -1, resl, resr;
        LL ans = 0;
        for (int i = 0;i < 2 * n; ++i) {
            while (front <= end && lis[front] < i - n / 2) {
                front++;
            }
            if (end >= front) {
                LL now = a[i] + R * i + v[lis[front]];
                if (now > ans) {
                    ans = now;
                    int l = i % n, r = lis[front] % n;
                    if (l > r) {
                        swap(l , r);
                    }
                    resr = r;
                    resl = l;
                }
                else if (now == ans) {
                    int l = i % n, r = lis[front] % n;
                    if (l > r) {
                        swap(l , r);
                    }
                    if (l < resl || (l == resl && r < resr)){
                        resr = r;
                        resl = l;
                    }
                }
            }
            while (front <= end && v[lis[end]] < v[i]) {
                --end;
            }
            lis[++end] = i;
        }
        printf("Case #%d:\n%d %d\n" , ca, resl+1 , resr+1);
    }
}


