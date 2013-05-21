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
class TheJediTest {
public:
    int minimumSupervisors(vector <int> students, int K) {
        int n = students.size();
        int res = 0, q = 0;
        for (int i = 0; i < n; ++i) {
            int now = q + students[i];
            if (now < 0) now = 0;
            res += now / K;
            q = now % K;
            if (q > students[i]) {
                res += ((q-students[i]+K-1)/K);
                q -= ((q-students[i]+K-1)/K)*K;
            }
        }
        if (q>0) res += ((q+K-1)/K);
        return res;
    }

};


// Powered by FileEdit
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by CodeProcessor
