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
struct data {
    char c;
    int d;
};
class StringGame {
public:
    bool okay(string a, string b) {
        int cnt1[26], cnt2[26];
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (int i = 0; i < a.length(); ++i)
            cnt1[a[i]-'a']++;
        for (int i = 0; i < b.length(); ++i)
            cnt2[b[i]-'a']++;
        for (int i = 0; i < 26; ++i)
            if (cnt1[i] > cnt2[i]) return true;
        return false;
    }
    void out(vector<int> a) {
        for (int i = 0; i < a.size(); ++i)
            printf("%d ", a[i]);
        puts("");
    }

    vector <int> getWinningStrings(vector <string> S) {
        int cnt[51][26], tot[51];
        bool use[26];
        memset(cnt, 0, sizeof(cnt));
        vector<int> res;
        res.clear();
        int n = S.size();
        for (int i = 0; i < n; ++i) {
            tot[i] = 0;
            for (int j = 0; j < S[i].length(); ++j)
                cnt[i][S[i][j]-'a']++;
        }
        for (int i = 0; i < n; ++i) {
            //cout << i << endl;
            vector<int> remain;
            remain.clear();
            for (int j = 0; j < n; ++j) if (i != j) remain.push_back(j);
            //out(remain);
            memset(use, 0, sizeof(use));
            bool result = true;
            for (int t = 0; t < 26; ++t) {
                bool find = false;
                for (int j = 0; j < 26; ++j) if (!use[j] && cnt[i][j]) {
                    bool flag = true;
                    for (int k = 0; k < remain.size(); ++k)
                        if (cnt[i][j] < cnt[remain[k]][j]) {
                            flag = false;
                            break;
                        }
                    if (flag) {
                        //printf("%c\n", j+'A');
                        find = true;
                        vector<int> late;
                        for (int k = 0; k < remain.size(); ++k)
                            if (cnt[i][j] == cnt[remain[k]][j]) late.push_back(remain[k]);
                        remain.clear();
                        for (int k = 0; k < late.size(); ++k)
                            remain.push_back(late[k]);
                        use[j] = true;
                        break;
                    }
                }
                if (!find) break;
                //out(remain);
            }
            for (int j = 0; j < 26; ++j)
                if (cnt[i][j] && !use[j]) {
                    result = false; break;
                }
            if (result && (remain.size() == 0)) res.push_back(i);
        }
        return res;
    }

};


// Powered by FileEdit
// Powered by CodeProcessor
