#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<queue>
#include<cctype>
#include<cstdio>
#include<string>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<typeinfo>
#include<algorithm>
using namespace std;
const double eps=1e-11,pi=acos(-1.0);
//int cl(double z){return ceil(z-eps);}
//int flr(double z){return floor(z+eps);}
//long long cll(double z){return ceil(z-eps);}
//long long  flrl(double z){return floor(z+eps);}
int dblcmp(double d){return (d<-eps)?-1:(d>eps);}
const int inf=999999999;
const long long infl=999999999999999999LL;


#define pb push_back
#define mpp make_pair
#define gcd __gcd
#define ctz __builtin_ctz
#define popcount __builtin_popcount
#define gch c=getchar()
#define clr(z,w) memset(z,w,sizeof(z))
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define MII map<int,int>
#define MLL map<long long,long long>

template<class T> inline void checkmin(T &a,const T &b){if(a>b)a=b;}
template<class T> inline void checkmax(T &a,const T &b){if(a<b)a=b;}



char name[1005][1005];
int value[1005];
bool ok[1005];


char buf[100005];

char g[1005][1005];

long long dp1[505][505][11];
long long dp2[505][505][11];

const long long BASE = 1000000007LL;
inline int MOD(int s)
{
	return (s+10)%10;
}
void solve()
{
	static int cas=1;
	printf("Case #%d:\n",cas++);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",g[i]);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)g[i][j]-='0';

	for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<10;k++)dp1[i][j][k]=dp2[i][j][k]=0;

	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			dp1[i][0][g[i][0] ] = 1;
			for(int j=1;j<m;j++)
			{
				int v = g[i][j];
				dp1[i][j][v] ++;
				for(int k=0;k<10;k++)//i j k = i j-1 kk
				{
					dp2[i][j][k] += dp1[i][j-1][MOD(k+v)];
					dp1[i][j][k] += dp2[i][j-1][MOD(k-v)];
					dp1[i][j][k] %= BASE;
					dp2[i][j][k] %= BASE;
				}
			}
			for(int j=0;j<m;j++)ans += dp1[i][j][0] + dp2[i][j][0];
			continue;
		}

		int v = g[i][0];
		dp1[i][0][v] ++;///k = 0-9
		for(int k=0;k<=9;k++)
		{
			dp2[i][0][k] += dp1[i-1][0][MOD(k+v)];
			dp1[i][0][k] += dp2[i-1][0][MOD(k-v)];
			dp1[i][0][k] %= BASE;
			dp2[i][0][k] %= BASE;
		}
		for(int j=1;j<m;j++)
		{
			int v = g[i][j];
			dp1[i][j][v] ++;
			for(int k=0;k<=9;k++)
			{
				dp2[i][j][k] += dp1[i-1][j][MOD(k+v)] + dp1[i][j-1][MOD(k+v)];
				dp1[i][j][k] += dp2[i-1][j][MOD(k-v)] + dp2[i][j-1][MOD(k-v)];
				dp1[i][j][k] %= BASE;
				dp2[i][j][k] %= BASE;
			}
		}
		for(int j=0;j<m;j++)ans += dp1[i][j][0] + dp2[i][j][0];
	}
	printf("-------%d\n",ans%BASE);
}
int main()
{
	int _;
	scanf("%d",&_);
	while(_--)solve();
	return 0;
}
