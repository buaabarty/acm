#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
class func {
    int ans[100010], next[100010];
    public : void gao() {
        int n; scanf("%d", &n);
        bool flag = true;
        memset(ans, -1, sizeof(ans));
        for (int i = 1; i <= n; ++i) scanf("%d", &next[i]);
        next[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if ((next[i] >= i) || (next[i] < 0)) {
                flag = false;
                break;
            }
            int j = next[i-1];
            int bitset = 0;
            while ((j > 0) && (j + 1 != next[i])) {
                bitset |= (1<<(ans[j+1]));
                j = next[j];
            }
            if (j + 1 != next[i]) {
                bitset |= (1<<(ans[j+1]));
                j = next[j];
                for (int k = 0; k < 16; ++k)
                    if (!((1<<k)&bitset)) {
                        ans[i] = k; break;
                    }
                if (ans[i] < 0) {
                    flag = false;
                    break;
                }
            } else {
                if ((1<<ans[j+1]) & bitset)  {
                    flag = false;
                    break;
                } else ans[i] = ans[j+1];
            }
        }
        if (!flag) {
            printf("-1\n");
        } else {
            for (int i = 1; i <= n; ++i) printf("%c", (char)(ans[i]+'a'));
            printf("\n");
        }
    }
};

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    func a;
    a.gao();
    return 0;
}
