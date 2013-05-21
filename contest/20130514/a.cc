#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
bool osc[10000], ip[10000], mms[10000];
int n, m;
map<string, int> rank;
int num[1009];
struct data {
    char name[200];
    double pt;
} d[509];
bool cmp(data a, data b) {
    if (fabs(a.pt-b.pt) > 1e-6) return a.pt > b.pt;
    return strcmp(a.name, b.name) < 0;
}
int main() {
    memset(ip, 1, sizeof(ip));
    ip[0] = 0;
    ip[1] = 0;
    for (int i = 2; i < 10000; ++i)
        for (int j = i*2; j < 10000; j += i)
            ip[j] = 0;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(osc, 0, sizeof(osc));
        memset(mms, 0, sizeof(mms));
        int k, x;
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            mms[x] = 1;
        }
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            osc[x] = 1;
        }
        rank.clear();
        scanf("%d", &k);
        char name[109];
        while (k--) {
            scanf("%s%d", name, &x);
            rank[string(name)] = x;
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%s", name);
            strcpy(d[i].name, name);
            scanf("%s", name);
            int k = rank[string(name)];
            d[i].pt = 0;
            if (k == 1) d[i].pt += 36;
            else if (k == 2) d[i].pt += 27;
            else if (k == 3) d[i].pt += 18;
            scanf("%s", name);
            if (name[0] == 'F') d[i].pt += 33;
            int p, c;
            scanf("%d%d", &p, &c);
            while (p--) {
                scanf("%d", &x);
                if (mms[x]) d[i].pt += 2.5;
                else if (osc[x]) d[i].pt += 1.5;
                else if (ip[x]) d[i].pt += 1;
                else d[i].pt += 0.3;
            }
            for (int j = 0; j < c; ++j)
                scanf("%d", &num[j]);
            sort(num, num+c);
            if (c >= 3) {
                double r = num[c-3];
                d[i].pt += max(0.0, (r-1200.0)/100.0)*1.5;
            }
        }
        sort(d+1, d+n+1, cmp);
        for (int i = 1; i <= m; ++i)
            printf("%s %.3f\n", d[i].name, d[i].pt);
    }
    return 0;
}
