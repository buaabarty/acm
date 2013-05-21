#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[10][10];
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        for (int i = 0; i < 4; ++i)
            scanf("%s", str[i]);
        bool o = false, x = false;
        for (int i = 0; i < 4; ++i) {
            int cx = 0, ct = 0, co = 0;
            for (int j = 0; j < 4; ++j)
                if (str[i][j] == 'X') ++cx;
                else if (str[i][j] == 'T') ++ct;
                else if (str[i][j] == 'O') ++co;
            if (cx + ct + co == 4) {
                if (!cx) o = true;
                if (!co) x = true;
            }
            cx = 0, ct = 0, co = 0;
            for (int j = 0; j < 4; ++j)
                if (str[j][i] == 'X') ++cx;
                else if (str[j][i] == 'T') ++ct;
                else if (str[j][i] == 'O') ++co;
            if (cx + ct + co == 4) {
                if (!cx) o = true;
                if (!co) x = true;
            }
        }
        int cx = 0, ct = 0, co = 0;
        for (int i = 0; i < 4; ++i)
            if (str[i][i] == 'X') ++cx;
            else if (str[i][i] == 'T') ++ct;
            else if (str[i][i] == 'O') ++co;
        if (cx + ct + co == 4) {
            if (!cx) o = true;
            if (!co) x = true;
        }
        cx = 0, ct = 0, co = 0;
        for (int i = 0; i < 4; ++i)
            if (str[i][3-i] == 'X') ++cx;
            else if (str[i][3-i] == 'T') ++ct;
            else if (str[i][3-i] == 'O') ++co;
        if (cx + ct + co == 4) {
            if (!cx) o = true;
            if (!co) x = true;
        }
        if (o || x) {
            printf("Case #%d: %s won\n", ca, o?"O":"X");
        } else {
            bool flag = true;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if (str[i][j] == '.') {
                        flag = false;
                        break;
                    }
            if (!flag) printf("Case #%d: Game has not completed\n", ca);
            else printf("Case #%d: Draw\n", ca);
        }
    }
    return 0;
}
