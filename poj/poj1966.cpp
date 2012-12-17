#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
typedef  struct {int v,next,val;} edge;
const int MAXN=128;
const int MAXM=4096;
const int INF =1000000000;

edge e[MAXM], temp[MAXM];
int p[MAXN],eid, tempp[MAXN], teid;

inline void sapinit(){memset(p,-1,sizeof(p));eid=0;}
//有向
inline void insert1(int from,int to,int val)
{
	e[eid].v=to;
	e[eid].val=val;
	e[eid].next=p[from];
	p[from]=eid++;

	swap(from,to);

	e[eid].v=to;
	e[eid].val=0;
	e[eid].next=p[from];
	p[from]=eid++;
}

//无向
inline void insert2(int from,int to,int val)
{
	e[eid].v=to;
	e[eid].val=val;
	e[eid].next=p[from];
	p[from]=eid++;

	swap(from,to);

	e[eid].v=to;
	e[eid].val=val;
	e[eid].next=p[from];
	p[from]=eid++;
}

int n,m;//n为点数 m为边数
int h[MAXN];
int gap[MAXN];

int source,sink;
inline int dfs(int pos,int cost)
{
	if (pos==sink)
	{
		return cost;
	}

	int j,minh=n-1,lv=cost,d;

	for (j=p[pos];j!=-1;j=e[j].next)
	{
		int v=e[j].v,val=e[j].val;
		if(val>0)
		{
			if (h[v]+1==h[pos])
			{
				if (lv<e[j].val) d=lv;
				else d=e[j].val;

				d=dfs(v,d);
				e[j].val-=d;
				e[j^1].val+=d;
				lv-=d;
				if (h[source]>=n) return cost-lv;
				if (lv==0) break;
			}

			if (h[v]<minh)	minh=h[v];
		}
	}

	if (lv==cost)
	{
		--gap[h[pos]];
		if (gap[h[pos]]==0) h[source]=n;
		h[pos]=minh+1;
		++gap[h[pos]];
	}

	return cost-lv;

}

int sap(int st,int ed)
{
	source=st;
	sink=ed;
	int ret=0;
	memset(gap,0,sizeof(gap));
	memset(h,0,sizeof(h));

	gap[st]=n;

	while (h[st]<n)
	{
		ret+=dfs(st,INT_MAX);
	}

	return ret;
}

int x[MAXM], y[MAXM];
bool connect[MAXN][MAXN];

bool init()
{
    if (scanf("%d%d", &n, &m) == EOF) return false;
    sapinit();
    memset(connect, false, sizeof(connect));
    char str[100];
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s", str);
        sscanf(str, "(%d,%d)", &x[i], &y[i]);
        x[i]++, y[i]++;
        connect[x[i]][y[i]] = true;
        connect[y[i]][x[i]] = true;
        insert1(x[i] + n, y[i], INF);
        insert1(y[i] + n, x[i], INF);
    }
    n *= 2;
    return true;
}

void fresh()
{
    sapinit();
    for (int i = 1; i <= n / 2; ++i)
        insert1(i, i + n / 2, 1);
    for (int i = 1; i <= m; ++i)
    {
        insert1(x[i] + n / 2, y[i], INF);
        insert1(y[i] + n / 2, x[i], INF);
    }
}

int main()
{
    while (init())
    {
        int res = INT_MAX, cnt = 0;
        for (int i = 2; i <= n / 2; ++i)
            if (!connect[1][i])
            {
                fresh();
                res = min(sap(n / 2 + 1, i), res);
            }
            else cnt++;
        if (res != INT_MAX) cout << res << endl;
        else if (cnt == n / 2 - 1) cout << n / 2 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
