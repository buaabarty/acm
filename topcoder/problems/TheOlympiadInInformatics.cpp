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
typedef long long LL;
class TheOlympiadInInformatics {
public:
    int find(vector <int> sums, int k) {
        int l = 0, r = 1000000000, mid, n = sums.size();
        while (l < r) {
            if (l + 1 == r) {
                LL cnt = 0;
                for (int i = 0; i < n; ++i)
                    cnt += (LL)sums[i] / (LL)(l + 1LL);
                if (cnt > (LL)k) l = r;
                break;
            }
            mid = (l + r) >> 1;
            LL cnt = 0;
            for (int i = 0; i < n; ++i)
                cnt += (LL)sums[i] / (LL)(mid + 1LL);
            if (cnt <= (LL)k) r = mid;
            else l = mid + 1;
        }
        return l;
    }

};
