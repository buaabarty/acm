/*
ID:ybojan2
LANG:C++
TASK:shuttle
*/
#include <fstream>
using namespace std;
ifstream cin("shuttle.in");
ofstream cout("shuttle.out");

int main()
{
    int n,t,s,res[500],tt=0;
    memset(res,0,sizeof(res));
    cin>>n;
    for (int i=2;i<=n+1;i++)
    {
        if (i%2==1) t=-2;
        else t=2;
        if (i%2==1) s=n+i;
        else s=n-i+2;
        res[++tt]=s;
        for (int j=2;j<=i;j++)
        {
            s+=t;
            res[++tt]=s;
        }
    }
    for (int i=n;i>=2;i--)
    {
        if (i%2==1) t=-2;
        else t=2;
        if (i%2==1) s=n+i;
        else s=n-i+2;
        res[++tt]=s;
        for (int j=2;j<=i;j++)
        {
            s+=t;
            res[++tt]=s;
        }
    }
    res[++tt]=n+1;
    for (int i=1;i<=tt;i++)
    {
        cout<<res[i];
        if ((i%20==0)||(i==tt)) cout<<endl;
        else cout<<" ";
    }
    return 0;
}
