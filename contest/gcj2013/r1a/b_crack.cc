#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int T;
int E,R,N;
int v[10005];
int S;
void dfs(int n,int val, int e)
{
    if (n == N)
    {
        S = max(S,val);
        return;
    }
    for (int i = 0; i <= e; ++i)
    {
        dfs(n + 1, val + v[n + 1]*i,min(e - i + R, E));
    }
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&T);
    for (int ca = 1; ca <= T; ++ca)
    {
        scanf("%d%d%d",&E,&R,&N);
        for (int i = 1; i <= N; ++i)
            scanf("%d",&v[i]);
        S= 0;
        dfs(0,0,E);
        printf("Case #%d: %d\n",ca,S);
    }
    return 0;
}
