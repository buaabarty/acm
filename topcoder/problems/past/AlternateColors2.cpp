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

class AlternateColors2 {
public:
    long long countWays(int n, int k) {
        long long res = 0;
        int x = k / 3;
        if (!x)++x;
        if (k%3==1)
        {

            for (int r = x; r <= n; ++r)
            {
                res += (LL)(n-r-x+1);
                if (x%2) res += (LL)((n-r)/2);
                else res += (LL)((n-r+1)/2);
            }
        }
        else if (k%3==2)
        {
            for (int r = x; r <= n; ++r)
            {
                res += (LL)(n-r-x+1);
                if (x%2) res += (LL)(((n-r)/2)*2);
                else res += (LL)(((n-r+1)/2)*2);
            }
        }
        else
        {
            for (int r = x; r <= n; ++r)
            {
                res += (LL)(n-r-x+1);
                if (x%2==0) res += (LL)(((n-r)/2)*2);
                else res += (LL)(((n-r+1)/2)*2);
            }
        }
        return res + ((LL)k/3+1LL);
    }

};
