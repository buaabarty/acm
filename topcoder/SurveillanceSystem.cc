
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;
// END CUT HERE
class SurveillanceSystem {
public:
    string getContainerInfo(string containers, vector <int> reports, int L) {
        int sum[100], o[100][100], n;
        int got[100];
        int ans[100];
        memset(sum, 0, sizeof(sum));
        memset(o, 0, sizeof(o));
        memset(got, 0, sizeof(got));
        memset(ans, 0, sizeof(ans));
        n = containers.size();
        int now = 0;
        for (int i = 0; i < reports.size(); ++i) {
            ++got[reports[i]];
        }
        for (int i = 0; i < L; ++i) now += (containers[i] == 'X');
        for (int i = 0; i < L; ++i)
            o[now][i] = 1;
        sum[now] = 1;
        for (int i = L; i < n; ++i) {
            now -= (containers[i-L] == 'X');
            now += (containers[i] == 'X');
            ++sum[now];
            for (int j = i - L + 1; j <= i; ++j)
                ++o[now][j];
        }
        string res = "";
        bool f[100];
        for (int i = 0; i < n; ++i) res = res + "?";
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= n; ++i) if (got[i]) {
            for (int j = 0; j < n; ++j)
                if (o[i][j]) f[j] = 1;
            if (sum[i] == got[i]) {
                for (int j = 0; j < n; ++j)
                    if (o[i][j]) res[j] = '+';
            } else {
                for (int j = 0; j < n; ++j)
                    if (sum[i] - o[i][j] < got[i]) res[j] = '+';
            }
        }
        for (int i = 0; i < n; ++i)
            if (!f[i]) res[i] = '-';
        return res;
    }

};

