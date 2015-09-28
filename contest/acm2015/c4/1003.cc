#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const LL N = 1000000 + 9;
map<LL, LL> hash1, hash2;
set<LL> edge;
struct edge {
    LL v, next;
} e[N * 4 + 3];
LL n, p[N * 2], eid, d[N * 2];
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(LL x, LL y) {
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert2(LL x, LL y) {
    insert(x, y);
    insert(y, x);
}

LL cnt1, cnt2;

int main() {
    LL T;
    scanf("%lld", &T);
    for (LL ca = 1; ca <= T; ++ca) {
        init();
        hash1.clear();
        hash2.clear();
        scanf("%lld", &n);
        cnt1 = 0;
        cnt2 = 0;
        edge.clear();
        memset(d, 0, sizeof(d));
        for (LL i = 1; i <= n; ++i) {
            LL x, y;
            scanf("%lld%lld", &x, &y);
            LL id_x, id_y;
            if (hash1.find(x) != hash1.end()) {
                id_x = hash1.find(x) -> second;
            } else {
                hash1[x] = ++cnt1;
                id_x = cnt1;
            }
            if (hash2.find(y) != hash2.end()) {
                id_y = hash2.find(y) -> second;
            } else {
                hash2[y] = ++cnt2;
                id_y = cnt2;
            }
            if (edge.find(id_x * n + id_y) == edge.end()) {
                edge.insert(id_x * n + id_y);
                insert2(id_x, id_y + n);
                d[id_x]++;
                d[id_y + n]++;
            }
        }
        LL res1 = 0, res2 = 0, res3 = 0;
        for (LL i = 1; i <= cnt1; ++i) {
            bool okay = true;
            LL cnt = 0;
            for (LL j = p[i]; j != -1; j = e[j].next) {
                ++cnt;
                if (d[e[j].v] > 1) {
                    okay = false;
                }
            }
            if (okay && cnt == 1) ++res3;
            else if (okay) ++res1;
        }
        for (LL i = 1; i <= cnt2; ++i) {
            bool okay = true;
            LL cnt = 0;
            for (LL j = p[i+n]; j != -1; j = e[j].next) {
                ++cnt;
                if (d[e[j].v] > 1) {
                    okay = false;
                }
            }
            if (okay && cnt > 1) ++res2;
        }
        printf("Case #%lld: %lld %lld %lld\n", ca, res1, res2, res3);
    }
}
