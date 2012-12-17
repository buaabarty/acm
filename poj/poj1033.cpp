#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int a[10010];
int n,k;

int move(int s,int p)
{
    if (a[a[p]] == 0)
    {
        a[a[p]] = a[p];
        printf("%d %d\n",p,a[p]);
        a[p] = 0;
        return 0;
    }else if(a[p] == s)
    {
        for (int i = n; i > 1; --i)
            if (a[i] == 0)
            {
                a[i] = a[p];
                printf("%d %d\n",p,i);
                //printf("%d %d\n",a[p],a[s]);
                a[p] = 0;
                return i;
            }
    }else
    {
        int d = move(s,a[p]);
        a[a[p]] = a[p];
        printf("%d %d\n",p,a[p]);
        a[p] = 0;
        if(p == s && d > 0)
        {
            a[s] = a[d];
            printf("%d %d\n",d,s);
            a[d] = 0;
            return 0;
        }else return d;
    }
}

int main()
{

        int x,num;
        num = 1;
        scanf("%d%d",&n,&k);
        memset(a,0,sizeof(a));
        for (int i = 1; i <= k; ++i)
        {
            scanf("%d",&x);
            for (int j = 1; j <= x; ++j)
            {
                int t;
                scanf("%d",&t);
                a[t] = num++;
            }
        }
        bool ok = true;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] != 0 && a[i] != i)
            {
                move(i,i);
                ok = false;
            }
        }
        if (ok)
            printf("No optimization needed\n");

    return 0;
}
