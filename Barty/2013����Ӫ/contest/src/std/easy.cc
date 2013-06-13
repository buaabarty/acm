#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
class func {
    public : void gao() {
        char str[1010];
        scanf("%s", str);
        int ans = 0;
        for (int i = 0; str[i]; ++i) {
            ans += (str[i] == '0' || str[i] == '6' || str[i] == '9');
            ans += (str[i] == '8') * 2;
        }
        printf("%d\n", ans);
    }
};
int main() {
    freopen("easy.in", "r", stdin);
    freopen("easy.out", "w", stdout);
    func a;
    a.gao();
    return 0;
}
