#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long

using namespace std;

LL rem[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
LL num[1550];
LL n;
LL p1,p2,v1,v2,k;

void list()
{
    num[0] = 0;
    num[1] = 4;
    num[2] = 7;
    n = 3;
    LL s,t;
    s = 1;t = n;
    for (LL i = 1; i <= 8; ++i)
    {
        for (LL j = s; j < t; ++j)
            num[n++] = 4*rem[i]+num[j];
        for (LL j = s; j < t; ++j)
            num[n++] = 7*rem[i]+num[j];
        s = t;t = n;
    }
    num[n] = 1000000001;
    n--;
}

long long cal(LL s,LL t)
{
    long long ap,av,bp,bv;
    ap = max(0LL,min(num[s],p2) - max(num[s - 1] + 1,p1) + 1);
    av = max(0LL,min(num[s],v2) - max(num[s - 1] + 1,v1) + 1);
    bp = max(0LL,min(num[t + 1] - 1,p2) - max(num[t],p1) + 1);
    bv = max(0LL,min(num[t + 1] - 1,v2) - max(num[t],v1) + 1);
    return ap*bv+av*bp;
}

int main()
{
    list();
    scanf("%lld%lld%lld%lld%lld",&p1,&p2,&v1,&v2,&k);
    double ans = 0.0;
    if (k <= n)
    {
        for (LL i = 1; i + k - 1 <= n; ++i)
        {
            ans += cal(i,i + k - 1);
        }
        ans = ans/(p2 - p1 + 1)/(v2 - v1 + 1);
    }
    printf("%.12f\n",fabs(ans));
    return 0;
}
