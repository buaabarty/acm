/*
ID:ybojan2
LANG:C++
TASK:fence
*/
#include <iostream>
#include <fstream>

using namespace std;

int d[1001],map[1001][1001],f,n,cnt,res[1000000];

void go(int v)
{
     for (int i=1;i<=n;i++)
         if (map[v][i]>0){
                          map[v][i]--;
                          map[i][v]--;
                          go(i);
                          }
     cnt++;
     res[cnt]=v;
}

int main()
{
    ifstream fin("fence.in");
    ofstream fout("fence.out");
    memset(d,0,sizeof(d));
    memset(map,0,sizeof(map));
    memset(res,0,sizeof(res));
    fin>>f;
    n=0;
    for (int i=1;i<=f;i++)
    {
        int x,y;
        fin>>x>>y;
        map[x][y]++;
        map[y][x]++;
        d[x]++;
        d[y]++;
        n=max(max(n,x),y);
    }
    int find=0;
    cnt=0;
    for (int i=1;i<=n;i++)
        if (d[i]%2==1){
                       find=i;
                       break;
                       }
    if (find==0){
                 for (int i=1;i<=n;i++)
                     if (d[i]>0){
                                 find=i;
                                 break;
                                 }
                 }
    go(find);
    for (int i=cnt;i>=1;i--)
        fout<<res[i]<<endl;
    return 0;
}
