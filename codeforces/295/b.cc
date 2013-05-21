#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, mat[501][501];
vector<int> now;
int inj[501];
const int inf = 100000000;
long long ans[501];
bool vst[501];
int d[501];
bool use[501];
void dijkstra(int v) {
    int s = now.size();
    for (int i = 0; i < s; ++i) d[i] = mat[v][now[i]];
    memset(use, 0, sizeof(use));
    for (int i = 1; i <= s; ++i) {
        int mt = -1, mx = inf;
        for (int j = 0; j < s; ++j)
            if (!use[j] && d[j] < mx) {
                mx = d[j]; mt = j;
            }
        use[mt] = 1;
        for (int j = 0; j < s; ++j)
            if (!use[j] && mx + mat[now[mt]][now[j]] < d[j]) {
                d[j] = mx + mat[now[mt]][now[j]];
            }
    }
    for (int j = 0; j < s; ++j)
        mat[v][now[j]] = d[j];
}
void dijkstra2(int v) {
    int s = now.size();
    for (int i = 0; i < s; ++i) d[i] = mat[now[i]][v];
    memset(use, 0, sizeof(use));
    for (int i = 1; i <= s; ++i) {
        int mt = -1, mx = inf;
        for (int j = 0; j < s; ++j)
            if (!use[j] && d[j] < mx) {
                mx = d[j]; mt = j;
            }
        use[mt] = 1;
        for (int j = 0; j < s; ++j)
            if (!use[j] && mx + mat[now[j]][now[mt]] < d[j]) {
                d[j] = mx + mat[now[j]][now[mt]];
            }
    }
    for (int j = 0; j < s; ++j)
        mat[now[j]][v] = d[j];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &mat[i][j]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &inj[i]);
    vst[inj[n]] = 1;
    now.push_back(inj[n]);
    for (int i = n - 1; i >= 1; --i) {
        now.push_back(inj[i]);
        dijkstra(inj[i]);
        dijkstra2(inj[i]);
        int s = now.size();
        for (int x = 0; x < s; ++x)
            for (int y = 0; y < s; ++y)
                mat[now[x]][now[y]] = min(mat[now[x]][now[y]], mat[now[x]][inj[i]] + mat[inj[i]][now[y]]);
        for (int x = 0; x < s; ++x)
            for (int y = 0; y < s; ++y)
                ans[i] = ans[i] + (long long)(mat[now[x]][now[y]]);
    }
    for (int i = 1; i <= n; ++i)
        printf("%I64d%c", ans[i], " \n"[i==n]);
    return 0;
}
