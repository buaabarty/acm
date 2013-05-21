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
const int N = 50;
class BallsSeparating {
public:
    int n , R , G , B , Ri , Gi , Bi , ans;
    vector<int> r , g , b;
    void dfs(int x) {
        if (x == 0) {
            if (R) {
                for (Ri = 0 ; Ri < n ; ++Ri)
                    dfs(x + 1);
            } else dfs(x + 1);
        }
        else if (x == 1) {
            if (G) {
                for (Gi = 0 ; Gi < n ; ++Gi) {
                if (Ri != -1 && Gi == Ri) continue;
                dfs(x + 1);
                }
            } else dfs(x + 1);
        }
        else if (x == 2) {
            if (B) {
                for (Bi = 0 ; Bi < n ; ++Bi) {
                    if (Ri != -1 && Bi == Ri) continue;
                    if (Gi != -1 && Gi == Bi) continue;
                    dfs(x + 1);
                }
            } else dfs(x + 1);
        }
        else {
            int now = 0;
            for (int i = 0 ; i < n ; ++i) {
                if (i == Ri) now += b[i] + g[i];
                else if (i == Bi) now += r[i] + g[i];
                else if (i == Gi) now += b[i] + r[i];
                else {
                    now += r[i] + g[i] + b[i] - max(r[i] , max(g[i] , b[i]));
                }
            }
            if (now < ans) ans = now;
        }
    }
	int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
		n = red.size();
		r = red, g = green, b = blue;
		R = G = B = 0;
		for (int i = 0; i < n; ++i){
            R += red[i];
            G += green[i];
            B += blue[i];
		}
        int cnt = 0;
        ans = 99999999999999999LL;
        if (R) ++cnt;
        if (G) ++ cnt;
        if (B) ++ cnt;
        if (cnt > n) return -1;
        if (cnt == 1) return 0;
        Ri = Gi = Bi = -1;
        dfs(0);
		return ans;
	}
};
