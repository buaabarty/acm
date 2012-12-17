#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 999999999

using namespace std;

int s[1005];
struct SUM
{
    int i;int j;
    int num;
}sum[1000005];
int n,cnt;

int cmp(const SUM &a,const SUM &b)
{
    return a.num < b.num;
}

int findx(int a[],int x,int f,int t)
{
    if (x < a[f] || x > a[t])
        return -1;
    int mid = (f + t)/2;
    while(f < t)
    {
        if (x > a[mid])
            f = mid + 1;
        else
            t = mid;
        mid = (f + t)/2;
    }
    return t;
}

int cal()
{
    int ind;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = cnt - 1; j >= 0; --j)
        {
            if (sum[j].i == i || sum[i].j == i)
                continue;
            ind = findx(s,s[i] - sum[j].num,0,i - 1);
            if (ind < 0)
                continue;
            if (ind != i && s[ind] == s[i] - sum[j].num && ind != sum[i].i && ind != sum[i].j)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    while(scanf("%d",&n) && n != 0)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d",&s[i]);
        if (n < 4)
        {
            printf("no solution\n");
            continue;
        }
        sort(s,s + n);
        cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    sum[cnt].i = i;
                    sum[cnt].j = j;
                    sum[cnt++].num = s[i]+s[j];
                }
            }
        sort(sum,sum + cnt,cmp);
        int ans = cal();
        if (ans < 0)
            printf("no solution\n");
        else printf("%d\n",s[ans]);
    }
    return 0;
}
