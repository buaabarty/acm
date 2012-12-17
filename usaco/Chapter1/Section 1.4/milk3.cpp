/*
ID:ybojan2
LANG:C++
TASK:milk3
*/

#include <iostream>
#include <fstream>

using namespace std;

bool got[21][21][21];
int va,vb,vc;

int min(int x,int y)
{
    return ((x<y)?x:y);
}

void dfs(int a,int b,int c)
{
     if (got[a][b][c]) return;
     got[a][b][c]=true;
     int delta=min(a+b,vb)-b;
     if (delta>0) dfs(a-delta,b+delta,c);
     delta=min(a+b,va)-a;
     if (delta>0) dfs(a+delta,b-delta,c);
     
     delta=min(a+c,vc)-c;
     if (delta>0) dfs(a-delta,b,c+delta);
     delta=min(a+c,va)-a;
     if (delta>0) dfs(a+delta,b,c-delta);
     
     delta=min(c+b,vb)-b;
     if (delta>0) dfs(a,b+delta,c-delta);
     delta=min(c+b,vc)-c;
     if (delta>0) dfs(a,b-delta,c+delta);

}

int main()
{
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    
    fin>>va>>vb>>vc;
    for (int i=0;i<=20;i++)
    {
        for (int j=0;j<=20;j++)
        {
            for (int k=0;k<=20;k++)
            {
                got[i][j][k]=false;
            } 
        }
    }
    dfs(0,0,vc);
    
    bool can[21];
    
    for (int i=0;i<=vc;i++) can[i]=false;
    for (int i=0;i<=vb;i++)
    {
        for (int j=0;j<=vc;j++)
        {
            if (got[0][i][j]) can[j]=true;
        }
    }
    int len=0,res[21];
    for (int i=0;i<=vc;i++)
        if (can[i]) 
        {
                    len++;
                    res[len]=i;
        }
    for (int i=1;i<len;i++)
        fout<<res[i]<<" ";
    fout<<res[len]<<endl;
    return 0;
}
