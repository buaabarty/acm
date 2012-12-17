#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 2600
#define LL long long
#define inf 100000000000000LL

using namespace std;

LL _max_flow(LL n,LL mat[][MAXN],LL source,LL sink,LL flow[][MAXN]){
	LL pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j,r;
	vector<LL> e[MAXN];
	for (i=0;i<n;i++)
		for (e[i].clear(),j=0;j<n;j++)
			if (mat[i][j]) e[i].push_back(j),e[j].push_back(i);
	for (;;){
		for (i=0;i<n;pre[i++]=0);
		pre[t=source]=source+1,d[t]=inf;
		for (p=q=0;p<=q&&!pre[sink];t=que[p++])
			for (r=0;r<e[t].size();++r){
				i=e[t][r];
				if (!pre[i]&&(j=mat[t][i]-flow[t][i]))
					pre[que[q++]=i]=t+1,d[i]=d[t]<j?d[t]:j;
				else if (!pre[i]&&(j=flow[i][t]))
					pre[que[q++]=i]=-t-1,d[i]=d[t]<j?d[t]:j;
			}
		if (!pre[sink]) break;
		for (i=sink;i!=source;)
			if (pre[i]>0)
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}
	for (j=i=0;i<n;j+=flow[source][i++]);
	return j;
}
LL limit_max_flow(LL n,LL mat[][MAXN],LL bf[][MAXN],LL source,LL sink,LL flow[][MAXN]){
	LL i,j,sk,ks;
	if (source==sink) return inf;
	for (mat[n][n+1]=mat[n+1][n]=mat[n][n]=mat[n+1][n+1]=i=0;i<n;i++)
		for (mat[n][i]=mat[i][n]=mat[n+1][i]=mat[i][n+1]=j=0;j<n;j++)
			mat[i][j]-=bf[i][j],mat[n][i]+=bf[j][i],mat[i][n+1]+=bf[i][j];
	sk=mat[source][sink],ks=mat[sink][source],mat[source][sink]=mat[sink][source]=inf;
	for (i=0;i<n+2;i++)
		for (j=0;j<n+2;flow[i][j++]=0);
	_max_flow(n+2,mat,n,n+1,flow);
	for (i=0;i<n;i++)
		if (flow[n][i]<mat[n][i]) return -1;
	flow[source][sink]=flow[sink][source]=0,mat[source][sink]=sk,mat[sink][source]=ks;
	_max_flow(n,mat,source,sink,flow);
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			mat[i][j]+=bf[i][j],flow[i][j]+=bf[i][j];
	for (j=i=0;i<n;j+=flow[source][i++]);
	return j;
}
LL mat[MAXN][MAXN], bf[MAXN][MAXN], flow[MAXN][MAXN];
int main()
{
    LL loc[60][60], cnt = 0;
    LL source = 0, sink;
    LL n;
    scanf("%I64d", &n);
    for (LL i = n; i >= 1; --i)
        for (LL j = 1; j <= i; ++j)
            loc[i][j] = ++cnt;
    sink = cnt * 2 + 1;
    memset(mat, 0, sizeof(mat));
    memset(bf, 0, sizeof(bf));
    memset(flow, 0, sizeof(flow));
    for (LL i = 1; i <= n; ++i)
    {
        scanf("%I64d", &mat[0][i]);
        bf[0][i] = 0;
    }
    for (LL i = n; i >= 1; --i)
        for (LL j = 1; j <= i; ++j)
        {
            scanf("%I64d", &bf[loc[i][j]][loc[i][j] + cnt]);
            mat[loc[i][j]][loc[i][j] + cnt] = inf;
        }
    for (LL i = n; i >= 1; --i)
        for (LL j = 1; j <= i; ++j)
        {
            if (j > 1) mat[loc[i][j] + cnt][loc[i - 1][j - 1]] = inf;
            if (j < i) mat[loc[i][j] + cnt][loc[i - 1][j]] = inf;
        }
    mat[loc[1][1] + cnt][sink] = inf;
    /*for (LL i = n; i >= 1; --i)
    {
        for (LL j = 1; j <= i; ++j)
            printf("%I64d\t", loc[i][j]);
        puts("");
    }
    for (LL i = 0; i < cnt * 2 + 2; ++i)
    {
        for (LL j = 0; j < cnt * 2 + 2; ++j)
            if (mat[i][j])
                printf("(%I64d,%I64d,%I64d,%I64d)\n", i, j, mat[i][j], bf[i][j]);
    }
    printf("%I64d %I64d %I64d\n", cnt, source, sink);*/
    LL res = limit_max_flow(cnt * 2 + 2, mat, bf, source, sink, flow);
    //printf("%I64d\n", res);

    if (res > 0)
    {
        printf("Cerealguy\n");
    }
    else
    {
        printf("Fat Rat\n");
    }
    /*while(scanf("%I64d%I64d", &n, &m) == 2)
    {

        for(i = 1; i <= n; i++)
        {
            scanf("%I64d", &k);
            for(j = 1; j <= k; j++)
            {
                scanf("%I64d", &ID);
                mat[n + ID][i] = 1;
            }
        }
        for(i = 1; i <= m; i++)
        {
            scanf("%I64d", &U);
            mat[0][n + i] = U;
        }
        for(i = 1; i <= m; i++)
        {
            scanf("%I64d", &D);
            bf[0][n + i] = D;
        }
        scanf("%I64d", &G);
        for(i = 1; i <= G; i++)
        {
            scanf("%I64d", &p);
            for(j = 1; j <= p; j++)
            {
                scanf("%I64d", &q);
                for(k = 1; k <= m; k++)
                    if(mat[n + k][q])
                    {
                        mat[n + k][q] = 0;
                        mat[n + k][n + m + i] = mat[n + m + i][q] = 1;
                    }
            }
        }
        for(i = 1; i <= n; i++)
            mat[i][n + m + G + 1] = 1;
        prLLf("%I64d\n", limit_max_flow(n + m + G + 2, mat, bf, 0, n + m + G + 1, flow));
    }
*/
    return 0;
}
