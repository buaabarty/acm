#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#define MAX_N 1024
#define MAX_B 32
using namespace std;
typedef  struct {int v,next,val;} edge;
const int MAXN=20010;
const int MAXM=500010;

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
int dat[MAX_N][MAX_B];
int c[MAX_B];
bool init()
{
    if ((scanf("%d%d", &n, &m)) == EOF) return false;
    memset(dat, 0, sizeof(dat));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &dat[i][j]);
        }
    for (int i = 1; i <= m; ++i)
        scanf("%d", &c[i]);
    return true;
}
bool okay(int low, int high)
{
    sapinit();
    for (int i = 1; i <= n; ++i)
        for (int j = low; j <= high; ++j)
            {
                insert1(i + 1, dat[i][j] + n + 1, 1);
                //g[i + 1][j + n + 1] = 1;
            }
    for (int i = 1; i <= n; ++i)
    {
        insert1(1, i + 1, 1);
        //g[1][i + 1] = 1;
    }
    for (int i = 1; i <= m; ++i)
    {
        insert1(i + n + 1, n + m + 2, c[i]);
        //g[i + n + 1][n + m + 2] = c[i];
    }
    int temp = n;
    n = n + m + 2;
    int res = sap(1, n);
    n = temp;
    return res == n;
}
bool done(int delta)
{
    for (int i = 1; i <= m - delta + 1; ++i)
        if (okay(i, i + delta - 1)) return true;
    return false;
}

int main()
{
    while (init())
    {
        int l = 1, r = m, mid;
        while (l < r)
        {
            if (l + 1 == r)
            {
                if (!done(l)) l = r;
                break;
            }
            mid = (l + r) / 2;
            if (done(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}
