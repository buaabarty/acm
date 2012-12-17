/*
ID:ybojan2
LANG:C++
TASK:maze1
*/

#include <iostream>
#include <fstream>

using namespace std;

int t,w,h,dat[4][200][200],k[4][2]={{-1,0},{0,1},{1,0},{0,-1}},d[200][200];

void go(int x,int y,int s)
{
     if (s<d[x][y]) d[x][y]=s;
     else return;
     for (int i=0;i<=3;i++)
     {
         if (dat[i][x][y]==1) continue;
         int x1=x+k[i][0],y1=y+k[i][1];
         if ((x1<1)||(x1>h)||(y1<1)||(y1>w)) continue;
         go(x1,y1,s+1);
     }
}

int main()
{
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");
    
    memset(dat,0,sizeof(dat));
    char c;
    fin>>w>>h;
    string str;
    getline(fin,str);
    getline(fin,str);
    t=0;
    for (int i=1;i<=w;i++)
    {
        t++;
        if (str[t]=='-') dat[0][1][i]=1;
        t++;
    }
    for (int i=1;i<=h;i++)
    {
        getline(fin,str);
        t=0;
        if (str[t]=='|') dat[3][i][1]=1;
        for (int j=1;j<=w;j++)
        {
            t+=2;
            if (str[t]=='|'){
                        dat[1][i][j]=1;
                        dat[3][i][j+1]=1;
                        }
        }
        getline(fin,str);
        t=0;
        for (int j=1;j<=w;j++)
        {
            t++;
            if (str[t]=='-'){
                        dat[2][i][j]=1;
                        dat[0][i+1][j]=1;
                        }
            t++;
        }
    }
    
    for (int i=1;i<=h;i++)
        for (int j=1;j<=w;j++)
            d[i][j]=2147483647;
    
    for (int i=1;i<=h;i++)
    {
        if (dat[3][i][1]==0){
                             go(i,1,1);
                             }
        if (dat[1][i][w]==0){
                             go(i,w,1);
                             }
    }
    for (int i=1;i<=w;i++)
    {
        if (dat[0][1][i]==0){
                             go(1,i,1);
                             }
        if (dat[2][h][i]==0){
                             go(h,i,1);
                             }
    }
    
    
    int res=0;

    for (int i=1;i<=h;i++)
    {
        for (int j=1;j<=w;j++)
        {
            if (d[i][j]>res) res=d[i][j];
        }
    }
            
    fout<<res<<endl;
    return 0;
}
