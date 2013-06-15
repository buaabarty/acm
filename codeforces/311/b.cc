#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

template <typename T> void checkMin(T &a, const T &b) {
    if (b < a) a = b;
}

const LL inf = 1<<30;

LL f[100000 + 9], g[100000 + 9];
LL n, m, p;
LL d[100000 + 9], h[100000 + 9], t[100000 + 9];
LL x[100000 + 9], s[100000 + 9];
LL q[100000 + 9];

LL dx(LL i, LL j) {
    return f[j] + s[j] - f[i] - s[i];
}
LL dy(LL i, LL j) {
    return j - i;
}

LL gao(LL i, LL head) {
    return f[q[head]] + s[q[head]]- x[i] * q[head];
}

int main() {
    while (scanf("%I64d%I64d%I64d", &n, &m, &p) == 3) {
        for (LL i = 2; i <= n; ++i) {
            scanf("%I64d", &d[i]);
            d[i] += d[i-1];
        }
        for (LL i = 1; i <= m; ++i) {
            LL a, b;
            scanf("%I64d%I64d", &a, &b);
            x[i] = b - d[a];
        }
        sort(x + 1, x + m + 1);
        memset(s, 0, sizeof(s));
        for (LL i = 1; i <= m; ++i) {
            s[i] = s[i - 1] + x[i];
            f[i] = x[i] * i - s[i];
            //f[i] = inf;
        }
        f[0] = 0;
        s[0] = 0;
        //for (LL i = 1; i <= m; ++i)
            //printf("%I64d%c", x[i], " \n"[i==m]);
        //for (LL i = 1; i <= m; ++i)
        //    f[i] = f[i-1] + x[m] - x[i];
        for (LL t = 1; t < p; ++t) {
            memset(q, 0, sizeof(q));
            int head = 1, tail = 1;
            q[1] = 0;
            //for (LL i = 1; i <= m; ++i)
            //    printf("%I64d%c", f[i] + s[i], " \n"[i==m]);
            for (LL i = 1; i <= m; ++i) {
                //cout << "HT  " << head << " " << tail << endl;
                //for (LL j = head; j <= tail; ++j)
                //    printf("%I64d%c", gao(i, q[j]), " \n"[j==tail]);
                //puts("");
                while (head < tail && gao(i, head) >= gao(i, head+1)) ++head;
                //cout << i << " " << q[head] << " " << gao(i, head) << endl;
                g[i] = gao(i, head) + x[i] * i - s[i];
                while (head < tail && dx(q[tail-1], q[tail]) * dy(q[tail], i) >= dx(q[tail], i) * dy(q[tail-1], q[tail])) --tail;
                q[++tail] = i;
            }
            for (LL i = 1; i <= m; ++i) f[i] = g[i];
            //for (LL i = 1; i <= m; ++i)
            //    printf("%I64d%c", f[i], " \n"[i==m]);
        }
        printf("%I64d\n", f[m]);
    }
    return 0;
}
