#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,rd[505][505],dp[505][505];
int s1[505],s2[505];
//下标从0开始
void LCIS()
{
	int mac = 0, ans = 0, I, J, lu[505], mx;
	for (int i = 1; i <= n; i++)
	{
		mx = 0;
		for (int j = 1; j <= m; j++)
		{
			int tem = dp[i][j] = dp[i - 1][j];
			if (mx < tem && s1[i - 1] > s2[j - 1])
			{
				mx = tem;
				mac = j;
			}
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = mx + 1;
				rd[i][j] = mac;
			}
			if (ans < dp[i][j])
			{
				ans = dp[i][j];
				I = i, J = j;
			}
		}
	}
	printf("%d\n", ans);
	int len = ans;
	if(ans > 0)
		lu[ans--] = J - 1;
	while(ans && I && J)
	{
		if(rd[I][J] > 0)
		{
			lu[ans--] = rd[I][J] - 1;
			J = rd[I][J];
		}
		I--;
	}
	for(int i = 1; i <= len; i++)
	{
		printf("%d ", s2[lu[i]]);
	}
	printf("\n");
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &s1[i]);
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
		scanf("%d", &s2[i]);
	LCIS();
	return 0;
}
