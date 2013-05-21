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
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

#define eps 1e-15
double s[30000*100+100];
class TheFrog {
public:
    double ans;
    vector<int> l, r;
    void gao(int x) {
        if (!x) return;
        for (int i = 30000; i >= 1; --i) {
            bool flag = true;
            for (int j = 0; j < l.size(); ++j)
                if (l[j]*i/x*x+x<r[j]*i) {
                    flag = false;
                    break;
                }
            if (flag) {
                ans = min(ans, x * 1.0 / (double)i);
                break;
            }
        }
    }
    double getMinimum(int D, vector <int> L, vector <int> R) {
        ans = 1e20;
        for (int i = 0; i < L.size(); ++i)
            l.push_back(L[i]), r.push_back(R[i]);
        gao(D);
        for (int i = 0; i < L.size(); ++i)
            gao(L[i]), gao(R[i]);
        return ans;
    }

};



// Powered by FileEdit
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by CodeProcessor
