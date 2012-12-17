/*
ID:ybojan2
LANG:C++
TASK:theme
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXL 5010
using namespace std;
int r[MAXL], sa[MAXL], rank[MAXL], height[MAXL];
int mem[2][MAXL], cnt[MAXL], wv[MAXL];
bool cmp(int *r, int a, int b, int k)
{
    return r[a] == r[b] && r[a + k] == r[b + k];
}
void da(int *r, int *sa, int n, int m)
{
    int *x = mem[0], *y = mem[1];
    int i, J, p;
    memset(cnt,0,m*sizeof(int ));
    for(i=0;i<n;i++) cnt[x[i]=r[i]]++;
    for(i=1;i<m;i++) cnt[i]+=cnt[i-1];
    for(i=n-1;i>=0;i--) sa[--cnt[x[i]]]=i;
    for(J=1,p=1;p<n; J*=2, m=p){
        for(p=0,i=n-J; i<n; i++) y[p++]=i;
        for(i=0;i<n;i++ )
            if(sa[i]>=J)
                y[p++]=sa[i]-J;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        memset(cnt,0,m*sizeof(int ));
        for(i=0;i<n;i++) cnt[wv[i]]++;
        for(i=1;i<m;i++) cnt[i]+=cnt[i-1];
        for(i=n-1;i>=0;i--) sa[--cnt[wv[i]]]=y[i];
        swap(x,y);
        for(x[sa[0]]=0,p=1,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],J )?p-1:p++;
    }
}
void get_H(int *r,int *sa,int n)
{
    int i,J,k=0;
    for(i=1;i<=n; i++) rank[sa[i]]=i;
    for(i=0,k=0;i<n; height[rank[i++]]=k)
        for(k?k--:0 ,J=sa[rank[i]-1]; r[i+k]==r[J+k] ; k++ );
}
int n, dat[MAXL];
bool okay(int limit)
{
    int xmin = INT_MAX, xmax = 0;
    for (int i = 1; i < n; ++i)
        if (height[i] >= limit){
            xmin = min(xmin, min(sa[i], sa[i - 1]));
            xmax = max(xmax, max(sa[i], sa[i - 1]));
            if (xmax > xmin + limit) return true;
        }
        else{
            xmin = INT_MAX;
            xmax = 0;
        }
    return false;
}
int main()
{
    freopen("theme.in", "r", stdin);
    freopen("theme.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &dat[i]);
    if (n < 10){ printf("0\n"); return 0; }
    for (int i = 0; i < n - 1; ++i) r[i] = (dat[i + 1] - dat[i]) + 88;
    r[n - 1] = 88 * 2;
        //for (int i = 0; i < n; ++i) printf("%d ", r[i]);printf("\n");
    da(r, sa, n, 88 * 2 + 1);
    get_H(r, sa, n);
    int left = 4, right = n / 2, mid;
    while (left < right)
    {
        if (left + 1 == right){
            if (okay(right)) left = right;
            break;
        }
        mid = (left + right + 1) / 2;
        if (okay(mid)) left = mid;
        else right = mid - 1;
    }
    if (okay(left)) printf("%d\n", left + 1);
    else printf("0\n");
    return 0;
}
