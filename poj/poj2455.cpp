#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
typedef  struct {int v,next,val;} edge;
const int MAXN=210;
const int MAXM=100010;
edge e[MAXM];
int p[MAXN],eid;
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
int n,m,t;//n为点数 m为边数
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
int a[MAXM], b[MAXM], c[MAXM];
bool init()
{
    if (scanf("%d%d%d", &n, &m, &t) == EOF) return false;
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
}
bool okay(int limit)
{
    sapinit();
    for (int i = 1; i <= m; ++i)
        if (c[i] <= limit)
            insert2(a[i], b[i], 1);
    return sap(1, n) >= t;
}
int main()
{
    while (init())
    {
        int l = 0, r = 1000000, mid;
        while (l < r)
        {
            if (l + 1 == r)
            {
                if (!okay(l)) l = r;
                break;
            }
            mid = (l + r) / 2;
            if (okay(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}
