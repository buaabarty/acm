/*
ID:ybojan2
LANG:C++
TASK:comehome
*/

#include <iostream>
#include <fstream>

using namespace std;

int ord(char c)
{
    if ((c>='a')&&(c<='z')) return (c-'a'+27);
    if ((c>='A')&&(c<='Z')) return (c-'A'+1);
}

int main()
{
    ifstream fin("comehome.in");
    ofstream fout("comehome.out");
    
    int p,map[53][53];
    fin>>p;
    for (int i=1;i<=52;i++)
        for (int j=1;j<=52;j++)
            map[i][j]=1000000000;
    for (int i=1;i<=p;i++)
    {
        char c;
        int x,y,d;
        fin>>c;
        x=ord(c);
        fin>>c;
        y=ord(c);
        fin>>d;
        if (d<map[x][y]){
                         map[x][y]=d;
                         map[y][x]=d;
                         }
    }
    for (int k=1;k<=52;k++)
        for (int i=1;i<=52;i++)
            for (int j=1;j<=52;j++)
                if (map[i][k]+map[k][j]<map[i][j])
                   map[i][j]=map[i][k]+map[k][j];
    int res=2147483647,k;
    for (int i=1;i<=25;i++)
        if (map[i][26]<res){
                          res=map[i][26];
                          k=i;
                          }
    fout<<(char)(k+'A'-1)<<" "<<res<<endl;
    return 0;
}
