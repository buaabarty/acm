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
class FoxAndMp3 {
public:
    int next(int now, int n) {
        if (now * 10 <= n) return now * 10;
        else if ((now + 1) % 10 == 0) return (now + 1) / 10;
        else if (now + 1 <= n) return now + 1;
        else if (now >= 10) return now / 10 + 1;
        else return -1;
    }
    string tostring(int x) {
        string ans = "";
        while (x) {
            ans = (char)(x%10+'0') + ans;
            x /= 10;
        }
        return ans;
    }
    vector <string> playList(int n) {
        vector<string> res;
        int now = 1, cnt = 0;
        do {
            ++cnt;
            string tmp = tostring(now) + ".mp3";
            if (res.size() && tmp < res[res.size()-1]) break;
            res.push_back(tmp);
            now = next(now, n);
        } while (now > 0 && cnt < 50);
        return res;
    }

};
