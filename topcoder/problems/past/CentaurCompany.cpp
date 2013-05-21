
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

const int N = 50;

double f[60][60][60][2];
int n;
vector<int>adj[60];

class CentaurCompany {
public:
	void gao(int x,int y) {
	    double g[60][60][2];
		f[x][0][0][0]=1;
        f[x][1][1][1]=1;
		for (int i = 0; i < adj[x].size(); ++i)
            if(adj[x][i]!=y) {
                gao(adj[x][i],x); memset(g, 0, sizeof(g));
                for (int j = 0; j < n + 1; ++j)
                    for (int k = 0; k < n + 1; ++k)
                        if(f[adj[x][i]][j][k][0]||f[adj[x][i]][j][k][1]) {
                            for(int l=0;l+j<=n;l++)
                                for(int m=0;m+k<=n;m++){
                                    g[l+j][m+k][0]+=f[x][l][m][0]*f[adj[x][i]][j][k][0];
                                    g[l+j][m+k][0]+=f[x][l][m][0]*f[adj[x][i]][j][k][1];
                                    g[l+j][m+k][1]+=f[x][l][m][1]*f[adj[x][i]][j][k][0];
                                    g[l+j][m+k-1][1]+=f[x][l][m][1]*f[adj[x][i]][j][k][1];
                                }
                }
                memcpy(f[x], g, sizeof(f[x]));
            }
	}

	double getvalue(vector <int> A, vector <int> B) {
	    double res = 0;
		n = A.size() + 1;
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; ++i)
            adj[i].clear();
		for(int i = 0; i<n-1 ; i++) {
			adj[A[i]].push_back(B[i]);
			adj[B[i]].push_back(A[i]);
		}
		gao(1, 0);
		for (int i = 0; i < n; ++i)
            for (int j = 0; j < i + 1; ++j)
                res+=(f[1][i][j][0]+f[1][i][j][1])*max((j-1)*2-i,0);
		for (int i = 0; i <= n - 2; ++i) res /= 2;
		return res;
	}
};
