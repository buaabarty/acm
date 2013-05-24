#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 400 + 9;
const int M = 1000000 + 9;
const int inf = 1000000000;

struct edge {
	int v, next, id;
} e[M];
int p[N], eid, n;
void init() {
	memset(p, -1, sizeof(p));
	eid = 0;
}
void insert(int x, int y, int id) {
	e[eid].v = y;
	e[eid].next = p[x];
	e[eid].id = id;
	p[x] = eid++;
}
void insert2(int x, int y, int id) {
	insert(x, y, id);
	insert(y, x, id);
}
void gao(int s, int t) {
	static int dist[N];
	static bool inq[N];
	int q[N], l, r;
	l = 0, r = 1;
	for (int i = 1; i <= n; ++i) {
		dist[i] = inf;
	}
	dist[s] = 0;
	q[0] = s;
	memset(inq, 0, sizeof(inq));
	inq[s] = 1;
	for (; l-r; ) {
		int now = q[l++];
		if (l >= N) l = 0;
		for (int i = p[now]; ~i; i = e[i].next)
			if (dist[now] + 1 < dist[e[i].v]) {
				dist[e[i].v] = dist[now] + 1;
				if (!inq[e[i].v]) {
					inq[e[i].v] = 1;
					q[r++] = e[i].v;
					if (r >= N) r = 0;
				}
			}
		inq[now] = 0;
	}
	static vector<int> ans[N];
	static bool got[M];
	memset(got, 0, sizeof(got));
	int maxdist = dist[t];
	for (int i = 1; i <= n; ++i) ans[i].clear();
	for (int i = 1; i <= n; ++i)
		for (int j = p[i]; ~j; j = e[j].next)
			if (!got[e[j].id] && dist[i] + 1 == dist[e[j].v] && dist[e[j].v] <= maxdist) {
				ans[dist[i]+1].push_back(e[j].id);
				got[e[j].id] = 1;
			}
	for (int i = 0; i < eid; ++i)
		if (!got[e[i].id]) {
			ans[1].push_back(e[i].id);
			got[e[i].id] = 1;
		}
	printf("%d\n", maxdist);
	for (int i = 1; i <= maxdist; ++i) {
		printf("%d", (int)ans[i].size());
		sort(ans[i].begin(), ans[i].end());
		for (int j = 0; j < ans[i].size(); ++j)
			printf(" %d", ans[i][j]);
		printf("\n");
	}
}
int main() {
	static int m, s, t;
	while (scanf("%d%d%d%d", &n, &m, &s, &t) == 4) {
		init();
		for (int i = 1; i <= m; ++i) {
			static int x, y;
			scanf("%d%d", &x, &y);
			insert2(x, y, i);
		}
		gao(s, t);
	}
	return 0;
}
