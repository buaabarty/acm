#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
typedef  struct {int v,next,val;} edge;
const int MAXN=512;
const int MAXM=65536;
const int INF =1000000000;

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

string r[MAXN], sp[MAXN], str, ma, mb;
int x[MAXN], y[MAXN];
int a, b, c, s, t, oa;
string data[MAXN];

void init()
{
    cin >> a;
    oa = a;
    for (int i = 1; i <= a; ++i)
        cin >> r[i];
    cin >> b;
    for (int i = 1; i <= b; ++i)
    {
        cin >> str >> sp[i];
        bool found = false;
        for (int j = 1; j <= a; ++j)
            if (r[j] == sp[i])
            {
                found = true;
                break;
            }
        if (!found) r[++a] = sp[i];
    }
    cin >> c;
    for (int i = 1; i <= c; ++i)
    {
        cin >> ma >> mb;
        bool found = false;
        for (int j = 1; j <= a; ++j)
            if (r[j] == ma)
            {
                found = true;
                break;
            }
        if (!found) r[++a] = ma;
        found = false;
        for (int j = 1; j <= a; ++j)
            if (r[j] == mb)
            {
                found = true;
                break;
            }
        if (!found) r[++a] = mb;
        for (int j = 1; j <= a; ++j)
            if (ma == r[j])
            {
                x[i] = j;
                break;
            }
        for (int j = 1; j <= a; ++j)
            if (mb == r[j])
            {
                y[i] = j;
                break;
            }
    }
}

void build()
{
    sapinit();
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            if (r[i] == sp[j]) insert1(j + a, i, 1);
    for (int i = 1; i <= c; ++i)
        insert1(x[i], y[i], INF);
    s = a + b + 1;
    t = s + 1;
    for (int i = 1; i <= b; ++i)
        insert1(s, i + a, 1);
    for (int i = 1; i <= oa; ++i)
        insert1(i, t, 1);
    n = t;
}

int main()
{
    init();
    build();
    cout << b - sap(s, t) << endl;
    return 0;
}
