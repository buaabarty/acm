#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int s[105];
int sg[10005];
int k,n,m,x,ans;

int cal(int x)
{
    if(sg[x] != -1)
        return sg[x];
    bool rem[10005];
    memset(rem,false,sizeof(rem));
    for (int i = 1; i <= k; ++i)
    {
        if(x - s[i] >= 0)
        {
            if (sg[x - s[i]] == -1)
                sg[x - s[i]] = cal(x - s[i]);
            rem[sg[x - s[i]]] = true;
        }else break;
    }
    for (int i = 0; i <= x; ++i)
        if(!rem[i])
        {
            sg[x] = i;
            return i;
        }
    return 0;
}

int main()
{
    while(scanf("%d",&k) && k != 0)
    {
        for (int i = 1; i <= k; ++i)
            scanf("%d",&s[i]);
        sort(s + 1,s + k + 1);
        scanf("%d",&m);
        memset(sg,-1,sizeof(sg));
        sg[0] = 0;
        while(m--)
        {
            scanf("%d",&n);
            ans = 0;
            for (int i = 1; i <= n; ++i)
            {
                scanf("%d",&x);
                ans ^= cal(x);
            }
            if(ans == 0)
                printf("L");
            else printf("W");
        }
        printf("\n");
    }
    return 0;
}
