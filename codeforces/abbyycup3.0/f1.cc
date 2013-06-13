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
#include <cmath>
#include <cstring>
using namespace std;
template <typename T> void checkMin(T &a, const T &b) { if (b < a) a = b; }
template <typename T> void checkMax(T &a, const T &b) { if (b > a) a = b; }

const int maxn = 1600 + 5;
int mat[maxn][maxn], vis[maxn][maxn];
int sun[maxn][maxn];
int r, c;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
#define x first
#define y second
	static pair<int, int> q[maxn * maxn], *qt, *qb;

void bfs(int i, int j, int color) {
	qt = qb = q;
	*qt++ = make_pair(i, j); vis[i][j] = color;
	for (;qt != qb; ++qb) {
		i = qb->x, j = qb->y;
		for (int k = 0; k < 4; ++k) {
			int ii = i + dx[k];
			int jj = j + dy[k];
			if ( vis[ii][jj] == 0 ) {
				vis[ii][jj] = color;
				*qt++ = make_pair(ii, jj);
			}
		}
	}
}

map<int, int> mm;

void bfs2(int i, int j, int color) {
	qt = qb = q;
	*qt++ = make_pair(i, j); vis[i][j] = 0;
	for (;qt != qb; ++qb) {
		int i = qb->x, j = qb->y;
		for (int k = 0; k < 4; ++k) {
			int ii = i + dx[k];
			int jj = j + dy[k];
			if ( vis[ii][jj] == color ) {
				vis[ii][jj] = 0;
				*qt++ = make_pair(ii, jj);
			}
		}
	}
}

void solve() {
	mm.clear();
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			scanf("%d", &mat[i][j]);
			vis[i][j] = 0;
		}
		vis[i][0] = vis[i][c+1] = 1;
	}
	for (int j = 0; j <= c + 1; ++j) vis[0][j] = vis[r+1][j] = 1;

	int cnt = 0;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if ( !vis[i][j] ) {
				bfs(i, j, ++cnt);
			}
		}
	}
	int of = 2;
	for (int i = 1 + of; i <= r - of; ++i ) {
		for (int j = 1 + of; j <= c - of; ++j ) {			
			int issun = vis[i][j];
			if (issun == 0) continue;
			for (int x = i - of; x <= i + of; ++x ) {
				for (int y = j - of; y <= j + of; ++y ) {
					if ( vis[x][y] != issun ) issun = 0;
				}
			}
			sun[i][j] = issun;
		}
	}
	for (int i = 1 + of; i <= r - of; ++i ) {
		for (int j = 1 + of; j <= c - of; ++j ) {			
			int issun = sun[i][j];
			if (issun == 0) continue;
			for (int x = i - of * 2; x <= i + of * 2; ++x ) {
				for (int y = j - of * 2; y <= j + of * 2; ++y ) {
					vis[x][y] = 0;
				}
			}
		}
	}
	vector<int> ans(cnt);
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if ( vis[i][j] ) {
				++ans[ vis[i][j] - 1 ];
				bfs2(i, j,  vis[i][j] );
			}
		}
	}
	sort( ans.begin(), ans.end() );
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	while (cin >> r >> c) solve();
}
