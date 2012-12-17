#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int M = 501;
//下标从0开始
int Greatest_Common_Increasing_Subsequence(int m,__int64 a[],int n,__int64 b[])
{
    int a_temp[M], a_max[M];
    memset(a_temp, -1, sizeof(a_temp));
    memset(a_max, 0, sizeof(a));
    for (int i = 0; i < m; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] == a[j])
            {
                a_temp[i]=j;
                break;
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        int maxs = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[i] < b[j])
                if (maxs < a_max[i]) maxs = a_max[i];
            if (a[i] == b[j])
            {
                if (a_temp[i] != -1 && maxs <= a_max[a_temp[i]])
                    a_max[i] = a_max[a_temp[i]];
                else
                    a_max[i] = maxs+1;
            }
        }
    }
    int maxs = 0;
    for(int i = 0; i < m; i++)
    {
        if(maxs < a_max[i])
        {
            maxs = a_max[i];
        }
    }
    return maxs;
}

int main()
{
    int n, m;
    __int64 a[M], b[M];

    while (cin >> m)
    {
        for (int i = 0; i < m; i++) scanf("%I64d",&a[i]);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%I64d",&b[i]);
        if (m >= n)
            printf("%d\n", Greatest_Common_Increasing_Subsequence(m,a,n,b));
        else
            printf("%d\n", Greatest_Common_Increasing_Subsequence(n,b,m,a));
    }
    return 0;
}
