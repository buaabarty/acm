/*
ID:ybojan2
LANG:C++
TASK:hamming
*/

#include <iostream>
#include <fstream>

using namespace std;

int dd(int x,int y)
{
    int cnt=0,tmp=x^y;
    for (;tmp>0;)
    {
        cnt++;
        tmp=tmp-(tmp&(-tmp));
    }
    return cnt;
}

int main()
{
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");
    
    int n,b,d,num[65],len=1;
    fin>>n>>b>>d;
    num[1]=0;
    for (int i=1;i<(1<<b);i++)
    {
        bool okay=true;
        for (int j=1;j<=len;j++)
            if (dd(i,num[j])<d)
            {
                              okay=false;
                              break;
            }
        if (okay) 
        {
                  len++;
                  num[len]=i;
        }
        if (len==n) break;
    }
    for (int i=1;i<=len;i++)
    {
        fout<<num[i];
        if ((i%10==0)||(i==len)) fout<<endl;
        else fout<<" ";
    }
    return 0;
}
