#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct data {
    string name;
    bool is_male;
    int round1, round2;
    float score;
    bool selected;
    void read() {
        selected = false;
        string mm;
        cin >> name >> mm >> round1 >> round2;
        if (mm == "male") {
            is_male = true;
        } else {
            is_male = false;
        }
    }
    bool operator < (const data& a) const {
        return score > a.score;
    }
} d[101];
int T, n, m;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        int max1 = 0, max2 = 0;
        bool has_female = false;
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; ++i) {
             d[i].read();
             max1 = max(max1, d[i].round1);
             max2 = max(max2, d[i].round2);
             if (!d[i].is_male) {
                 has_female = true;
             }
        }
        for (int i = 1; i <= n; ++i) {
            d[i].score = d[i].round1 * 300. / max1 * 0.3 + d[i].round2 * 300. / max2 * 0.7;
        }
        sort(d + 1, d + n + 1);
        cout << "The member list of Shandong team is as follows:" << endl;
        if (has_female) {
            for (int i = 1; i <= n; ++i) {
                if (!d[i].is_male) {
                    d[i].selected = true;
                    break;
                }
            }
            for (int i = 1, j = m - 1; j; ++i) {
                if (!d[i].selected) {
                     d[i].selected = true;
                     --j;
                }
            }
            for (int i = 1; i <= n; ++i)
                if (d[i].selected) {
                    cout << d[i].name << endl;
                }
        } else {
            for (int i = 1; i <= m; ++i) {
                cout << d[i].name << endl;
            }
        }
    }
    return 0;
}
