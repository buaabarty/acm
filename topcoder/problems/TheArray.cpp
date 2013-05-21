#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

class TheArray {
public:
    int iabs(int x) {
        return (x < 0) ? -x : x;
    }
    bool okay(int n, int d, int first, int last, int k) {
        return first+k*d-(n-1-k)*d<=last;
    }
    int find(int n, int d, int first, int last) {
        int l = 0, r = n - 1, mid;
        while (l < r) {
            if  (l + 1 == r) {
                if (okay(n, d, first, last, r)) l = r;
                break;
            }
            mid = (l + r + 1) >> 1;
            if (okay(n, d, first, last, mid)) l = mid;
            else r = mid - 1;
        }
        int delta = last - (first+l*d-(n-1-l)*d);
        int ans = first + l * d;
        if (delta >= d) ans += delta - d;
        return ans;
    }

};


// Powered by FileEdit
// Powered by CodeProcessor
