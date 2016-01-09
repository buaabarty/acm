#include <cstdio>
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
struct loc { int l, r; };
struct trie {
    trie* p[26];
    loc l;
};

trie* new_trie(int l, int r) {
    trie* t = new trie;
    memset(t->p, 0, sizeof(t->p));
    t->l = {l, r};
    return t;
}

int main() {
    string t, s;
    int n, m;
    int dp[2200], l[2200], len;
    loc ans[2200];
    loc res[2200];
    cin >> t >> s;
    n = t.length(); m = s.length();
    memset(dp, 0, sizeof(dp));
    trie root = {};
    for (int i = 0; i < n; ++i) {
        trie *it = &root;
        for (int j = i; j < n; ++j) {
            if (!it->p[t[j]-'a']) {
                it->p[t[j]-'a'] = new_trie(i, j);
            }
            it = it->p[t[j]-'a'];
        }
        it = &root;
        for (int j = i; j >= 0; --j) {
            if (!it->p[t[j]-'a']) {
                it->p[t[j]-'a'] = new_trie(i, j);
            }
            it = it->p[t[j]-'a'];
        }
    }
    for (int i = 1; i <= m; ++i) {
        trie *it = &root;
        dp[i] = 1000000000;
        for (int j = i - 1; j >= 0; --j) {
            if (!it->p[s[j]-'a']) {
                break;
            }
            it = it->p[s[j]-'a'];
            if (dp[j] + 1 < dp[i]) {
                dp[i] = dp[j] + 1;
                ans[i] = it->l;
                l[i] = j;
            }
        }
    }
    if (dp[m] >= 1000000000) {
        puts("-1");
    } else {
        printf("%d\n", dp[m]);
        len = dp[m];
        int i = m, k = 1;
        while (i) {
            res[len - (k++)] = ans[i];
            i = l[i];
        }
        for (int i = 0; i < len; ++i) {
            printf("%d %d\n", res[i].r + 1, res[i].l + 1);
        }
    }
    return 0;
}
