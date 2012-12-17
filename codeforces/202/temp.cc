#include<map>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
#define ctz __builtin_ctz
#define popcount __builtin_popcount
#define REP(z,a,b) for(LL z=(a);z<=(b);z++)

LL state[1055][110];
LL qs[110];
LL sz[1055];
LL cnt = 0;

map<string,LL> MM;
int main()
{
    LL n;
    while(scanf("%lld",&n)!=EOF)
    {
        MM.clear();
        //init();
        static char buf[1055];
        static char tmp[1055];
        cnt=0;
        REP(i,1,n)
        {
            scanf("%s%lld",buf,&sz[i]);
            char *p=buf;
            LL mark=0;
            memset(state[i],0,90*4);
            while(true)
            {
                while(*p!='['&& *p)p++;
                if(*p==0)break;
                p++;
                sscanf(p,"%[^]]",tmp);
               LL id=-1;
               if( MM.find( tmp )==MM.end() )
               {
                   MM[tmp] = ++cnt;
                   id=cnt;
               }
               else id = MM[tmp ];

                LL offset = id/30;
                LL rem = id%30;
                state[i][offset] |= (1<<rem);
            }
        }
        LL q;
        scanf("%lld",&q);
        while(q--)
        {
            scanf("%s",buf);
            char *p=buf;
            memset(qs,0,sizeof(qs));
            bool can = true;
            while(true)
            {
                while(*p!='['&& *p)p++;
                if(*p==0)break;
                p++;
                sscanf(p,"%[^]]",tmp);
                LL id=MM[tmp ];
                if (id == 0) {
                    can = false;
                    continue;
                }
                LL offset = id/30;
                LL rem = id%30;
                qs[offset] |= (1<<rem);
            }
            long long ans=0;
            REP(i,1,n)
            {
                bool flag=true;
                bool same = true;
                REP(j,0,80)
                {
                    if( qs[j]!=state[i][j] )same=false;
                    if( (qs[j]&state[i][j]) != qs[j]) {flag=false;break;}
                }
                if(flag)ans+=sz[i];
            }
            if (can) printf("%lld\n",ans);
            else printf("0\n");
        }
    }
}


/*

5
[comic][naruto][01] 1024
[comic][naruto][02] 1024
[comic][inuyasha][01] 1024
[comic][inuyasha][02] 1024
[comic][inuyasha][03] 1024
3
[inuyasha]
[comic][01]
[ost]

*/
