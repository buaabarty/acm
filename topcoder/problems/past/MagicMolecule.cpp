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
class MagicMolecule {
public:
    bool mat[51][51], del[51];
    int n, ans, dat[51], last[51];
    void dfs(int rem, int remsum) {
        if (rem * 3 < n * 2) return ;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (!mat[i][j] && !del[i] && !del[j]) {
                    del[i] = 1;
                    dfs(rem - 1, remsum - dat[i]);
                    del[i] = 0;
                    del[j] = 1;
                    dfs(rem - 1, remsum - dat[j]);
                    del[j] = 0;
                    return ;
                }
        ans = max(ans, remsum);
    }
    int maxMagicPower(vector <int> magicPower, vector <string> magicBond) {
        n = magicPower.size();
        for (int i = 0; i < n; ++i)
            dat[i] = magicPower[i];
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                if (magicBond[i][j] == 'Y') mat[i][j] = mat[j][i] = 1;
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += dat[i];
        ans = -1;
        memset(del, 0, sizeof(del));
        dfs(n, sum);
        return ans;
    }

};
