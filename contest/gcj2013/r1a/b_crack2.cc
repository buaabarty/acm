#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T, E, R, N;
int v[100010];
int ans;
void dfs(int n, int val, int e) {
    ans = max(ans, val);
    if (n == N) return ;
    for (int i = 0; i <= e; ++i)
        dfs(n+1, val+i*v[n+1], min(E, e-i+R));
}
int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d%d", &E, &R, &N);
        for (int i = 1; i <= N; ++i) scanf("%d", &v[i]);
        ans = 0;
        dfs(0, 0, E);
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
