#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#include <algorithm>

#define pb push_back


using namespace std;

struct data {
    int p, h;
    bool operator < (const data &a) const {
        return p < a.p;
    }
    data(int _p, int _h) {
        p = _p; h = _h;
    }
    data() {}
};

int n, q, f[100];
vector<data> d;
int main() {
    scanf("%d%d", &n, &q);
    while (q--) {
        int k, x, y;
        scanf("%d%d", &k, &x);
        if (k == 1) {
            scanf("%d", &y);
            d.pb(data(x, y));
            sort(d.begin(), d.end());
        } else {
            sort(d.begin(), d.end());
            d.erase(d.begin()+x-1);
        }
        memset(f, 0, sizeof(f));
        int len = d.size(), mm = 0;
        //printf("LALA");
        //for (int i = 0; i < len; ++i)
        //    printf("(%d,%d) ", d[i].p, d[i].h);
        //puts("");
        for (int i = 0; i < len; ++i) {
            f[i] = 1;
            for (int j = 0; j < i; ++j)
                if (d[j].h < d[i].h) f[i] = max(f[i], f[j] + 1);
            mm = max(mm, f[i]);
        }
        for (int i = 0; i < len; ++i) d[i].h = d[i].h + 1;
        printf("%d\n", mm);
    }
    return 0;
}


